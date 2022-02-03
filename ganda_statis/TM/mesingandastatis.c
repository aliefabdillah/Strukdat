#include "headgandastatis.h"

void create_list(list *L)
{
    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for ( i = 0; i < 6; i++)
    {
        // proses menginisialisasi isi array
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

int count_element(list L)
{
    int total = 0;      //variabel menyimpan banyak elemen di dalam list
    if(L.first != -1)
    {
        // jika list tidak null
        int count;     //pointer count untuk menghitung list

        // inisaliasi
        count = L.first;

        while (count != -1)
        {
            total = total + 1;

            // pengulangan
            count = L.data[count].next;       //mengakses pointer next pada elemen saat pointer hitung berada saat ini
        }
        
    }

    return total;
}

int empty_elemen(list L)
{
    int total = -1;     //jika array sudah penuh set -1

    //jika belum
    if (count_element(L) < 6)
    {
        int found = 0;

        int i = 0;
        while ((found == 0) && (i<10))
        {
            if (L.data[i].next  == -2)
            {
                total = i;
                found = 1;
            }
            else
            {
                i++;
            }
        }   
    }
    
    return total;
}

void add_first(char nama[], char tipe[], char jumlah[], list *L)
{
    if (count_element(*L) < 6)
    {
        int new = empty_elemen(*L);        //pointer untuk menyimpan index yang nasih kosong
        strcpy((*L).data[new].kontainer.nama, nama);
        strcpy((*L).data[new].kontainer.tipe, tipe);
        strcpy((*L).data[new].kontainer.jumlah, jumlah);

        //jika list nya list kosong
        if ((*L).first == -1)
        {
            (*L).data[new].prev = -1;      //pointer sebelumnya jadi -1
            (*L).data[new].next = -1;      //pointer setelahnya jadi -1
            (*L).tail = new;               //pointer tail menunjuk data new
        }
        else
        {
            // jika list tidak kosong
            (*L).data[new].prev = -1;              //pointer sebelumnya menjadi -1
            (*L).data[new].next = (*L).first;      //pointer setelahnya menunjuk data pertama sebelumnya
            (*L).data[(*L).first].prev = new;      //pointer sebelumnya dari data pertama sebelumnya menunjuk ke data new
        }
        
        (*L).first = new;      //first menunjuk new
    }
    else
    {
        // jika array sudah penuh
        printf("List sudah tidak dapat di tambah\n");
    }
    
}

void add_after(int before, char nama[], char tipe[], char jumlah[], list *L)
{
    if (count_element(*L) < 6)
    {
        int new = empty_elemen(*L);

        strcpy((*L).data[new].kontainer.nama, nama);
        strcpy((*L).data[new].kontainer.tipe, tipe);
        strcpy((*L).data[new].kontainer.jumlah, jumlah);

        //jika add pada data paling belakang
        if ((*L).data[before].next == -1)
        {
            (*L).data[new].prev = before;      //pointer prev pada new menunjuk data before
            (*L).data[before].next = new;      //pointer next dari data before menunjuk ke new
            (*L).data[new].next = -1;          //pointer next dari data new menjadi null karena paling akhir
            (*L).tail = new;                   //pointer tail menunjuk data new karena data new paling akhir
        }
        else
        {   
            //jika di tambah di tengah
            (*L).data[new].prev = before;                      //pointer prev dari data new menunjuk prev
            (*L).data[new].next = (*L).data[before].next;      //pointer next dari data new menunjuk ke next/setelahnya dari data before
            (*L).data[before].next = new;                      //pointer next dari data before menunjuk data new
            (*L).data[(*L).data[new].next].prev = new;        //pointer prev dari data yang ditunjuk oleh pointer next data new(data setelah data new) menunjuk ke data new
        }  
    }
    else
    {
        // jika array sudah penuh
        printf("List sudah tidak dapat di tambah\n");
    }
}

void add_last(char nama[], char tipe[], char jumlah[], list *L)
{
    if ((*L).first == -1)
    {
        //jika list masih kosong
        add_first(nama, tipe, jumlah, L);
    }
    else
    {
        /* jika list sudah berisi element */
        if (count_element(*L) < 6)
        {
            add_after((*L).tail, nama, tipe, jumlah, L);
        }
        else
        {
            // proses jika array penuh
            printf("List sudah tidak dapat di tambah\n");
        }
    }
}

void del_first(list *L)
{
    if ((*L).first != -1)
    {
        int erase = (*L).first;
        if (count_element(*L) == 1)     //jika elemen cuma 1
        {
            (*L).first = -1;        //first jadi null
            (*L).tail = -1;         //tail jadi null
        }
        else
        {
            /* (*L).first = (*L).data[(*L).first].next;        //pointer first menunjuk pada data yang ditunjuk oleh pointer next data first awal (pointer first menunjuk data setalah data first)
            (*L).data[(*L).first].prev = -1; */                //pointer prev dari data setelah data first menjadi null

            (*L).first = (*L).data[erase].next;
            (*L).data[erase].prev = -1;

        }
        
        // elemen awal sebeleumnya dikosongkan
        (*L).data[erase].prev = -2;
        (*L).data[erase].next = -2;
    }
    else
    {
        // proses jika array penuh
        printf("list kosong\n");
    }
}

void del_after(int before, list *L)
{
    int erase = (*L).data[before].next;         //hapus berisi data yang ditunjuk pointer next dari before (data setelah before)
    if (erase != -1)
    {   
        //jika paling belakang
        if ((*L).data[erase].next == -1)
        {
            (*L).tail = before;                 //tail menunjuk before
            (*L).data[before].next = -1;        //pointer next dari before menjadi null
        }
        //jika ditengah
        else
        {
            (*L).data[before].next = (*L).data[erase].next;     //pointer next dari before menujuk data yang ditunjuk oleh pointer next dari data hapus (pointer next before menunjuk ke data setelah data hapus)
            (*L).data[(*L).data[erase].next].prev = before;     //pointer prev dari data yang ditunjuk oleh pointer next data hapus menujuk before (pointer prev setelah data hapus menunjuk before)
        }

        // pengosongan elemen
        (*L).data[erase].prev = -2;
        (*L).data[erase].next = -2;
    }
}

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
            // elemen sebelum elemen tail menjadi \before
            del_after((*L).data[(*L).tail].prev, L);
        }
    }
    else
    {
        // proses jika array penuh
        printf("list kosong\n");
    }
}

