#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nama[50];
    char tipe[50];
    char jumlah[2];
}nilaimatkul;

typedef struct
{
    nilaimatkul kontainer;
    int prev;
    int next;
}elemen;

typedef struct 
{
    int first;
    int tail;
    elemen data[6];
}list;

void create_list(list *L);
int count_element(list L);
int empty_elemen(list L);
void add_first(char nim[], char nama[], char nilai[], list *L);
void add_after(int before, char nim[], char nama[], char nilai[], list *L);
void add_last(char nim[], char nama[], char nilai[], list *L);
void del_first(list *L);
void del_after(int before, list *L);
void del_last(list *L);
void del_all(list *L);
void print_forward(list L);
void print_reverse(list L);