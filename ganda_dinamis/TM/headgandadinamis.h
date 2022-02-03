#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char nama[50];
    char matkul[50];
    char nilai[2];
}nilaimatkul;

typedef struct elmt* alamat;
typedef struct elmt
{
    nilaimatkul kontainer;
    alamat prev;
    alamat next;
}elemen;

typedef struct 
{
    elemen *first;
    elemen *tail;
}list;

void create_list(list *L);
int count_element(list L);
void add_first(char nama[], char matkul[], char nilai[], list *L);
void add_after(elemen* before, char nama[], char matkul[], char nilai[], list *L);
void add_before(elemen* after, char nama[], char matkul[], char nilai[], list *L);
void add_last(char nama[], char matkul[], char nilai[], list *L);
void del_first(list *L);
void del_after(elemen* before, list *L);
void del_last(list *L);
void del_all(list *L);
void print_forward(list L);
void print_reverse(list L);