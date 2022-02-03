/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis Cksg21 dalam mata kuliah Struktur Data
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
}daftar_menu;

//deklarasi pointer
typedef struct elmt* almt_elmn;     
typedef struct elmt
{
    daftar_menu kontainer;
    almt_elmn next;
}elemen;

//deklarasi pointer first
typedef struct 
{
    elemen* first;      //first disini bertipe pointer yang menuju sebuah elemen
}list;

void create_list(list *L);
int count_elemen(list L);
void add_first(char nama[], int harga, list *L);
void add_after(elemen* prev, char nama[], int harga, list *L);
void add_last(char nama[], int harga, list *L);
void del_first(list *L);
void del_after(elemen* prev, list *L);
void del_last(list *L);
void swap(char tukar_1[], char tukar_2[], list *L_1, list *L_2);
void print_elemen(list L);