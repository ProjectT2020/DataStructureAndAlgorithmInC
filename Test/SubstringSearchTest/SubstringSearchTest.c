//
// Created by temTeng on 2021/7/8.
//

#include <stdio.h>
#include "SubstringSearchTest.h"
#include "../../Algorithm/SubstringSearch/SubstringSearch.h"
#include "../../Algorithm/BruteForceSubstringSearch.h"
#include "../../Algorithm/KnuthMorrisPrattAlgorithm.h"

void SubstringSearchTest() {
    char text[] = "Hello World! Hi every one. My name is Richard. What is your name?";
    char pattern[] = "o";

    int matchIndex = bruteForceSubstringSearch(text, pattern);
    if (-1 != matchIndex) {
        Substring_Show(text, pattern, matchIndex);
    } else {
        printf("找不到pattern\n");
    }

    Matches matches = KnuthMorrisPratt_Search(text, pattern);

    Substring_MultiShow(text, pattern, matches);

}

void partialMatchTableTest() {
    char pattern[] = "ABCDABCXXXX";
    showPartialMatchTable(pattern);
    printf("\n");
    char pattern2[] = "AACDAACXXXX";
    showPartialMatchTable(pattern2);
}
