/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian main

#include "headtp1.h"

int main(){
    list L;                 //deklarsi list
    create_list(&L);        //prosedur membuat listkosong

    //deklarasi array sementara untuk masukan
    int n = 0;

    char nama[50][50];       
    int harga[50];
    float rate[50];

    //perulangan masukan
    do
    {
        scanf("%s", nama[n]);
        if (strcmp(nama[n], "*") != 0)
        {
            scanf("%d %f", &harga[n], &rate[n]);
            n++;
        }
    }while (strcmp(nama[n], "*") != 0);

    //proses memasukan list
    int i;
    for(i = 0 ; i < n ; i++)
    {
        add(nama[i], harga[i], rate[i], &L);
    }

    int money;
    scanf("%d", &money);

    char choose_sort[10];
    scanf("%s", choose_sort);

    sort(n, choose_sort, &L);       //prosedur sorting
    
    print_allmenu(L);           //menampilkan seluruh menu yang telah di sort
    print_buy(money, L);        //menampilkan makaann apa saja yang bisa dibeli
    
    return 0;
    
}


