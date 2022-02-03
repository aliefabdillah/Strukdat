
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    int bil;
}daftar_int;

typedef struct elmt* almt_elmn;     
typedef struct elmt
{
    daftar_int kontainer;
    almt_elmn next;
}elemen;

typedef struct 
{
    elemen* first;
}list;


void create(list *L);
void add_first(int bil, list *L);
void print_element(list L);


