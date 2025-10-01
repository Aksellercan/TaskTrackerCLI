#ifndef STRING_H
#define STRING_H

_Bool compareStrings(const char *str1, const char *str2);
_Bool includesSpace(const char *str);
char* trim(const char *str);
int stringLength(const char *str);
_Bool isNullOrWhiteSpace(const char* str);
_Bool ContainsChar(const char *str, const char *containsChar);
int CountCharinString(const char *str, const char *containsChar);
void StringCopy(const char *stringToCopy, char *destination);
char* RemoveTrailingNewLine(char *stringToRemove);
_Bool Contains(const char *str, const char *stringToFind);
char* ToLowerCase(const char *str);
char* ToUpperCase(const char *str);
char* StringAppend(const char* mainString, const char* appendString);
int getStringLength(const char *str);

#endif //STRING_H
