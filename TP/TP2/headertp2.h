/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP5 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//deklarasi data pada list
typedef struct 
{
    char nama[50];
    int harga;
    int kode;
}daftar_perangkat;

//deklarasi pointer
typedef struct elmt* alamat;
typedef struct elmt
{
    daftar_perangkat kontainer;
    alamat prev;
    alamat next;
}elemen;

typedef struct 
{
    elemen *first;
    elemen *tail;
}list;

// prosedur dan fungsi
void create_list(list *L);
int count_element(list L);
void add(char nama[], int harga, int kode, list *L);
void cek(list *L);
void del_first(list *L);
void del_after(elemen* before, list *L);
void sort(char komponen[], char methode[], list *L);
void print(list L);
void swap(elemen* a, elemen* b, list *L);
