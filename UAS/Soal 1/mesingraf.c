/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UAS grmmt21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

#include "headgraf.h"

void createEmpty(graph *G)
{
    (*G).first = NULL;
}

void addNode(char simp, graph *G)
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

node* findNode(char simp, graph G)
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

// function check cycle in graph
int check_cycle(node *vertex)
{
    int result = 0;
    if (vertex != NULL)
    {
        node *help = vertex;
        while (help != NULL)
        {
            arc *help_arc = help->arc;
            while (help_arc != NULL)
            {
                if (help_arc->dest->kontainer == vertex->kontainer)
                {
                    result = 1;
                }
                
                help_arc = help_arc->next_arc;
            }

            help = help->next;
        }

        result = check_cycle(vertex->next);
    }
    
    return result;
       
}
