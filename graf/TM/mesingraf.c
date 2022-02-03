#include "headgraf.h"

void createEmpty(graph *G)
{
    (*G).first = NULL;
}

void addNode(int simp, graph *G)
{
    node *new;
    new = (node *) malloc (sizeof (node));

    new->kontainer = simp;
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

void addArc(node *beginning, node *destination)
{
    arc *new;
    new = (arc *) malloc (sizeof (arc));
    // new->arc_kontainer = NULL;
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

node* findNode(int simp, graph G)
{
    node *result = NULL;
    node *help = G.first;

    int found = 0;
    while ((help != NULL) && (found == 0))
    {
        if (help->kontainer == simp)
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

void delArc(int simp_dest, node *beginning)
{
    arc *erase = beginning->arc;

    if (erase != NULL)
    {
        arc *prev = NULL;

        /* procces finding arc that will be erase */

        int found = 0;
        while (erase != NULL && found == 0)
        {
            //jika tujuan dari jalur sama dengan masukan
            if (erase->dest->kontainer == simp_dest)
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
                if (erase->next_arc == NULL)
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
    }
}

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

void delNode(int simp, graph *G)
{
    node *erase = (*G).first;
    if (erase != NULL)
    {
        node *prev = NULL;

        // looking to node will be delete

        int found = 0;
        while ((erase != NULL) && (found == 0))
        {
            if (erase->kontainer == simp)
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
            
            node *help = (*G).first;

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
            printf("Node %d\n", help->kontainer);

            arc *help_arc = help->arc;

            while (help_arc != NULL)
            {
                printf("Jalur %d ke %d\n", help->kontainer, help_arc->dest->kontainer);
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