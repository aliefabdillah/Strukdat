#include "headtree.h"

void make_tree(char alpha, tree *T)
{
    simpul *new;
    new = (simpul*) malloc (sizeof (simpul));
    
    //input new elemen to root of tree
    new->kontainer = alpha;
    new->right = NULL;
    new->left = NULL;
    (*T).root = new;            //root pointing to new element
    new = NULL;
}

//procedure add right
void add_right(char alpha, simpul *root)
{
    //if node right of root is null
    if (root->right == NULL)
    {
        simpul *new;
        new = (simpul*) malloc (sizeof (simpul));
        
        //input new elemen to child of root
        new->kontainer = alpha;
        new->right = NULL;
        new->left = NULL;
        root->right = new;
    }
    else
    {
        printf("sub root kanan sudah terisi\n");
    }
}

//procedure add left
void add_left(char alpha, simpul *root)
{
    //if node left of root is null
    if (root->left == NULL)
    {
        simpul *new;
        new = (simpul*) malloc (sizeof (simpul));

        //input new elemen to child of root
        new->kontainer = alpha;
        new->right = NULL;
        new->left = NULL;
        root->left = new;
    }
    else
    {
        printf("sub root kiri sudah terisi\n");
    }
}

//erase all of child
void del_all(simpul *root)
{
    if (root != NULL)
    {
        del_all(root->left);            //remove left child 
        del_all(root->right);           //remove right child
        free(root);     
    }
}

//remove right child from tree
void del_right(simpul *root)
{
    //if root not null
    if (root != NULL)
    {
        //if noode right from root is not null
        if (root->right != NULL)
        {
            //call recursive
            del_all(root->right);
            //  node right of root equal NULL
            root->right = NULL;

        }
        
    }
    
}

//remove left child from tree
void del_left(simpul *root)
{
    //if root not null
    if (root != NULL)
    {
        //if noode left from root is not null
        if (root->left != NULL)
        {
            //call recursive
            del_all(root->left);
            //  node right of root equal NULL
            root->left = NULL;

        }   
    }
}

//prrocedur pre order, in order, post order
void print_pre_order(simpul *root)
{
    if (root != NULL)
    {
        if (root->kontainer == 'A')
        {
            printf("%c ", root->kontainer);
        }
        else if (root->kontainer == 'J')
        {
            printf("- %c\n", root->kontainer);
        }
        else
        {
            printf("- %c ", root->kontainer);
        }
        print_pre_order(root->left);
        print_pre_order(root->right);
    }   
}


void print_in_order(simpul *root)
{
    if (root != NULL)
    {
        print_in_order(root->left);
        if (root->kontainer == 'B')
        {
            printf("%c ", root->kontainer);
        }
        else if (root->kontainer == 'J')
        {
            printf("- %c\n", root->kontainer);
        }
        else
        {
            printf("- %c ", root->kontainer);
        }
        print_in_order(root->right);
    }   
}

void print_post_order(simpul *root)
{
    if (root != NULL)
    {
        print_post_order(root->left);
        print_post_order(root->right);
        if (root->kontainer == 'G')
        {
            printf("%c ", root->kontainer);
        }
        else if (root->kontainer == 'A')
        {
            printf("- %c\n", root->kontainer);
        }
        else
        {
            printf("- %c ", root->kontainer);
        }
    }
}