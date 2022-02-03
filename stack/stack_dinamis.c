// Stack Dinamsi
/*
    mirip seperti list dinamis yaitu memiliki pointer next dan first,
    hanya saja first nya diganti top
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char nim[10];
    char nama[50];
    float nilai;
}nilai_matkul;

typedef struct elmt* alamat_elemen;     
typedef struct elmt
{
    nilai_matkul kontainer;
    alamat_elemen next;
}elemen;

typedef struct 
{
    elemen* top;
}stack;


void create_empty(stack *S){
    (*S).top = NULL;
}

/* Bisa dihilangin karena udah di wakilin sama fungsi count elemen */
// int is_empty(stack S){
//     int hasil = 0;
//     if (S.top == NULL)
//     {
//         hasil = 1;
//     }
//     return hasil;
// }

int count_elemen(stack S){
    int hasil = 0;

    if (S.top != NULL)
    {
        /* List tidak kosong */
        elemen* tunjuk;

        //inisialiasi
        tunjuk = S.top;

        while (tunjuk != NULL)
        {
            hasil = hasil + 1;

            //iterasi
            tunjuk = tunjuk->next;
        }   
    }
    return hasil;
}

void push(char nim[], char nama[], float nilai, stack *S){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nim, nim);
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.nilai = nilai;

    if ((*S).top == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*S).top;
    }
    (*S).top = baru;
    baru = NULL;
}

void pop(stack *S)
{
    
    if ((*S).top != NULL)     //jika list tidak kosong
    {
        elemen* hapus = (*S).top;     //pointer hapus menunjuk elemen pertama dari list
        if (count_elemen(*S) == 1)      //jika cuma 1 elemen saja
        {
            (*S).top = NULL;
        }
        else{

            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        free(hapus);        //prosedur melepaskan elemen dari memori yang ditunjuk pointer hapus
    }
    else
    {
        printf("stack kosong\n");
    }
}

void print_stack(stack S)
{
    if (S.top != NULL)    //jika list tidak kosong
    {
        printf("------- ISI STACK ------\n");
        //inisialisasi
        elemen* tunjuk = S.top;
        
        int i = count_elemen(S);
        while (tunjuk != NULL)      //perulangan selemen pointer tunjuk tidak bernilai null
        {
            printf("===============\n");
            printf("elemen ke : %d\n",i);
            printf("nim : %s\n",tunjuk->kontainer.nim);
            printf("nama : %s\n",tunjuk->kontainer.nama);
            printf("nilai : %0.2f\n",tunjuk->kontainer.nilai);
            //printf("--------------------------\n");

            tunjuk = tunjuk->next;
            i--;        
        }
    }
    else
    {
        printf("stack kosong\n");
    }
    
}

int main(){
    stack S;
    create_empty(&S);
    print_stack(S);

    printf("===============\n");
    push("2003623", "Nana", 64.75, &S);
    push("2003321", "Rudi", 75.11, &S);
    push("2003123", "Dea", 84.63, &S);
    print_stack(S);

    printf("===============\n");
    pop(&S);
    pop(&S);
    print_stack(S);

    printf("===============\n");
    return 0;
}