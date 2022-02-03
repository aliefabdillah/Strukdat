#include <stdio.h>
#include <string.h>

int n;
typedef struct 
{
    float angka;
}nilai;

typedef struct 
{
    nilai kontainer;
    int next; 
}elemen;

typedef struct 
{
    int first;
    elemen data[10];
}list;

void create(list *L)
{
    int i;
    (*L).first = -1;

    for ( i = 0; i < n; i++)
    {
        (*L).data[i].next = -2;
    }
}

int hitung_elemen(list L)
{
    int hasil = 0;
    if (L.first != -1)
    {
        int hitung;
        hitung = L.first;

        while (hitung != -1)
        {
            hasil++;
            hitung = L.data[hitung].next;
        }
    }

    return hasil;
}

int cek_elemen_kosong(list L)
{
    int hasil = -1;
    if (hitung_elemen(L) < n)
    {
        int ketemu = 0;
        
        int i = 0;
        while((ketemu == 0) && (i<n))
        {
            if (L.data[i].next == -2)
            {
                hasil = i;
                ketemu = 1;
            }
            else
            {
                i++;
            }
        }
    }

    return hasil;
}

void addfirst(float angka, list *L)
{
    if (hitung_elemen(*L) < n)
    {
        int new = cek_elemen_kosong(*L);
        (*L).data[new].kontainer.angka = angka;

        if ((*L).first == -1)
        {
            (*L).data[new].next = -1;
        }
        else
        {
            (*L).data[new].next = (*L).first;
        }

        (*L).first = new;
    }
    else
    {
        printf("List sudah tidak bisa ditambahkan\n");
    }
}

void cetak_elemen(list L)
{
    if (L.first != -1)
    {
        int tunjuk = L.first;
        printf("\n");
        while (tunjuk != -1)
        {
            printf("%0.2f\n", L.data[tunjuk].kontainer.angka);
            
            tunjuk = L.data[tunjuk].next;
        }
    }
    else
    {
        printf("Elemen Kosong\n");
    }
}

int main(){
    
    scanf("%d", &n);

    list L;
    create(&L);

    int i;
    float angka;
    for ( i = 0; i < n; i++)
    {
        scanf("%f", &angka);
        addfirst(angka,&L);
    }

    cetak_elemen(L);

    return 0;
    
}

/* 
1.10
2.20
3.30
4.40
5.50
 */