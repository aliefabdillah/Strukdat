#include "headsh2.h"

int main(){
    int i;
    char stack1[10];
    scanf("%s", stack1);
    
    stack S1;
    create_empty(&S1);
    int n;
    scanf("%d", &n);

    float float1[n];
    for ( i = 0; i < n; i++)
    {
        scanf("%f", &float1[i]);
    }

    for ( i = n-1; i >= 0; i--)
    {
        push(float1[i], &S1);
    }
    
    ///////////////////////////////

    char stack2[10];
    scanf("%s", stack2);
    
    stack S2;
    create_empty(&S2);
    int m;
    scanf("%d", &m);

    float float2[m];
    for ( i = 0; i < m; i++)
    {
        scanf("%f", &float2[i]);
    }

    for ( i = m-1; i >= 0; i--)
    {
        push(float2[i], &S2);
    }


    checking(S1, S2);
    
    return 0;
}
