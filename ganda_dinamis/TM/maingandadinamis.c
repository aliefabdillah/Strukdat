#include "headgandadinamis.h"

int main(){
    list L;
    create_list(&L);

    //array penampung masukan
    char nama[6][50];
    char matkul[6][50];
    char nilai[6][2];

    int i;
    for ( i = 0; i < 6; i++)
    {
        scanf("%s %s %s", nama[i], matkul[i], nilai[i]);
    }

    //alur print pertama (add first index 0  dan addafter index 1, dan addbeforeindex 2)
    add_first(nama[0], matkul[0], nilai[0], &L);
    add_after(L.first, nama[1], matkul[1], nilai[1], &L);
    add_before(L.first->next, nama[2], matkul[2], nilai[2], &L);
    print_forward(L);
    

    //alur print kedua (del first index 2 , add last index 3)
    del_after(L.first->next->prev, &L);
    add_last(nama[3], matkul[3], nilai[3], &L);
    print_forward(L);
    
    
    //alur print ketiga (del first, add last index 4. add after index 5, del last)
    del_first(&L);
    add_last(nama[4], matkul[4], nilai[4], &L);
    add_after(L.first->next, nama[5], matkul[5], nilai[5], &L);
    del_last(&L);
    print_reverse(L);
    

    //alur print keempat (del all)
    del_all(&L);
    print_forward(L);
    
    return 0;
}

