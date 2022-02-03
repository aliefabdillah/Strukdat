#include <stdio.h>
#include <malloc.h>

//struct to containt element of tree
typedef struct smp *alamat_simpul;
typedef struct smp
{
    char kontainer;
    alamat_simpul right;
    alamat_simpul left;
}simpul;

typedef struct 
{
    simpul* root;
}tree;

//procedure
void make_tree(char alpha, tree *T);
void add_right(char alpha, simpul *root);
void add_left(char alpha, simpul *root);
void del_all(simpul *root);
void del_right(simpul *root);
void del_left(simpul *root);
void print_pre_order(simpul *root);
void print_in_order(simpul *root);
void print_post_order(simpul *root);