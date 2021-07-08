//
// Created by temTeng on 2021/7/8.
//

#ifndef DATASTRUCTUREANDALGORITHM_EIGHTQUEENSPUZZLE_H
#define DATASTRUCTUREANDALGORITHM_EIGHTQUEENSPUZZLE_H

typedef struct chessboard {
    int board[8][8];
} ChessboardStructure, *Chessboard;

Chessboard chessboardCreate();

int chessboardShow(Chessboard chessboard, char *message);

int chessboardInit(Chessboard chessboard);

int chessboardCopy(Chessboard sourceChessboard, Chessboard destinationChessboard);

/**
 * 递归解决八皇后问题
 * @param currentRow
 * @param n
 * @param chessboard
 * @param count
 * @return
 */
Chessboard solutionEightQueensPuzzle(int currentRow, int n, Chessboard chessboard, int *count);

Chessboard eightQueensRandom(Chessboard chessboard);

/**
 * 检查是否满足八皇后问题条件
 * @param chessboard
 * @return
 */
int eightQueensCheck(Chessboard chessboard);

/**
 * 判断某一位置是否危险
 * @param targetRow       base 0
 * @param targetColumn    base 0
 * @param chessboard
 * @return
 */
int dangerCheck(int targetRow, int targetColumn, Chessboard chessboard);

/**
 * 展示棋盘并确认是否满足八皇后问题
 * @param chessboard
 * @return
 */
int eightQueensCheckShow(Chessboard chessboard);

#endif //DATASTRUCTUREANDALGORITHM_EIGHTQUEENSPUZZLE_H
