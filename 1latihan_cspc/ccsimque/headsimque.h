#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    int nilai;
}daftar_angka;

typedef struct elmt* alamat_elemen;     
typedef struct elmt
{
    daftar_angka kontainer;
    alamat_elemen next;
}elemen;

typedef struct 
{
    elemen* first;
    elemen* last;
}queue;

void create_empty(queue *Q);
int count_elemen(queue Q);
void add(int nilai, queue *Q);
void out(queue *Q);
void prioriy_add(int nilai, int priority, queue *Q);
void print_queue(queue Q);