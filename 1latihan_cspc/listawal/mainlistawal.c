#include "headlistawal.h"

int main(){
    list L;
    create_list(&L);

    //jumlah masukan
    int i, n;
    scanf("%d", &n);

    int input;
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &input);
        checking(input, &L);
    }

    print_elemen(L);

    return 0;
}