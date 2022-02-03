#include "headmainstr.h"

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

void cek_a(char inp[][20], int n){

    int total_a[n];
    int i,j;

    for ( i = 0; i < n; i++)
    {
        total_a[i] = 0;
        int size = strlen(inp[i]);
        j = 0;
        while (j<size)
        {
            if (inp[i][j] == 'a')
            {
                total_a[i]++;
            }
            j++;
        }
    }

    //sort

    int temp_tot;
    char temp_inp[20];

    for ( i = 0; i < n; i++)
    {
        int max = i;
        for ( j = i+1; j < n; j++)
        {
            if (total_a[max] < total_a[j])
            {
                max = j;
            }
        }
        temp_tot = total_a[i];
        total_a[i] = total_a[max];
        total_a[max] = temp_tot;

        strcpy(temp_inp, inp[i]);
        strcpy(inp[i], inp[max]);
        strcpy(inp[max], temp_inp);
    }
}

