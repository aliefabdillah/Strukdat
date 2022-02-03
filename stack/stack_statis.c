/* Materi Stack tumpukan Statits alokasi dinamis */

/* 
    tumpukan atau stack memiliki mekanisme LIFO (last in first out)
    dan memiliki elemen tunjuk top

    ada 2 mekanisme utama :
    1. Push
        - memasukan elemen ke dalam stack di posisi paling atas
        - dan merubah penunjuk top ke elemen baru
    2. Pop
        - penunjuk top diturunkan ke elemen bawahnya
        - elemen paling atas di keluarkan
 */

//kode progam stack representasi statis
#include <stdio.h>
#include <string.h>

typedef struct 
{
    char nim[10];
    char nama[50];
    float nilai;
}nilai_matkul;

typedef struct 
{
    int top;
    nilai_matkul data[10];          //isi data bisa bervariasi sesuai spesifikasi yanag diminta
}stack;

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

//proses memasukan elemen ke dalam stack dan mendorong pointer top ke atas
void push(char nim[], char nama[], float nilai, stack *S){

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
            strcpy((*S).data[0].nim, nim);
            strcpy((*S).data[0].nama, nama);
            (*S).data[0].nilai = nilai;
        }
        else
        {
            //jika stack tidak kosong
            (*S).top++;
            strcpy((*S).data[(*S).top].nim, nim);
            strcpy((*S).data[(*S).top].nama, nama);
            (*S).data[(*S).top].nilai = nilai;
        }
    }
}

//prosedur mengeluarkan elemen dari stack yang terakhir di masukan
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
        printf("------- ISI STACK ------\n");
        int i;
        //di print dari urutan elemen paling atas
        for ( i = S.top; i >= 0; i--)
        {
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", S.data[i].nim);
            printf("nama : %s\n", S.data[i].nama);
            printf("nilai : %0.2f\n", S.data[i].nilai);
            printf("--------------------------\n");
        }
    }
    else
    {
        //jika stack kosong
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
