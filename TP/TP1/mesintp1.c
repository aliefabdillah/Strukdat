/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP1 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin

#include "headtp1.h"

void create_list(list *L){
    (*L).first = NULL;      //NULL artinya pointer first mengaskses elemen kosong di sebuah memori
}

int count_elemen(list L){
    int hasil = 0;

    if (L.first != NULL)
    {
        /* list tidak kosong */
        elemen* tunjuk;

        //inisialiasi
        tunjuk = L.first;

        while (tunjuk != NULL)
        {
            hasil = hasil + 1;

            tunjuk = tunjuk->next;
        }   
    }
    return hasil;
}

void add(char nama[], int harga, float rate, list *L){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru

    //proses memasukan input ke dalam list
    strcpy(baru->kontainer.nama, nama);             
    baru->kontainer.harga = harga;
    baru->kontainer.rate = rate;

    if ((*L).first == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = (*L).first;
    }
    (*L).first = baru;
    baru = NULL;
}

//sorting secara bubble sort
void sort(int n, char choose_sort[], list *L){
    int swap;             
    
    //variabel untuk pertukaran
    elemen* temp;
    int  temp_harga;
    float temp_rate;
    char temp_nama[50];

    elemen* pointer;                //pointer untuk elemen sekarang
    elemen* last = NULL;        //pointer elemen terakhir

    //jika list tidak kosong
    if((*L).first != NULL)
    {
        //perulangan selama swap == 1
        do
        {
            swap = 0;
            pointer = (*L).first;       //pointer now berisi pointer first

            //perulangan selama pointer next dari now tidak sama dengan NULL
            while (pointer->next != last)
            {   
                //jika ascending
                if (strcmp(choose_sort, "asc") == 0)
                {
                    if (pointer->kontainer.rate > pointer->next->kontainer.rate)
                    {
                        //proses Swap list
                        temp_rate = pointer->kontainer.rate;
                        pointer->kontainer.rate = pointer->next->kontainer.rate;
                        pointer->next->kontainer.rate = temp_rate;

                        temp_harga = pointer->kontainer.harga;
                        pointer->kontainer.harga = pointer->next->kontainer.harga;
                        pointer->next->kontainer.harga = temp_harga;

                        strcpy(temp_nama, pointer->kontainer.nama);
                        strcpy(pointer->kontainer.nama, pointer->next->kontainer.nama);
                        strcpy(pointer->next->kontainer.nama, temp_nama);

                        swap = 1;       //penanda
                    }
                }
                else
                {
                    if (pointer->kontainer.rate < pointer->next->kontainer.rate)
                    {
                        //proses Swap list
                        temp_rate = pointer->kontainer.rate;
                        pointer->kontainer.rate = pointer->next->kontainer.rate;
                        pointer->next->kontainer.rate = temp_rate;

                        temp_harga = pointer->kontainer.harga;
                        pointer->kontainer.harga = pointer->next->kontainer.harga;
                        pointer->next->kontainer.harga = temp_harga;

                        strcpy(temp_nama, pointer->kontainer.nama);
                        strcpy(pointer->kontainer.nama, pointer->next->kontainer.nama);
                        strcpy(pointer->next->kontainer.nama, temp_nama);

                        swap = 1;       //penanda
                    }
                }
                pointer = pointer->next;
            }
        } while (swap == 1);
    }
    //jkika lisat kosong
    else
    {
        printf("list kosong\n");
    }
    
}

void print_allmenu(list L)
{
    //menampilakn menu list secara terurut
    printf("=== Menu Terurut ===\n");
    if (L.first != NULL)
    {
        /* inisialisasi */
        elemen* tunjuk = L.first;
        
        while (tunjuk != NULL)
        {
            printf("%s %d %0.1f\n", tunjuk->kontainer.nama, tunjuk->kontainer.harga, tunjuk->kontainer.rate);
            
            // iterasi
            tunjuk = tunjuk->next;
        }
        
    }
    else
    {
        printf("list kosong\n");
    }
}

void print_buy(int total_money, list L)
{   

    int sisa_uang = 0;              //var sisa uang
    int total_buy = 0;              //var total harga yang dibeli
    elemen* tunjuk = L.first;

    printf("\n=== Dapat Dibeli ===\n");

    //jika data pertama pada list lebih dari jumlah uang 
    if (tunjuk->kontainer.harga > total_money)
    {
        printf("Tidak ada yang dapat dibeli\n");
    }
    //jika tidak
    else
    {   
        
        //perulangan selama pointer tunjuk tidak sama dengan null dan total harga yang dibeli kurang dari jumlah uang
        do
        {   
            total_buy = total_buy + tunjuk->kontainer.harga;
            if (total_buy <= total_money)
            {
                printf("%s %d %0.1f\n", tunjuk->kontainer.nama, tunjuk->kontainer.harga, tunjuk->kontainer.rate);
            }
            else
            {
                total_buy = total_buy - tunjuk->kontainer.harga;        //agar jumlah harga yang dibeli tidak lebih jadi dikurangi harga pada index sbeelumnya
            }
            tunjuk = tunjuk->next; 
        }
        while (tunjuk != NULL && total_buy <= total_money);
    }

    sisa_uang = total_money - total_buy;
    printf("\nSisa uang: %d\n", sisa_uang);
}

