#include "headgandastatis.h"

int main(){
    list L;
    create_list(&L);

    //array penampung masukan
    char nama[6][50];
    char tipe[6][20];
    char jumlah[6][2];

    int i;
    for ( i = 0; i < 6; i++)
    {
        scanf("%s %s %s", nama[i], tipe[i], jumlah[i]);
    }
    
    add_first(nama[0], tipe[0], jumlah[0], &L);

    add_last(nama[1], tipe[1], jumlah[1], &L);

    add_after(L.first, nama[2], tipe[2], jumlah[2], &L);

    print_forward(L);

    del_after(L.data[L.first].next, &L);

    print_forward(L);

    add_after(L.data[L.first].next, nama[3], tipe[3], jumlah[3], &L);
    
    add_last(nama[4], tipe[4], jumlah[4], &L);

    del_first(&L);

    print_forward(L);

    add_first(nama[5], tipe[5], jumlah[5], &L);
    
    del_after(L.first, &L);

    print_reverse(L);

    del_all(&L);

    print_forward(L);
    
    return 0;
}

