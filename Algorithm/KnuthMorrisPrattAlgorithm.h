//
// Created by temTeng on 2021/7/8.
//

#ifndef DATASTRUCTUREANDALGORITHM_KNUTHMORRISPRATTALGORITHM_H
#define DATASTRUCTUREANDALGORITHM_KNUTHMORRISPRATTALGORITHM_H

int *KMP_Next;

typedef struct {
    int *matchIndices;
    int nMatches;
} MatchesStruct, *Matches;

typedef struct {
    int *data;
    unsigned int length;
}IntegerArrayStruct, *IntegerArray;

IntegerArray prefixTable(char *pattern);

Matches KnuthMorrisPratt_Search(char *text, char *pattern);

int *getPartialMatchTable(char *pattern);
int showPartialMatchTable(char *pattern);


#endif //DATASTRUCTUREANDALGORITHM_KNUTHMORRISPRATTALGORITHM_H
