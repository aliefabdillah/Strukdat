#include <stdio.h>
#include <string.h>

typedef struct {
    char nim[20];
    char nama[50];
    int priority;
} nilaiMatkul;

typedef struct {
    int first;
    int last;
    nilaiMatkul data[100];
} queue;

void createEmpty(queue *Q);
int isEmpty(queue Q);
int isFull(queue Q);
int countElement(queue Q);
void add(char nim[], char nama[], queue *Q);
void del(queue *Q1, queue *Q2);
void printQueue(queue Q, char Queue[]);
void addPriority(char nim[], char nama[], int priority, queue *Q);