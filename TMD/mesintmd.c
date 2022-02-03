/* 
Saya Alief Muhammad Abdillah-2003623 mengerjakan evaluasi
Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecura ngan
seperti yang telah dispesifikasikan. Aamiin. 
*/

#include "headtmd.h"

//make new tree procedure
void make_tree(char daerah[], int korban, tree *T)
{
    node *new;
    new = (node *) malloc (sizeof (node));

    //input new data to element of tree
    strcpy(new->kontainer.daerah, daerah);
    new->kontainer.korban = korban;

    new->sibling = NULL;
    new->child = NULL;
    (*T).root = new;           //root pointing to new elemen
    new = NULL;
}

//add child procedure dan sorting
void add_child(char daerah[], int korban, node *root)
{
    //if root not null, add node child to root
    if (root != NULL)
    {
        node *new;
        new = (node *) malloc (sizeof (node));

        strcpy(new->kontainer.daerah, daerah);
        new->kontainer.korban = korban;

        new->child = NULL;

        //if root didnt have child, so new node become first child
        if (root->child == NULL)
        {
            new->sibling = NULL;
            root->child = new;
        }
        else
        {
            //if root have a child who didnt have sibling , so new node become second child
            if (root->child->sibling == NULL)
            {
                node* help = root->child;
                //if new if the number of victims is greater than the number of victims in the tree
                // add new child in first order
                if (help->kontainer.korban < new->kontainer.korban)
                {
                    help->sibling = new;
                    new->sibling = help;
                    root->child = new;
                }
                // add new child in second order
                else
                {
                    help->sibling = new;
                    new->sibling = help;
                }
            }
            else
            {
                //if parent have minimal two child, so find the last child, last child is sibling = first child
                node *ptr = root->child;
                node *prev = NULL;
                int found = 0;
                // looping until victim of new child greater than victim in tree
                while ((ptr->sibling != root->child) && (found == 0))
                {
                    if (ptr->kontainer.korban < new->kontainer.korban)
                    {
                        found = 1;
                    }
                    else
                    {
                        if (found == 1)
                        {
                            break;
                        }
                        prev = ptr;
                        ptr = ptr->sibling;
                    }
                }

                //if you don't find a smaller number of victims 
                if (found == 0)
                {
                    //add new child before last child
                    if (ptr->kontainer.korban < new->kontainer.korban)
                    {
                        prev->sibling = new;
                        new->sibling = ptr;
                    }
                    // add new child in last order
                    else
                    {
                        ptr->sibling = new;
                        new->sibling = root->child;
                    }
                }
                else
                {
                    //if find a smaller number of victims in first order
                    if (prev == NULL)
                    {
                        //find last child in tree
                        node *last = root->child;

                        while (last->sibling != root->child)
                        {
                            last = last->sibling;
                        }
                        
                        //add first new child
                        last->sibling = new;
                        new->sibling = ptr;
                        root->child = new;
                    }
                    else
                    {
                        //add after new child
                        prev->sibling = new;
                        new->sibling = ptr;
                    }
                }
            }
        }
    }
}

//find node procedure
node* find_node(char parent[], node *root)
{
    node *result = NULL;
    if (root != NULL)
    {
        if (strcmp(root->kontainer.daerah, parent) == 0)
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
                    if (strcmp(help->kontainer.daerah, parent) == 0)
                    {
                        result = help;
                    }
                    else
                    {
                        result = find_node(parent, help);
                    }
                }
                else
                {
                    // if have more than one child
                    int found = 0;
                    while ((help->sibling != root->child) && (found == 0))
                    {
                        if (strcmp(help->kontainer.daerah, parent) == 0)
                        {
                            result = help;
                            found = 1;
                        }
                        else
                        {
                            result = find_node(parent, help);
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
                        if (strcmp(help->kontainer.daerah, parent) == 0)
                        {
                            result = help;
                        }
                        else
                        {
                            result = find_node(parent, help);
                        }
                    }
                }
            }
        }
    }

    return result;
}

