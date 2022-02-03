#include "headsimque_statis.h"

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
    if (Q.last == 5)          //jika statis ini bisa ganti-ganti sesuai spesifikasi yang diminta
    {
        hasil = 1;
    }
    return hasil;
}

void add(char nama[], char nim[], queue *Q){
    if (is_empty(*Q) == 1)
    {
        //jika queue kosong
        (*Q).first = 0;
        (*Q).last = 0;


        strcpy((*Q).data[0].nama, nama);
        strcpy((*Q).data[0].nim, nim);
    }
    else
    {
        // jika queue tidak penuh
        if (is_full(*Q) != 1)
        {
            /* selama queue tidak penuh */
            (*Q).last++;

            strcpy((*Q).data[(*Q).last].nama, nama);
            strcpy((*Q).data[(*Q).last].nim, nim);
        }
        else
        {
            printf("queue penuh\n");
        }
    }
}

void out(queue *Q)
{
    
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
            strcpy((*Q).data[i-1].nama, (*Q).data[i].nama);
            strcpy((*Q).data[i-1].nim, (*Q).data[i].nim);
        }
        (*Q).last--;
    }
}

void prioriy_add(char nama[], char nim[], int priority, queue *Q)
{
    if (is_empty(*Q) == 1)
    {
        add(nama, nim, Q);
    }
    else
    {
        if (priority-1 > (*Q).last)
        {
            add(nama, nim, Q);
        }
        else
        {
            for (int i = (*Q).last; i >= priority-1; i--)
            {
                strcpy((*Q).data[i+1].nama, (*Q).data[i].nama);
                strcpy((*Q).data[i+1].nim, (*Q).data[i].nim);
            }
            (*Q).last++;

            strcpy((*Q).data[priority-1].nama, nama);
            strcpy((*Q).data[priority-1].nim, nim);

        }
    }
}

void print_queue(queue Q)
{
    if (Q.first != -1)
    {
        int i;
        //di print dari urutan elemen paling awal
        for ( i = Q.last; i >= Q.first; i--)
        {
            printf("%s ", Q.data[i].nama);
            printf("%s\n", Q.data[i].nim);
        }
    }
    else
    {
        //jika queue kosong
        printf("queue kosong\n");
    }
}