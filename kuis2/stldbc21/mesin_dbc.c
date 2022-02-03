#include "head_dbc.h"

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
    if (S.top == 50)          //jika statis ini bisa ganti-ganti sesuai spesifikasi yang diminta
    {
        hasil = 1;
    }
    return hasil;
}

void push(char nama[], char jenis[], stack *S){

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
            strcpy((*S).data[0].jenis, jenis);
        }
        else
        {
            //jika stack tidak kosong
            (*S).top++;
            strcpy((*S).data[(*S).top].nama, nama);
            strcpy((*S).data[(*S).top].jenis, jenis);
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

//prosedur ambil baju
// void ambil_baju(char ambil[], stack *S_real, stack *S_temp)
// {
//     //mencari elemen untuk batas pengambilan baju
//     int batas = -1;
//     for (int i = (*S_real).top; i >= 0; i--)
//     {
//         //jika nama yang diingin ada pada stack list
//         if (strcmp(ambil, (*S_real).data[i].nama) == 0)
//         {
//             batas = i;
//         }
//     }

//     //jika nama yang di minta ada pada list nama stack
//     if (batas != -1)
//     {
//         //perulangan sampai dengan batas ditemukan nama pengambil
//         for (int i = (*S_real).top; i >= batas; i--)
//         {
//             //mengahapus nama pengambil dari stack
//             if (strcmp(ambil, (*S_real).data[i].nama) == 0)
//             {
//                 (*S_real).top = (*S_real).top - 1;
//             }
//             //memindahkan nama yang bukan pengambil ke stack sementara
//             else
//             {
//                 push((*S_real).data[i].nama, (*S_real).data[i].jenis, S_temp);
//                 (*S_real).top = (*S_real).top - 1;
//             }
//         }
//     }
//     //jika nama yang di minta tidak ada pada stack utama
//     else
//     {
//         //pengecekan di stack temp
//         for (int i = (*S_temp).top; i >= 0; i--)
//         {
//             //jika nama yang di inginkan ada pada stack temp
//             if (strcmp(ambil, (*S_temp).data[i].nama) == 0)
//             {
//                 //jika nama pengambil ada di indeks top stack temp
//                 if (i == (*S_temp).top)
//                 {
//                     //maka langsung hapus nama pengambil dari stack sementara
//                     pop(S_temp);
//                 }
//                 else
//                 {
//                     char temp_nama[50];
//                     char temp_jenis[50];
//                     //jika tidak nama pengambil di hapus dengan cara menggeser data ke atas
//                     for (int j = i+1; j <= (*S_temp).top; j++)
//                     {
//                         strcpy(temp_nama, (*S_temp).data[j].nama);
//                         strcpy((*S_temp).data[j].nama, (*S_temp).data[j-1].nama);
//                         strcpy((*S_temp).data[j-1].nama, temp_nama);

//                         strcpy(temp_jenis, (*S_temp).data[j].jenis);
//                         strcpy((*S_temp).data[j].jenis, (*S_temp).data[j-1].jenis);
//                         strcpy((*S_temp).data[j-1].jenis, temp_jenis);
//                     }
                    
//                     pop(S_temp);
//                 }
                
//             }
//         }
//     }
    
// }

void print_stack(stack S){
    if (S.top != -1)
    {
        //di print dari urutan elemen paling atas
        int i;
        for ( i = S.top; i >= 0; i--)
        {
            printf("%s ", S.data[i].nama);
            printf("%s\n", S.data[i].jenis);
        }
    }
    else
    {
        //jika stack kosong
        printf("kosong\n");
    }
}