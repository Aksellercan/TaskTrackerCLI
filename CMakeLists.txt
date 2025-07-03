cmake_minimum_required(VERSION 3.31)
project(TaskTrackerCLI C)

set(CMAKE_C_STANDARD 11)

add_executable(TaskTrackerCLI main.c FileUtility.c FileUtility.h Tasks.c Tasks.h String/String.c String/String.h cJSON/cJSON.c cJSON/cJSON.h)
