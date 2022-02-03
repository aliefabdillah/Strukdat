
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    float bil;
}daftar_float;

typedef struct elmt* almt_elmn;     
typedef struct elmt
{
    daftar_float kontainer;
    almt_elmn next;
}elemen;

typedef struct 
{
    elemen* first;
}list;


void create(list *L);
void add_first(float bil, list *L);
void print_element(list L);


