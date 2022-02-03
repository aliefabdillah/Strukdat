
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char kata[20];
}daftar_kata;

typedef struct elmt* almt_elmn;     
typedef struct elmt
{
    daftar_kata kontainer;
    almt_elmn next;
}elemen;

typedef struct 
{
    elemen* first;
}list;


void create(list *L);
void add_first(char kata[], list *L);
void cek_a(char inp[][20], int n);
void print_element(list L);


