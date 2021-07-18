//
// Created by temTeng on 2021/7/8.
//

#include <string.h>
#include <stdio.h>
#include "StringTest.h"

void StringTest() {
    char a[] = "hello";
    char *b = "hello";
    int aLengh = strlen(a);
    int bLength = strlen(b);

    printf("length of a: %d\n", aLengh);
    printf("length of b: %d\n", bLength);

}

