#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char nama[50];
    int harga;
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
void push(char nama[], int harga, stack *S);
void pop(stack *S);
void print_stack(stack S);