#include "Tasks.h"
#include "String/String.h"
#include "FileUtility.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Task *taskList;
int arrayLength;
int reallocateCounter;

void print_tasks(Task* task) {
    if (isNullOrWhiteSpace(task->updatedAt)) {
        printf("\n%d: %s\nStatus: %s, Created At: %s\n", task->id, task->description,task->status ,task->createdAt);
    } else {
        printf("\n%d: %s\nStatus: %s, Updated At: %s\n", task->id, task->description,task->status, task->updatedAt);
    }
}

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
    _Bool success = false;
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
        Task *taskFound = &taskList[i];
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
    if (taskList == NULL) {
        printf("No tasks found\n");
        return;
    }
    printf("Task List:\n");
    for (int i = 0; i < arrayLength; i++) {
        Task *task = &taskList[i];
        print_tasks(task);
    }
}

void sort_task_by_completed() {
    if (taskList == NULL) {
        printf("No tasks found\n");
        return;
    }
    printf("Completed Tasks:\n");
    int listLength = 0;
    for (int i = 0; i < arrayLength; i++) {
        Task *task = &taskList[i];
        if (compareStrings(task->status, "done")) {
            print_tasks(task);
            listLength++;
        }
    }
    if (listLength == 0) {
        printf("No tasks found\n");
    }
}

void sort_task_by_in_progress() {
    if (taskList == NULL) {
        printf("No tasks found\n");
        return;
    }
    printf("In Progress:\n");
    int listLength = 0;
    for (int i = 0; i < arrayLength; i++) {
        Task *task = &taskList[i];
        if (compareStrings(task->status, "in-progress")) {
            print_tasks(task);
            listLength++;
        }
    }
    if (listLength == 0) {
        printf("No tasks found\n");
    }
}

void sort_task_by_todo() {
    if (taskList == NULL) {
        printf("No tasks found\n");
        return;
    }
    printf("To Do List:\n");
    int listLength = 0;
    for (int i = 0; i < arrayLength; i++) {
        Task *task = &taskList[i];
        if (compareStrings(task->status, "todo")) {
            print_tasks(task);
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
