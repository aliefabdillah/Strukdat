#include "headlistgg.h"

void create_list(list *L){
    (*L).first = NULL;      //NULL artinya pointer first mengaskses elemen kosong di sebuah memori
}

int count_elemen_baris(list L){
    int hasil = 0;

    if (L.first != NULL)
    {
        /* List tidak kosong */
        elemen_baris* pointer;

        //inisialiasi
        pointer = L.first;

        while (pointer != NULL)
        {
            hasil = hasil + 1;

            pointer = pointer->next;
        }   
    }
    return hasil;
}

int count_elemen_kolom(elemen_baris L){
    int hasil = 0;

    if (L.col != NULL)
    {
        /* List tidak kosong */
        elemen_kolom* pointer;

        //inisialiasi
        pointer = L.col;

        while (pointer != NULL)
        {
            hasil = hasil + 1;

            pointer = pointer->next_kol;
        }   
    }
    return hasil;
}

void add_first_baris(int angka_baris, list *L){
    elemen_baris* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_baris*) malloc (sizeof (elemen_baris));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    baru->kontainer.angka_baris = angka_baris;
    baru->col = NULL;

    if ((*L).first == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

void add_first_kolom(int angka_kolom, elemen_baris *L){
    elemen_kolom* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_kolom*) malloc (sizeof (elemen_kolom));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    baru->kontainer_kol.angka_kolom = angka_kolom;

    if ((*L).col == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = (*L).col;
    }
    (*L).col = baru;
    baru = NULL;
}

void add_after_kolom(elemen_kolom *prev, int angka_kolom){
    elemen_kolom* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_kolom*) malloc (sizeof (elemen_kolom));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    baru->kontainer_kol.angka_kolom = angka_kolom;

    if (prev->next_kol == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = prev->next_kol;
    }
    prev->next_kol = baru;
    baru = NULL; 
}

void add_last_kolom(int angka_kolom, elemen_baris *L){
    if ((*L).col == NULL)     //jika list kosong
    {
        add_first_kolom(angka_kolom, L);
    }
    else
    {
        /* jika list kolom tidak kosong */
        //mencari elemen terakhir pada list;
        elemen_kolom* last = (*L).col;
        while (last->next_kol != NULL)
        {
            //iterasi
            last = last->next_kol;
        }
        add_after_kolom(last, angka_kolom);
    }
}

void print_elemen(list L){

    if (L.first != NULL)    //jika list tidak kosong
    {
        //inisialisasi
        elemen_baris* tunjuk = L.first;
        
        while (tunjuk != NULL)      //perulangan selemen pointer tunjuk tidak bernilai null
        {
            printf("%d\n", tunjuk->kontainer.angka_baris);
    
            if (tunjuk->col != NULL)
            {
                elemen_kolom* tunjuk_kol = tunjuk->col;
                while (tunjuk_kol != NULL)
                {
                    printf("-%d\n", tunjuk_kol->kontainer_kol.angka_kolom);

                    //iterasi kolom
                    tunjuk_kol = tunjuk_kol->next_kol;
                }
                
            }
            else
            {
                printf("Kolom Kosong\n");
            }
            
            /* iterasi baris */
            tunjuk = tunjuk->next;      
        }
    }
    else
    {
        printf("List Kosong\n");
    }
}