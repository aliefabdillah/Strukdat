// graph

// graf adalah sebuah konsep terdirii dari kumpulan node dan arc (simpul dan garis)
// sebuah garis harus di akhiri dengan simpul
// jalur / arc dinyatakan sbb : ex : a = [A,B], garis a terdiri dari simpul A dan B


/* Graf Lengkap */
// setiap simpul memiliki jalur ke semua simpul lainnya

/* Graf bearah */
// biasa digunakan untuk memodelkan jalan/arc yang hanya di lewati satu arah
// sehingga arah di pertimbangkan

/* Representasi Graf */
// dengan matriks tetangga
// terdiri dari simpul awal dan tujuan

// dengan matriks tetangga yang memiliki bobot 

/* Representasi Graf Dinamis */
// teridiri dari kontaibner dan 2 pointer yang menenunjukan simpul dan jalan


/* Kode Progam  */
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
    int arc_kontainer;
    arc_address next_arc;
    node* dest;
}arc;

typedef struct 
{
    node* first;
}graph;

void createEmpty(graph *G)
{
    (*G).first = NULL;
}

void addNode(char c, graph *G)
{
    node *new;
    new = (node *) malloc (sizeof (node));

    new->kontainer = c;
    new->next = NULL;
    new->arc = NULL;

    if ((*G).first == NULL)
    {
        (*G).first = new;
    }
    else
    {
        // add new node to end of graph
        //similiat with add last of dinamic list
        node *last = (*G).first;

        while (last->next != NULL)
        {
            last = last->next;
        }
        
        last->next = new;
    }
}

void addArc(node *beginning, node *destination, int load)
{
    arc *new;
    new = (arc *) malloc (sizeof (arc));
    new->arc_kontainer = load;
    new->next_arc = NULL;
    new->dest = destination;

    if (beginning->arc == NULL)
    {
        /* if arc list null */
        beginning->arc = new;
    }
    else
    {
        /* add new arc to end of list arc */
        // similiar add last in list of list
        arc *last = beginning->arc;

        while (last->next_arc != NULL)
        {
            last = last->next_arc;
        }

        last->next_arc = new;
    }   
}

node* findNode(char c, graph G)
{
    node *result = NULL;
    node *help = G.first;

    int found = 0;
    while ((help != NULL) && (found == 0))
    {
        if (help->kontainer == c)
        {
            result = help;
            found = 1;
        }
        else
        {
            help = help->next;
        }
    }
    
    return result;
}

void delArc(char c_dest, node *beginning)
{
    arc *erase = beginning->arc;

    if (erase != NULL)
    {
        arc *prev = NULL;

        /* procces finding arc that will be erase */

        int found = 0;
        while ((erase != NULL) && (found == 0))
        {
            //jika tujuan dari jalur sama dengan masukan
            if (erase->dest->kontainer == c_dest)
            {
                found = 1;
            }
            else
            {
                prev = erase;
                erase = erase->next_arc;
            }
        }

        if (found == 1)
        {
            if (prev == NULL)
            {
                // erase first arc
                // similiar with del first in list
                beginning->arc = erase->next_arc;
                erase->next_arc = NULL;

            }
            else
            {
                if (erase->next_arc = NULL)
                {
                    // erase last arc
                    // similiar with del lastt in list
                    prev->next_arc = NULL;
                }
                else
                {
                    // erase arc in middle list
                    // similiar with delafter in list
                    prev->next_arc = erase->next_arc;
                    erase->next_arc = NULL;
                }
            }
            
            free(erase);
        }
        else
        {
            printf("tidak ada jalur dengan simpul tujuan\n");
        }
    }
    else
    {
        printf("tidak ada jalur dengan simpul tujuan\n");    
    }
}

// del all arc
void delAllArc(node *beginning)
{
    arc *help;
    help = beginning->arc;
    arc *erase;

    while (help != NULL)
    {
        erase = help;
        help = help->next_arc;
        beginning->arc = help;
        erase->next_arc = NULL;
        free(erase);
    }
    
}

void delNode(char c, graph *G)
{
    node *erase = (*G).first;
    if (erase != NULL)
    {
        node *prev = NULL;

        // looking to node will be delete

        int found = 0;
        while ((erase != NULL) && (found == 0))
        {
            if (erase->kontainer == c)
            {
                found = 1;
            }
            else
            {
                prev = erase;
                erase = erase->next;
            }
        }
        
        if (found == 1)
        {
            // if there node who will to be delete
            // delete all arc from another node that lead to deleted node
            
            node *help;
            help = (*G).first;

            // checking all node in graph
            while (help != NULL)
            {
                // if current node is not equal with node will be delete
                if (help != erase)
                {
                    // delete all arc who lead to deleted node
                    delArc(erase->kontainer, help);

                }
                help = help->next;
            }
            
            // delete all arc
            delAllArc(erase);

            if (prev == NULL)
            {
                // delete first node
                (*G).first = erase->next;
                erase->next = NULL;
            }
            else
            {
                if (erase->next == NULL)
                {
                    // erase last node
                    prev->next = NULL;
                }
                else
                {
                    // erase node in the middle
                    prev->next = erase->next;
                    erase->next = NULL;
                }
            }

            free(erase);
        }
        else
        {
            printf("tidak ada simpul pada graph\n");
        }
    }
    else
    {
        printf("tidak ada simpul pada graph\n");
    }
}

void printGraph(graph G)
{
    node *help = G.first;

    if (help != NULL)
    {
        while (help != NULL)
        {
            printf("simpul : %c\n", help->kontainer);

            arc *help_arc = help->arc;

            while (help_arc != NULL)
            {
                printf("  - ada jalur ke simpul : %c dengan beban : %d\n", help_arc->dest->kontainer,  help_arc->arc_kontainer);
                help_arc = help_arc->next_arc;
            }
            
            help = help->next;
        }
    }
    else
    {
        printf("Graph Kosong\n");
    }
}

int main(){
    graph G;

    createEmpty(&G);
    addNode('A', &G);
    addNode('B', &G);
    addNode('C', &G);
    addNode('D', &G);
    addNode('E', &G);
    addNode('F', &G);

    node *begin = findNode('A', G);
    node *end = findNode('B', G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end, 3);
    }

    begin = findNode('B', G);
    end = findNode('D', G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end, 3);
    }

    end = findNode('E', G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end, 7);
    }

    begin = findNode('C', G);
    end = findNode('A', G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end, 3);
    }
    
    begin = findNode('D', G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end, 8);
    }

    end = findNode('C', G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end, 3);
    }

    begin = findNode('E', G);
    end = findNode('D', G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end, 4);
    }
    
    end = findNode('F', G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end, 4);
    }

    begin = findNode('F', G);
    end = findNode('D', G);
    if ((begin != NULL) && (end != NULL))
    {
        addArc(begin, end, 2);
    }

    printf("=== ==== ==== ==== ===\n");
    printGraph(G);
    printf("=== ==== ==== ==== ===\n");
    
    begin = findNode('A', G);
    if (begin != NULL)
    {
        delArc('B', begin);
    }

    printf("=== ==== ==== ==== ==\n");
    printf("setelah dihapus\n");
    printGraph(G);
    printf("=== ==== ==== ==== ===\n");
    
    return 0;
}