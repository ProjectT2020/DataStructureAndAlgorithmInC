//
// Created by temTeng on 2021/7/8.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "EightQueensPuzzle.h"
#include "../Commons/Show.h"

Chessboard chessboardCreate() {
    Chessboard newChessboard = (Chessboard) malloc(sizeof(ChessboardStructure));
    chessboardInit(newChessboard);
    return newChessboard;
}

int chessboardInit(Chessboard chessboard) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            chessboard->board[i][j] = 0;
        }
    }
    return 0;
}

int chessboardShow(Chessboard chessboard, char *message) {
    show2DimensionalIntegerArray((int *) chessboard->board, 8, 8, " \0", message);
    return 0;
}

int chessboardCopy(Chessboard sourceChessboard, Chessboard destinationChessboard) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            destinationChessboard->board[i][j] =
                    sourceChessboard->board[i][j];
        }
    }
    return 0;
}

/**
*
* @param currentRow 起始行
* @param n
* @param chessboard
* @return
*/
Chessboard solutionEightQueensPuzzle(int currentRow, int n, Chessboard chessboard, int *count) {
    Chessboard currentChessboard = chessboardCreate();
    chessboardCopy(chessboard, currentChessboard);

    if (8  == currentRow) {//最后一行不危险并进入递归函数，则表明找到一个解，
        *count = *count + 1;
        char messageBuffer[1024];
        sprintf(messageBuffer, "#%d eight queens puzzle solution: \n", *count);
        chessboardShow(currentChessboard, messageBuffer);
    } else {
        for (int currentColumn = 0; currentColumn < 8; ++currentColumn) {
            if (0 == dangerCheck(currentRow, currentColumn, currentChessboard)) {//如果不危险则选定
                currentChessboard->board[currentRow][currentColumn] = 1;

                //如果不行则重新设置currentChessboard
                Chessboard result = solutionEightQueensPuzzle(currentRow + 1, n, currentChessboard, count);//递归
                if (0 != eightQueensCheck(result)) {
                    currentChessboard->board[currentRow][currentColumn] = 0;
                }
            } else {
                continue;   //如果危险则进入下一列
            }
        }
    }
    return chessboard;
}

/**
 * 获得一个随机摆放8个皇后的棋盘
 * @param chessboard
 * @return
 */
Chessboard eightQueensRandom(Chessboard chessboard) {
    srand(time(NULL));
    for (int i = 0; i < 8; ++i) {
        int randomColumn = rand() % 8;
        chessboard->board[i][randomColumn] = 1;
    }
    return chessboard;
}

int dangerCheck(int targetRow, int targetColumn, Chessboard chessboard) {
    const int stepDirection[8][2] = {
            {-1, 0},
            {-1, 1},
            {0,  1},
            {1,  1},
            {1,  0},
            {1,  -1},
            {0,  -1},
            {-1, -1},
    };

    for (int direction = 0; direction < 8; ++direction) {//八个方向进行检查
        for (int step = 1; step < 8; ++step) {          //最多走七步
            int currentRow = targetRow + step * stepDirection[direction][0];
            int currentColumn = targetColumn + step * stepDirection[direction][1];
            if (0 <= currentRow && currentRow < 8 && 0 <= currentColumn && currentColumn < 8) {//在棋盘内
                if (1 == chessboard->board[currentRow][currentColumn]) {                //如果当前位置有皇后则返回负数，否则继续检查
                    return -1 - direction;
                }
            } else {
                break;  //不在棋盘内则跳出某一方向的循环，进入下一个方向
            }
        }
    }
    return 0;
}

/**
 *
 * @param chessboard
 * @return 0 满足条件
 */
int eightQueensCheck(Chessboard chessboard) {
    //将二维数组棋盘转换为稀疏数组
    int sparseArrayChessboard[8][3];
    int queensCount = 0;

    //遍历棋盘
    for (int row = 0; row < 8; ++row) {
        for (int column = 0; column < 8; ++column) {

            if (1 == chessboard->board[row][column]) { //如果棋盘i行j列为皇后
                if (queensCount < 8) {      //如果稀疏数组未满，皇后个数还未到八个
                    sparseArrayChessboard[queensCount][0] = row;  //此皇后的行坐标
                    sparseArrayChessboard[queensCount][1] = column;  //此皇后的列坐标
                    sparseArrayChessboard[queensCount][2] = chessboard->board[row][column];    //此皇后对应的值

                    queensCount = queensCount + 1;              //皇后计数加一
                } else {
                    return -1;              //皇后个数超过8，返回-1，不满足八皇后问题
                }
            }

        }
    }
    if (queensCount != 8) {
        return -1;              //皇后个数不为8，返回-1，不满足八皇后问题
    }

    //遍历皇后们，判断皇后之间是否有威胁
    for (int focusQueen = 0; focusQueen < 8; ++focusQueen) {
        int focusQueenRow = sparseArrayChessboard[focusQueen][0];
        int focusQueenColumn = sparseArrayChessboard[focusQueen][1];
        //检查皇后focus与其他皇后other的关系
        for (int otherQueen = focusQueen + 1;
             otherQueen < 8; ++otherQueen) {//只与后面的皇后进行检查总共需要7+6+...+2+1 = 7*(1+7)/2 = 28次检查
            int otherQueenRow = sparseArrayChessboard[otherQueen][0];
            int otherQueenColumn = sparseArrayChessboard[otherQueen][1];
            //检查两个皇后是否在同一行
            if (focusQueenRow == otherQueenRow) {
                return -2;
            }
                //检查两个皇后是否在同一列
            else if (focusQueenColumn == otherQueenColumn) {
                return -3;
            }
                //检查两个皇后是否在同一斜线
            else if (
                    (focusQueenRow > otherQueenRow ? focusQueenRow - otherQueenRow : otherQueenRow -
                                                                                     focusQueenRow)//两个皇后所在行距离
                    ==
                    (focusQueenColumn > otherQueenColumn ? focusQueenColumn - otherQueenColumn : otherQueenColumn -
                                                                                                 focusQueenColumn)//两个皇后所在列的距离

                    ) {//如果行距离跟列距离相等则认为两个皇后在同一斜线上
                return -4;
            }
        }
    }

    return 0;//如果以上条件（共八个皇后，且相互没有威胁）都通过则认为满足八皇后问题
}

int eightQueensCheckShow(Chessboard chessboard) {
    chessboardShow(chessboard, "the chessboard to be checked\n");
    int checkResult = eightQueensCheck(chessboard);
    switch (checkResult) {
        case 0:
            printf("pass eight queens puzzle check!");
            break;
        case -1:
            printf("the number of queens in the chessboard is not 8!");
            break;
        case -2:
            printf("there are two queens in the same row!");
            break;
        case -3:
            printf("there are two queens in the same column!");
            break;
        case -4:
            printf("there are two queens in the same diagonal!");
            break;
        default:
            printf("unknown case...");
    }
}
