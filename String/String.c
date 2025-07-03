#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include <stdbool.h>


int counter(const char *str, int count) {
    if (str == NULL) return 0;
    if (str[count] == '\0') {
        return count;
    }
    count++;
    return counter(str, count);
}

int stringLength(const char *str) {
    return counter(str, 0);
}

bool compareStrings(const char *str1, const char *str2) {
    const int len1 = stringLength(str1);
    if (len1 != stringLength(str2)) {
        return false;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }
    return true;
}

bool includesSpace(const char *str) {
    const int strLen = stringLength(str);
    if (str[0] == ' ' || str[strLen - 1] == ' ') {
        return true;
    }

    for (int i = 0; i < strLen; i++) {
        if (str[i] == ' ') {
            return true;
        }
    }
    return false;
}

char* trim(const char *str) {
    const int strLen = stringLength(str);
    char *newString = malloc(strLen + 1); //print (+1) for null terminator '\0'
    if (strLen == 0) { return NULL; }
    int count = 0;
    bool trimmed = false;
    while (!trimmed) {
        if (str[count] != ' ') {
            if (newString != NULL) {
                for (int i = 0; i < strLen; i++) {
                    newString[i] = str[count+i];
                }
                trimmed = true;
            } else {
                printf("Memory Allocation Failed!\n");
                exit(3);
            }
            if (str[strLen-1] == ' ') {
                const int newLength = stringLength(newString);
                int j = strLen-1;
                for (int i = newLength-1; i >= 0; i--) {
                    if (str[j] != ' ') {
                        break;
                    }
                    if (j >= 0) j--;
                    newString[i] = '\0';
                }
            }
        }
        count++;
    }
    return newString;
}

bool isNullOrWhiteSpace(const char *str) {
    if (str == NULL) { return true; }
    const int strLen = stringLength(str);
    if (strLen == 0) {
        return true;
    }
    if (strLen == 1) {
        if (str[0] == ' ') {
            return true;
        }
    }
    bool isSpace = true;
    for (int i = 0; i < strLen; i++) {
        if (str[i] != ' ') {
            isSpace = false;
        }
    }
    return isSpace;
}

bool ContainsChar(const char* str, const char* containsChar) {
    const int strLen = stringLength(str);
    if (strLen == 0) { return false; }
    for (int i = 0; i < strLen; i++) {
        if (str[i] == *containsChar) {
            return true;
        }
    }
    return false;
}

int CountCharinString(const char *str, const char *containsChar) {
    const int strLen = stringLength(str);
    if (strLen == 0) { return 0; }
    int count = 0;
    for (int i = 0; i < strLen; i++) {
        if (str[i] == *containsChar) {
            count++;
        }
    }
    return count;
}

void StringCopy(const char *stringToCopy, char *destination) {
    if (stringToCopy == NULL) {
        return;
    }
    const int strlen = stringLength(stringToCopy);
    if (strlen == 0) { return; }
    for (int i = 0; i < strlen; i++) {
        destination[i] = stringToCopy[i];
    }
}

char* RemoveTrailingNewLine(char *stringToRemove) {
    const int strLen = stringLength(stringToRemove);
    if (strLen == 0) { return NULL; }
    for (int i = 0; i < strLen; i++) {
        if (stringToRemove[i] == '\n') {
            stringToRemove[i] = '\0';
        }
    }
    return stringToRemove;
}