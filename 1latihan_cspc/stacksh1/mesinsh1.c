#include "headsh1.h"

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

void push_selang_seling(stack *S1, stack *S2)
{
    stack S_all;
    create_empty(&S_all);

    elemen* tunjuk_S1 = (*S1).top;
    elemen* tunjuk_S2 = (*S2).top;

    while ((tunjuk_S1 != NULL) && (tunjuk_S2 != NULL))
    {
        push(tunjuk_S1->kontainer.number, &S_all);
        push(tunjuk_S2->kontainer.number, &S_all);

        tunjuk_S1 = tunjuk_S1->next;
        tunjuk_S2 = tunjuk_S2->next;
    }
    
    if (tunjuk_S1 != NULL)
    {
        while (tunjuk_S1 != NULL)
        {
            push(tunjuk_S1->kontainer.number, &S_all);
            tunjuk_S1 = tunjuk_S1->next;
        }   
    }
    if (tunjuk_S2 != NULL)
    {
        while (tunjuk_S2 != NULL)
        {
            push(tunjuk_S2->kontainer.number, &S_all);
            tunjuk_S2 = tunjuk_S2->next;
        }   
    }

    print_stack(S_all);
    
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