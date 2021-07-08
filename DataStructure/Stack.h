//
// Created by temTeng on 2021/7/7.
//

#ifndef DATASTRUCTUREANDALGORITHM_STACK_H
#define DATASTRUCTUREANDALGORITHM_STACK_H


#define MaxSize 1024

//typedef struct {
//    double data;
//    char *name;
//} ElementStruct, *ElemType;
typedef double *ElemType;

typedef struct {
    ElemType data[MaxSize];
    //top指向栈顶，data[top]为最新数据
    int top;
} SequenceStackStruct, *SequenceStack;

int SequenceStack_Pop(SequenceStack sequenceStack, ElemType *output);

int SequenceStack_Push(SequenceStack sequenceStack, ElemType element);

int SequenceStack_Init(SequenceStack sequenceStack);

void SequenceStack_Show(SequenceStack sequenceStack);

#endif //DATASTRUCTUREANDALGORITHM_STACK_H
