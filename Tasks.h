#ifndef TASKS_H
#define TASKS_H
#include <stdbool.h>

typedef struct {
    int id;
    char description[30];
    char status[15];
    char createdAt[30];
    char updatedAt[30];
} Task;

void add_task(const Task *task, bool saveToFile);
void remove_task(int task_id);
void update_task(int taskid, const char *description);
void sort_task_by_completed();
void sort_task_by_in_progress();
void sort_task_by_todo();
void mark_task_status(int taskid, const char *status);
void list_tasks();
void free_tasks();

#endif //TASKS_H