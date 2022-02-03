/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan Kuis (gasta21)|
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

int main(){
    list L;
    int i, count;
    
    scanf("%d", &count);
    createList(&L, count);
    content arr[count];
    for ( i = 0; i < count; i++)
    {
        scanf("%s", &arr[i].str);
    }

    addFirst(arr[0].str, &L, count);
    for ( i = count - 1; i > 0; i--)
    {
        addAfter(L.first, arr[i].str, &L, count);
    }
    
    printElement(L, count);

    return 0;
}