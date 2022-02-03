/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis Cksg21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian main
#include "headercksg.h"

int main(){
    //membuat list 1 dan list 2
    list L_1;
    create_list(&L_1);
    list L_2;
    create_list(&L_2);

    int i, n, m, o;

    //masukan list 1
    scanf("%d", &n);
    char nama[n][50];
    int harga[n];
    for ( i = 0; i < n; i++)
    {
        scanf("%s %d", nama[i], &harga[i]);
        add_last(nama[i], harga[i], &L_1);
    }

    //masukan list 2
    scanf("%d", &m);
    char nama2[m][50];
    int harga2[m];
    for ( i = 0; i < m; i++)
    {
        scanf("%s %d", nama2[i], &harga2[i]);
        add_last(nama2[i], harga2[i], &L_2);
    }
    
    //masukan data yang ingin ditukar
    scanf("%d", &o);
    char tukar_1[o][50];
    char tukar_2[o][50];
    for ( i = 0; i < o; i++)
    {
        scanf("%s %s", tukar_1[i], tukar_2[i]);
    }

    //proses tukar
    for ( i = 0; i < o; i++)
    {
        swap(tukar_1[i], tukar_2[i], &L_1, &L_2);
    }
    
    //print akhir
    printf("menu warung pertama:\n");
    print_elemen(L_1);
    printf("\nmenu warung kedua:\n");
    print_elemen(L_2);

    return 0;
}