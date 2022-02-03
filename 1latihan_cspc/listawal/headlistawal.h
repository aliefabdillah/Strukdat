#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    int angka_baris;
}baris;

typedef struct 
{
    int angka_kolom;
}kolom;

typedef struct e_kolom* alamatkolom;
typedef struct e_kolom
{
    kolom kontainer_kol;
    alamatkolom next_kol;
}elemen_kolom;

typedef struct e_baris* alamatbaris;
typedef struct e_baris
{
    baris kontainer;
    elemen_kolom *col;      
    alamatbaris next;
}elemen_baris;

typedef struct 
{
    elemen_baris *first;
}list;

void create_list(list *L);
int count_elemen_baris(list L);
int count_elemen_kolom(elemen_baris L);
void add_first_baris(int angka_baris, list *L);
void add_after_baris(elemen_baris *prev, int angka_baris);
void add_last_baris(int angka_baris, list *L);
void add_first_kolom(int angka_kolom, elemen_baris *L);
void add_after_kolom(elemen_kolom *prev, int angka_kolom);
void add_last_kolom(int angka_kolom, elemen_baris *L);
void checking(int input, list *L);
void print_elemen(list L);