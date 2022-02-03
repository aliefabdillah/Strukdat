#include "headlistmana.h"

int main(){
    list L;
    create_list(&L);

    //jumlah masukan
    int i, n;
    scanf("%d", &n);

    char input[100];
    for ( i = 0; i < n; i++)
    {
        scanf("%s", input);
        checking(input, &L);
    }

    print_elemen(L);
    
    return 0;
}