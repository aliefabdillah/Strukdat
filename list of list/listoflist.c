/* Materi list of List 
    - di dalam list terdapat list
    - biasa digunakan untuk membuat matrix di dalam list dinamis atau dinamis
    - terdapata baris dan kolom
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char nim[10];
    char nama[50];
}mahasiswa;

typedef struct 
{
    char kode[10];
    char nilai[2];
}matkul;

typedef struct e_kolom* alamatkolom;
typedef struct e_kolom
{
    matkul kontainer_kol;
    alamatkolom next_kol;
}elemen_kolom;

typedef struct e_baris* alamatbaris;
typedef struct e_baris
{
    mahasiswa kontainer;
    elemen_kolom *col;      //mirip first pada baris
    alamatbaris next;
}elemen_baris;

typedef struct 
{
    elemen_baris *first;
}list;


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

void add_first_baris(char nim[], char nama[], list *L){
    elemen_baris* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_baris*) malloc (sizeof (elemen_baris));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
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

void add_first_kolom(char kode[], char nilai[], elemen_baris *L){
    elemen_kolom* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_kolom*) malloc (sizeof (elemen_kolom));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer_kol.kode, kode);
    strcpy(baru->kontainer_kol.nilai, nilai);

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

void add_after_baris(elemen_baris *prev, char nim[], char nama[]){
    elemen_baris* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_baris*) malloc (sizeof (elemen_baris));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
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

void add_after_kolom(elemen_kolom *prev, char kode[], char nilai[]){
    elemen_kolom* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_kolom*) malloc (sizeof (elemen_kolom));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer_kol.kode, kode);
    strcpy(baru->kontainer_kol.nilai, nilai);

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

void add_last_baris(char nim[], char nama[], list *L){
    if ((*L).first == NULL)     //jika list kosong
    {
        add_first_baris(nim, nama, L);
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
        add_after_baris(last, nim, nama);
    }
}

void add_last_kolom(char kode[], char nilai[], elemen_baris *L){
    if ((*L).col == NULL)     //jika list kosong
    {
        add_first_kolom(kode, nilai, L);
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
        add_after_kolom(last, kode, nilai);
    }
}

void del_first_kolom(elemen_baris *L)
{
    
    if ((*L).col != NULL)     //jika kolom tidak kosong
    {
        elemen_kolom* hapus = (*L).col;     //pointer hapus menunjuk elemen pertama dari kolom
        if (count_elemen_kolom(*L) == 1)      //jika cuma 1 elemen saja
        {
            (*L).col = NULL;
        }
        else{
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }

        free(hapus);        //prosedur melepaskan elemen dari memori yang ditunjuk pointer hapus
    }
    else
    {
        printf("LIST KOSONG\n");
    }
}

void del_after_kolom(elemen_kolom *prev)
{
    elemen_kolom* hapus = prev->next_kol;
    
    //jika elemen yang ditunjuk setelah prev != NULL / ada elemen yang akan dihapus
    if (hapus != NULL)
    {
        if (hapus->next_kol == NULL)    //jika elemennya di akhir
        {
            prev->next_kol = NULL;
        }
        else                        //jika ditengah
        {       
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void del_last_kolom(elemen_baris *L)
{
    if ((*L).col != NULL)
    {
        if (count_elemen_kolom(*L) == 1)
        {
            del_first_kolom(L);
        }
        
        else
        {
            elemen_kolom *last = (*L).col;
            elemen_kolom *prev_last;

            while (last->next_kol != NULL)
            {
                prev_last = last;
                last = last->next_kol;
            }
        
            del_after_kolom(prev_last);
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
    
}

void del_all_kolom(elemen_baris *L)
{
    if (count_elemen_kolom(*L) != 0)      //jika list tidak kosong
    {
        int i;

        for ( i = count_elemen_kolom(*L); i >= 1; i--)
        {
            del_last_kolom(L);
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
}

void del_first_baris(list *L)
{
    if ((*L).first != NULL)     //jika baris tidak kosong
    {
        elemen_baris* hapus = (*L).first;     //pointer hapus menunjuk elemen pertama dari baris

        //jika kolom tidak kosong maka di hapus semua terlebih dahulu
        if (hapus->col != NULL)
        {
            del_all_kolom(hapus);
        }
        
        if (count_elemen_baris(*L) == 1)      //jika cuma 1 elemen saja
        {
            (*L).first = NULL;
        }
        else{
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }

        free(hapus);        //prosedur melepaskan elemen dari memori yang ditunjuk pointer hapus
    }
    else
    {
        printf("LIST KOSONG\n");
    }
}

void del_after_baris(elemen_baris *prev)
{   
    if (prev != NULL)
    {
        elemen_baris* hapus = prev->next;
        //jika elemen yang ditunjuk setelah prev != NULL / ada elemen yang akan dihapus
        if (hapus != NULL)
        {
            
            if (hapus->col != NULL)         //jika kolom tidak kosong maka di hapus semua terlebih dahulu
            {
                del_all_kolom(hapus);
            }
            
            if (hapus->next == NULL)    //jika elemennya di akhir
            {
                prev->next = NULL;
            }
            else                        //jika ditengah
            {       
                prev->next = hapus->next;
                hapus->next = NULL;
            }

            free(hapus);
        }
    }
}

void del_last_baris(list *L)
{
    if ((*L).first != NULL)
    {
        if (count_elemen_baris(*L) == 1)
        {
            del_first_baris(L);
        }
    
        else
        {
            elemen_baris *last = (*L).first;
            elemen_baris *prev_last;

            while (last->next != NULL)
            {
                prev_last = last;
                last = last->next;
            }
            del_after_baris(prev_last);
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
}

void del_all_baris(list *L)
{
    if (count_elemen_baris(*L) != 0)      //jika list tidak kosong
    {
        int i;

        for ( i = count_elemen_baris(*L); i >= 1; i--)
        {
            del_last_baris(L);
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
}

void print_elemen(list L)
{
    if (L.first != NULL)    //jika list tidak kosong
    {
        //inisialisasi
        elemen_baris* tunjuk = L.first;
        
        int i = 1;
        while (tunjuk != NULL)      //perulangan selemen pointer tunjuk tidak bernilai null
        {
            printf("elemen ke : %d\n",i);
            printf("nim : %s\n",tunjuk->kontainer.nim);
            printf("nama : %s\n",tunjuk->kontainer.nama);

            elemen_kolom* tunjuk_col = tunjuk->col;                             //pointer tunjuk untuk kolom
            while (tunjuk_col != NULL)
            {
                printf("kode matkul : %s\n",tunjuk_col->kontainer_kol.kode);
                printf("nilai : %s\n",tunjuk_col->kontainer_kol.nilai);
                
                //iterasi kolom
                tunjuk_col = tunjuk_col->next_kol;
            }
            
            printf("-------------\n");
            /* iterasi baris */
            tunjuk = tunjuk->next;
            i++;        
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
}

int main(){
    list L;
    create_list(&L);

    // printf("=====================\n");

    // add_first_baris("1", "orang_1", &L);
    // add_first_kolom("IF40KI", "A", L.first);
    // add_after_kolom(L.first->col, "IF40Z1", "A");
    // add_last_kolom("IF40Z2", "A", L.first);

    // add_after_baris(L.first, "2", "orang_2");
    // add_first_kolom("TI5141", "A", L.first->next);
    // add_last_kolom("IF5021", "A", L.first->next);

    // add_last_baris("3", "orang_3", &L);
    // add_first_kolom("IF5321", "A", L.first->next->next);

    // print_elemen(L);

    // printf("=====================\n");
    
    // del_all_baris(&L);
    // print_elemen(L);

    // printf("=====================\n");

}

