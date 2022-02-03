/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis Cksg21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

//struct of name of restaurant
typedef struct 
{
    char nama_res[100];
}daftar_res;


//struct of list of menu and price
typedef struct 
{
    char menu[100];
    char harga[100];
}daftar_menu;

//declarastion of pointer kolom
typedef struct e_kolom* alamatkolom;
typedef struct e_kolom
{
    daftar_menu kontainer_kol;
    alamatkolom next_kol;
}elemen_kolom;

typedef struct e_baris* alamatbaris;
typedef struct e_baris
{
    daftar_res kontainer;
    elemen_kolom *col;      //similiar with first in row
    alamatbaris next;
}elemen_baris;

typedef struct 
{
    elemen_baris *first;
}list;

//procedure and function
void create_list(list *L);
int count_elemen_baris(list L);
int count_elemen_kolom(elemen_baris L);
void add_first_baris(char nama_res[], list *L);
void add_first_kolom(char menu[], char harga[], elemen_baris *L);
void add_after_baris(elemen_baris *prev, char nama_res[]);
void add_after_kolom(elemen_kolom *prev, char menu[], char harga[]);
void add_last_baris(char nama_res[], list *L);
void add_last_kolom(char menu[], char harga[], elemen_baris *L);
elemen_baris* isi_kolom(char nama_res[], list L);
void print_elemen(list L);
void swap(char res1[], char res2[], char menu_switch[], list *L);
