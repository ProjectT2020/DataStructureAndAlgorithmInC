//
// Created by temTeng on 2021/7/7.
//

#include <stdio.h>
#include "LatinSquareSingleLinkedCircularList.h"
#include "../DataStructure/LinkList.h"

void LatinSquareSingleLinkedCircularList() {
    int n;

    printf("input size of the Latin Square\n");
    scanf_s("%d", &n);

    LinkList numbers = SinglyLinkedCircularList_Init(n);

    for (int i = 0; i < n; ++i) {
        LNode *cur = GetElem(numbers, i + 1);

        //print one line
        for (int j = 0; j < n; ++j) {
            printf("%d\t", cur->data);
            cur = cur->next;
        }
        printf("\n");
    }

}
