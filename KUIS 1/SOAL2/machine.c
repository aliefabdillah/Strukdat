/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan Kuis (gasta21)|
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createList(list *L, int count){
    (*L).first = -1;
    (*L).tail = -1;
    int i;
    for ( i = 0; i < count; i++)
    {
        (*L).data[i].next = -2;
        (*L).data[i].prev = -2;
    }
}

int countElement(list L){
    int result = 0;
    if (L.first != -1)
    {
        int ptr = L.first;
        while (ptr != -1)
        {
            result++;
            ptr = L.data[ptr].next;
        }
    }
    return result;
}

int emptyElement(list L, int count){
    int result = 0;
    if (countElement(L) < count)
    {
        int i = 0, found = 0;
        while (found == 0 && i < count)
        {
            if (L.data[i].next == -2)
            {
                result = i;
                found = 1;
            }else
            {
                i++;
            }
        }
    }
    return result;
}

void addFirst(char str[], list *L, int count){
    if (countElement(*L) < count)
    {
        int new = emptyElement(*L, count);
        strcpy((*L).data[new].container.str, str);

        if ((*L).first == -1)
        {
            (*L).data[new].prev = -1;
            (*L).data[new].next = -1;
            (*L).tail = new;
        }else
        {
            (*L).data[new].next = (*L).first;
            (*L).data[new].prev = -1;
            (*L).data[(*L).first].prev = new;
        }
        (*L).first = new;
    }else
    {
        printf("list penuh\n");
    }
}

void addAfter(int before, char str[], list *L, int count){
    if (countElement(*L) < count)
    {
        int new = emptyElement(*L, count);
        strcpy((*L).data[new].container.str, str);

        if ((*L).data[before].next != -1)
        {
            (*L).data[new].prev = before;
            (*L).data[new].next = (*L).data[before].next;
            (*L).data[before].next = new;
            (*L).data[(*L).data[new].next].prev = new;
        }else
        {
            (*L).data[new].prev = before;
            (*L).data[before].next = new;
            (*L).data[new].next = -1;
            (*L).tail = new;
        }
    }else
    {
        printf("list penuh\n");
    }
}

void printElement(list L, int count){
    if (L.first != -1)
    {
        int ptr = L.first;
        int totalLen = 0;
        while (ptr != -1)
        {
            totalLen += strlen(L.data[ptr].container.str);
            ptr = L.data[ptr].next;
        }
        int ptrFront = L.first;
        int ptrBack = L.tail;
        int space = 0, i = 0;
        int temp = count;
        count /= 2;
        int j;
        while (i < count)
        {
            totalLen -= (strlen(L.data[ptrBack].container.str) + strlen(L.data[ptrFront].container.str));
            for ( j = 0; j < space; j++)
            {
                printf(" ");
            }
            printf("%s", L.data[ptrBack].container.str);
            space += strlen(L.data[ptrBack].container.str);
            for ( j = 0; j < totalLen; j++)
            {
                printf(" ");
            }
            printf("%s\n", L.data[ptrFront].container.str);
            ptrBack = L.data[ptrBack].prev;
            ptrFront = L.data[ptrFront].next;
            i++;
        }
        if (temp % 2 != 0)
        {
            for ( i = 0; i < space; i++)
            {
                printf(" ");
            }
            printf("%s\n", L.data[ptrFront].container.str);
        }
        
    }else
    {
        printf("list kosong\n");
    }
}