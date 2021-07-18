//
// Created by temTeng on 2021/7/8.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "KnuthMorrisPrattAlgorithm.h"

int *getPartialMatchTable(char *pattern);

IntegerArray prefixTable(char *pattern) {
    int length = strlen(pattern);

    IntegerArray prefixTable = (IntegerArray) malloc(sizeof(IntegerArrayStruct));
    prefixTable->data = (int *) malloc(sizeof(length));
    prefixTable->length = length;


}

Matches KnuthMorrisPratt_Search(char *text, char *pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    Matches matches = (Matches) malloc(sizeof(MatchesStruct));
    matches->matchIndices = (int *) malloc(sizeof(int) * textLength);
    matches->nMatches = 0;


    int *partialMatchTable = getPartialMatchTable(pattern);
    if (partialMatchTable == NULL) {
        return matches;
    }

    int currentText = 0;
    int currentPattern = 0;
    while (currentText < textLength) {
        if (pattern[currentPattern] == text[currentText]) {
            currentText = currentText + 1;
            currentPattern = currentPattern + 1;
            if (currentPattern == patternLength) {
                matches->matchIndices[matches->nMatches] = currentText - currentPattern;
                matches->nMatches = matches->nMatches + 1;
                currentPattern = partialMatchTable[currentPattern];
            }
        } else {
            currentPattern = partialMatchTable[currentPattern];
            if (currentPattern < 0) {
                currentText = currentText + 1;
                currentPattern = currentPattern + 1;
            }
        }
    }

    return matches;
}

int *getPartialMatchTable(char *pattern) {
    int patternLength = strlen(pattern);
    if (patternLength == 0) {//pattern啥也没有
        return NULL;
    }

    int *partialMatchTable = (int *) malloc(sizeof(int) * (patternLength + 1));

    int currentPosition = 1;
    int cnd = 0;
    partialMatchTable[0] = -1;
    while (currentPosition < patternLength) {
        if (pattern[currentPosition] == pattern[cnd]) {
            partialMatchTable[currentPosition] = partialMatchTable[cnd];
        } else {
            partialMatchTable[currentPosition] = cnd;
            while (cnd >= 0 && pattern[currentPosition] != pattern[cnd]) {
                cnd = partialMatchTable[cnd];
            }
        }
        currentPosition = currentPosition + 1;
        cnd = cnd + 1;
    }

    partialMatchTable[currentPosition] = cnd;

    return partialMatchTable;
}

int showPartialMatchTable(char *pattern) {
    int patternLenght = strlen(pattern);
    if (patternLenght == 0) {//pattern啥也没有
        printf("[]");
    }
    int *partialMatchTable = getPartialMatchTable(pattern);

    printf("[ ");
    for (int i = 0; i < patternLenght; ++i) {
        printf("%c\t", pattern[i]);
    }
    printf(" ]\n");

    printf("[ ");
    for (int i = 0; i < patternLenght; ++i) {
        printf("%d\t", partialMatchTable[i]);
    }
    printf(" ]\n");
}
