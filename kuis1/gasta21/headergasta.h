/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis Gasta21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian header
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char kata[50];
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
    elemen data[100];
}list;

//prosedur dan fungsi
void create_list(int n, list *L);
int count_element(list L);
int empty_elemen(int n, list L);
void add(int n, char kata[], list *L);
void print(int n, list L);