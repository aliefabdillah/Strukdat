/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM1           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

// tipe data terstruktur yang dipakai
typedef struct
{
    char name[100];
    int price;
    float rating;
}menu;

typedef struct elmt* alamatelmt;
typedef struct elmt
{
    menu container;
    alamatelmt next;
}element;

typedef struct
{
    element* first;
}list;

// prosedur dan fungsi yang dipakai
void createList(list *L);   // membuat list
int countElement(list L);   // menghitung element
// prosedur menambahkan element
void addFirst(char name[], int price, float rating, list *L);
void addAfter(element* prev, char name[], int price, float rating, list *L);
void addLast(char name[], int price, float rating, list *L);
// prosedur menghapus element
void delFirst(list *L);
void delAfter(element* prev, list *L);
void delLast(list *L);
void delAll(list *L);
// mengeluarkan output list
void printElement(int money, list L);
// sorting list
void sortingList(char mode[], list *L, float arr[], int count);
void swapPointer(float rating1, float rating2, list *L);