/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UAS grmmt21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

#include <stdio.h>
#include <malloc.h>

typedef struct smp *node_address;
typedef struct jlr *arc_address;
typedef struct smp
{
    char kontainer;
    node_address next;
    arc_address arc;
}node;

typedef struct jlr
{
    arc_address next_arc;
    node* dest;
}arc;

typedef struct 
{
    node* first;
}graph;

// procedure and function
void createEmpty(graph *G);
void addNode(char simp, graph *G);
void addArc(node *beginning, node *destination);
node* findNode(char simp, graph G);
int check_cycle(node *vertex);