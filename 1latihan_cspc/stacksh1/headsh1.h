#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    float number;
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
void push(float number, stack *S);
void push_selang_seling(stack *S1, stack *S2);
void print_stack(stack S);