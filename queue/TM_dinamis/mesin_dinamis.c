#include "head_dinamis.h"

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

void add(char nama[], char nim[], queue *Q){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
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

void prioriy_add(char nama[], char nim[], int priority, queue *Q){
    elemen* baru;                               
    baru = (elemen*) malloc (sizeof (elemen));    
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);

    if ((*Q).first == NULL)
    {
        add(nama, nim, Q);
    }
    else
    {
        if (priority > count_elemen(*Q))
        {
            add(nama, nim, Q);
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
            printf("%s ", pointer->kontainer.nama);
            printf("%s\n", pointer->kontainer.nim);

            pointer = pointer->next;
        }
    }
    else
    {
        //jika queue kosong
        printf("queue kosong\n");
    }
}