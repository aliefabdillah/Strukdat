/*Saya Alief Muhammad Abdillah 2003623 mengerjakan pbdd21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

#include "headtreebin.h"

int main()
{
    //make new tree
    tree T;

    int num1, num2;
    //input from user
    scanf("%d %d", &num1, &num2);
    make_tree(num1, num2, &T);

    //call function operation (divide the number and add to child)
    operation(T.root);
    print_tree(0, T.root);
    printf("\n");

    return 0;
}
