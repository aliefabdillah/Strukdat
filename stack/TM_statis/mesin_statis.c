#include "head_statis.h"

void create_empty(stack *S){
    (*S).top = -1;
}

int is_empty(stack S){
    int hasil = 0;
    if (S.top == -1)
    {
        hasil = 1;
    }
    return hasil;
}

int is_full(stack S){
    int hasil = 0;
    if (S.top == 9)          //jika statis ini bisa ganti-ganti sesuai spesifikasi yang diminta
    {
        hasil = 1;
    }
    return hasil;
}

void push(char nama[], int harga, stack *S){

    if (is_full(*S) == 1)
    {
        //jika stack penuh
        printf("stack penuh\n");
    }
    else
    {
        if (is_empty(*S) == 1)
        {
            //joka stack kosong
            (*S).top = 0;
            strcpy((*S).data[0].nama, nama);
            (*S).data[0].harga = harga;
        }
        else
        {
            //jika stack tidak kosong
            (*S).top++;
            strcpy((*S).data[(*S).top].nama, nama);
            (*S).data[(*S).top].harga = harga;
        }
    }
}

void pop(stack *S){
    
    if ((*S).top == 0)
    {
        //jika elemen didalam stack tinggal 1
        (*S).top = -1;
    }
    else
    {
        if ((*S).top != -1)
        {
            //jika stack masih memilik elemen lebih dari 1
            (*S).top = (*S).top - 1;
        }
    }
}

void print_stack(stack S){
    if (S.top != -1)
    {
        //di print dari urutan elemen paling atas
        int i;
        int n = 1;
        for ( i = S.top; i >= 0; i--)
        {
            printf("%d. %s\n", n, S.data[i].nama);
            n++;
        }
    }
    else
    {
        //jika stack kosong
        printf("- Stack Kosong\n");
    }
}