#include "headsimque.h"

void create_empty(queue *Q){
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int count_elemen(queue Q){
    int hasil = 0;

    if (Q.first != NULL)
    {
        /* queue tidak kosong */
        elemen* tunjuk;

        //inisialiasi
        tunjuk = Q.first;

        while (tunjuk != NULL)
        {
            hasil = hasil + 1;

            //iterasi
            tunjuk = tunjuk->next;
        }   
    }
    return hasil;
}

void add(int nilai, queue *Q){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    baru->kontainer.nilai = nilai;
    baru->next = NULL;

    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
    }
    else
    {
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

void out(queue *Q)
{
    
    if ((*Q).first != NULL)     //jika queue tidak kosong
    {
        elemen* hapus = (*Q).first;     //pointer hapus menunjuk elemen pertama dari queue
        if (count_elemen(*Q) == 1)      //jika cuma 1 elemen saja
        {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else{

            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }
        free(hapus);        //prosedur melepaskan elemen dari memori yang ditunjuk pointer hapus
    }
    else
    {
        printf("queue kosong\n");
    }
}

void prioriy_add(int nilai, int priority, queue *Q){
    elemen* baru;                               
    baru = (elemen*) malloc (sizeof (elemen));    
    baru->kontainer.nilai = nilai;

    if ((*Q).first == NULL)
    {
        add(nilai, Q);
    }
    else
    {
        if (priority > count_elemen(*Q))
        {
            add(nilai, Q);
        }
        else
        {
            if (priority == 1)
            {
                baru->next = (*Q).first;
                (*Q).first = baru;
                baru = NULL;
            }
            else
            {
                elemen* ptr = (*Q).first;
                for (int i = 1; i < priority-1; i++)
                {
                    ptr = ptr->next;
                }

                baru->next = ptr->next;
                ptr->next = baru;
                baru = NULL;
            }
        }
        
    }
}

void print_queue(queue Q)
{
    if (Q.first != NULL)
    {

        elemen* pointer = Q.first;

        while (pointer != NULL)
        {
            printf("%d\n", pointer->kontainer.nilai);

            pointer = pointer->next;
        }
        printf("-1\n");
    }
    else
    {
        //jika queue kosong
        printf("queue kosong\n");
    }
}