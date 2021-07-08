//
// Created by temTeng on 2021/7/7.
//
#include "LinkList.h"
#include <stdlib.h>
#include <stdio.h>

void List_Show(LinkList linkList) {
    while (linkList->next != NULL) {
        printf("%d\t", linkList->next->data);
        linkList = linkList->next;
    }
    printf("\n");
}

void List_Destroy(LinkList linkList) {
    LNode *nextNode;
    while (linkList->next != NULL) {
        nextNode = linkList->next;   //保存下一个节点
        free(linkList);         //free 当前节点, 包括头节点也会被删掉
        linkList = nextNode;         //当前节点等于下一个节点
    }
    free(linkList);             //free 最后一个节点, 包括空list（只有头节点）会在这里被删掉
}

LinkList List_TailInsert() {
    int data;
    LinkList L = (LinkList) malloc(sizeof(LNode));   //create head node
    LNode *newNode, *tail = L;
    L->next = NULL;                           //init empty linked list
    scanf("%d", &data);
    while (data > -100 && data < 100) {
        newNode = (LNode *) malloc(sizeof(LNode));     //create new node
        //尾插
        newNode->data = data;
        tail->next = newNode;
        tail = newNode;       //指向新的表尾节点
        //下一个数字
        scanf("%d", &data);
    }
    tail->next = NULL;        //尾指针置空

    return L;
}


LNode *LocateElement(LinkList linkList, int element) {
    LNode *cur = linkList->next;
    while (cur != NULL && cur->data != element) {//直到链表尾, 或者找到element
        cur = cur->next;
    }
    return cur;
}

LNode *GetLastElem(LinkList linkList) {
    if (linkList->next == NULL) {
        return NULL;
    }

    LNode *cur = linkList->next;
    while (linkList->next != cur->next) {
        cur = cur->next;
    }
    return cur;
}

LNode *GetElem(LinkList linkList, int index) {
    int i = 1;
    LNode *cur = linkList->next;
    if (index == 0) {
        return linkList;
    }
    if (index < 0) {
        return NULL;
    }
    while (cur && i < index) {
        cur = cur->next;
        i++;
    }
    return cur;
}

LNode *SinglyLinkedCircularList_Delete(LinkList linkList, int index) {
    LNode *cur = NULL;

    if (index <= 0) {//索引非法
        return NULL;
    }

    if (linkList->next == NULL) {//空线性表
        return NULL;
    }
    if (linkList->next->next == linkList->next) {//只有一个元素的线性表
        cur = linkList->next;
        linkList->next = NULL;
        return cur;
    }
    if (index == 1) {//如果要删除第一个节点
        //cur为第一个节点
        cur = linkList->next;

        //将第一个节点与第二个节点互换数据
        int data = cur->data;
        cur->data = cur->next->data;
        cur->next->data = data;

        //将第二个节点指向第一个节点，然后删除并返回第二个节点
        LNode *result = cur->next;//返回第二个节点
        //第一个节点指向第三个节点
        cur->next = result->next;
        //第二个节点指向第一个节点
        result->next = cur;



        return result;
    }

    LNode *pre = linkList;
    for (int i = 1; i < index; ++i) {
        pre = pre->next;
    }//走到要删除的节点之前的一个节点

    //删除节点
    cur = pre->next;
    if (cur == linkList->next) {//如果要删除的节点是第一个节点
        linkList->next = linkList->next->next;
    }
    pre->next = cur->next;

    return cur;
}

LinkList SinglyLinkedCircularList_Init(int nodeNum) {
    //新建头节点
    LinkList linkList = (LinkList) malloc(sizeof(LNode));   //create head node
    //新建第一个节点
    LNode *newNode = (LNode *) malloc(sizeof(LNode));     //create new node
    newNode->data = 1;
    newNode->next = newNode;
    //接入第一个节点
    linkList->next = newNode;

    for (int i = 2; i <= nodeNum; ++i) {
        //尾部插入节点
        SinglyLinkedCircularList_Append(linkList, i);
    }

    //最后一个节点链接的一个节点
    GetLastElem(linkList)->next = linkList->next;

    return linkList;
}

void SinglyLinkedCircularList_Show(LinkList linkList) {
    if (linkList->next == NULL) {
        printf("NULL\n");
    }

    LNode *cur = linkList->next;
    while (linkList->next != cur->next) {
        printf("%d\t", cur->data);
        cur = cur->next;
    }
    printf("%d\t", cur->data);
    printf("\n");
}

LinkList SinglyLinkedCircularList_Append(LinkList linkList, int data) {
    LNode *lastElement = GetLastElem(linkList);

    LNode *newNode = (LNode *) malloc(sizeof(LNode));     //create new node
    newNode->data = data;

    newNode->next = lastElement->next;
    lastElement->next = newNode;

    return linkList;
}

LinkList SinglyLinkedCircularList_InsertFront(LinkList linkList, int data, int index) {
    //获取对应位置的节点
    LNode *node = GetElem(linkList, index);
    //新建节点
    LNode *newNode = (LNode *) malloc(sizeof(LNode));     //create new node
    newNode->data = data;

    //插入
    newNode->next = node->next;
    node->next = newNode;

    //交换数据
    int tmp = node->data;
    node->data = newNode->data;
    newNode->data = tmp;

    return linkList;
}

LinkList List_HeadInsert() {
    LNode *s;
    int x;
    LinkList L = (LinkList) malloc(sizeof(LNode));   //create head node
    L->next = NULL;                           //init empty linked list
    scanf("%d", &x);
    while (x > -100 && x < 100) {
        s = (LNode *) malloc(sizeof(LNode));     //create new node
        //头插
        s->data = x;
        s->next = L->next;
        L->next = s;
        //下一个数字
        scanf("%d", &x);
    }

    return L;
}
