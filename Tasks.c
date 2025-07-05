#include "Tasks.h"
#include "String/String.h"
#include "FileUtility.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Task *taskList;
int arrayLength;
int reallocateCounter;

void allocate_memory() {
    if (taskList != NULL) {
        Task *ptr = realloc(taskList, sizeof(Task) * (arrayLength + 1));
        if (ptr == NULL) {
            printf("Memory reallocation failed\n");
            exit(3);
        }
        taskList = ptr;
        reallocateCounter++;
        return;
    }
    taskList = (Task *) malloc(sizeof(Task));
    if (taskList == NULL) {
        printf("Memory allocation error\n");
        exit(3);
    }
}

void add_task(const Task *task, const bool saveToFile) {
    if (task == NULL) return;
    allocate_memory();
    taskList[arrayLength] = *task;
    arrayLength++;
    if (saveToFile) {
        save_to_file(taskList, arrayLength);
    }
}

void remove_task(const int task_id) {
    bool success = false;
    for (int i = 0; i < arrayLength; i++) {
        const Task *task = &taskList[i];
        if (task->id == task_id) {
            taskList[i] = taskList[arrayLength - 1];
            arrayLength--;
            allocate_memory();
            success = true;
        }
    }
    if (success) {
        printf("Task with id %d removed\n", task_id);
        save_to_file(taskList, arrayLength);
    } else {
        printf("Task with id %d not found\n", task_id);
    }
}

void mark_task_status(const int taskid, const char *status) {
    bool success = false;
    for (int i = 0; i < arrayLength; i++) {
        Task *taskFound = &taskList[i];
        if (taskFound->id == taskid) {
            time_t currentTime;
            time(&currentTime);
            StringCopy(RemoveTrailingNewLine(ctime(&currentTime)), taskFound->updatedAt);
            StringCopy(status, taskFound->status);
            taskList[i] = *taskFound;
            success = true;
        }
    }
    if (success) {
        printf("Task with id %d status updated\n", taskid);
        save_to_file(taskList, arrayLength);
    } else {
        printf("Task with id %d not found\n", taskid);
    }
}

void update_task(const int taskid, const char *description) {
    bool success = false;
    for (int i = 0; i < arrayLength; i++) {
        const Task *taskFound = &taskList[i];
        if (taskFound->id == taskid) {
            time_t currentTime;
            time(&currentTime);
            StringCopy(RemoveTrailingNewLine(ctime(&currentTime)), taskFound->updatedAt);
            StringCopy(description, taskFound->description);
            char *status = "todo";
            StringCopy(status, taskFound->status);
            success = true;
        }
    }
    if (success) {
        printf("Task with id %d updated\n", taskid);
        save_to_file(taskList, arrayLength);
    } else {
        printf("Task with id %d not found\n", taskid);
    }
}

void list_tasks() {
    if (taskList == NULL) return;
    printf(">=====| LIST |=====<\n");
    printf("\n");
    for (int i = 0; i < arrayLength; i++) {
        const Task *task = &taskList[i];
        printf("   \tTask description: %s\n", task->description);
        printf("%d:", i + 1);
        printf("\tTask status: %s\n", task->status);
        printf("\tTask id: %d\n", task->id);
        printf("\tTask Created at %s\n", task->createdAt);
        printf("\tTask Updated at %s\n", task->updatedAt);
        printf("\n");
    }
}

void sort_task_by_completed() {
    if (taskList == NULL) return;
    printf(">=====| COMPLETED LIST |=====<\n");
    printf("\n");
    int listLength = 0;
    for (int i = 0; i < arrayLength; i++) {
        Task *task = &taskList[i];
        if (compareStrings(task->status, "done")) {
            printf("   \tTask description: %s\n", task->description);
            printf("%d:", listLength + 1);
            printf("\tTask status: %s\n", task->status);
            printf("\tTask id: %d\n", task->id);
            printf("\tTask Created at %s\n", task->createdAt);
            printf("\tTask Updated at %s\n", task->updatedAt);
            printf("\n");
            listLength++;
        }
    }
    if (listLength == 0) {
        printf("No tasks found\n");
    }
}

void sort_task_by_in_progress() {
    if (taskList == NULL) return;
    printf(">=====| IN PROGRESS LIST |=====<\n");
    printf("\n");
    int listLength = 0;
    for (int i = 0; i < arrayLength; i++) {
        Task *task = &taskList[i];
        if (compareStrings(task->status, "in-progress")) {
            printf("   \tTask description: %s\n", task->description);
            printf("%d:", listLength + 1);
            printf("\tTask status: %s\n", task->status);
            printf("\tTask id: %d\n", task->id);
            printf("\tTask Created at %s\n", task->createdAt);
            printf("\tTask Updated at %s\n", task->updatedAt);
            printf("\n");
            listLength++;
        }
    }
    if (listLength == 0) {
        printf("No tasks found\n");
    }
}

void sort_task_by_todo() {
    if (taskList == NULL) return;
    printf(">=====| TODO LIST |=====<\n");
    printf("\n");
    int listLength = 0;
    for (int i = 0; i < arrayLength; i++) {
        Task *task = &taskList[i];
        if (compareStrings(task->status, "todo")) {
            printf("   \tTask description: %s\n", task->description);
            printf("%d:", listLength + 1);
            printf("\tTask status: %s\n", task->status);
            printf("\tTask id: %d\n", task->id);
            printf("\tTask Created at %s\n", task->createdAt);
            printf("\tTask Updated at %s\n", task->updatedAt);
            printf("\n");
            listLength++;
        }
    }
    if (listLength == 0) {
        printf("No tasks found\n");
    }
}

void free_tasks() {
    if (taskList == NULL) return;
    free(taskList);
}
