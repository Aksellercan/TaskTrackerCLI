#ifndef STRING_H
#define STRING_H

unsigned int compareStrings(const char *str1, const char *str2);
unsigned int includesSpace(const char *str);
char *trim(const char *str);
unsigned long stringLength(const char *str);
unsigned int isNullOrWhiteSpace(const char *str);
unsigned int ContainsChar(const char *str, const char *containsChar);
unsigned long CountCharinString(const char *str, const char *containsChar);
void StringCopy(const char *stringToCopy, char *destination);
char *RemoveTrailingNewLine(char *stringToRemove);
unsigned int Contains(const char *str, const char *stringToFind);
char *ToLowerCase(const char *str);
char *ToUpperCase(const char *str);
char *StringAppend(const char *mainString, const char *appendString);
unsigned long getStringLength(const char *str);

#endif // STRING_H
