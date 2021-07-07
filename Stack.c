//
// Created by temTeng on 2021/7/7.
//

#include <stdio.h>
#include "Stack.h"


void SequenceStack_Show(SequenceStack sequenceStack) {
    for (int i = 0; i <= sequenceStack->top; ++i) {
        printf("%f\t", *(sequenceStack->data[i]));
    }
}

int SequenceStack_Init(SequenceStack sequenceStack) {
    sequenceStack->top = -1;
}

int SequenceStack_Push(SequenceStack sequenceStack, ElemType element) {
    //如果还有空间则push
    if (sequenceStack->top < MaxSize - 1) {
        sequenceStack->top = sequenceStack->top + 1;
        sequenceStack->data[sequenceStack->top] = element;
        return 0;
    } else {
        return -1;
    }
}

int SequenceStack_Pop(SequenceStack sequenceStack, ElemType *output) {
    //空栈无法弹出
    if (sequenceStack->top < 0) {
        return -1;
    }
    *output = sequenceStack->data[sequenceStack->top];
    sequenceStack->top = sequenceStack->top - 1;

    return 0;
}
