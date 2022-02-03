#include <stdio.h>
#include <malloc.h>
#include <string.h>

//struct of daftarclub
typedef struct 
{
    char klub[50];
    int tahun;
}daftar_klub;


//struct of daftar pemain
typedef struct 
{
    char nama_pemain[50];
}daftar_pemain;

typedef struct e_kolom* alamatkolom;
typedef struct e_kolom
{
    daftar_pemain kontainer_kol;
    alamatkolom next_kol;
}elemen_kolom;

typedef struct e_baris* alamatbaris;
typedef struct e_baris
{
    daftar_klub kontainer;
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
void add_first_baris(char klub[], int tahun, list *L);
void add_first_kolom(char nama_pemain[], elemen_baris *L);
void add_after_baris(elemen_baris *prev, char klub[], int tahun);
void add_after_kolom(elemen_kolom *prev, char nama_pemain[]);
void add_last_baris(char klub[], int tahun, list *L);
void add_last_kolom(char nama_pemain[], elemen_baris *L);
void del_first_kolom(elemen_baris *L);
void del_after_kolom(elemen_kolom *prev);
void del_last_kolom(elemen_baris *L);
void del_all_kolom(elemen_baris *L);
void del_first_baris(list *L);
void del_after_baris(elemen_baris *prev);
void del_last_baris(list *L);
void del_all_baris(list *L);
void print_elemen(list L);
elemen_baris* isi_kolom(char klub[], list L);
void cek(char klub[], int tahun, list *L);
void cek_kol(char klub[], list *L);