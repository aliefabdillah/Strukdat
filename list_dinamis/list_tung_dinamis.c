// contoh kodingan
//karena dinamis akan ada perbedaan
/* 
    1. menggunakan library tambahan <mallloc.h>
    2. dan akan menggunakan pointer yang benar" mengacu alamat elemen di memori 
 */
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char nim[10];
    char nama[50];
    char nilai[2];
}nilaimatkul;

/*
    cara untuk mendeklarasikan pointer dengan tipe sembarang sehingga
    didalam bungkungsan bisa di panggil sebagai pointer next
*/
typedef struct elmt* alamat_elemen;     
typedef struct elmt
{
    nilaimatkul kontainer;
    alamat_elemen next;
}elemen;

typedef struct 
{
    elemen* first;      //first disini bertipe pointer yang menuju sebuah elemen
}list;


void create_list(list *L){
    (*L).first = NULL;      //NULL artinya pointer first mengaskses elemen kosong di sebuah memori
}

int count_elemen(list L){
    int hasil = 0;

    if (L.first != NULL)
    {
        /* List tidak kosong */
        elemen* tunjuk;

        //inisialiasi
        tunjuk = L.first;

        while (tunjuk != NULL)
        {
            hasil = hasil + 1;

            tunjuk = tunjuk->next;
        }   
    }
    return hasil;
}


void add_first(char nim[], char nama[], char nilai[], list *L){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);

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

void add_after(elemen* prev, char nim[], char nama[], char nilai[], list *L){
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.nilai, nilai);

    //jika add after di paling akhir
    if (prev->next == NULL)
    {
        baru->next = NULL;
    }
    // jika addafter di tengah"
    else
    {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void add_last(char nim[], char nama[], char nilai[], list *L){
    if ((*L).first == NULL)     //jika list kosong
    {
        add_first(nim, nama, nilai, L);
    }
    else
    {
        /* jika list tidak kosong */
        //mencari elemen terakhir pada list;
        elemen* prev = (*L).first;
        while (prev->next != NULL)
        {
            //iterasi
            prev = prev->next;
        }
        add_after(prev, nim, nama, nilai, L);
    }
}

void del_first(list *L)
{
    
    if ((*L).first != NULL)     //jika list tidak kosong
    {
        elemen* hapus = (*L).first;     //pointer hapus menunjuk elemen pertama dari list
        if (count_elemen(*L) == 1)      //jika cuma 1 elemen saja
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

void del_after(elemen* prev, list *L)
{
    elemen* hapus = prev->next;
    
    //jika elemen yang ditunjuk setelah prev != NULL / ada elemen yang akan dihapus
    if (hapus != NULL)
    {
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

void del_last(list *L)
{
    if ((*L).first != NULL)     //jika elemen tidak kosong
    {
        if (count_elemen(*L) == 1)  //jika elemen tinggal 1
        {
            del_first(L);
        }
        else
        {
            // mencari elemen terakhir di list
            elemen* last = (*L).first;
            elemen* prev;

            while (last->next != NULL)
            {
                //iterasi
                prev = last;
                last = last->next;
            }

            del_after(prev, L);
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
    
}

void del_all(list *L)
{
    if (count_elemen(*L) != 0)      //jika list tidak kosong
    {
        int i;

        for ( i = count_elemen(*L); i >= 1; i--)
        {
            del_last(L);
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
        elemen* tunjuk = L.first;
        
        int i = 1;
        while (tunjuk != NULL)      //perulangan selemen pointer tunjuk tidak bernilai null
        {
            printf("elemen ke : %d\n",i);
            printf("nim : %s\n",tunjuk->kontainer.nim);
            printf("nama : %s\n",tunjuk->kontainer.nama);
            printf("nilai : %s\n",tunjuk->kontainer.nilai);
            printf("-------------\n");

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
    print_elemen(L);
    printf("============\n");
    
    add_first("1","orang_1","A", &L);
    add_after(L.first, "2","orang_2","A",&L);
    add_last("3", "orang_3","A", &L);
    print_elemen(L);

    printf("============\n");

    //del_all(&L);
    del_last(&L);
    del_after(L.first, &L);
    del_first(&L);
    print_elemen(L);

    printf("============\n");

    /* for (int i = 1; i < 6-1; i++)
    {
        printf("halo\n");
    }
     */
    
    return 0;
}