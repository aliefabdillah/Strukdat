#include "headlistawal.h"

void create_list(list *L){
    (*L).first = NULL;      //NULL artinya pointer first mengaskses elemen kosong di sebuah memori
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

void add_after_baris(elemen_baris *prev, int angka_baris){
    elemen_baris* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_baris*) malloc (sizeof (elemen_baris));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    baru->kontainer.angka_baris = angka_baris;
    baru->col = NULL;

    if (prev->next == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;   
}

void add_last_baris(int angka_baris, list *L){
    if ((*L).first == NULL)     //jika list kosong
    {
        add_first_baris(angka_baris, L);
    }
    else
    {
        /* jika list tidak kosong */
        //mencari elemen terakhir pada list;
        elemen_baris* last = (*L).first;
        while (last->next != NULL)
        {
            //iterasi
            last = last->next;
        }
        add_after_baris(last, angka_baris);
    }
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

void checking(int input, list *L){
    int input_row;
    
    if (input >= 10)
    {
        input_row = input/10;
    }
    else
    {
        input_row = input;
    }
    
    if ((*L).first == NULL)
    {
        add_first_baris(input_row, L);
        add_first_kolom(input, (*L).first);
    }
    else
    {
        elemen_baris* tunjuk = (*L).first;
        elemen_baris* prev = NULL;
        int stop = 0;
        while (tunjuk != NULL && stop == 0)
        {
            if (input_row == tunjuk->kontainer.angka_baris)
            {
                stop = 1;
            }
            else
            {
                prev = tunjuk;
                tunjuk = tunjuk->next;
            }
        }
        
        if (stop == 1)
        {
            if (tunjuk->col == NULL)
            {
                add_first_kolom(input, tunjuk);
            }
            else
            {
                add_last_kolom(input, tunjuk);
            }
        }
        else
        {
            add_last_baris(input_row, L);
            add_first_kolom(input, prev->next);
        }
    }
}