

// Bagian Header
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char merek[50];
    char warna[20];
    int ukuran;
}daftar_sepatu;

typedef struct
{
    daftar_sepatu kontainer;
    int next;
}elemen;

typedef struct 
{
    int first;
    elemen data[5];
}list;

void create_list(list *L);
int hitung_element(list L);
int cek_elemen_kosong(list L);
void add_first(char merek[], char warna[], int ukuran, list *L);
void add_after(int prev, char merek[], char warna[], int ukuran, list *L);
void add_last(char merek[], char warna[], int ukuran, list *L);
void del_first(list *L);
void del_after(int prev, list *L);
void del_last(list *L);
void del_all(list *L);
void cetak_element(list L);