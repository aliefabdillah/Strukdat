#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    int waktu;
    char nama[50];
}daftar_antrian;

typedef struct elmt* alamat_elemen;     
typedef struct elmt
{
    daftar_antrian kontainer;
    alamat_elemen next;
}elemen;

typedef struct 
{
    elemen* first;
    elemen* last;
}queue;

int time;
void create_empty(queue *Q);
int count_elemen(queue Q);
void add(int waktu, char nama[], queue *Q);
void checking(int time, queue Q);