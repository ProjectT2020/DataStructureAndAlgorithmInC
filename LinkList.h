//
// Created by temTeng on 2021/7/7.
//

#ifndef DATASTRUCTUREANDALGORITHM_LINKLIST_H
#define DATASTRUCTUREANDALGORITHM_LINKLIST_H


typedef struct LNode LNode, *LinkList;
struct LNode {
    int data;
    struct LNode *next;
};

void List_Show(LinkList linkList);

LNode *LocateElement(LinkList linkList, int element);

LNode *GetElem(LinkList linkList, int index);

LNode *GetLastElem(LinkList linkList);

LinkList SinglyLinkedCircularList_Init(int nodeNum);

LNode *SinglyLinkedCircularList_Delete(LinkList linkList, int index);

LinkList SinglyLinkedCircularList_InsertFront(LinkList linkList, int data, int index);

LinkList SinglyLinkedCircularList_Append(LinkList linkList, int data);

void SinglyLinkedCircularList_Show(LinkList linkList);

LinkList List_HeadInsert();

LinkList List_TailInsert();

//LinkList List_TailInsert(LinkList linkList, int data);
void List_Destroy(LinkList linkList);


#endif //DATASTRUCTUREANDALGORITHM_LINKLIST_H
