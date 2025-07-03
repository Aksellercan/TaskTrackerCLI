#ifndef FILEUTILITY_H
#define FILEUTILITY_H
#include "Tasks.h"

extern int lastIdentifier;

void save_to_file(const Task *tasklist, int arrayLength);
void load_from_file();

#endif //FILEUTILITY_H
