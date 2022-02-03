#include "head_statis.h"

int main(){
    int i;

    //membuat stak 1 dan 2
    stack S1, S2;
    create_empty(&S1);
    create_empty(&S2);

    //variabel masukan nama dan harga
    char nama[6][50];
    int harga[6];

    //proses input nama dan harga
    for ( i = 0; i < 6; i++)
    {
        scanf("%s", nama[i]);
        scanf("%d", &harga[i]);
    }
    
    //proses print stack S1 dan S2
    printf("S1:\n");
    print_stack(S1);
    printf("S2:\n");
    print_stack(S2);
    printf("==================\n");

    //proses 3 push pertama
    push(nama[0], harga[0], &S1);
    push(nama[1], harga[1], &S2);
    push(nama[2], harga[2], &S2);

    //proses print S1 dan S2
    printf("S1:\n");
    print_stack(S1);
    printf("S2:\n");
    print_stack(S2);
    printf("==================\n");

    //proses pop S1 dan Pop S2 dan masukan ke S1
    pop(&S1);
    pop(&S2);
    push(nama[2], harga[2], &S1);

    //proses 3 push selanjutnya
    push(nama[3], harga[3], &S1);
    push(nama[4], harga[4], &S2);
    push(nama[5], harga[5], &S1);

    //proses pop S2 dan proses pop S1 ke S2
    pop(&S2);
    pop(&S1);
    push(nama[5], harga[5], &S2);
    
    //print akhir stack
    printf("S1:\n");
    print_stack(S1);
    printf("S2:\n");
    print_stack(S2);
    printf("==================\n");

    return 0;
}