//
// Created by temTeng on 2021/7/7.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "ReversePolishNotationCalculator.h"
#include "Stack.h"

int ReversePolishNotationCalculator() {
    SequenceStack sequenceStack = (SequenceStack) malloc(sizeof(SequenceStackStruct));
    SequenceStack_Init(sequenceStack);
    char inputCharacter;

    //input expression
    printf("input Reverse Polish Notation to compute, delimited by space\n");
    scanf_s("%c", &inputCharacter);

    ElemType inputNumber = NULL;
    ElemType leftNumber = NULL;
    ElemType rightNumber = NULL;
    ElemType resultNumber = NULL;
    char digitBuffer[1024];
    char *inputNumberBuffer = digitBuffer;
    while (inputCharacter != '#') {
        int digitCount = 0;
        while (isdigit(inputCharacter) || inputCharacter == '.') {
            digitBuffer[digitCount] = inputCharacter;
            digitCount++;
            digitBuffer[digitCount] = '\0';
            if (digitCount >= 1024) {
                printf("input digit too long!");
            }

            scanf_s("%c", &inputCharacter);
            if (inputCharacter == ' ') {
                inputNumber = (ElemType) malloc(sizeof(double));
                *inputNumber = atof(inputNumberBuffer);
                SequenceStack_Push(sequenceStack, inputNumber);
                digitCount = 0;//重新缓存digit buffer
            }
            scanf_s("%c", &inputCharacter);
        }

        switch (inputCharacter) {
            case '+':
                //取操作数据
                SequenceStack_Pop(sequenceStack, &rightNumber);
                SequenceStack_Pop(sequenceStack, &leftNumber);
                //计算
                resultNumber = (double *) malloc(sizeof(double));
                *resultNumber = *leftNumber + *rightNumber;
                //销毁数据
                free(leftNumber);
                free(rightNumber);
                //将结果入栈
                SequenceStack_Push(sequenceStack, resultNumber);
                break;
            case '-':
                //取操作数据
                SequenceStack_Pop(sequenceStack, &rightNumber);
                SequenceStack_Pop(sequenceStack, &leftNumber);
                //计算
                resultNumber = (double *) malloc(sizeof(double));
                *resultNumber = *leftNumber - *rightNumber;
                //销毁数据
                free(leftNumber);
                free(rightNumber);
                //将结果入栈
                SequenceStack_Push(sequenceStack, resultNumber);
                break;
            case '*':
                //取操作数据
                SequenceStack_Pop(sequenceStack, &rightNumber);
                SequenceStack_Pop(sequenceStack, &leftNumber);
                //计算
                resultNumber = (double *) malloc(sizeof(double));
                *resultNumber = (*leftNumber) * (*rightNumber);
                //销毁数据
                free(leftNumber);
                free(rightNumber);
                //将结果入栈
                SequenceStack_Push(sequenceStack, resultNumber);
                break;
            case '/':
                //取操作数据
                SequenceStack_Pop(sequenceStack, &rightNumber);
                SequenceStack_Pop(sequenceStack, &leftNumber);
                //计算
                resultNumber = (double *) malloc(sizeof(double));
                if (*rightNumber != 0) {
                    *resultNumber = *leftNumber / *rightNumber;
                } else {
                    printf("Divided by Zero Error!");
                    return -1;
                }
                //销毁数据
                free(leftNumber);
                free(rightNumber);
                //将结果入栈
                SequenceStack_Push(sequenceStack, resultNumber);
                break;

            default:
                break;
        }
        scanf_s("%c", &inputCharacter);
    }

    resultNumber = (double *) malloc(sizeof(double));
    SequenceStack_Pop(sequenceStack, &resultNumber);
    printf("result = %f\n", *resultNumber);
    free(resultNumber);

    return 0;
}
