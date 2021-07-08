//
// Created by temTeng on 2021/7/8.
//

#include <stdio.h>
#include <string.h>
#include "Show.h"

int show2DimensionalIntegerArray(int *matrix, int rows, int columns, char *delimiter, char *message) {
    printf(message);
    char Format[1024] = "%d";
    strcat_s(Format, 1024, delimiter);

    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            printf(Format, *(matrix + row * 8 + column));
        }
        printf("\n");
    }
    return 0;
}
