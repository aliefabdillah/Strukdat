/* 
Saya Alief Muhammad Abdillah-2003623 mengerjakan evaluasi
Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecura ngan
seperti yang telah dispesifikasikan. Aamiin. 
*/

#include "headtmd.h"


int main()
{
    int n,m;    // variabel jumlah masukan
    int i,j;    // iterator

    // Deklarasi Tree
    tree T;

    // Deklarasi Variabel
    char input[100];
    char wilayah[50], ortu[50];
    char temp_wilayah[50], temp_korban[100], temp_ortu[50];
    int korban;
    
    scanf("%d", &n);    // Meminta user untuk memasukan jumlah masukan
    
    // Perulangan selama i lebih kecil dari jumlah masukan
    for (i = 0; i < n; i++)
    {
        scanf("%s", input);

        // Deklarasi Variabel dan Inisialisasi
        int len = strlen(input);
        int x = 0;
        int status = 0;
        
        // Perulangan selama j lebih kecil dari jumlah panjang kata
        for (j = 0; j < len; j++)
        {
            // Jika status sama dengan 0
            if (status == 0)
            {
                // Jika input bukan "#"
                if (input[j] != '#')
                {
                    temp_ortu[x] = input[j];
                    x++;
                }
                // Jika input "#"
                else
                {
                    status = 1;
                }
            }
            // Jika status sama dengan 1
            else if (status == 1)
            {
                // Jika input bukan "#"
                if (input != "#")
                {
                    temp_wilayah[x] = input[j];
                    x++;
                }
                // Jika input "#"
                else
                {
                    status = 2;
                    
                }
            }
            // Jika status sama dengan 2
            else if (status == 2)
            {
                temp_korban[x] = input[j];
                x++;
            }
            // Jika tidak

                // Jika status sama dengan 1
                if (status == 1)
                {
                    temp_ortu[x] = '\0';
                    strcpy(ortu, temp_ortu);
                    x = 0;
                }
                else if (status == 2)
                {
                    temp_wilayah[x] = '\0';
                    strcpy(wilayah, temp_wilayah);
                    x = 0;
                }
                
        }
        temp_korban[x] = '\0';
        korban = atoi(temp_korban);

        // Jika ortu sama dengan null
        if (strcmp(ortu, "null") == 0)
        {
            makeTree(wilayah, korban, &T);
        }
        else
        {
            simpul *orTu = findSimpul(ortu, T.root);
            if (orTu != NULL)
            {
                addChild(wilayah, korban, orTu);
            }
        }
    }

    scanf("%d", &m);
    char input2[100][100];

    for (i = 0; i < m; i++)
    {
        scanf("%s", input2[i]);
    }

    printf("pohon lengkap:\n");
    printTree(T.root, 0);
    printf("Sub-pohon:\n");
    for (i = 0; i < m; i++)
    {
        simpul *orTu = findSimpul(input2[i], T.root);
        
        printTree(orTu, 0); 
    }
    
    return 0;
}