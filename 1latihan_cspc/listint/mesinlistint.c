#include "headlistint.h"

void create(list *L){
    (*L).first = NULL;      
}

void add_first(int bil, list *L){
    elemen* new;                               
    new = (elemen*) malloc (sizeof (elemen));    
    new->kontainer.bil = bil;

    if ((*L).first == NULL)
    {
        new->next = NULL;
    }
    else
    {
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

void print_element(list L)
{
    if (L.first != NULL)    //jika list tidak kosong
    {
        //inisialisasi
        elemen* choose = L.first;
        
        while (choose != NULL)      //perulangan selemen pointer choose tidak bernilai null
        {
            printf("%d\n",choose->kontainer.bil);

            choose = choose->next;
                   
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
    
}