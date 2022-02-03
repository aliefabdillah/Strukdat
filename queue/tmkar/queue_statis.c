#include "header.h"

int main() {
    queue Q1, Q2;
    createEmpty(&Q1);
    createEmpty(&Q2);
    char nim[20], nama[50];
    int priority = 1;
    scanf("%s%s", nama, nim);
    add(nim, nama, &Q1);
    scanf("%s%s", nama, nim);
    add(nim, nama, &Q1);
    scanf("%s%s", nama, nim);
    addPriority(nim, nama, 2, &Q1);
    printQueue(Q1, "Q1");
    del(&Q1, &Q2);
    printQueue(Q1, "Q1");
    printQueue(Q2, "Q2");
    scanf("%s%s", nama, nim);
    addPriority(nim, nama, 1, &Q1);
    scanf("%s%s", nama, nim);
    addPriority(nim, nama, 99, &Q1);
    printQueue(Q1, "Q1");
    del(&Q1, &Q2);
    del(&Q1, &Q2);
    scanf("%s%s", nama, nim);
    add(nim, nama, &Q1);
    printQueue(Q1, "Q1");
    printQueue(Q2, "Q2");
    printf("******************\n");
    return 0;
}