/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan Kuis (cksg21) |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createList(list *L){
    (*L).first = NULL;
}

int countElement(list L){
    int result = 0;
    if (L.first != NULL)
    {   // jika list tidak kosong
        element* ptr;
        ptr = L.first;
        while (ptr != NULL)
        {
            result++;
            ptr = ptr->next;
        }
    }
    return result;
}

void addFirst(char name[], int price, list *L){
    element* new = (element*) malloc (sizeof (element));
    strcpy(new->container.name, name);
    new->container.price = price;

    if ((*L).first == NULL)
    {
        new->next = NULL;
    }else
    {
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

void addAfter(element* prev, char name[], int price, list *L){
    element* new = (element*) malloc (sizeof (element));
    strcpy(new->container.name, name);
    new->container.price = price;

    if (prev->next == NULL)
    {
        new->next = NULL;
    }else
    {
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;
}

void addLast(char name[], int price, list *L){
    if ((*L).first == NULL)
    {
        addFirst(name, price, L);
    }else
    {
        element* prev = (*L).first;
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        addAfter(prev, name, price, L);
    }
}

void delFirst(list *L){
    if ((*L).first != NULL)
    {
        element* delete = (*L).first;
        if (countElement(*L) == 1)
        {
            (*L).first = NULL;
        }else
        {
            (*L).first = (*L).first->next;
            delete->next = NULL;
        }
        free(delete);
    }
}

void delAfter(element* prev, list *L){
    element* delete = prev->next;
    if (delete != NULL)
    {
        if (delete->next == NULL)
        {
            prev->next = NULL;
        }else
        {
            prev->next = delete->next;
            delete->next = NULL;
        }
        free(delete);
    }
}

void delLast(list *L){
    if ((*L).first != NULL)
    {
        if (countElement(*L) == 1)
        {
            delFirst(L);
        }else
        {
            element* last = (*L).first;
            element* prev;
            while (last->next != NULL)
            {
                prev = last;
                last = last->next;
            }
            delAfter(prev, L);
        }
    }
}

void delAll(list *L){
    if (countElement(*L) != 0)
    {
        for (int i = countElement(*L); i > 0; i--)
        {
            delLast(L);
        }
    }
}

void printElement(list L){
    if (L.first != NULL)
    {
        element* ptr = L.first;
        while (ptr != NULL)
        {
            printf("%s %d\n", ptr->container.name, ptr->container.price);
            ptr = ptr->next;
        }
    }else
    {
        printf("list kosong\n");
    }
}

void swapMenu(list *L, list *R, char targetA[], char targetB[]){
    element *ptrA = (*L).first;
    element *prevA = NULL;
    while (ptrA != NULL)
    {
        if (strcmp(ptrA->container.name, targetA) == 0)
        {
            addLast(ptrA->container.name, ptrA->container.price, R);
            if (prevA == NULL)
            {
                delFirst(L);
            }else
            {
                delAfter(prevA, L);
            }
        }
        if (strcmp(ptrA->container.name, targetB) == 0)
        {
            addLast(ptrA->container.name, ptrA->container.price, R);
            if (prevA == NULL)
            {
                delFirst(L);
            }else
            {
                delAfter(prevA, L);
            }
        }
        prevA = ptrA;
        ptrA = ptrA->next;
    }

    element *ptrB = (*R).first;
    element *prevB = NULL;
    while (ptrB != NULL)
    {
        if (strcmp(ptrB->container.name, targetA) == 0)
        {
            addLast(ptrB->container.name, ptrB->container.price, L);
            if (prevB == NULL)
            {
                delFirst(R);
            }else
            {
                delAfter(prevB, R);
            }
        }
        if (strcmp(ptrB->container.name, targetB) == 0)
        {
            addLast(ptrB->container.name, ptrB->container.price, L);
            if (prevB == NULL)
            {
                delFirst(R);
            }else
            {
                delAfter(prevB, R);
            }
        }
        prevB = ptrB;
        ptrB = ptrB->next;
    }
}