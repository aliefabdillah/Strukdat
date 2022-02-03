#include "headmainflot.h"

int main(){
    list L;
    create(&L);

    int n;
    scanf("%d", &n);

    float inp[n];
    float sel[n];
    int satuan[n];

    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%f", &inp[i]);
        satuan[i] = inp[i];
        sel[i] = inp[i] - satuan[i];
    }

    sort(sel, inp, n);
    
    for ( i = 0; i < n; i++)
    {
        add_first(inp[i], &L);
    }
    
    print_element(L);

    return 0;
    
}