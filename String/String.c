#include <stdio.h>
#include <stdlib.h>
#include "String.h"

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

_Bool compareStrings(const char *str1, const char *str2) {
    const int len1 = stringLength(str1);
    if (len1 != stringLength(str2)) {
        return 0;
    }
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            return 0;
        }
    }
    return 1;
}

_Bool includesSpace(const char *str) {
    const int strLen = stringLength(str);
    if (str[0] == ' ' || str[strLen - 1] == ' ') {
        return 1;
    }

    for (int i = 0; i < strLen; i++) {
        if (str[i] == ' ') {
            return 1;
        }
    }
    return 0;
}

char* trim(const char *str) {
    const int strLen = stringLength(str);
    char *newString = malloc(strLen + 1); //print (+1) for null terminator '\0'
    if (strLen == 0) { return NULL; }
    int count = 0;
    _Bool trimmed = 0;
    while (!trimmed) {
        if (str[count] != ' ') {
            if (newString != NULL) {
                for (int i = 0; i < strLen; i++) {
                    newString[i] = str[count+i];
                }
                trimmed = 1;
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

_Bool isNullOrWhiteSpace(const char *str) {
    if (str == NULL) { return 1; }
    const int strLen = stringLength(str);
    if (strLen == 0) {
        return 1;
    }
    if (strLen == 1) {
        if (str[0] == ' ') {
            return 1;
        }
    }
    _Bool isSpace = 1;
    for (int i = 0; i < strLen; i++) {
        if (str[i] != ' ') {
            isSpace = 0;
        }
    }
    return isSpace;
}

_Bool ContainsChar(const char* str, const char* containsChar) {
    const int strLen = stringLength(str);
    if (strLen == 0) { return 0; }
    for (int i = 0; i < strLen; i++) {
        if (str[i] == *containsChar) {
            return 1;
        }
    }
    return 0;
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

_Bool Contains(const char *pattern, const char *stringToFind) {
    const int patternLen = stringLength(pattern);
    int correctLetterCount = 0;
    int jIndex = 0;
    int stringToFindLen = stringLength(stringToFind);
    for (int i = 0; i < stringToFindLen; i++) {
        if (jIndex == patternLen-1) {
            jIndex = 0;
        }
        if (pattern[jIndex] == stringToFind[i] && pattern[jIndex+1] == stringToFind[i+1]) {
            correctLetterCount++;
            jIndex++;
        }
        if (correctLetterCount == patternLen-1) {
            return 1;
        }
    }
    return 0;
}

char* ToLowerCase(const char * str) {
    const int strLen = stringLength(str);
    char returnString[strLen];
    if (strLen == 0) { return NULL; }
    for (int i = 0; i < strLen; i++) {
        char c = str[i];
        if (c == '\0') {
            break;
        }
        //Uppercase letters in ASCII Table
        if (c > 64 && c < 91) {
            c = c+32;
            returnString[i] = c;
        }
        returnString[i] = c;
    }
    returnString[strLen] = '\0';
    char* newString = malloc(strLen+1);
    StringCopy(returnString, newString);
    return newString;
}

char* ToUpperCase(const char * str) {
    const int strLen = stringLength(str);
    char returnString[strLen];
    if (strLen == 0) { return NULL; }
    for (int i = 0; i < strLen; i++) {
        char c = str[i];
        if (c == '\0') {
            break;
        }
        //Lowercase letters in ASCII Table
        if (c > 96 && c < 123) {
            c = c-32;
            returnString[i] = c;
        }
        returnString[i] = c;
    }
    returnString[strLen] = '\0';
    char* newString = malloc(strLen+1);
    StringCopy(returnString, newString);
    return newString;
}

char* StringAppend(const char* mainString, const char* appendString) {
    const int mainStringLength = stringLength(mainString);
    const int appendStringLength = stringLength(appendString);
    if (appendStringLength == 0) { return (char*) mainString; }
    if (mainStringLength == 0) { return (char*) appendString; }
    int fullLength = mainStringLength+appendStringLength;
    char* fullString = (char*)malloc(fullLength + 1);
    for (int i = 0; i < fullLength; i++) {
        if (i >= mainStringLength) {
            fullString[i] = appendString[i-mainStringLength];
            continue;
        }
        fullString[i] = mainString[i];
    }
    fullString[fullLength] = '\0';
    return fullString;
}