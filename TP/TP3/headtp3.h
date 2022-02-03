#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    int year;
    char title[50];
    char band[50];
}song_list;

typedef struct elmt* alamat_elemen;     
typedef struct elmt
{
    song_list kontainer;
    alamat_elemen next;
}elemen;

typedef struct 
{
    elemen* top;
}stack;

void create_empty(stack *S);
int count_elemen(stack S);
void push(int year, char title[], char band[], stack *S);
void pop(stack *S);
void print_stack(stack S);
void input_rock_pop(stack S_all, stack *S_rock, stack *S_pop);