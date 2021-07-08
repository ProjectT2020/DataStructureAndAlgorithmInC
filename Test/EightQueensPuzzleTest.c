//
// Created by temTeng on 2021/7/8.
//

#include "EightQueensPuzzleTest.h"
#include "../Algorithm/EightQueensPuzzle.h"

void EightQueensPuzzleTest(){
    int count = 0;
    int *countPointer = &count;

    solutionEightQueensPuzzle(0, 8, chessboardCreate(), countPointer);
}
