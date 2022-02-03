#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct smp *alamat_simpul;
typedef struct smp
{
    int kontainer;
    alamat_simpul right;
    alamat_simpul left;
}simpul;

typedef struct 
{
    simpul* root;
}tree;

void make_tree(int number, tree *T);
void add_right(int number, simpul *root);
void add_left(int number, simpul *root);
void input(int number, int parent, char direction[], tree T);
void checking(int number, int parent, char direction[], simpul *root);
