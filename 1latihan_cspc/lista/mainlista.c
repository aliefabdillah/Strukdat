#include "headlista.h"

int main(){
    list L;
    create_list(&L);

    //jumlah masukan
    int i, n;
    scanf("%d", &n);

    char input[100];
    int total_huruf_a;
    for ( i = 0; i < n; i++)
    {
        scanf("%s", input);
        total_huruf_a = count_a(input);
        checking(input, total_huruf_a,  &L);
    }

    print_elemen(L);
    
    return 0;
}