//
// Created by temTeng on 2021/7/8.
//

#include <stdio.h>
#include <string.h>
#include "SubstringSearch.h"

int Substring_MultiShow(char *text, char *pattern, Matches matches) {
    int textLengh = strlen(text);
    int patternLengh = strlen(pattern);
    printf("text:\n%s\n", text);

    printf("match:\n");
    for (int match = 0; match < matches->nMatches; ++match) {
        for (int i = 0; i < textLengh; ++i) {
            if (matches->matchIndices[match] <= i && i < (matches->matchIndices[match] + patternLengh)) {//如果在match里面
                printf("_");
            } else {
                printf("%c", text[i]);
            }
        }
        printf("\n");
    }

}

int Substring_Show(char *text, char *pattern, int matchIndex) {
    int textLengh = strlen(text);
    int patternLengh = strlen(pattern);
    printf("text:\n%s\n", text);

    printf("match:\n");
    for (int i = 0; i < textLengh; ++i) {
        if (matchIndex <= i && i < (matchIndex + patternLengh)) {//如果在match里面
            printf("_");
        } else {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}