void del_all(list *L){
    int i;
    for ( i = count_element(*L); i >= 1 ; i--)      //hapus data dari belakang (bisa juga dari depan tinggal ganti aja fornya)
    {
        del_last(L);
    }
    
}

void print_forward(list L){
    if (L.first != -1)
    {
        /* inisialisasi */
        int tunjuk = L.first;
        int i = 1;

        while (tunjuk != -1)
        {
        
            printf("%s %s %s\n", L.data[tunjuk].kontainer.nama, L.data[tunjuk].kontainer.tipe, L.data[tunjuk].kontainer.jumlah);
            // iterasi
            tunjuk = L.data[tunjuk].next;
            i++;
        }
    }
    else
    {
        printf("List kosong\n");
    }
    printf("========\n");
}

void print_reverse(list L){
    if (L.first != -1)
    {
        /* inisialisasi */
        int tunjuk = L.tail;
        
        int i = count_element(L);

        while (tunjuk != -1)
        {
        
            printf("%s %s %s\n", L.data[tunjuk].kontainer.nama, L.data[tunjuk].kontainer.tipe, L.data[tunjuk].kontainer.jumlah);
            // iterasi
            tunjuk = L.data[tunjuk].prev;
            i--;
        }
    }
    else
    {
        printf("List kosong\n");
    }
    printf("========\n");
}