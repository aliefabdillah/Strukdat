#include "headliststr.h"

void create(list *L){
    (*L).first = NULL;      
}

void add_first(char kata[], list *L){
    elemen* new;                               
    new = (elemen*) malloc (sizeof (elemen));    
    strcpy(new->kontainer.kata, kata);

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
            printf("%s\n",choose->kontainer.kata);

            choose = choose->next;
                   
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
    
}