//conver string to int procedure
int string_to_int(char korban[]){

    int number = 0;
    int neg = korban[0] == '-';
    int i = neg ? 1 : 0;            //ternary operation
    while ( korban[i] >= '0' && korban[i] <= '9' )
    {
        number *= 10;               // multiply number by 10
        number += korban[i] - '0';  // convet ASCII '0'..'9' to digit 0..9 and add it to number           
        i++;                        
    }
    
    // if negative
    if (neg == 1)
    {
       number *= 0;
    }

    return number;
}

//accumulater all victim to parent procedure
int accumulate(node *root, int temp)
{
    if (root != NULL)
    {
        node *help = root->child;
        if (help != NULL)
        {
            if (help->sibling == NULL)
            {
                //if just have 1 child
                temp = help->kontainer.korban;
                temp = accumulate(help, temp);
                root->kontainer.korban = root->kontainer.korban + temp;
            }
            else
            {
                //if have more than 1 child
                while (help->sibling != root->child)
                {
                    temp = help->kontainer.korban;
                    temp = accumulate(help, temp);
                    root->kontainer.korban = root->kontainer.korban + temp;
                    help = help->sibling;
                }

                //procced last node child
                temp = help->kontainer.korban;
                temp = accumulate(help, temp);
                root->kontainer.korban = root->kontainer.korban + temp;
            }

        }
        
        return root->kontainer.korban;
    }
}

//print tree procedure
void print_tree(node *root, node *root2, int space, int level, char word, int count_sub)
{
    if (root != NULL)
    {
        node *ptr_temp = root2;     
        node* help = root->child;
        //if word = b / subtree
        if (word == 'b')
        {
            printf("\n");
            count_level(ptr_temp, 0, 0, word);      //count space per level
            //print space
            for (int i = 0; i < space; i++)
            {
                printf(" ");
            }
            //add spaces
            space = space + sub_layer[level];
            level++;        //incrase level
            level_temp += level;    //add level to level temp (variable is )
            //This variable is used to delete the contents of the sub layer variables during the next iteration

            printf("|%s - %d\n", root->kontainer.daerah, root->kontainer.korban);
        }
        //if word = a / all tree
        else
        {
            printf("\n");
            count_level(ptr_temp, 0, 0, word);      //count space per level
            for (int i = 0; i < space; i++)
            {
                printf(" ");
            }
            space = space + layer[level];
            level++;

            printf("|%s - %d\n", root->kontainer.daerah, root->kontainer.korban);
        }
        
        //pre order print procedure
        if (help != NULL)
        {
            if (help->sibling == NULL)
            {
                //if just have 1 child
                print_tree(help, ptr_temp, space, level, word, count_sub);
            }
            else
            {
                    //if have more than 1 child
                while (help->sibling != root->child)
                {
                    print_tree(help, ptr_temp, space, level, word, count_sub);
                    help = help->sibling;
                }

                 //procced last node child
                print_tree(help, ptr_temp, space, level, word, count_sub);
            }
        }
    }
    else
    {
        printf("tree kosong\n");
    }
}

void count_level(node *root, int level, int total_space, char word)
{    
    if(root != NULL)
    {
        //calculate the length of each string of names and victims
        int temp;
        char str_korban[10];
        sprintf(str_korban, "%d", root->kontainer.korban);
        int len_daerah = strlen(root->kontainer.daerah);
        int len_korban = strlen(str_korban);
        temp = len_daerah + len_korban + 4;

        //if word = a / all tree
        if (word == 'a')
        {
            if (temp > layer[level])
            {
                layer[level] = temp;    //input temp to layer
            }
        }
        else
        {
            if (temp > sub_layer[level])
            {
                sub_layer[level] = temp;    //input temp to sub_layer
            }
        }
        

        level++;        //level incrase

        //count space in every root procedure
        node *ptr_space = root->child;
        if(ptr_space != NULL)
        {
            if(ptr_space->sibling == NULL)
            {
                count_level(ptr_space, level, total_space, word);
            }else
            {
                while(ptr_space->sibling != root->child)
                {
                    count_level(ptr_space, level, total_space, word);
                    ptr_space = ptr_space->sibling;
                }
                count_level(ptr_space, level, total_space, word);
            }
        }
    }   
}
