// bagian main

#include "headstatis.h"

int main()
{   
    /* deklarasi List */
    list L;
    create_list(&L);        //membuat list kosong

    /* Variabel masukan */
    char merek[50];
    char warna[20];
    int ukuran;

    /* proses masukan user pertama dan add first */
    scanf("%s", merek); scanf("%s", warna); scanf("%d", &ukuran);
    add_first(merek, warna, ukuran, &L);

    /* proses masukan user kedua dan add first kedua */
    scanf("%s", merek); scanf("%s", warna); scanf("%d", &ukuran);
    add_first(merek, warna, ukuran, &L);    
    
    /* proses masukan user ketiga dan add last */
    scanf("%s", merek); scanf("%s", warna); scanf("%d", &ukuran);
    add_last(merek, warna, ukuran, &L);

    /* print elemen*/
    cetak_element(L);
    printf("========\n");

    /* proses del last*/
    del_last(&L);
    
    /* proses masukan user keempat dan add last */
    scanf("%s", merek); scanf("%s", warna); scanf("%d", &ukuran);
    add_last(merek, warna, ukuran, &L);
        
    /* proses masukan user kelima dan add after L.first */
    scanf("%s", merek); scanf("%s", warna); scanf("%d", &ukuran);
    add_after(L.first, merek, warna, ukuran, &L);

    /* proses del first */
    del_first(&L);

    /* print elemen*/
    cetak_element(L);
    printf("========\n");
    
    /* proses masukan user keenam dan add after L.data[L.first].next */
    scanf("%s", merek); scanf("%s", warna); scanf("%d", &ukuran);
    add_after(L.data[L.first].next, merek, warna, ukuran, &L);
    
    /* proses del after L.First */
    del_after(L.first, &L);

    /* print elemen*/
    cetak_element(L);
    printf("========\n");

    /* proses del all */
    del_all(&L);

    /* print elemen*/
    cetak_element(L);
    printf("========\n");

    return 0;
}

/* 
Adidas Putih 39
Converse Hitam 41
Vans Kuning 36
Puma Hitam 40
Ventela Biru 38
Aerostreet Abu 40
 */