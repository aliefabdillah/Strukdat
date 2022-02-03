//bagian main

#include "headdinamis.h"

int main(){
    list L;                 //deklarsi list
    create_list(&L);        //prosedur membuat listkosong

    
    //deklarasi array sementara untuk masukan
    
    char nama[6][50];       
    char rumus[6][50];
    char kons[6][10];

    //perulangan masukan
    int i;
    for ( i = 0; i < 6; i++)
    {
        scanf("%s", nama[i]);
        scanf("%s", rumus[i]);
        scanf("%s", kons[i]);
    }

    // alur
    printf("======\n");

    //alur print pertama (add first index 0  dan add last index 1, dan addafter index 2)
    add_first(nama[0], rumus[0], kons[0], &L);
    add_last(nama[1], rumus[1], kons[1], &L);
    add_after(L.first->next, nama[2], rumus[2], kons[2]);
    print_elemen(L);
    

    //alur print kedua (del first index 0 , add last index 3, dan del after index 2)
    del_first(&L);
    add_last(nama[3], rumus[3], kons[3], &L);
    del_after(L.first->next, &L);
    print_elemen(L);
    
    
    //alur print ketiga (del last, add first index 4)
    del_last(&L);
    add_first(nama[4], rumus[4], kons[4], &L);
    print_elemen(L);
    

    //alur print keempat (del all)
    del_all(&L);
    print_elemen(L);
    

    //alur print kelima (add last index ke 5)
    add_last(nama[5], rumus[5], kons[5], &L);
    print_elemen(L);
    

    return 0;
    
}

/* 
AsamKlorida HCl 0.1
GaramDapur NaCl 0.3
KaliumHidroksida KOH 0.8
SodaApi NaOH 0.05
AsamSulfat H2SO4 1.0
CukaDapur CH3COOH 0.001
 */