#include "head_statis.h"

int main(){
    //membuat queue
    queue Q1, Q2;
    create_empty(&Q1);
    create_empty(&Q2);

    //deklarasi masukan
    char nama[6][50];
    char nim[6][50];
    for (int i = 0; i < 6; i++)
    {
        scanf("%s", nama[i]);
        scanf("%s", nim[i]);
    }
    
    printf("******************\n");
    //prosedur add dan priority add sebelum print Q1 pertama
    add(nama[0], nim[0], &Q1);
    add(nama[1], nim[1], &Q1);
    prioriy_add(nama[2], nim[2], 2, &Q1);

    printf("Queue 1\n");
    print_queue(Q1);
    printf("******************\n");

    //prosedur out dan memasukan data ke Q2
    out(&Q1);
    add(nama[0], nim[0], &Q2);

    printf("Queue 1\n");
    print_queue(Q1);
    printf("******************\n");
    
    printf("Queue 2\n");
    print_queue(Q2);
    printf("******************\n");
    
    //prosedur priority add
    prioriy_add(nama[3], nim[3], 1, &Q1);
    prioriy_add(nama[4], nim[4], 99, &Q1);
    
    printf("Queue 1\n");
    print_queue(Q1);
    printf("******************\n");

    //prosedur out dari Q1 dan memasukan data ke Q2
    out(&Q1);
    add(nama[3], nim[3], &Q2);
    out(&Q1);
    add(nama[2], nim[2], &Q2);

    add(nama[5], nim[5], &Q1);
    
    printf("Queue 1\n");
    print_queue(Q1);
    printf("******************\n");
    
    printf("Queue 2\n");    
    print_queue(Q2);
    printf("******************\n");

    return 0;
    
}