/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TP2           |
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
    int productCode;
}PCParts;   // isi list

typedef struct elmt *alamatElmt;
typedef struct elmt
{
    PCParts container;
    alamatElmt prev;
    alamatElmt next;
}element;

typedef struct
{
    element *first;
    element *tail;
}list;

// prosedur dan fungsi yang dipakai
void createList(list *L);   // membuat list
int countElement(list L);   // menghitung banyak element
// memasukan data kedalam element
void addFirst(char name[], int price, int productCode, list *L);
void addAfter(element* before, char name[], int price, int productCode, list *L);
// hapus element
void delFirst(list *L);
void delAfter(element* before, list *L);
void delAll(list *L);
void delLast(list *L);
// check produk orisinil
void checkingProduct(list *L);
// soritng
void bubbleSort(list *L, char sortMode[], int arr[], int count, char sortBy);
// swap pointer
void swapPtr(list *L, int valueA, int valueB, char sortBy);
// output
void printElement(list L);