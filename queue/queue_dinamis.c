#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char nim[10];
    char nama[50];
    float nilai;
}nilai_matkul;

typedef struct elmt* alamat_elemen;     
typedef struct elmt
{
    nilai_matkul kontainer;
    alamat_elemen next;
}elemen;

typedef struct 
{
    elemen* first;
    elemen* last;
}queue;

void create_empty(queue *Q){
    (*Q).first = NULL;
    (*Q).last = NULL;
}

/* Bisa dihilangin karena udah di wakilin sama fungsi count elemen */
int is_empty(queue Q){
    int hasil = 0;
    if (Q.first == NULL)
    {
        hasil = 1;
    }
    return hasil;
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

void add(char nim[], char nama[], float nilai, queue *Q){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
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

void prioriy_add(char nim[], char nama[], float nilai, int priority, queue *Q){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.nilai = nilai;

    if ((*Q).first == NULL)
    {
        add(nim, nama, nilai, Q);
    }
    else
    {
        if (priority > count_elemen(*Q))
        {
            add(nim, nama, nilai, Q);
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

void print_queue(queue Q){
    if (Q.first != NULL)
    {
        printf("------- ISI Queue ------\n");

        elemen* pointer = Q.first;
        int i = 0;

        while (pointer != NULL)
        {
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", pointer->kontainer.nim);
            printf("nama : %s\n", pointer->kontainer.nama);
            printf("nilai : %0.2f\n", pointer->kontainer.nilai);
            printf("------------------------\n");

            pointer = pointer->next;
            i++;
        }
    }
    else
    {
        //jika queue kosong
        printf("queue kosong\n");
    }
}

int main(){
    queue Q;
    create_empty(&Q);
    print_queue(Q);

    printf("===============\n");
    add("2003623", "Nana", 64.75, &Q);
    add("2003321", "Rudi", 75.11, &Q);
    add("2003123", "Dea", 84.63, &Q);
    print_queue(Q);

    printf("===============\n");
    out(&Q);
    out(&Q);
    print_queue(Q);

    printf("===============\n");
    return 0;
}