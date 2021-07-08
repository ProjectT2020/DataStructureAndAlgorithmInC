cmake_minimum_required(VERSION 3.19)
project(DataStructureAndAlgorithm C)

set(CMAKE_C_STANDARD 99)

add_executable(DataStructureAndAlgorithm MagicCards.c LinkList.h main.c MagicCards.h LinkedListTest.c LinkedListTest.h LinkList.c MagicCardsSingleLinkedCircularList.c MagicCardsSingleLinkedCircularList.h LatinSquareSingleLinkedCircularList.c LatinSquareSingleLinkedCircularList.h Stack.c Stack.h ReversePolishNotationCalculator.c ReversePolishNotationCalculator.h SequenceStackTest.c SequenceStackTest.h Algorithm/EightQueensPuzzle.c Algorithm/EightQueensPuzzle.h Commons/Show.c Commons/Show.h)