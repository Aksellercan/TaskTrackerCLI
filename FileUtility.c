#include "FileUtility.h"
#include "cJSON/cJSON.h"
#include "Tasks.h"
#include "String/String.h"

#include <stdio.h>
#include <stdlib.h>

int taskCounter = 0;
int lastIdentifier = 0;

void parse_from_JSON(const char *json_string) {
    const cJSON *parseJSON = cJSON_Parse(json_string);
    if (parseJSON == NULL) {
        printf("Failed to parse JSON\n");
        // exit(1);
    }
    //get array length
    const cJSON *get_JSON_ArrayLength = cJSON_GetArrayItem(parseJSON, 0);
    const double parsedArrayLength = cJSON_GetNumberValue(get_JSON_ArrayLength);

    const cJSON *get_JSON_Array = cJSON_GetArrayItem(parseJSON, 1);
    for (int i = 0; i < parsedArrayLength; i++) {
        const cJSON *get_Array_Elements = cJSON_GetArrayItem(get_JSON_Array, i);
        const cJSON *objectId = cJSON_GetObjectItem(get_Array_Elements, "id");
        const cJSON *objectDescription = cJSON_GetObjectItem(get_Array_Elements, "description");
        const cJSON *objectStatus = cJSON_GetObjectItem(get_Array_Elements, "status");
        const cJSON *objectCreatedAt = cJSON_GetObjectItem(get_Array_Elements, "createdAt");
        const cJSON *objectUpdatedAt = cJSON_GetObjectItem(get_Array_Elements, "updatedAt");

        const char *taskDescription = cJSON_GetStringValue(objectDescription);
        const char *taskStatus = cJSON_GetStringValue(objectStatus);
        const int taskId = (int) cJSON_GetNumberValue(objectId);
        const char *taskCreatedAt = cJSON_GetStringValue(objectCreatedAt);
        const char *taskUpdatedAt = cJSON_GetStringValue(objectUpdatedAt);
        const Task parsedTask = {taskId};
        StringCopy(taskCreatedAt, parsedTask.createdAt);
        StringCopy(taskUpdatedAt, parsedTask.updatedAt);
        StringCopy(taskDescription, parsedTask.description);
        StringCopy(taskStatus, parsedTask.status);
        add_task(&parsedTask, false);
        if (lastIdentifier < taskId) {
            lastIdentifier = taskId;
        }
        taskCounter++;
    }
}

void save_to_file(const Task *tasklist, int arrayLength) {
    cJSON *json = cJSON_CreateObject();
    cJSON_AddNumberToObject(json, "arrayLength", arrayLength);
    cJSON *innerArray = cJSON_AddArrayToObject(json, "tasks");

    for (int i = 0; i < arrayLength; i++) {
        const Task *task = &tasklist[i];
        cJSON *arrayElements = cJSON_AddObjectToObject(innerArray, "taskList");
        cJSON_AddNumberToObject(arrayElements, "id", task->id);
        cJSON_AddStringToObject(arrayElements, "description", task->description);
        cJSON_AddStringToObject(arrayElements, "status", task->status);
        cJSON_AddStringToObject(arrayElements, "createdAt", task->createdAt);
        cJSON_AddStringToObject(arrayElements, "updatedAt", task->updatedAt);
    }

    const char *json_str = cJSON_Print(json);
    FILE *fptr = fopen("data.json", "w");
    if (fptr == NULL) {
        printf("File could not be opened\n");
    }
    cJSON_free(json);
    fprintf(fptr, json_str);
    fclose(fptr);
}

void load_from_file() {
    FILE *fptr = fopen("data.json", "r");
    if (fptr == NULL) {
        return;
    }
    fseek(fptr, 0, SEEK_END);
    const int filesize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    char *str = malloc(filesize * sizeof(char));
    if (str == NULL) {
        printf("Memory could not be allocated\n");
        return;
    }

    fread(str, sizeof(char), filesize, fptr);

    fclose(fptr);
    parse_from_JSON(str);
    free(str);
}
