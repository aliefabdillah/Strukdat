#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    int number;
}daftar_menu;

typedef struct elmt* alamat_elemen;     
typedef struct elmt
{
    daftar_menu kontainer;
    alamat_elemen next;
}elemen;

typedef struct 
{
    elemen* top;
}stack;

void create_empty(stack *S);
int count_elemen(stack S);
void push(int number, stack *S);
void pop(stack *S);
void pop_cari(int nilai, stack *S);
void pop_banyak(int nilai, stack *S);
void print_stack(stack S);