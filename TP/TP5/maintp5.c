#include "headtp5.h"

int main()
{
    int i,j;
    int len;    

    tree T;
    char query[15];
    char child[50];
    char parent_temp[50];
    char parent[50];

    int count_print = 0;
    int n = 0;

    do
    {
        scanf("%s", query);
        //if query not equal with DONE and PREORDER
        if ((strcmp(query, "DONE;") != 0) && (strcmp(query, "PREORDER;") != 0))
        {
            if (strcmp(query , "MAKETREE") == 0)
            {
                scanf("%s", parent_temp);
                //procces erase coma
                len = strlen(parent_temp);
                j = 0;
                for (i = 0; i < len -1; i++)
                {
                    parent[j]  = parent_temp[i] ;
                    j++;
                }
                parent[j]  = '\0';

                //proccess make new tree
                make_tree(parent, &T);
            }
            else if (strcmp(query , "CHILD") == 0)
            {
                scanf("%s", child);
                scanf("%s", parent_temp);

                //procces erase coma
                len  = strlen(parent_temp);
                j = 0;
                for (i = 0; i < len -1; i++)
                {
                    parent[j]  = parent_temp[i] ;
                    j++;
                }
                parent[j]  = '\0';
                
                //process add child in tree
                node* par = find_node(parent, T.root);
                if (par != NULL)
                {
                    add_child(child, par);
                }
            }
            else if (strcmp(query , "DELLCHILD") == 0)
            {
                scanf("%s", child);
                scanf("%s", parent_temp);

                //procces erase coma
                len  = strlen(parent_temp);
                j = 0;
                for (i = 0; i < len -1; i++)
                {
                    parent[j]  = parent_temp[i] ;
                    j++;
                }
                parent[j]  = '\0';
                
                // procces delete child in tree
                node* par = find_node(parent, T.root);
                if (par != NULL)
                {
                    del_child(child, par);
                }
            }
        }
        else
        {
            //if query is PREORDER
            if (strcmp(query , "PREORDER;") == 0)
            {
                int level = 0;
                count_print++;
                printf("Output %d:\n", count_print);
                printf("=========\n");
                print_pre_order(T.root, level);
            }
            //if query is DONE
            if (strcmp(query , "DONE;") == 0)
            {
                printf("=========\n");
            }
        }
    } while (strcmp(query , "DONE;") != 0);
    
    return 0;
    
}