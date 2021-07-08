#include <stdio.h>
#include "LinkedListTest.h"
#include "LinkList.h"
#include "MagicCards.h"
#include "MagicCardsSingleLinkedCircularList.h"
#include "LatinSquareSingleLinkedCircularList.h"
#include "SequenceStackTest.h"
#include "ReversePolishNotationCalculator.h"
#include "Algorithm/EightQueensPuzzle.h"
//
// Created by temTeng on 2021/7/7.
//

int main() {
    int count = 0;
    int *countPointer = &count;

    solutionEightQueensPuzzle(0, 8, chessboardCreate(), countPointer);

    return 0;
}