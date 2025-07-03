#ifndef STRING_H
#define STRING_H
#include <stdbool.h>

bool compareStrings(const char *str1, const char *str2);
bool includesSpace(const char *str);
char* trim(const char *str);
int stringLength(const char *str);
bool isNullOrWhiteSpace(const char* str);
bool ContainsChar(const char *str, const char *containsChar);
int CountCharinString(const char *str, const char *containsChar);
void StringCopy(const char *stringToCopy, char *destination);
char* RemoveTrailingNewLine(char *stringToRemove);

#endif //STRING_H
