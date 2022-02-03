/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis 2 qqbsep21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char nama[50];
    int prioritas;
    char kota[50];
    int biaya;
}daftar_orang;

typedef struct elmt* alamat_elemen;     
typedef struct elmt
{
    daftar_orang kontainer;
    alamat_elemen next;
}elemen;

typedef struct 
{
    elemen* first;
    elemen* last;
}queue;

void create_empty(queue *Q);
int count_elemen(queue Q);
void add(char nama[], int prioritas, char kota[], int biaya, queue *Q);
void out(queue *Q);
void prioriy_add(char nama[], int prioritas, char kota[], int biaya, queue *Q);
void print_queue(int jumlah_keluar, queue Q);