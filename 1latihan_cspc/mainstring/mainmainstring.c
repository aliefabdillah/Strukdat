//bagian main
#include "headmainstring.h"

int main()
{
    int n;
    scanf("%d", &n);

    char kata[n][50];
    int jumlah_a[n];

    for ( i = 0; i < n; i++)
    {
        scanf("%s", kata[i]);
    }

    i = 0;
    while (i < n)
    {
        jumlah_a[i] = cari_a(n, kata, i);
        i++;
    }
    
    
    sorting(n, kata, jumlah_a);
    for ( i = 0; i < n; i++)
    {
        printf("%s\n", kata[i]);
    }
    
    return 0;
}