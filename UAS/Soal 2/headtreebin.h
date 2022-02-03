/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UAS pbbd21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

#include <stdio.h>
#include <malloc.h>

//struct to containt element of tree
typedef struct smp *alamat_simpul;
typedef struct smp
{
    int number1, number2;
    alamat_simpul right;
    alamat_simpul left;
}simpul;

typedef struct 
{
    simpul* root;
}tree;


void make_tree(int number1, int number2, tree *T);
void add_right(int number1, int number2, simpul *root);
void add_left(int number1, int number2, simpul *root);
void operation(simpul *root);
void print_tree(int spasi, simpul *root);