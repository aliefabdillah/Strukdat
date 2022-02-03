#include "headsimsta.h"

void create_empty(stack *S){
    (*S).top = NULL;
}

int count_elemen(stack S){
    int hasil = 0;

    if (S.top != NULL)
    {
        /* List tidak kosong */
        elemen* tunjuk;

        //inisialiasi
        tunjuk = S.top;

        while (tunjuk != NULL)
        {
            hasil = hasil + 1;

            //iterasi
            tunjuk = tunjuk->next;
        }   
    }
    return hasil;
}


void push(int number, stack *S){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    baru->kontainer.number = number;

    if ((*S).top == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S)
{
    
    if ((*S).top != NULL)     //jika list tidak kosong
    {
        elemen* hapus = (*S).top;     //pointer hapus menunjuk elemen pertama dari list
        if (count_elemen(*S) == 1)      //jika cuma 1 elemen saja
        {
            (*S).top = NULL;
        }
        else{

            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);        //prosedur melepaskan elemen dari memori yang ditunjuk pointer hapus
    }
    else
    {
        printf("stack kosong\n");
    }
}

void pop_cari(int nilai, stack *S)
{
    
    if ((*S).top != NULL)     //jika list tidak kosong
    {
        elemen* pointer = (*S).top;     //pointer hapus menunjuk elemen pertama dari list
        int stop = 0;
        while (pointer != NULL && stop == 0)
        {
            if (nilai == pointer->kontainer.number)
            {
                stop = 1;
            }
            pop(S);
            pointer = pointer->next;
        }
    }
}

void pop_banyak(int nilai, stack *S)
{
    
    if ((*S).top != NULL)     //jika list tidak kosong
    {
        for (int i = 0; i < nilai; i++)
        {
            pop(S);
        }
    }
}

void print_stack(stack S)
{
    if (S.top != NULL)    //jika list tidak kosong
    {
        
        //inisialisasi
        elemen* tunjuk = S.top;
        
        while (tunjuk != NULL)      //perulangan selemen pointer tunjuk tidak bernilai null
        {
            printf("%d\n", tunjuk->kontainer.number);
            tunjuk = tunjuk->next;
            
        }
        printf("-1\n");
    }
    else
    {
        printf("- Stack Kosong\n");
    }
}