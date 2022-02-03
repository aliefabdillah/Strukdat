#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char name[50];
    char member[50];
    int time;
}daftar_pasien;

typedef struct elmt* alamat_elemen;     
typedef struct elmt
{
    daftar_pasien kontainer;
    alamat_elemen next;
}elemen;

typedef struct 
{
    elemen* first;
    elemen* last;
}queue;

void create_empty(queue *Q);
int count_elemen(queue Q);
void add(char name[], char nilai[], int time, queue *Q);
void out(queue *Q);
void prioriy_add(char name[], char member[], int time, queue *Q);
int count_time(queue Q);
void print_queue(queue Q);