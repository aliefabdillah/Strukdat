#include <stdio.h>
#include <malloc.h>

typedef struct smp *node_address;
typedef struct jlr *arc_address;
typedef struct smp
{
    int kontainer;
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
void addNode(int simp, graph *G);
void addArc(node *beginning, node *destination);
node* findNode(int simp, graph G);
void delArc(int simp_dest, node *beginning);
void delAllArc(node *beginning);
void delNode(int simp, graph *G);
void printGraph(graph G);