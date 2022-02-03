/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UAS Pbbd21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

#include "headtreebin.h"

void make_tree(int number1, int number2, tree *T)
{
    simpul *new;
    new = (simpul*) malloc (sizeof (simpul));
    
    //input new elemen to root of tree
    new->number1 = number1;
    new->number2 = number2;
    new->right = NULL;
    new->left = NULL;
    (*T).root = new;            //root pointing to new element
    new = NULL;
}

//procedure add right
void add_right(int number1, int number2, simpul *root)
{
    //if node right of root is null
    if (root->right == NULL)
    {
        simpul *new;
        new = (simpul*) malloc (sizeof (simpul));
        
        //input new elemen to child of root
        new->number1 = number1;
        new->number2 = number2;
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
void add_left(int number1, int number2, simpul *root)
{
    //if node left of root is null
    if (root->left == NULL)
    {
        simpul *new;
        new = (simpul*) malloc (sizeof (simpul));

        //input new elemen to child of root
        new->number1 = number1;
        new->number2 = number2;
        new->right = NULL;
        new->left = NULL;
        root->left = new;
    }
    else
    {
        printf("sub root kiri sudah terisi\n");
    }
}

void operation(simpul *root)
{
    
    if (root != NULL && root->number1 > 1 && root->number2 > 1)
    {
        simpul *help = root;
        int number_left;
        int number_right;

        //add result of division operation to child
        //if number1 more than 1 and number 2 more than 1
        if (root->number2 > 1 && root->number1 > 1)
        {
            number_left = root->number1/2;
            add_left(number_left, root->number2, &(*root));
            number_right = root->number2/2;
            add_right(root->number1, number_right, &(*root));
        }
        
        //condition for recursive
        if (root->left->number1 > 1) 
        {
            if (root->right->number2 > 1)
            {
                operation(root->left);
                operation(root->right);
            }
        }
    }
    
}

void print_tree(int spasi, simpul *root)
{
    if (root != NULL)
    {
        
        // print leaf in tree
        if ((root->left == NULL) || (root->right == NULL))
        {
            if (spasi == 0)
            {
                printf("%d %d", root->number1, root->number2);
            }
            else
            {
                printf(" ");
                printf("%d %d", root->number1, root->number2);
            }
        }
        print_tree(spasi++, root->left);
        print_tree(spasi++, root->right);
    }   
}