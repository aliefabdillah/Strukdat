#include "headmainflot.h"

void create(list *L){
    (*L).first = NULL;      
}

void add_first(float bil, list *L){
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
            printf("%0.2f\n",choose->kontainer.bil);

            choose = choose->next;
                   
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
    
}

void sort(float sel[], float inp[], int n){
    float temp_sel;
    float tem_inp;

    int i,j;
    for ( i = 0; i < n; i++)
    {
        int max = i;
        for ( j = i+1; j < n; j++)
        {
             if (sel[max] < sel[j])
            {
                max = j;
            }
        }
        temp_sel = sel[i];
        sel[i] = sel[max];
        sel[max] = temp_sel;

        tem_inp = inp[i];
        inp[i] = inp[max];
        inp[max] = tem_inp;
    }
    
}