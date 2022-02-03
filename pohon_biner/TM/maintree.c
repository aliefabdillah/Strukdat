#include "headtree.h"

int main()
{
    //input from user
    char alpha[14];
    for (int  i = 0; i < 14; i++)
    {
        scanf(" %c", &alpha[i]);
    }
    
    //input procces to tree
    tree T;
    make_tree(alpha[0], &T); 
	add_left(alpha[1], T.root);
	add_right(alpha[2], T.root);
	add_left(alpha[3], T.root->right);
	add_right(alpha[4], T.root->left);
	add_right(alpha[5], T.root->right);
	add_left(alpha[6], T.root->left->right);
	add_right(alpha[7], T.root->right->left);
	add_right(alpha[8], T.root->left->right);
	add_right(alpha[9], T.root->right->right);
	add_left(alpha[10], T.root->right->right);
	add_left(alpha[11], T.root->left->right->left);
	add_left(alpha[12], T.root->right->left->right);
	add_right(alpha[13], T.root->right->left->right);

    //procedur print pre order
    printf("Pre Order:\n");
	print_pre_order(T.root);

    del_left(T.root->left->right->left);
    //procedure print in order
    printf("In Order:\n");
	print_in_order(T.root);

    del_right(T.root->right->right);
    
    //procedure print post order
    printf("Post Order:\n");
	print_post_order(T.root);
    
    return 0;
}