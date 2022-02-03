/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagain main
#include "headertp2.h"

int main(){
    list L;                 //deklarsi list
    create_list(&L);        //prosedur membuat listkosong

    //deklarasi array sementara untuk masukan
    int n = 0;

    char nama[50][50];       
    int harga[50];
    int kode[50];

    //perulangan masukan
    do
    {
        scanf("%s", nama[n]);
        if (strcmp(nama[n], "---") != 0)
        {
            scanf("%d %d", &harga[n], &kode[n]);
            add(nama[n], harga[n], kode[n], &L);
            n++;
        }
    }while (strcmp(nama[n], "---") != 0);

    char komponen[2];
    char methode[5];
    scanf("%s %s", komponen, methode);

    
    //cek data ganjil
    cek(&L);
    //sorting
    sort(komponen, methode, &L);
    print(L);

    return 0;
}

