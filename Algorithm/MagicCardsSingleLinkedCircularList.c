//
// Created by temTeng on 2021/7/7.
//

#include <stdio.h>
#include "MagicCardsSingleLinkedCircularList.h"
#include "../DataStructure/LinkList.h"

void MagicCardsSingleLinkedCircularList() {
    LinkList cards = SinglyLinkedCircularList_Init(13);
    SinglyLinkedCircularList_Show(cards);

    int magicCardsOrder[13];

    //第一步
    LNode *cur = cards->next;//第一个节点
    magicCardsOrder[cur->data - 1] = 1; //第一张牌放在第一个位置
    SinglyLinkedCircularList_Delete(cards, 1);  //删除第一个节点

    cur = cards;    //cur走两步到第二个节点
    LNode *pre = NULL;
    for (int i = 2; i <= 13; ++i) {
        for (int j = 0; j < i; ++j) {//i等于几就走几步
            pre = cur;
            cur = cur->next;        //走一步
        }
        magicCardsOrder[cur->data - 1] = i;
        //删除cur节点
        pre->next = cur->next;
    }

    for (int i = 0; i < 13; ++i) {
        printf("%d\t", magicCardsOrder[i]);
    }
    printf("\n");

}

