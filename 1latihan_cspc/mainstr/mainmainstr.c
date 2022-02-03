#include "headmainstr.h"

int main(){
    list L;
    create(&L);

    int n;
    scanf("%d", &n);

    char inp[n][20];

    int i;
    for ( i = 0; i < n; i++)
    {
        scanf("%s", inp[i]);
    }

    cek_a(inp, n);
    
    for ( i = 0; i < n; i++)
    {
        add_first(inp[i], &L);
    }
    
    print_element(L);

    return 0;
    
}