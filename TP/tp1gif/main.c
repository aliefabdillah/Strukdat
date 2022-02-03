/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM1           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main(){
    list L;
    createList(&L); // membuat list
    int i = 0, money;
    char mode[5];
    
    menu data[100];
    scanf("%s %d %f", &data[i].name, &data[i].price, &data[i].rating);
    while (strcmp(data[i].name, "*") != 0)  // input selama tidak bertemu dengan *
    {
        i++;
        scanf("%s", &data[i].name);
        if (strcmp(data[i].name, "*") != 0) // jika input nama bukanlah *
        {
            scanf("%d %f", &data[i].price, &data[i].rating);
        }
    }
    scanf("%d %s", &money, &mode);

    // memasukan data ke dalam list
    addFirst(data[0].name, data[0].price, data[0].rating, &L);
    int count = i;
    for ( i = count-1; i > 0; i--)
    {
        addAfter(L.first, data[i].name, data[i].price, data[i].rating, &L);
    }

    // memasukan data rating ke dalam array sementara
    float temp[count];
    for ( i = 0; i < count; i++)
    {
        temp[i] = data[i].rating;
    }
    
    sortingList(mode, &L, temp, count); // list di sorting
    printElement(money, L); // output

    return 0;
}