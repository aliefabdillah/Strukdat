//bagian header
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//deklarasi data pada list
typedef struct 
{
    char nama[50];
    char rumus[50];
    char kons[10];
}senyawa;

//deklarasi pointer
typedef struct elmt* almt_elmn;     
typedef struct elmt
{
    senyawa kontainer;
    almt_elmn next;
}elemen;

//deklarasi pointer first
typedef struct 
{
    elemen* first;      //first disini bertipe pointer yang menuju sebuah elemen
}list;


//fungsi dan prosedur
void create_list(list *L);
int count_elemen(list L);
void add_first(char nama[], char rumus[], char kons[], list *L);
void add_after(elemen* prev, char nama[], char rumus[], char kons[]);
void add_last(char nama[], char rumus[], char kons[], list *L);
void del_first(list *L);
void del_after(elemen* prev, list *L);
void del_last(list *L);
void del_all(list *L);
void print_elemen(list L);
