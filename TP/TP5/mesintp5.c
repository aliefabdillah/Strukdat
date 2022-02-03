#include "headtp5.h"

//make new tree procedur
void make_tree(char name[], tree *T)
{
    node *new;
    new = (node *) malloc (sizeof (node));

    //input new data to element of tree
    strcpy(new->kontainer.name, name);
    new->sibling = NULL;
    new->child = NULL;
    (*T).root = new;           //root pointing to new elemen
    new = NULL;
    //printf("ini make tree\n");
}

void add_child(char name[], node *root)
{
    //if root not null, add node child to root
    if (root != NULL)
    {
        node *new;
        new = (node *) malloc (sizeof (node));

        strcpy(new->kontainer.name, name);
        new->child = NULL;

        //if root didnt have child, so new node become first child
        if (root->child == NULL)
        {
            new->sibling = NULL;
            root->child = new;
            //printf("halo ini add child\n");
        }
        else
        {
            //if root have a child who didnt have sibling , so new node become second child
            if (root->child->sibling == NULL)
            {
                new->sibling = root->child;
                root->child->sibling = new;
            }
            else
            {
                //if parent have minimal two child, so find the last child, last child is sibling = first child
                node *last = root->child;

                while (last->sibling != root->child)
                {
                    last = last->sibling;
                }

                new->sibling = root->child;
                last->sibling = new;
            }
            //printf("halo ini add child\n");
        }
    }
}

//procedure to erase all child in root
void del_all(node *root)
{
    if (root != NULL)
    {
        //checking if node root is not null
        if (root->child != NULL)
        {
            //if parent just have 1 children
            if (root->child->sibling == NULL)
            {
                del_all(root->child);
                free(root);
            }
            else
            {
                node *help;
                node *proccess;
                help = root->child;
                
                while (help->sibling != root->child)
                {
                    proccess = help;
                    help = help->sibling;
                    del_all(proccess);
                }
                free(root);
            } 
        }
        else
        {
            //if dont have child just free parent node
            free(root);
        }
    }
}

void del_child(char name[], node *root)
{
    if (root != NULL)
    {
        node *erase = root->child;
        if (erase != NULL)
        {
            if (erase->sibling == NULL)
            {
                //if parent just have 1 child
                if (strcmp(root->child->kontainer.name, name) == 0)
                {
                    del_all(root->child);
                    root->child = NULL;
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
            else
            {
                //if have more than 1 child
                node *prev = NULL;

                int found = 0;
                while ((erase->sibling != root->child) && (found == 0))
                {
                    if (strcmp(erase->kontainer.name, name) == 0)
                    {
                        found = 1;
                    }
                    else
                    {
                        prev = erase;
                        erase = erase->sibling;
                    }
                }

                //proccess last node child because last child didnt procced in looping
                if ((found == 0) && (strcmp(erase->kontainer.name, name) == 0))
                {
                    found = 1;
                }
                if (found == 1)
                {
                    //find last node child for helping proccess or to check if erase element is last child
                    node *last = root->child;

                    while (last->sibling != root->child)
                    {
                        last = last->sibling;
                    }

                    //if erase node is first child
                    if (prev == NULL)
                    {
                        if ((erase->sibling == last) && (last->sibling == root->child))
                        {
                            // if just 2 child
                            root->child = last;
                            last->sibling = NULL;
                        }
                        else
                        {
                            // if have more than 2 child
                            root->child = erase->sibling;
                            last->sibling = root->child;
                        }
                    }
                    else
                    {
                        // if just have 2 child, and erase element is second child
                        if ((prev == root->child) && (last == erase))
                        {
                            root->child->sibling = NULL;
                        }
                        else
                        {
                            // if erase element not first child and root have more than 2 child
                            prev->sibling = erase->sibling;
                            erase->sibling = NULL;
                        }
                    }
                    del_all(erase);
                }
                else
                {
                    printf("tidak ada simpul anak dengan kontainer karakter masukan\n");
                }
            }
        }
    }
}

node* find_node(char name[], node *root)
{
    node *result = NULL;
    if (root != NULL)
    {
        if (strcmp(root->kontainer.name, name) == 0 )
        {
            result = root;
        }
        else
        {
            node *help = root->child;
            if (help != NULL)
            {
                // if just have 1 child
                if (help->sibling == NULL)
                {
                    if (strcmp(help->kontainer.name, name) == 0)
                    {
                        result = help;
                    }
                    else
                    {
                        result = find_node(name, help);
                    }
                }
                else
                {
                    // if have more than one child
                    int found = 0;
                    while ((help->sibling != root->child) && (found == 0))
                    {
                        if (strcmp(help->kontainer.name, name) == 0)
                        {
                            result = help;
                            found = 1;
                        }
                        else
                        {
                            result = find_node(name, help);
                            if (result != NULL)
                            {
                                found = 1;
                            }
                            help = help->sibling;
                        }
                    }

                    //proccess last child beause last child didnt procced in looping
                    if (found == 0)
                    {
                        if (strcmp(help->kontainer.name, name) == 0)
                        {
                            result = help;
                        }
                        else
                        {
                            result = find_node(name, help);
                        }
                    }
                }
            }
        }
    }
    
    return result;
}

void print_pre_order(node *root, int level)
{
    if (root != NULL)
    {
        for (int i = 0; i < level; i++)
        {
            printf("->");
        }
        printf("%s\n", root->kontainer.name);
        node *help = root->child;
        
        //level incrase
        level++;
        if (help != NULL)
        {
            if (help->sibling == NULL)
            {
                //if just have 1 child
                print_pre_order(help, level);
            }
            else
            {
                //if have more than 1 childe
                while (help->sibling != root->child)
                {
                    print_pre_order(help, level);
                    help = help->sibling;
                }

                //procced last node child
                print_pre_order(help, level);
            }
        }
    }
    else
    {
        printf("Tree Kosong\n");
    }
}


/* void print_sub(node *root, int space)
{
    if (root != NULL)
    {
        for (int i = 0; i < space; i++)
        {
            printf(" ");
        }

        printf("|%s - %d\n", root->kontainer.daerah, root->kontainer.korban);
            
        char str_korban[10];
        sprintf(str_korban, "%d", root->kontainer.korban);
        int len_daerah = strlen(root->kontainer.daerah);
        int len_korban = strlen(str_korban);

        space = space + len_daerah + len_korban + 4;

        node *help = root->child;

        if (help != NULL)
        {
            if (help->sibling == NULL)
            {
                //if just have 1 child
                print_sub(help, space);
            }
            else
            {
                //if have more than 1 childe
                while (help->sibling != root->child)
                {
                    print_sub(help, space);
                    help = help->sibling;
                }

                //procced last node child
                print_sub(help, space);
            }
        }
    }      
} */