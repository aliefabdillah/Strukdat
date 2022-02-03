/* Saya [Muhammad Satria Ramadhani - 2005128] mengerjakan evaluasi Kuis 01
[cksg21] dalam mata kuliah [Struktur Data] untuk keberkahan-Nya, maka saya
tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

#include "header.h"

int main()
{
    // Deklarasi variabel perulangan dan masukan.
    int i,
        n1, n2, m;
    char input1[52], input2[52];

    // Deklarasi list dan masukan data.
    list L1; list L2; value data;
    createlist(&L1); createlist(&L2);

    // Menerima masukan jumlah juga menu pertama, lalu menambahkannya ke list.
    scanf("%d", &n1);
    for(i = 0; i < n1; i++)
    {
        scanf("%s %d", &data.name, &data.price);
        addlast(data, &L1);
    }

    // Menerima masukan jumlah juga menu kedua, lalu menambahkannya ke list.
    scanf("%d", &n2);
    for(i = 0; i < n2; i++)
    {
        scanf("%s %d", &data.name, &data.price);
        addlast(data, &L2);
    }

    // Menerima data pindahan. Segera setelah dimasukkan, data dipindahkan.
    scanf("%d", &m);
    for(i = 0; i < m; i++)
    {
        scanf("%s %s", &input1, &input2);
        moveelement(&L1, &L2, input1);
        moveelement(&L1, &L2, input2);
    }

    // Keluaran menu pertama.
    printf("menu warung pertama:\n");
    printelement(L1);

    // Keluaran menu kedua.
    printf("\n");
    printf("menu warung kedua:\n");
    printelement(L2);

    return 0;
}