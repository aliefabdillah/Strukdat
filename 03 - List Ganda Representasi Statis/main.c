/* Saya [Muhammad Satria Ramadhani - 2005128] mengerjakan evaluasi Kuis 01
[gasta21] dalam mata kuliah [Struktur Data] untuk keberkahan-Nya, maka saya
tidak melakukan kecurangan seperti yang telah dispesifikasikan. Aamiin. */

// Deklarasi sumber global.
#include "header.h"

int main()
{
    // Deklarasi variabel perulangan dan jumlah string.
    int i, n;

    // Deklarasi masukan dan list.
    value data; list L;
    createlist(&L);

    // Menerima masukan string sesuai jumlahnya, lalu menambahkannya ke list.
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%s", data.str);
        addlast(data, &L);
    }

    // Menampilkan list menggunakan printelement yang sudah dimodifikasi.
    printelement(L);

    return 0;
}