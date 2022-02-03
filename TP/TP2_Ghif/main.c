/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TP2           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main(){
    list L;
    int i, count = 0;
    char sortBy, sortMode[5];
    PCParts data[50];

    do  // input selama inputan string nama bukan '---'
    {
        scanf("%s", &data[count].name);
        if (strcmp(data[count].name, "---") != 0)
        {
            scanf("%d %d", &data[count].price, &data[count].productCode);
            count++;
        }
    } while (strcmp(data[count].name, "---") != 0);
    scanf(" %c %s", &sortBy, &sortMode); //sorting bedasarkan variabel apa dan asc / desc

    createList(&L); // buat list
    // proses memasukan data kedalam list
    addFirst(data[0].name, data[0].price, data[0].productCode, &L);
    for ( i = count-1; i > 0; i--)
    {
        addAfter(L.first, data[i].name, data[i].price, data[i].productCode, &L);
    }
    // proses memasukan data sementara untuk dijadikan acuan sorting
    int temp[count];
    for ( i = 0; i < count; i++)
    {
        if (sortBy == 'K')
        {
            temp[i] = data[i].productCode;
        }else
        {
            temp[i] = data[i].price;
        }
    }
    // sorting
    bubbleSort(&L, sortMode, temp, count, sortBy);
    // check produk orisinil
    checkingProduct(&L);
    // output
    printElement(L);
    
    return 0;
}