#include <stdio.h>
#include <string.h>
#include <malloc.h>

typedef struct 
{
    char name[50];
}family_tree;

typedef struct smp *node_address;
typedef struct smp
{
    family_tree kontainer;
    node_address sibling;
    node_address child;
}node;

typedef struct 
{
    node* root;
}tree;



void make_tree(char name[], tree *T);
void add_child(char name[], node *root);
void del_all(node *root);
void del_child(char name[], node *root);
node* find_node(char name[], node *root);
void print_pre_order(node *root, int level);
//char* erase_coma(char parent_temp[]);