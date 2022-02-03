/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis Cksg21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

/* Bagian Mesin */
#include "headuts.h"

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

void add_first_baris(char nama_res[], list *L){
    elemen_baris* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_baris*) malloc (sizeof (elemen_baris));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nama_res, nama_res);
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

void add_first_kolom(char menu[], char harga[], elemen_baris *L){
    elemen_kolom* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_kolom*) malloc (sizeof (elemen_kolom));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer_kol.menu, menu);
    strcpy(baru->kontainer_kol.harga, harga);

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

void add_after_baris(elemen_baris *prev, char nama_res[]){
    elemen_baris* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_baris*) malloc (sizeof (elemen_baris));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nama_res, nama_res);
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

void add_after_kolom(elemen_kolom *prev, char menu[], char harga[]){
    elemen_kolom* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_kolom*) malloc (sizeof (elemen_kolom));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer_kol.menu, menu);
    strcpy(baru->kontainer_kol.harga, harga);

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

void add_last_baris(char nama_res[], list *L){
    if ((*L).first == NULL)     //jika list kosong
    {
        add_first_baris(nama_res, L);
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
        add_after_baris(last, nama_res);
    }
}

void add_last_kolom(char menu[], char harga[], elemen_baris *L){
    if ((*L).col == NULL)     //jika list kosong
    {
        add_first_kolom(menu, harga, L);
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
        add_after_kolom(last, menu, harga);
    }
}

//fungsi untuk mengetahui posisi elemen di baris kebererapa saaat mengisi kolom
elemen_baris* isi_kolom(char nama_res[], list L){
    elemen_baris* now = 0;
    if (L.first != NULL)
    {
        now = L.first;      //inisialisation
        while (now != NULL && strcmp(now->kontainer.nama_res, nama_res) != 0)
        {
            now = now->next;
        }
        return now;     //return the value of now
    }
}

//tukar elemen
void swap(char res1[], char res2[], char menu_switch[], list *L){
    elemen_baris* now_row1 = (*L).first;
    int stop = 0;
    
    //mencari restoran 1
    while (now_row1 != NULL && stop == 0)
    {
        if (strcmp(res1, now_row1->kontainer.nama_res) == 0)
        {
            stop = 1;
        }
        else
        {
            now_row1 = now_row1->next;
        }
    }

    elemen_kolom* swap_col = now_row1->col;
    elemen_kolom* prev = NULL;
    //elemen_kolom* after = now_row1->col->next_kol;
    stop = 0;
    //mencari posisi menu di restoran 1
    while (swap_col != NULL && stop == 0)
    {
        if (strcmp(menu_switch, swap_col->kontainer_kol.menu) == 0)
        {
            stop = 1;
        }
        else
        {
            prev = swap_col;
            swap_col = swap_col->next_kol;
            //after = swap_col->next_kol;
        }
    }

    //mencari posisi restoran 2 di baris list
    elemen_baris* now_row2 = (*L).first;
    stop = 0;
    while (now_row2 != NULL && stop == 0)
    {
        if (strcmp(res2, now_row2->kontainer.nama_res) == 0)
        {
            stop = 1;
        }
        else
        {
            now_row2 = now_row2->next;
        }

    }
    
    //mencari posisi elemen akhir kolom pada elemen baris ke 2
    elemen_kolom* last_target2 = now_row2->col;
    while (last_target2->next_kol != NULL)
    {
        last_target2 = last_target2->next_kol;
    }
    
    //jika elemen pertama
    if (prev == NULL)
    {
        last_target2->next_kol = now_row1->col;
        now_row1->col = swap_col->next_kol;
    }
    //jika buka elemen pertama
    else
    {

        prev->next_kol = swap_col->next_kol;
        last_target2->next_kol = swap_col;
        
    }
    swap_col->next_kol = NULL;
    //pointer akhir di elemen kolom restoran 2 menunjuk ke nama menu yang ditukar
    
}

void print_elemen(list L)
{
    if (L.first != NULL)    //if list not null
    {
        //inisialisasi
        elemen_baris* tunjuk = L.first;
        
        while (tunjuk != NULL)      //perulangan selemen pointer tunjuk tidak bernilai null
        {
            printf("%s:\n",tunjuk->kontainer.nama_res);

            elemen_kolom* tunjuk_col = tunjuk->col;                             //pointer tunjuk for coloumn
            while (tunjuk_col != NULL)
            {
                printf("- %s ",tunjuk_col->kontainer_kol.menu);
                printf("%s\n",tunjuk_col->kontainer_kol.harga);
                
                //iterasi kolom
                tunjuk_col = tunjuk_col->next_kol;
            }
            if (tunjuk->next != NULL)
            {
                printf("\n");
            }
            
            /* iterasi baris */
            tunjuk = tunjuk->next;   
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
    
}

