/*Saya Alief Muhammad Abdillah 2003623 mengerjakan TP2 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headertp2.h"

void create_list(list *L){
    (*L).first = NULL;      //NULL artinya pointer first mengaskses elemen kosong di sebuah memori
    (*L).tail = NULL;
}

int count_elemen(list L){
    int total = 0;

    if (L.first != NULL)
    {
        /* List tidak kosong */
        elemen* ptr;

        //inisialiasi
        ptr = L.first;

        while (ptr != NULL)
        {
            total = total + 1;

            ptr = ptr->next;
        }   
    }
    return total;
}

void add(char nama[], int harga, int kode, list *L){
    elemen* new;                               //deklarasi pointer bernama new
    new = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer new
    strcpy(new->kontainer.nama, nama);
    new->kontainer.harga = harga;
    new->kontainer.kode = kode;

    if ((*L).first == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        (*L).tail = new;
        
    }
    else
    {
        new->next = (*L).first;
        new->prev = NULL;
        (*L).first->prev = new;
    }
    (*L).first = new;
    new = NULL;
}

void del_first(list *L)
{
    
    if ((*L).first != NULL)     //jika list tidak kosong
    {
        elemen* erase = (*L).first;     //pointer hapus menunjuk elemen pertama dari list
        if (count_elemen(*L) == 1)      //jika cuma 1 elemen saja
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else{
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            erase->next = NULL;
        }

        free(erase);        //prosedur melepaskan elemen dari memori yang ditunjuk pointer hapus
    }
}

void del_after(elemen* before, list *L)
{
    if (before != NULL)
    {
        elemen* erase = before->next;
    
        //jika elemen yang ditunjuk setelah prev != NULL / ada elemen yang akan dihapus
        if (erase != NULL)
        {
            if (erase->next == NULL)    //jika elemennya di akhir
            {
                before->next = NULL;
                (*L).tail = before;
            }
            else                        //jika ditengah
            {       
                before->next = erase->next;         //pointer next dari before menjadi menunjuk ke next dari erase
                erase->next->prev = before;         //pointer prev dari data setelah prev menunjuk before
                erase->next = NULL;                 //pointer next dari elemen yang akan dihapus di null kan
            }
            erase->prev = NULL;
            free(erase);
        }
    }
}

void del_last(list *L)
{
    if ((*L).first != NULL)     //jika elemen tidak kosong
    {
        if (count_elemen(*L) == 1)  //jika elemen tinggal 1
        {
            del_first(L);
        }
        else
        {
            del_after((*L).tail->prev, L);
        }
    }
}

void cek(list *L)
{
    if ((*L).first != NULL)
    {
        int total = 0;          //varirabel total untuk menghitung jumlah kode yang ganjik
        
        elemen* count = (*L).first;

        while (count != NULL)
        {
            if (count->kontainer.kode % 2 != 0)
            {
                total++;
            }
            count = count->next;
        }
        
        //jika total kode ganjil = jumlah element maka dell all
        if (total == count_elemen(*L))
        {
            int i;

            for ( i = count_elemen(*L); i >= 1; i--)
            {
                del_last(L);
            }
        }
        //jika tidak
        else
        {
            elemen* ptr = (*L).first;
            do
            {
                //jika kode ganjil
                if (ptr->kontainer.kode % 2 != 0)
                {
                    elemen* erase;
                    elemen* before;
                    erase = ptr;
                    if (erase == (*L).first)                //jika data ada di elemen pertama
                    {
                        (*L).first = (*L).first->next;
                        ptr = (*L).first;
                        (*L).first->prev = NULL;
                        erase->next = NULL;
                        free(erase); 
                    }
                    else                                    //jika tidak
                    {
                        before = erase->prev;
                        if (erase->next == NULL)    //jika elemennya di akhir
                        {
                            before->next = NULL;
                            ptr = before->next;
                            (*L).tail = before;
                        }
                        else                        //jika ditengah
                        {       
                            before->next = erase->next;         //pointer next dari before menjadi menunjuk ke next dari erase
                            ptr = before->next;
                            erase->next->prev = before;         //pointer prev dari data setelah prev menunjuk before
                            erase->next = NULL;                 //pointer next dari elemen yang akan dihapus di null kan
                        }
                        erase->prev = NULL;
                        free(erase);
                    }
                }
                else        //jika kode bukan ganjil
                {
                    ptr = ptr->next;
                }
            }while (ptr != NULL);
        }
    }
}


void sort(char komponen[], char methode[], list *L){
    int swapped;             
    
    //variabel untuk pertukaran
    char temp_nama[50];
    int  temp_harga;
    int temp_kode;

    elemen* pointer;                //pointer untuk elemen sekarang

    //jika list tidak kosong
    if((*L).first != NULL)
    {
        //perulangan selama swap == 1
        do
        {
            swapped = 0;
            pointer = (*L).first;       //pointer now berisi pointer first

            //perulangan selama pointer next dari now tidak sama dengan NULL
            while (pointer->next != NULL)
            {   
                //jika ascending
                if (strcmp(komponen, "K") == 0)
                {
                    if (strcmp(methode, "Asc") == 0)
                    {
                        if (pointer->kontainer.kode > pointer->next->kontainer.kode)
                        {
                            //proses Swap list
                            swap(pointer, pointer->next, L);

                            swapped = 1;       //penanda
                        }
                    }
                    if (strcmp(methode, "Desc") == 0)
                    {
                        if (pointer->kontainer.kode < pointer->next->kontainer.kode)
                        {
                            //proses Swap list
                            swap(pointer, pointer->next, L);

                            swapped = 1;       //penanda
                        }
                    }
                    
                }
                else
                {
                    if (strcmp(methode, "Asc") == 0)
                    {
                        if (pointer->kontainer.harga > pointer->next->kontainer.harga)
                        {
                            //proses Swap list
                            swap(pointer, pointer->next, L);

                            swapped = 1;       //penanda
                        }
                    }
                    if (strcmp(methode, "Desc") == 0)
                    {
                        if (pointer->kontainer.harga < pointer->next->kontainer.harga)
                        {
                            //proses Swap list
                            swap(pointer, pointer->next, L);

                            swapped = 1;       //penanda
                        }
                    }
                }
                pointer = pointer->next;
            }
        } while (swapped == 1);
    }
}

void swap(elemen* a, elemen*b , list *L){
    char temp_nama[50];
    int  temp_harga;
    int temp_kode;

    //tukar harga
    temp_harga = a->kontainer.harga;
    a->kontainer.harga = b->kontainer.harga;
    b->kontainer.harga = temp_harga;

    //tukar kode
    temp_kode = a->kontainer.kode;
    a->kontainer.kode = b->kontainer.kode;
    b->kontainer.kode = temp_kode;

    //tukar nama
    strcpy(temp_nama, a->kontainer.nama);
    strcpy(a->kontainer.nama, b->kontainer.nama);
    strcpy(b->kontainer.nama, temp_nama);
}

void print(list L){
    if(L.first != NULL)
    {
        /* inisialisasi */
        elemen* tunjuk = L.first;
        
        while (tunjuk != NULL)
        {
            printf("%s %d %d\n", tunjuk->kontainer.nama, tunjuk->kontainer.harga, tunjuk->kontainer.kode);
            
            // iterasi
            tunjuk = tunjuk->next;
        }
    }
    else
    {
        printf("=================\n");
        printf(" Loh kok gaada:(\n");
        printf("=================\n");
    }
    
}