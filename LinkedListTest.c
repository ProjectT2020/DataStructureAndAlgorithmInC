//
// Created by temTeng on 2021/7/7.
//

#include <stdio.h>
#include "LinkedListTest.h"
#include "LinkList.h"

void linkedGetLastElemTest() {
    printf("how many nodeNum you want?\n");
    int nodeNum;
    scanf_s("%d", &nodeNum);
    LinkList linkList = SinglyLinkedCircularList_Init(nodeNum);
    SinglyLinkedCircularList_Show(linkList);

    LNode *ele = GetLastElem(linkList);
    if (ele == NULL) {
        printf("the list is empty\n");
    } else {
        printf("ele: %d\n", ele->data);
    }
}

void linkedListLocateElementTest() {
    LinkList L = List_TailInsert();
    List_Show(L);

    printf("what element you want?\n");
    int element;
    scanf_s("%d", &element);
    LNode *ele = LocateElement(L, element);
    if (ele == NULL) {
        printf("no such element\n");
    } else {
        printf("ele: %d\n", ele->data);
    }
}

void linkedListGetElementTest() {
    LinkList L = List_TailInsert();
    List_Show(L);

    printf("which element you want?\n");
    int index;
    scanf_s("%d", &index);
    LNode *ele = GetElem(L, index);
    printf("ele: %d\n", ele->data);
}

void linkedListTest() {
    LNode a;
    a.data = 9;
    printf("%d\n", a.data);

    LinkList l = &a;
    l->data = 19;
    printf("%d\n", a.data);

    printf("enter new linked list: \n");

    LinkList L = List_HeadInsert();
    List_Show(L);

    //TODO destroy old list first
    List_Destroy(L);
    L = List_TailInsert();
    List_Show(L);

    LNode *ele = GetElem(L, 3);
    printf("ele: %d\n", ele->data);


//    LinkList b;
}