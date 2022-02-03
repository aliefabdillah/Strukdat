#include "header.h"

void createEmpty(queue *Q) {
    (*Q).first = -1;
    (*Q).last = -1;
}

int isEmpty(queue Q) {
    int hasil = 0;
    if(Q.first == -1) {
        hasil = 1;
    }
    return hasil;
}

int isFull(queue Q) {
    int hasil = 0;
    if(Q.last == 99) {
        hasil = 1;
    }
    return hasil;
}

int countElement(queue Q) {
    int hasil = 0;
    for(int i = Q.first; i <= Q.last; i++) {
        hasil++;
    }
    return hasil;
}

void add(char nim[], char nama[], queue *Q) {
    if(isEmpty(*Q) == 1) {
        (*Q).first = 0;
        (*Q).last = 0;
        strcpy((*Q).data[0].nim, nim);
        strcpy((*Q).data[0].nama, nama);
    } else {
        if(isFull(*Q) != 1) {
            (*Q).last++;
            strcpy((*Q).data[(*Q).last].nim, nim);
            strcpy((*Q).data[(*Q).last].nama, nama);
        } else {
            printf("queue penuh\n");
        }
    }
}

void addPriority(char nim[], char nama[], int priority, queue *Q) {
    if(isEmpty(*Q) == 1) {
        (*Q).first = 0;
        (*Q).last = 0;
        strcpy((*Q).data[0].nim, nim);
        strcpy((*Q).data[0].nama, nama);
        (*Q).data[0].priority = priority;
    } else {
        if(isFull(*Q) != 1) {
            if(priority > countElement(*Q)) {
                add(nim, nama, Q);
            } else {
                (*Q).last++;
                if(priority > 0) {
                    for(int i = (*Q).last - 1; i >= priority-1; i--) {
                        strcpy((*Q).data[i+1].nim, (*Q).data[i].nim);
                        strcpy((*Q).data[i+1].nama, (*Q).data[i].nama);
                    }
                    strcpy((*Q).data[priority-1].nim, nim);
                    strcpy((*Q).data[priority-1].nama, nama);
                    (*Q).data[priority-1].priority = priority;
                }
            }
        } else {
            printf("queue penuh\n");
        }
    }
}

void del(queue *Q1, queue *Q2) {
    add((*Q1).data[(*Q1).first].nim, (*Q1).data[(*Q1).first].nama, Q2);
    if((*Q1).last == 0) {
        (*Q1).first = -1;
        (*Q1).last = -1;
    } else {
        int i = 0;
        for(i = ((*Q1).first + 1); i <= (*Q1).last; i++) {
            strcpy((*Q1).data[i-1].nim, (*Q1).data[i].nim);
            strcpy((*Q1).data[i-1].nama, (*Q1).data[i].nama);
        }
        (*Q1).last--;
    }
}

void printQueue(queue Q, char Queue[]) {
    printf("******************\n");
    printf("Queue %s\n", Queue);
    if(Q.first != -1) {
        int i = 0;
        for(i = Q.first; i <= Q.last; i++) {
            printf("%s %s\n", Q.data[i].nama, Q.data[i].nim);
        }
    } else {
        printf("queue kosong\n");
    }
}