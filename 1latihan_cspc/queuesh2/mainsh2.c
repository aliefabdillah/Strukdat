#include "headsh2.h"

int main(){

    
    scanf("%d", &time);

    char queue1[2];
    scanf("%s", queue1);
    queue Q1;
    create_empty(&Q1);

    int n;
    scanf("%d", &n);

    int waktu;
    char nama[50];
    for (int i = 0; i < n ;i++)
    {
        scanf("%d", &waktu);
        scanf("%s", nama);
        add(waktu, nama, &Q1);
    }
    
    ////////////////////////////

    char queue2[2];
    scanf("%s", queue2);
    queue Q2;
    create_empty(&Q2);

    int m;
    scanf("%d", &m);

    int waktu2;
    char nama2[50];
    for (int i = 0; i < m ;i++)
    {
        scanf("%d", &waktu2);
        scanf("%s", nama2);
        add(waktu2, nama2, &Q2);
    }

    ////////////////////////////////
    
    char queue3[2];
    scanf("%s", queue3);
    queue Q3;
    create_empty(&Q3);

    int o;
    scanf("%d", &o);

    int waktu3;
    char nama3[50];
    for (int i = 0; i < o ;i++)
    {
        scanf("%d", &waktu3);
        scanf("%s", nama3);
        add(waktu3, nama3, &Q3);
    }

    checking(time, Q1);
    checking(time, Q2);
    checking(time, Q3);
    //print_queue(Q2);

    return 0;
    
}