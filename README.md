
Sample solution for the [task-tracker](https://roadmap.sh/projects/task-tracker) challenge from roadmap.sh.

```bash
    ./TaskTrackerCLI add "task description"
    ./TaskTrackerCLI update 1 "new task description"
    ./TaskTrackerCLI delete 2 
    ./TaskTrackerCLI list
    ./TaskTrackerCLI list todo/done/in-progress
    ./TaskTrackerCLI mark-done 1
    ./TaskTrackerCLI mark-in-progress 3
    ./TaskTrackerCLI sort-completed
    ./TaskTrackerCLI sort-incomplete
    ./TaskTrackerCLI help
```

```bash
    ./TaskTrackerCLI help
    Usage: [OPTION] <description/id>
    
    Options:
    add <description>
    delete <id>
    update <id> <description>
    mark-in-progress <id>
    mark-done <id>
    list <todo, in-progress, done>
    
    Usage: [OPTION]
    sort-completed -> Sort by completed
    sort-incomplete -> Sort by incomplete or in-progress
    list -> List all tasks
    help -> print this menu
```