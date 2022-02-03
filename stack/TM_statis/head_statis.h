#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nama[50];
    int harga;
}daftar_menu;

typedef struct 
{
    int top;
    daftar_menu data[6];          //isi data bisa bervariasi sesuai spesifikasi yanag diminta
}stack;

void create_empty(stack *S);
int is_empty(stack S);
int is_full(stack S);
void push(char nama[], int harga, stack *S);
void pop(stack *S);
void print_stack(stack S);