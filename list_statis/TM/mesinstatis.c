

//bagian mesin 
#include "headstatis.h"

void create_list(list *L)
{
    (*L).first = -1;
    int i;

    for ( i = 0; i < 6; i++)
    {
        // proses menginisialisasi isi array
        (*L).data[i].next = -2;
    }
}

int hitung_element(list L)
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

int cek_elemen_kosong(list L)
{
    int hasil = -1;     //jika array sudah penuh set -1

    //jika belum
    if (hitung_element(L) < 6)
    {
        int ketemu = 0;

        int i = 0;
        while ((ketemu == 0) && (i<6))
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

void add_first(char merek[], char warna[], int ukuran, list *L)
{
    if (hitung_element(*L) < 6)
    {
        int baru = cek_elemen_kosong(*L);        //pointer untuk menyimpan index yang nasih kosong
        strcpy((*L).data[baru].kontainer.merek, merek);
        strcpy((*L).data[baru].kontainer.warna, warna);
        (*L).data[baru].kontainer.ukuran = ukuran;

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

void add_after(int prev, char merek[], char warna[], int ukuran, list *L)
{
    if (hitung_element(*L) < 10)
    {
        int baru = cek_elemen_kosong(*L);

        strcpy((*L).data[baru].kontainer.merek, merek);
        strcpy((*L).data[baru].kontainer.warna, warna);
        (*L).data[baru].kontainer.ukuran = ukuran;

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

void add_last(char merek[], char warna[], int ukuran, list *L)
{
    if ((*L).first == -1)
    {
        //jika list masih kosong
        add_first(merek, warna, ukuran, L);
    }
    else
    {
        /* jika list sudah berisi element */
        if (hitung_element(*L) < 10)
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
            
            add_after(prev, merek, warna, ukuran, L);
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
        if (hitung_element(*L) == 1)
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

void del_last(list *L)
{
    if ((*L).first != -1)
    {
        //jika terdiri dari satu element saja
        if (hitung_element(*L) == 1)
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

void del_all(list *L)
{
    int i;
    for ( i = hitung_element(*L); i >= 1; i--)
    {
        del_last(L);
    }
}

void cetak_element(list L)
{
    if (L.first != -1)
    {
        /* inisialisasi */
        int tunjuk = L.first;

        while (tunjuk != -1)
        {
            printf("%s %s %d\n", L.data[tunjuk].kontainer.merek, L.data[tunjuk].kontainer.warna, L.data[tunjuk].kontainer.ukuran);
            
            // iterasi
            tunjuk = L.data[tunjuk].next;
        }
    }
    else
    {
        printf("List kosong\n");
    }
}
