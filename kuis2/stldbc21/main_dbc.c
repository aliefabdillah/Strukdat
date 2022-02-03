#include "head_dbc.h"

int main(){
    //deklarasi banyaknya stack
    int n;
    scanf("%d", &n);

    //deklarasi masukan
    int checking;
    char name[50];
    char type[50];

    //deklrasi stack dalam bentuk array
    stack S_real[n];
    stack S_temp[n];

    //masukan
    for (int i = 0; i < n; i++)
    {
        create_empty(&S_real[i]);
        scanf("%d", &checking);
        if (checking == 1)
        {
            scanf("%s", name);
            while (strcmp(name, "0") != 0)
            {
                scanf("%s", type);
                push(name, type, &S_real[i]);
                scanf("%s", name);
            }
        }
    }
    
    //masukan nama pengambil baju
    int m;
    scanf("%d", &m);
    char ambil[m][50];
    for (int i = 0; i < m; i++)
    {
        scanf("%s", ambil[i]);
    }

    // //prosedur ambil baju
    // for (int i = 0; i < n; i++)
    // {
    //     create_empty(&S_temp[i]);
    //     for (int j = 0; j < m; j++)
    //     {
            
    //         ambil_baju(ambil[j], &S_real[i], &S_temp[i]);
    //     }
    // }
    int count[n];
    for (int i = 0; i < n; i++)
    {
        count[i] = 0;
        for (int j = S_real[i].top; j >= 0; j--)
        {
            for (int k = 0; k < m; k++)
            {
                if (strcmp(S_real[i].data[j].nama, ambil[k]) == 0)
                {
                    count[i]++;
                }
            }
                
        }
    }


    for (int i = 0; i < n; i++)
    {
        create_empty(&S_temp[i]);
        int j = S_real[i].top;
        int batas = 0;
        while (j >= 0 && count[i] != batas)
        {
            int k = 0;
            int cek = 0;
            while (k < m && cek == 0)
            {
                if (strcmp(S_real[i].data[j].nama, ambil[k]) == 0)
                {
                    pop(&S_real[i]);
                    cek = 1;
                    batas++;

                }
                else
                {
                    k++;
                }
                
            }

            if (cek == 0)
            {
                push(S_real[i].data[j].nama, S_real[i].data[j].jenis, &S_temp[i]);
                pop(&S_real[i]);
            }
            
            j--;
        }
    }
    

    //prosedur print stack
    for (int i = 0; i < n; i++)
    {
        printf("stack %d:\n", i+1);
        print_stack(S_real[i]);
        printf("\n");
    }
    
    for (int i = n-1; i >= 0; i--)
    {
        printf("batas stack %d\n", i+1);
        print_stack(S_temp[i]);
    }
    
    return 0;
}