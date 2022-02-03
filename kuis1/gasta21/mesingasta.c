/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis Gasta21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headergasta.h"

void create_list(int n, list *L)
{
    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for ( i = 0; i < n; i++)
    {
        // proses menginisialisasi isi array
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

int count_element(list L)
{
    int total = 0;      //variabel menyimpan banyak elemen di dalam list
    if(L.first != -1)
    {
        // jika list tidak null
        int count;     //pointer count untuk menghitung list

        // inisaliasi
        count = L.first;

        while (count != -1)
        {
            total = total + 1;

            // pengulangan
            count = L.data[count].next;       //mengakses pointer next pada elemen saat pointer hitung berada saat ini
        }
        
    }

    return total;
}

int empty_elemen(int n, list L)
{
    int total = -1;     //jika array sudah penuh set -1

    //jika belum
    if (count_element(L) < n)
    {
        int found = 0;

        int i = 0;
        while ((found == 0) && (i<n))
        {
            if (L.data[i].next  == -2)
            {
                total = i;
                found = 1;
            }
            else
            {
                i++;
            }
        }   
    }
    
    return total;
}

void add(int n, char kata[], list *L)
{
    if (count_element(*L) < n)
    {
        int new = empty_elemen(n, *L);        //pointer untuk menyimpan index yang nasih kosong
        strcpy((*L).data[new].kontainer.kata, kata);

        //jika list nya list kosong
        if ((*L).first == -1)
        {
            (*L).data[new].prev = -1;      //pointer sebelumnya jadi -1
            (*L).data[new].next = -1;      //pointer setelahnya jadi -1
            (*L).tail = new;               //pointer tail menunjuk data new
        }
        else
        {
            // jika list tidak kosong
            (*L).data[new].prev = -1;              //pointer sebelumnya menjadi -1
            (*L).data[new].next = (*L).first;      //pointer setelahnya menunjuk data pertama sebelumnya
            (*L).data[(*L).first].prev = new;      //pointer sebelumnya dari data pertama sebelumnya menunjuk ke data new
        }
        
        (*L).first = new;      //first menunjuk new
    }
    else
    {
        // jika array sudah penuh
        printf("List sudah tidak dapat di tambah\n");
    }
    
}

void print(int n, list L){
    int spasi_front = 0;
    int spasi_back = 0;
    int pointer = L.first;
    int back = L.tail;
    int i, j, k, m, o, p, r;
    
    //jika genap
    if (n % 2 == 0)
    {
        int l = n-1;
        for ( i = 0; i < n/2; i++)
        {   
            //perulangan spasi awal
            for ( j = 0; j < spasi_front; j++)
            {
                printf(" ");
            }
            printf("%s", L.data[pointer].kontainer.kata);
            //jika i nya sudah tidak sama dengan elemen sebelum tengah
            if (i != (n/2)-1)
            {
                for ( p = i; p < n/2; p++)
                {
                    pointer = L.data[pointer].next;
                    //mencetak spasi sebanyak panjang kata di elemen setelahnya
                    for ( k = 0; k < strlen(L.data[pointer].kontainer.kata); k++)
                    {
                        printf(" ");
                    }
                }
                
                for ( r = p; r > i ; r--)
                {
                    pointer = L.data[pointer].prev;
                }
            }
            
            int broke = 0;
            //do while selama l lebih dari elemen tengah dan broke nya = 0
            do
            {
                
                if (l != (n/2))
                {
                    for ( p = l; p > (n/2)+1; p--)
                    {
                        back = L.data[back].prev;
                        //mencetak spasi sebanyak panjang kata di elemen sebelumnya
                        for ( k = 0; k < strlen(L.data[back].kontainer.kata); k++)
                        {
                            printf(" ");
                        }
                    }
                    
                    for ( r = p; r < l; r++)
                    {
                        back = L.data[back].next;
                    }
                }
                printf("%s", L.data[back].kontainer.kata);
                
                printf("\n");
                //iterasi
                back = L.data[back].prev;
                l--;
                broke = 1;          //untuk keluar dari perulangan do-while
                
            }while (l>n/2 && broke == 0);

            spasi_front = spasi_front + strlen(L.data[pointer].kontainer.kata);
            pointer = L.data[pointer].next;
        }
    }
    //jika ganjil
    else
    {
        int l = n-1;
        for ( i = 0; i <= (n/2); i++)
        {   
            //perulangan spasi awal
            for ( j = 0; j < spasi_front; j++)
            {
                printf(" ");
            }
            printf("%s", L.data[pointer].kontainer.kata);
            //jika i nya sudah tidak sama dengan elemen sebelum tengah
            if (i != (n/2)-1)
            {
                for ( p = i; p < n/2; p++)
                {
                    pointer = L.data[pointer].next;
                    //mencetak spasi sebanyak panjang kata di elemen setelahnya
                    for ( k = 0; k < strlen(L.data[pointer].kontainer.kata); k++)
                    {
                        printf(" ");
                    }
                }
                
                //kembali ke i
                for ( r = p; r > i ; r--)
                {
                    pointer = L.data[pointer].prev;
                }
            }
            
            int broke = 0;
            //do while selama l dimulai dari akhir dan lebih dari elemen tengah dan broke nya = 0
            do
            {
                //jika l  tidak sama dengan elemen tengah
                if (l != (n/2))
                {
                    //mencetak spasi sebanyak panjang kata di elemen sebelumnya
                    for ( p = l; p > (n/2)+1; p--)
                    {
                        back = L.data[back].prev;
                        for ( k = 0; k < strlen(L.data[back].kontainer.kata); k++)
                        {
                            printf(" ");
                        }
                    }
                    
                    for ( r = p; r < l; r++)
                    {
                        back = L.data[back].next;
                    }
                }
                //jika l sama dengan elemen sebelum setengah
                if(l == (n/2)+1)
                {
                    back = L.data[back].prev;
                    for ( k = 0; k < strlen(L.data[back].kontainer.kata); k++)
                    {
                        printf(" ");
                    }
                    back = L.data[back].next;
                }

                //jika l tidak sama dengan elemen setengah
                if (l != n/2)
                {
                    printf("%s", L.data[back].kontainer.kata);
                }
                
                printf("\n");

                //iterasi
                back = L.data[back].prev;
                l--;
                broke = 1;
                
            }while (l>(n/2)+2 && broke == 0);

            spasi_front = spasi_front + strlen(L.data[pointer].kontainer.kata);
            pointer = L.data[pointer].next;
        }
    }
    
    
    
}
