#include "head_sep.h"

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

void add(char nama[], int prioritas, char kota[], int biaya, queue *Q){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.prioritas = prioritas;
    strcpy(baru->kontainer.kota, kota);
    baru->kontainer.biaya = biaya;

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

//prosedur prioritas antrian
void prioriy_add(char nama[], int prioritas, char kota[], int biaya, queue *Q){
    elemen* baru;                               
    baru = (elemen*) malloc (sizeof (elemen));   

    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.prioritas = prioritas;
    strcpy(baru->kontainer.kota, kota);
    baru->kontainer.biaya = biaya;

    //jika elemen pada queue kosong
    if ((*Q).first == NULL)
    {
        add(nama, prioritas, kota, biaya, Q);
    }
    else
    {   
        //jika angka prioritas baru lebih besar dari jumlah elemen saat ini
        //masukan elemen baru di data terakhir
        if (prioritas > count_elemen(*Q))
        {
            add(nama, prioritas, kota, biaya, Q);
        }
        else
        {
            //jika prioritas = 1. maka masukan di awal
            if (prioritas == 1)
            {
                baru->next = (*Q).first;
                (*Q).first = baru;
                baru = NULL;
            }
            else
            {
                elemen* ptr = (*Q).first;
                //perulangan mencari posisi prioritasi di tengah
                for (int i = 1; i < prioritas-1; i++)
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

void print_queue(int jumlah_keluar, queue Q)
{
    if (Q.first != NULL)
    {

        elemen* pointer = Q.first;

        int i = 0;
        printf("Bantuan Tersalurkan:\n");
        while (i < jumlah_keluar)
        {
            printf("%s ", pointer->kontainer.nama);
            printf("%d ", pointer->kontainer.prioritas);
            printf("%s ", pointer->kontainer.kota);
            printf("%d\n", pointer->kontainer.biaya);

            pointer = pointer->next;
            i++;
        }
        
        printf("\nAntrian berisi:\n");
        while (pointer != NULL)
        {
            printf("%s ", pointer->kontainer.nama);
            printf("%d ", pointer->kontainer.prioritas);
            printf("%s ", pointer->kontainer.kota);
            printf("%d\n", pointer->kontainer.biaya);

            pointer = pointer->next;
        }
    }
    else
    {
        //jika queue kosong
        printf("queue kosong\n");
    }
}


