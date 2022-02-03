/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis Gasta21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian main
#include "headergasta.h"
int main(){
    //masukan banyaknya elemen
    int n;
    scanf("%d", &n);
    
    //prosedur membuat list
    list L;
    create_list(n, &L);

    char kata[n][50];
    
    //masukan data ke dalam list
    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%s", kata[i]);
        add(n, kata[i], &L);
    }

    //print akhir
    print(n, L);
    
    return 0;
    
}