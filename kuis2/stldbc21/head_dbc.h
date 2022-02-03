/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis 2 stldbc dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nama[50];
    char jenis[50];
}nilai_laundry;

typedef struct 
{
    int top;
    nilai_laundry data[50];          //isi data bisa bervariasi sesuai spesifikasi yanag diminta
}stack;

void create_empty(stack *S);
int is_empty(stack S);
int is_full(stack S);
void push(char nama[], char jenis[], stack *S);
void pop(stack *S);
void ambil_baju(int n, int m, char ambil[][50], stack *S_real, stack *S_temp);
void print_stack(stack S);