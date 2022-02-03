#include "headlistint.h"

int main(){
    list L;
    create(&L);

    int n;
    scanf("%d", &n);

    int inp[n];

    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &inp[i]);
        add_first(inp[i], &L);
    }

    print_element(L);

    return 0;
    
}