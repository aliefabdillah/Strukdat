#include "headgraf.h"

int main()
{
    graph G;

    int erase_node;
    scanf("%d", &erase_node);

    createEmpty(&G);
    addNode(1, &G);
    addNode(2, &G);
    addNode(3, &G);
    addNode(4, &G);
    addNode(5, &G);
    addNode(6, &G);
    addNode(7, &G);
    addNode(8, &G);

    //add arc from node '8'
    node *begin = findNode(8, G);
    node *end = findNode(1, G);
    node *end2 = findNode(4, G);
    node *end3 = findNode(6, G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end);
        addArc(begin, end2);
        addArc(begin, end3);
    }

    //add arc from node 1
    begin = findNode(1, G);
    end = findNode(2, G);
    end2 = findNode(3, G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end);
        addArc(begin, end2);
    }

    //add arc from node 6
    begin = findNode(6, G);
    end = findNode(7, G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end);
    }

    //add arc from node 7
    begin = findNode(7, G);
    end = findNode(5, G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end);
    }

    //add arc from node 4
    begin = findNode(4, G);
    end = findNode(5, G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end);
    }

    printGraph(G);
    printf("===========\n");
    
    //del node from input user
    delNode(erase_node, &G);
    printGraph(G);

    return 0;
}