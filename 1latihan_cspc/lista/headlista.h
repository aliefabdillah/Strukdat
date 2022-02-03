#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    int total_a;
}baris;

typedef struct 
{
    char kata_kolom[100];
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
void add_first_baris(int total_a, list *L);
void add_after_baris(elemen_baris *prev, int total_a);
void add_last_baris(int total_a, list *L);
void add_first_kolom(char kata[], elemen_baris *L);
void add_after_kolom(elemen_kolom *prev, char kata[]);
void add_last_kolom(char kata[], elemen_baris *L);
void checking(char input[], int row_a, list *L);
int count_a(char input[]);
void print_elemen(list L);