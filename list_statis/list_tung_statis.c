/* 
    List Tunggal Represebtasi Statis

    - pointer next pada list statis adalah integer
    yang mengacu pada index elemen setelahnya
    - pointer isinya index-index elemen
    - untuk pointer next pada index elemen yang belum di isi bisa di isi dengan index negatif
    atau index yang belum dipakai pada baris elemen

    Create List
    - array nya merupakan array kosong, dan pointer next nya di set negatif
    bisa (-2)
    - pointer first di isi -1 yang artinya null
    - lalu melakuka addfirst dan yang pertama kali di isi adalah index pertama
    dan ponter first berubah menjadi index pertama dab poiunter next pada elemen
    pertama menjadi null (-1), dst
 */

// contoh kodingan

#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nim[10];
    char nama[50];
    char nilai[2];
}nilaimatkul;

typedef struct
{
    nilaimatkul kontainer;
    int next;
}elemen;

typedef struct 
{
    int first;
    elemen data[10];
}list;

// fungsi membuat list kosong
void create_list(list *L)
{
    (*L).first = -1;
    int i;

    for ( i = 0; i < 10; i++)
    {
        // proses menginisialisasi isi array
        (*L).data[i].next = -2;
    }
}

//fungsi menghitung banyaknya element pada list
int count_element(list L)
{
    int hasil = 0;      //variabel menyimpan banyak elemen di dalam list
    if(L.first != -1)
    {
        // jika list tidak null
        int hitung;     //pointer baru untuk menghitung list

        // inisaliasi
        hitung = L.first;

        while (hitung != -1)
        {
            hasil = hasil + 1;

            // pengulangan
            hitung = L.data[hitung].next;       //mengakses pointer next pada elemen saat pointer hitung berada saat ini
        }
        
    }

    return hasil;
}

// fungsi menghasilkan index dari elemen array yang masih kosong
int empty_elemen(list L)
{
    int hasil = -1;     //jika array sudah penuh set -1

    //jika belum
    if (count_element(L) < 10)
    {
        int ketemu = 0;

        int i = 0;
        while ((ketemu == 0) && (i<10))
        {
            if (L.data[i].next  == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i++;
            }
        }   
    }
    
    return hasil;
}

//mekanisme add first pada list kosong (karenapada contoh ini kosong)
void add_first(char nim[], char nama[], char nilai[], list *L)
{
    if (count_element(*L) < 10)
    {
        int baru = empty_elemen(*L);        //pointer untuk menyimpan index yang nasih kosong
        strcpy((*L).data[baru].kontainer.nim, nim);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.nilai, nilai);

        //jika list nya list kosong
        if ((*L).first == -1)
        {
            (*L).data[baru].next = -1;
        }
        else
        {
            // jika list tidak kosong
            (*L).data[baru].next = (*L).first;
        }
        
        (*L).first = baru;
    }
    else
    {
        // jika array sudah penuh
        printf("List sudah tidak dapat di tambah\n");
    }
    
}

//mekanisme add after
void add_after(int prev, char nim[], char nama[], char nilai[], list *L)
{
    if (count_element(*L) < 10)
    {
        int baru = empty_elemen(*L);

        strcpy((*L).data[baru].kontainer.nim, nim);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.nilai, nilai);

        //jika add pada data paling belakang
        if ((*L).data[prev].next == -1)
        {
            (*L).data[baru].next = -1;
        }
        else
        {   
            //jika di tambah di tengah
            (*L).data[baru].next = (*L).data[prev].next;
        }
        
        (*L).data[prev].next = baru;
        
    }
    else
    {
        // jika array sudah penuh
        printf("List sudah tidak dapat di tambah\n");
    }
}

//mekanisme add last, jika kosong add first jika banyak elemen add after
void add_last(char nim[], char nama[], char nilai[], list *L)
{
    if ((*L).first == -1)
    {
        //jika list masih kosong
        add_first(nim, nama, nilai, L);
    }
    else
    {
        /* jika list sudah berisi element */
        if (count_element(*L) < 10)
        {
            /* jika array belum penuh */
            /* maka proses mencari elemen terakhir */
            //inisialiasi
            int prev = (*L).first;

            while ((*L).data[prev].next != -1)
            {
                // pengulangan
                prev = (*L).data[prev].next;
            }
            
            add_after(prev, nim, nama, nilai, L);
        }
        else
        {
            // proses jika array penuh
            printf("List sudah tidak dapat di tambah\n");
        }
    }
}

//mekanisme hapus elemen element pertama 
void del_first(list *L)
{
    if ((*L).first != -1)
    {
        int hapus = (*L).first;
        if (count_element(*L) == 1)
        {
            (*L).first = -1;
        }
        else
        {
            (*L).first = (*L).data[hapus].next;
        }
        
        // elemen awal sebeleumnya dikosongkan
        (*L).data[hapus].next = -2;
    }
    else
    {
        // proses jika array penuh
        printf("List kosong\n");
    }
}

//mekanis menghapus paling belakang atau di tengah
void del_after(int prev, list *L)
{
    int hapus = (*L).data[prev].next;
    if (hapus != -1)
    {   
        //jika paling belakang
        if ((*L).data[hapus].next == -1)
        {
            (*L).data[prev].next = -1;
        }
        //jika ditengah
        else
        {
            (*L).data[prev].next = (*L).data[hapus].next;
        }

        // pengosongan elemen
        (*L).data[hapus].next = -2;
    }
}

//mekanisme delete palingakhir
void del_last(list *L)
{
    if ((*L).first != -1)
    {
        //jika terdiri dari satu element saja
        if (count_element(*L) == 1)
        {
            // jika hanya satu element saja
            del_first(L);
        }
        //jika terdiri dari banyak element
        else
        {
            int hapus = (*L).first;
            int prev;
            
            //mencari elemen ke 2 terakhir
            while ((*L).data[hapus].next != -1)
            {
                //iterasi
                prev = hapus;
                hapus = (*L).data[hapus].next;
            }
            // elemen sebelum elemen terakhir menjadi elemen terakhir
            del_after(prev, L);
        }
    }
    else
    {
        // proses jika array penuh
        printf("List kosong\n");
    }
}

// menampilkan list
void print_element(list L){
    if (L.first != -1)
    {
        /* inisialisasi */
        int tunjuk = L.first;
        int i = 1;

        while (tunjuk != -1)
        {
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", L.data[tunjuk].kontainer.nim);
            printf("nama : %s\n", L.data[tunjuk].kontainer.nama);
            printf("nilai : %s\n", L.data[tunjuk].kontainer.nilai);
            printf("next : %d\n", L.data[tunjuk].next);
            printf("------------------\n");

            // iterasi
            tunjuk = L.data[tunjuk].next;
            i++;
        }
    }
    else
    {
        printf("list kosong\n");
    }
}


int main(){
    list L;
    create_list(&L);
    print_element(L);
    printf("============\n");
    
    add_first("1", "orang_1", "A", &L);
    add_after(L.first, "2", "orang_2","A",&L);
    add_last("3", "orang_3", "A", &L);
    print_element(L);

    printf("============\n");

    del_last(&L);
    del_after(L.first, &L);
    del_first(&L);
    print_element(L);

    printf("============\n");

    return 0;
}