/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan Kuis (cksg21) |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct
{
    char name[50];
    int price;
}menu;

typedef struct elmt* elmtAddress;
typedef struct elmt
{
    menu container;
    elmtAddress next;
}element;

typedef struct
{
    element* first;
}list;

void createList(list *L);
int countElement(list L);
void addFirst(char name[], int price, list *L);
void addAfter(element* prev, char name[], int price, list *L);
void addLast(char name[], int price, list *L);
void delAfter(element* prev, list *L);
void printElement(list L);
void swapMenu(list *L, list *R, char targetA[], char targetB[]);