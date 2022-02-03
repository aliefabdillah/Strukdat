#include "headlistflot.h"

int main(){
    list L;
    create(&L);

    int n;
    scanf("%d", &n);

    float inp[n];

    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%f", &inp[i]);
        add_first(inp[i], &L);
    }

    print_element(L);

    return 0;
    
}