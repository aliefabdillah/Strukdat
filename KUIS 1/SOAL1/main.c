/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan Kuis (cksg21) |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main(){
    int i, countA, countB;
    list L, R;
    createList(&L);
    createList(&R);

    // input
    scanf("%d", &countA);
    menu arrA[countA];
    for ( i = 0; i < countA; i++)
    {
        scanf("%s %d", &arrA[i].name, &arrA[i].price);
    }
    scanf("%d", &countB);
    menu arrB[countB];
    for ( i = 0; i < countB; i++)
    {
        scanf("%s %d", &arrB[i].name, &arrB[i].price);
    }

    // input data to list
    addFirst(arrA[0].name, arrA[0].price, &L);
    for ( i = countA - 1; i > 0; i--)
    {
        addAfter(L.first, arrA[i].name, arrA[i].price, &L);
    }
    addFirst(arrB[0].name, arrB[0].price, &R);
    for ( i = countB - 1; i > 0; i--)
    {
        addAfter(R.first, arrB[i].name, arrB[i].price, &R);
    }
    
    int countTarget;
    scanf("%d", &countTarget);
    char targetA[countTarget][50], targetB[countTarget][50];
    for ( i = 0; i < countTarget; i++)
    {
        scanf("%s %s", &targetA[i], &targetB[i]);
        swapMenu(&L, &R, targetA[i], targetB[i]);
    }
    
    printf("menu warung pertama:\n");
    printElement(L);
    printf("\nmenu warung kedua:\n");
    printElement(R);
    
    return 0;
}