/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan Kuis (gasta21)|
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    char str[100];
}content;

typedef struct
{
    content container;
    int prev;
    int next;
}element;

typedef struct
{
    int first;
    int tail;
    element data[100];
}list;

void createList(list *L, int count);
int countElement(list L);
int emptyElement(list L, int count);
void addFirst(char str[], list *L, int count);
void addAfter(int before, char str[], list *L, int count);
void printElement(list L, int count);