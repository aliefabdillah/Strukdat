#include "headnary.h"

int main()
{
    masukan input[9];

    for (int i = 0; i < 9; i++)
    {
        scanf("%s", input[i].nama);
        scanf("%d", &input[i].nilai);
    }

    // step 1
    tree T;
    printf("Step 1:\n");
    printf("================\n");
    make_tree(input[0], &T);
    add_child(input[1], T.root);
    add_child(input[2], T.root);
    add_child(input[3], T.root);
    add_child(input[4], T.root->child);
    add_child(input[5], T.root->child);
    print_pre_order(T.root);
    printf("\n");
    del_child(T.root->child->child->sibling, T.root->child);
    print_pre_order(T.root);
    printf("\n");
    add_child(input[6], T.root->child->sibling);
    add_child(input[7], T.root->child->sibling);
    add_child(input[8], T.root->child->sibling->sibling);
    print_pre_order(T.root);
    printf("\n");

    // step 2
    printf("Step 2:\n");
    printf("================\n");
    tree T2;
    copy_tree(T.root, &T2.root);
    if (is_equal(T.root, T2.root) == 0)
    {
        printf("Sama\n");
    }
    else
    {
        printf("Tidak sama\n");
    }

    // step 3
    printf("Step 3:\n");
    printf("================\n");
    node *result;
    // a
    result = find_node(input[7], T.root->child->child);
    if (result != NULL)
    {
        printf("%s ditemukan\n", input[7].nama);
    }
    else
    {
        printf("%s tidak ditemukan\n", input[7].nama);
    }
    
    // b
    result = find_node(input[7], T.root->child->sibling);
    if (result != NULL)
    {
        printf("%s ditemukan\n", input[7].nama);
    }
    else
    {
        printf("%s tidak ditemukan\n", input[7].nama);
    }
    
    // c
    result = find_node(input[7], T.root);
    if (result != NULL)
    {
        printf("%s ditemukan\n", input[7].nama);
    }
    else
    {
        printf("%s tidak ditemukan\n", input[7].nama);
    }
    
    return 0;
}