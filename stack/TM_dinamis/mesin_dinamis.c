#include "head_dinamis.h"

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


void push(char nama[], int harga, stack *S){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.harga = harga;

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
        printf("- Stack Kosong\n");
    }
}

void print_stack(stack S)
{
    if (S.top != NULL)    //jika list tidak kosong
    {
        
        //inisialisasi
        elemen* tunjuk = S.top;
        
        int i = 1;
        while (tunjuk != NULL)      //perulangan selemen pointer tunjuk tidak bernilai null
        {
            printf("%d. %s\n", i, tunjuk->kontainer.nama);
            tunjuk = tunjuk->next;
            i++;      
        }
    }
    else
    {
        printf("- Stack Kosong\n");
    }
}