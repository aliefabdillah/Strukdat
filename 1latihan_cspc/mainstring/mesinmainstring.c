//bagian mesin
#include "headmainstring.h"

int cari_a(int n, char kata[][50], int i){
    int panjang_kata = 0;
    int banyak_a = 0;

    while (kata[i][panjang_kata] != '\0')
    {
        if (kata[i][panjang_kata] == 'a')
        {
            banyak_a++;
        }
        panjang_kata++;
    }

    return banyak_a;
}

void sorting(int n, char kata[][50], int jumlah_a[]){

    int min;
    int sisip_a;
    char sisip_kata[50];

    for ( i = 0; i < n; i++)
    {
        min = i;
        for ( j = i+1; j < n; j++)
        {
            if (jumlah_a[min] > jumlah_a[j])
            {
                min = j;
            }
            
        }
        sisip_a = jumlah_a[i];
        jumlah_a[i] = jumlah_a[min];
        jumlah_a[min] = sisip_a;

        strcpy(sisip_kata, kata[i]); 
        strcpy(kata[i], kata[min]);
        strcpy(kata[min], sisip_kata);
    }
    
}