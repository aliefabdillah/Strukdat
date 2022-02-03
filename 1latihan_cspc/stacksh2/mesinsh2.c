#include "headsh2.h"

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


void push(float number, stack *S){
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

void checking(stack S1, stack S2){

    if (count_elemen(S1) == count_elemen(S2))
    {
        elemen* tunjuk_S1 = (S1).top;
        elemen* tunjuk_S2 = (S2).top;
        int stop = 0;
        while ((tunjuk_S1 != NULL) && (tunjuk_S2 != NULL) && (stop == 0))
        {
            if (tunjuk_S1->kontainer.number != tunjuk_S2->kontainer.number)
            {
                stop = 1;
            }
            tunjuk_S1 = tunjuk_S1->next;
            tunjuk_S2 = tunjuk_S2->next;
        }
        
        if (stop == 0)
        {
            print_stack(S1);
        }
        else
        {
            print_stack(S1);
            print_stack(S2);
        }
    }
    else
    {
        print_stack(S1);
        print_stack(S2);
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
            printf("%0.2f\n", tunjuk->kontainer.number);
            tunjuk = tunjuk->next;  
        }
    }
    else
    {
        printf("- Stack Kosong\n");
    }
}