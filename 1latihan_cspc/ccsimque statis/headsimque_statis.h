#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nama[50];
    char nim[50];
}daftar_angka;

typedef struct 
{
    int first;
    int last;
    daftar_angka data[6];
}queue;

void create_empty(queue *Q);
int is_empty(queue Q);
int is_full(queue Q);
void add(char nama[], char nim[], queue *Q);
void out(queue *Q);
void prioriy_add(char nama[], char nim[], int priority, queue *Q);
void print_queue(queue Q);