#include "headnary.h"

//make new tree procedur
void make_tree(masukan input, tree *T)
{
    node *new;
    new = (node *) malloc (sizeof (node));

    //input new data to element of tree
    strcpy(new->kontainer.nama, input.nama);
    new->kontainer.nilai = input.nilai;
    new->sibling = NULL;
    new->child = NULL;
    (*T).root = new;           //root pointing to new elemen
    new = NULL;
    //printf("ini make tree\n");
}

void add_child(masukan input, node *root)
{
    //if root not null, add node child to root
    if (root != NULL)
    {
        node *new;
        new = (node *) malloc (sizeof (node));

        strcpy(new->kontainer.nama, input.nama);
        new->kontainer.nilai = input.nilai;
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

void del_child(node *nama, node *root)
{
    if (root != NULL)
    {
        node *erase = root->child;
        if (erase != NULL)
        {
            if (erase->sibling == NULL)
            {
                //if parent just have 1 child
                if (strcmp(root->child->kontainer.nama, nama->kontainer.nama) == 0)
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
                    if (strcmp(erase->kontainer.nama, nama->kontainer.nama) == 0)
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
                if ((found == 0) && (strcmp(erase->kontainer.nama, nama->kontainer.nama) == 0))
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
                        if ((prev == root->child) && (last->sibling == root->child))
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

//find node is equal with c
node* find_node(masukan input, node *root)
{
    node *result = NULL;
    if (root != NULL)
    {
        if (strcmp(root->kontainer.nama, input.nama) == 0)
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
                    if (strcmp(help->kontainer.nama, input.nama) == 0)
                    {
                        result = help;
                    }
                    else
                    {
                        result = find_node(input, help);
                    }
                }
                else
                {
                    // if have more than one child
                    int found = 0;
                    while ((help->sibling != root->child) && (found == 0))
                    {
                        if (strcmp(help->kontainer.nama, input.nama) == 0)
                        {
                            result = help;
                            found = 1;
                        }
                        else
                        {
                            result = find_node(input, help);
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
                        if (strcmp(help->kontainer.nama, input.nama) == 0)
                        {
                            result = help;
                        }
                        else
                        {
                            result = find_node(input, help);
                        }
                    }
                }
            }
        }
    }
    
    return result;
}

void print_pre_order(node *root)
{
    if (root != NULL)
    {

        printf("%s %d", root->kontainer.nama, root->kontainer.nilai);
        node *help = root->child;
        
        if (help != NULL)
        {
            if (help->sibling == NULL)
            {
                //if just have 1 child
                printf("-");
                print_pre_order(help);
            }
            else
            {
                //if have more than 1 childe
                while (help->sibling != root->child)
                {
                    printf("-");
                    print_pre_order(help);
                    help = help->sibling;
                }

                //procced last node child
                printf("-");
                print_pre_order(help);
            }
        }
    }
    else
    {
        printf("Tree Kosong");
    }

}

void copy_tree(node *root1, node **root2)
{
    if (root1 != NULL)
    {
        (*root2) = (node *) malloc (sizeof(node));
        (*root2)->kontainer = root1->kontainer;
        if (root1->sibling != NULL)
        {
            (*root2)->sibling = root1->sibling;
        }
        if (root1->child != NULL )
        {
            (*root2)->child = root1->child;        
        }
        

        // if root have child's
        if (root1->child != NULL)
        {
            if (root1->child->sibling == NULL)
            {
                // if just have 1 child
                copy_tree(root1->child, &(*root2)->child);
            }
            else
            {
                // if have more than 1 child
                node *help1 = root1->child;
                node *help2 = (*root2)->child;

                while (help1->sibling != root1->child)
                {
                    copy_tree(help1, &help2);
                    help2 = help2->sibling;
                    help1 = help1->sibling;
                }
                
                /* procced last node child */
                copy_tree(help1, &help2);

            }
        }
    }
    
}

int is_equal(node *root1, node *root2)
{
    int result = 1;
    if ((root1 != NULL) && (root2 != NULL))
    {
        if (root1->kontainer.nama != root2->kontainer.nama)
        {
            result = 0;
        }
        else
        {
            if ((root1->child != NULL) && (root2->child != NULL))
            {
                if (root1->child->sibling == NULL)
                {
                    result = is_equal(root1->child, root2->child);  
                }
                else
                {
                    // if have more than 1 child
                    node *help1 = root1->child;
                    node *help2 = root2->child;

                    while ((help1->sibling != root1->child) || (help2->sibling != root2->child))
                    {
                        if ((help1 != NULL) && (help2 != NULL))
                        {
                            result = is_equal(help1, help2);
                            if (result == 0)
                            {
                                break;
                            }
                            help1 = help1->sibling;
                            help2 = help2->sibling;
                        }
                        else
                        {
                            result = 0;
                            break;
                        }
                    }
                    
                    if (result != 0)
                    {
                        /* procced last node child */
                        result = is_equal(help1, help2);
                    }
                }  
            }
            else
            {
                result = is_equal(root1->child, root2->child);  
            } 
        }
    }
    else
    {
        if((root1 != NULL) || (root2 != NULL))
        {
            result = 0;
        }
    }
    
    return result;
    
}