/* 
    - Konsep strukdat dengan mekanisme FIFO : First in First Out
    - ada prosedur del dimana elemen keluar dari depan dan ada add masuk dari depan
    - ada 2 pointer first dan last dmana first ada di belakagn dan last ada di depan (kebalikan)
 */

// kode progam  queue statis

//deklarasi
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
    int first;
    int last;
    nilai_matkul data[10];
}queue;


void create_empty(queue *Q){
    (*Q).first = -1;
    (*Q).last = -1;
}

int is_empty(queue Q){
    int hasil = 0;
    if (Q.first == -1)
    {
        hasil = 1;
    }
    return hasil;
}

int is_full(queue Q){
    int hasil = 0;
    if (Q.last == 9)          //jika statis ini bisa ganti-ganti sesuai spesifikasi yang diminta
    {
        hasil = 1;
    }
    return hasil;
}

//ditambahkan dibelakang
void add(char nim[], char nama[], float nilai, queue *Q){
    if (is_empty(*Q) == 1)
    {
        //jika queue kosong
        (*Q).first = 0;
        (*Q).last = 0;

        strcpy((*Q).data[0].nim, nim);
        strcpy((*Q).data[0].nama, nama);
        (*Q).data[0].nilai = nilai;
    }
    else
    {
        // jika queue tidak penuh
        if (is_full(*Q) != 1)
        {
            /* selama queue tidak penuh */
            (*Q).last++;

            strcpy((*Q).data[(*Q).last].nim, nim);
            strcpy((*Q).data[(*Q).last].nama, nama);
            (*Q).data[(*Q).last].nilai = nilai;
        }
        else
        {
            printf("queue penuh\n");
        }
    }
}

void out(queue *Q){
    
    if ((*Q).last == 0)
    {
        //jika elemen didalam stack tinggal 1
        (*Q).first = -1;
        (*Q).last = -1;
    }
    else
    {
        //jika isi queue tidak sama dengan 1
        int i;
        for ( i = ((*Q).first+1); i <= (*Q).last; i++)
        {
            strcpy((*Q).data[i-1].nim, (*Q).data[i].nim);
            strcpy((*Q).data[i-1].nama, (*Q).data[i].nama);
            (*Q).data[i-1].nilai = (*Q).data[i].nilai;
        }
        (*Q).last--;
    }
}

void priority_add(char nim[], char nama[], float nilai, int priority, queue *Q){
    if (is_empty(*Q) == 1)
    {
        add(nim, nama, nilai, Q);
    }
    else
    {
        if (priority-1 > (*Q).last)
        {
            add(nim, nama, nilai, Q);
        }
        else
        {
            for (int i = (*Q).last; i >= priority-1; i--)
            {
                strcpy((*Q).data[i+1].nim, (*Q).data[i].nim);
                strcpy((*Q).data[i+1].nama, (*Q).data[i].nama);
                (*Q).data[i+1].nilai = (*Q).data[i].nilai;
            }
            (*Q).last++;

            strcpy((*Q).data[priority-1].nim, nim);
            strcpy((*Q).data[priority-1].nama, nama);
            (*Q).data[priority-1].nilai = nilai;


        }
    }
}

void print_queue(queue Q){
    if (Q.first != -1)
    {
        printf("------- ISI Queue ------\n");
        int i;
        //di print dari urutan elemen paling awal
        for ( i = Q.last; i >= Q.first; i--)
        {
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", Q.data[i].nim);
            printf("nama : %s\n", Q.data[i].nama);
            printf("nilai : %0.2f\n", Q.data[i].nilai);
            printf("--------------------------\n");
        }
    }
    else
    {
        //jika queue kosong
        printf("queue kosong\n");
    }
}

int main(){
    queue Q;
    create_empty(&Q);
    print_queue(Q);

    printf("===============\n");
    add("2003623", "Nana", 64.75, &Q);
    add("2003321", "Rudi", 75.11, &Q);
    add("2003123", "Dea", 84.63, &Q);
    print_queue(Q);

    printf("===============\n");
    out(&Q);
    out(&Q);
    print_queue(Q);

    printf("===============\n");
    return 0;
}