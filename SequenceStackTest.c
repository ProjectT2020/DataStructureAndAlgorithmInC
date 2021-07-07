//
// Created by temTeng on 2021/7/7.
//

#include "SequenceStackTest.h"
#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

void SequenceStackTest() {
    SequenceStack sequenceStack = (SequenceStack) malloc(sizeof(SequenceStackStruct));
    SequenceStack_Init(sequenceStack);

//    ElemType e1 = (ElemType) malloc(sizeof(ElementStruct));
//    e1->data = 12.2;
//    e1->name = "hello world";
//
//    ElemType e2 = (ElemType) malloc(sizeof(ElementStruct));
//    e2->data = 22.2;
//    e2->name = "hello Richard";
//
//    SequenceStack_Push(sequenceStack, e1);
//    SequenceStack_Push(sequenceStack, e2);

    SequenceStack_Show(sequenceStack);


}
