#include "headkij.h"

void make_tree(int number, tree *T)
{
    simpul *new;
    new = (simpul*) malloc (sizeof (simpul));
    
    new->kontainer = number;
    new->right = NULL;
    new->left = NULL;
    new = NULL;
}

void add_right(int number, simpul *root)
{
    if (root->right == NULL)
    {
        simpul *new;
        new = (simpul*) malloc (sizeof (simpul));
        
        new->kontainer = number;
        new->right = NULL;
        new->left = NULL;
        root->right = new;
    }
    else
    {
        printf("sub root kanan sudah terisi");
    }
}

void add_left(int number, simpul *root)
{
    if (root->left == NULL)
    {
        simpul *new;
        new = (simpul*) malloc (sizeof (simpul));
        
        new->kontainer = number;
        new->right = NULL;
        new->left = NULL;
        root->left = new;
    }
    else
    {
        printf("sub root kiri sudah terisi");
    }
}

void input(int number, int parent, char direction, tree T)
{
    if (parent == 0)
    {
        make_tree(number, &T);
    }
    else
    {
        checking(number, parent, direction, T.root);
    }
    
    
}

void checking(int number, int parent, char direction, simpul *root)
{
    if (root != NULL)
    {
        if (root == parent)
        {
            if (strcmp(direction, "kanan") == 0)
            {
                add_right(number, &root);
            }
            else
            {
                add_left(number, &root);
            }
        }
        else
        {
            if (root->left != NULL)
            {
                checking(number, parent, direction, root->left);
            }
            
            if (root->right != NULL)
            {
                checking(number, parent, direction, root->right);
            }
        }
    }
}