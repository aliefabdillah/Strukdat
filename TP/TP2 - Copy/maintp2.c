
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
    
    cek(&L);
    sort(komponen, methode, &L);
    print(L);

    return 0;
}

/* 
Intel_Core_i9 8000000 6
AMD_Ryzen_7 6820000 8
Gigabyte_Aorus_Master 5650000 2
Asus_TUF_Gaming_Z490 3850000 2
---
K Asc 
*/

/* 
AMD_Ryzen_9 9800000 5431
Intel_Core_i9 7600000 1091
Gigabyte_Aorus_Master 5650000 5985
Asus_ROG_Maximus_XIII 7870000 2321
GeForce_RTX_3060 14000000 1923
EVGA_500B 817000 9981
---
K Desc 
*/