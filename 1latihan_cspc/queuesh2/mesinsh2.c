#include "headsh2.h"

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

void add(int waktu, char nama[], queue *Q){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    baru->kontainer.waktu = waktu;
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

void checking(int time, queue Q)
{
    elemen* ptr = Q.first;

    int stop = 0;
    int total_waktu = 0;
    while (ptr != NULL && stop == 0)
    {
        total_waktu = total_waktu + ptr->kontainer.waktu;
        if (total_waktu >= time)
        {
            stop = 1;
            if (ptr->next == NULL)
            {
                printf("end\n");
            }
            else
            {
                ptr = ptr->next;
                while (ptr != NULL)
                {
                    printf("%s\n", ptr->kontainer.nama);
                    ptr = ptr->next;
                }
            }
            
        }
        else
        {
            ptr = ptr->next;
        }
        
    }

    if (stop == 0)
    {
        printf("end\n");
    }
    
}

