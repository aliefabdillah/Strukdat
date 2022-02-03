#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct 
{
    char nama[50];
    int nilai;
}data;

typedef struct smp *node_address;
typedef struct smp
{
    data kontainer;
    node_address sibling;
    node_address child;
}node;

typedef struct 
{
    node* root;
}tree;

typedef struct 
{
    char nama[50];
    int nilai;
}masukan;

void make_tree(masukan input, tree *T);
void add_child(masukan input, node *root);
void del_all(node *root);
void del_child(node *nama, node *root);
node* find_node(masukan input, node *root);
void print_pre_order(node *root);
void copy_tree(node *root1, node **root2);
int is_equal(node *root1, node *root2);