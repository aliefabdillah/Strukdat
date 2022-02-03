
/* Saya Alief Muhammad Abdillah-2003623 mengerjakan evaluasi
Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecura ngan
seperti yang telah dispesifikasikan. Aamiin. */

//deklrasi library
#include <stdio.h>
#include <string.h>
#include <malloc.h>

//struct untuk masukan user
typedef struct
{
    char daerah[50];
    int korban;
}data_daerah;

//struct untuk tree
typedef struct smp *node_address;
typedef struct smp
{
    data_daerah kontainer;
    node_address sibling;
    node_address child;
}node;

typedef struct 
{
    node* root;
}tree;

//variabel global
int layer[50];
int sub_layer[50];
int level_temp;

//prosedur dan fungsi
void make_tree(char daerah[], int korban, tree *T);
void add_child(char daerah[], int korban, node *root);
node* find_node(char parent[], node *root);
int string_to_int(char korban[]);
int accumulate(node *root, int temp);
void print_tree(node *root, node *root2, int space, int level, char word, int count_sub);
void count_level(node *root, int level, int total_space, char word);