/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP1 dalam mata kuliah Struktur Data
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
    float rate;
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


//fungsi dan prosedur
void create_list(list *L);
int count_elemen(list L);
void add(char nama[], int harga, float rate, list *L);
void sort(int n, char choose_sort[], list *L);                  //prosdur sorting list
void print_allmenu(list L);                                     //menampilkan menu secara terurut
void print_buy(int total_money, list L);                        //menampilkan daftar menu yang dibeli
