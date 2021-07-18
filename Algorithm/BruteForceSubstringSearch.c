//
// Created by temTeng on 2021/7/8.
//

#include <string.h>
#include "BruteForceSubstringSearch.h"

/**
 *
 * @param text
 * @param pattern
 * @return index of the matched pattern or -1 for failed to match
 */
int bruteForceSubstringSearch(char text[], char pattern[]) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    for (int i = 0; i < textLength - (patternLength - 1); ++i) {
        int matchFlag = 1;
        for (int j = 0; j < patternLength; ++j) {
            if (text[i + j] != pattern[j]) {
                matchFlag = 0;
                break;
            }
        }
        if (matchFlag) {
            return i;
        }
    }
    return -1;
}
