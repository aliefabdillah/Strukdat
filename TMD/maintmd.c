/* 
Saya Alief Muhammad Abdillah-2003623 mengerjakan evaluasi
Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecura ngan
seperti yang telah dispesifikasikan. Aamiin. 
*/

#include "headtmd.h"

int main()
{
    int i,j;
    tree T;     //tree declaration

    int n;
    scanf("%d", &n);        //total input user
    char input[100];        //temporary variable for collect user input 

    //temporary variable to separate string from the input variable
    char temp_parent[50];
    char temp_daerah[50];
    char temp_korban[10];

    //main variable for input to tree
    char parent[50];
    char daerah[50];
    int korban;

    for ( i = 0; i < n; i++)
    {
        scanf("%s", input);
        int len = strlen(input);
        int k = 0;
        int count = 0;
        //procces for split the string into parts
        for ( j = 0; j < len; j++)
        {
            // if find #
            if (input[j] != '#')
            {
                if (count == 0)
                {
                    temp_parent[k] = input[j];
                    k++;
                }
                else if (count == 1)
                {
                    temp_daerah[k] = input[j];
                    k++;
                }
                else
                {
                    temp_korban[k] = input[j];
                    k++;
                }
            }
            else
            {
                
                count++;
                //checkk parent
                if (count == 1)
                {
                    temp_parent[k] = '\0';
                    strcpy(parent, temp_parent);
                }
                else if(count == 2)
                {
                    temp_daerah[k] = '\0';
                    strcpy(daerah, temp_daerah);
                }
                k = 0;
            }
        }
        temp_korban[k] = '\0';
        korban = string_to_int(temp_korban);    //conver string into interger

        //if input parent null
        if (strcmp(parent, "null") == 0)
        {
            //use make tree procedure
            make_tree(daerah, korban, &T);   
        }
        else
        {
            //use add child procedure
            node *par = find_node(parent, T.root);
            if (par != NULL)
            {
                add_child(daerah, korban, par);   
            }
        }
    }

    //sub tree input from user
    int m;
    scanf("%d", &m);
    char sub_tree[50][50];
    for ( i = 0; i < m; i++)
    {
        scanf("%s", sub_tree[i]);
    }

    //accumulate victim
    accumulate(T.root, 0);
    
    //print all tree
    printf("pohon lengkap:\n");
    print_tree(T.root, T.root, 0, 0, 'a', 0);

    //print sub tree
    level_temp = 0;         //set temporary level variable to 0
    printf("\nSub-pohon:\n");
    for ( i = 0; i < m; i++)
    {
        node *par = find_node(sub_tree[i], T.root);
        if (par != NULL)
        {   
            //if iteration not equal  0
            if (i != 0)
            {
                //set sub_layer to 0
                for (int j = 0; j < level_temp; j++)
                {
                    sub_layer[j] = 0;
                }   
            }
            print_tree(par, par, 0, 0, 'b', i);  
        }
        else
        {
            printf("tidak ada sub pohon dengan nama tersebut\n");
        }
    }

    return 0;
}