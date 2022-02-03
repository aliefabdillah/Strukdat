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
    int prev;
    int next;
}elemen;

typedef struct 
{
    int first;
    int tail;
    elemen data[10];
}list;

void create_list(list *L)
{
    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for ( i = 0; i < 10; i++)
    {
        // proses menginisialisasi isi array
        (*L).data[i].prev = -2;
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
            (*L).data[baru].prev = -1;      //pointer sebelumnya jadi -1
            (*L).data[baru].next = -1;      //pointer setelahnya jadi -1
            (*L).tail = baru;               //pointer tail menunjuk data baru
        }
        else
        {
            // jika list tidak kosong
            (*L).data[baru].prev = -1;              //pointer sebelumnya menjadi -1
            (*L).data[baru].next = (*L).first;      //pointer setelahnya menunjuk data pertama sebelumnya
            (*L).data[(*L).first].prev = baru;      //pointer sebelumnya dari data pertama sebelumnya menunjuk ke data baru
        }
        
        (*L).first = baru;      //first menunjuk baru
    }
    else
    {
        // jika array sudah penuh
        printf("List sudah tidak dapat di tambah\n");
    }
    
}

void add_after(int before, char nim[], char nama[], char nilai[], list *L)
{
    if (count_element(*L) < 10)
    {
        int baru = empty_elemen(*L);

        strcpy((*L).data[baru].kontainer.nim, nim);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.nilai, nilai);

        //jika add pada data paling belakang
        if ((*L).data[before].next == -1)
        {
            (*L).data[baru].prev = before;      //pointer prev pada baru menunjuk data before
            (*L).data[before].next = baru;      //pointer next dari data before menunjuk ke baru
            (*L).data[baru].next = -1;          //pointer next dari data baru menjadi null karena paling akhir
            (*L).tail = baru;                   //pointer tail menunjuk data baru karena data baru paling akhir
        }
        else
        {   
            //jika di tambah di tengah
            (*L).data[baru].prev = before;                      //pointer prev dari data baru menunjuk prev
            (*L).data[baru].next = (*L).data[before].next;      //pointer next dari data baru menunjuk ke next/setelahnya dari data before
            (*L).data[before].next = baru;                      //pointer next dari data before menunjuk data abru
            (*L).data[(*L).data[baru].next].prev = baru;        //pointer prev dari data yang ditunjuk oleh pointer next data baru(data setelah data baru) menunjuk ke data baru
        }
        //bisa juga taro sini si ini
        //(*L).data[before].next = baru;   
    }
    else
    {
        // jika array sudah penuh
        printf("List sudah tidak dapat di tambah\n");
    }
}

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
            add_after((*L).tail, nim, nama, nilai, L);
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
        int hapus = (*L).first;
        if (count_element(*L) == 1)     //jika elemen cuma 1
        {
            (*L).first = -1;        //first jadi null
            (*L).tail = -1;         //tail jadi null
        }
        else
        {
            /* (*L).first = (*L).data[(*L).first].next;        //pointer first menunjuk pada data yang ditunjuk oleh pointer next data first awal (pointer first menunjuk data setalah data first)
            (*L).data[(*L).first].prev = -1; */                //pointer prev dari data setelah data first menjadi null

            //bisa juga begini
            
            (*L).first = (*L).data[hapus].next;
            (*L).data[hapus].prev = -1;
            
        }
        
        // elemen awal sebeleumnya dikosongkan
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    }
    else
    {
        // proses jika array penuh
        printf("list kosong\n");
    }
}

void del_after(int before, list *L)
{
    int hapus = (*L).data[before].next;         //hapus berisi data yang ditunjuk pointer next dari before (data setelah before)
    if (hapus != -1)
    {   
        //jika paling belakang
        if ((*L).data[hapus].next == -1)
        {
            (*L).tail = before;                 //tail menunjuk before
            (*L).data[before].next = -1;        //pointer next dari before menjadi null
        }
        //jika ditengah
        else
        {
            (*L).data[before].next = (*L).data[hapus].next;     //pointer next dari before menujuk data yang ditunjuk oleh pointer next dari data hapus (pointer next before menunjuk ke data setelah data hapus)
            (*L).data[(*L).data[hapus].next].prev = before;     //pointer prev dari data yang ditunjuk oleh pointer next data hapus menujuk before (pointer prev setelah data hapus menunjuk before)
        }

        // pengosongan elemen
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
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
        del_last( L);
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

//contoh
//tampilkan isi list gand depan dan belakang hanya nim saja separuh-separuh
//jika ganjil maka tampilkan elemen tengah setelahnya

void print_depan_belakang(list L){
    int depan = L.first;    //pointer namanya depan isinya pointer first
    int blk = L.tail;       //pointer namanya blk isinya pointer tail

    //jika elemen lebih dari 1
    if (count_element(L) > 1)
    {
        int i;
        //perulangan sebanyak setengah banyaknya elemen maju
        for ( i = 0; i <= count_element(L)/2; i++)
        {
            printf("%s", L.data[depan].kontainer.nim);
            if (i != count_element(L)/2)    //jika i tidak sama dengan setenagh jumlah elemen
            {
                printf(" ");
            } 
            depan = L.data[depan].next;           //pointer depan berisi index dari pointer next dari data sebelumnya
        }
        //perulangan sebanyak setengah banyaknya elemen mundur
        for ( i = 0; i <= count_element(L)/2; i++)
        {
            printf("%s", L.data[blk].kontainer.nim);
            if (i != count_element(L)/2)
            {
                printf(" ");                
            }
            blk = L.data[blk].prev;                 //pointer blk berisi index yang ditunjuk oleh pointer prev dari data sebelumnya
        }
        //jika banyak elemen ganjil
        if (count_element(L) % 2 == 1)
        {
            printf("%s", L.data[blk].kontainer.nim);        //print data tengah
        }
    }
    //jika elemen cuma 1
    else if (count_element(L) == 1)
    {
        printf("%s\n", L.data[depan].kontainer.nim);
    }
    else
    {
        printf("list kosong");
    }
}

int main(){
    // list L;
    // create_list(&L);
    // print_element(L);
    // printf("============\n");
    
    // add_first("1", "orang_1", "A", &L);
    // add_after(L.first, "2", "orang_2","A",&L);
    // add_last("3", "orang_3", "A", &L);
    // print_element(L);
    // print_depan_belakang(L);

    // printf("============\n");

   /*  del_last(&L);
    del_after(L.first, &L);
    del_first(&L);
    print_element(L);
 */

    int i,j;

    for ( i = 5; i < 0; i--)
    {
        for ( j = i; j < 0; j--)
        {
            printf("%d", i);
        }
        printf("\n");
        
    }


    return 0;

    printf("============\n");

}