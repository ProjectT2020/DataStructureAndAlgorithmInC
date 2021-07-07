#include <stdio.h>

void MagicCards(){
    int cards[13] = {0};
    for (int i = 0; i < 13; ++i) {
        printf("%d\t", i + 1);
    }
    printf("\n");
    for (int i = 0; i < 13; ++i) {
        printf("%d\t", cards[i]);
    }
    printf("\n");

    int cur = 0;
    for (int i = 0; i < 13; ++i) {

        //往后数i次，忽略已经有的位置
        //第二次循环：i=1,
        for (int count = 0; count < i; ++count) {
            //往下走一步
            cur = (cur + 1) % 13;
            while (cards[cur] != 0) {
                cur = (cur + 1) % 13;
            }
            //遇到0则继续走
        }

        //定牌
        cards[cur] = i + 1; //确定牌(i+1)的位置
        //往下走一步
        cur = (cur + 1) % 13;
        //如果i==12，则死循环, 需要特别处理一下
        while (cards[cur] != 0 && i != 12) {
            cur = (cur + 1) % 13;
        }
    }

    for (int i = 0; i < 13; ++i) {
        printf("%d\t", cards[i]);
    }
    printf("\n");
}
