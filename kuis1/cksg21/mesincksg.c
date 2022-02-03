/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis Cksg21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

//bagian mesin
#include "headercksg.h"

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

void add_first(char nama[], int harga, list *L){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.harga = harga;

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

void add_after(elemen* prev, char nama[], int harga, list *L){
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nama, nama);
    baru->kontainer.harga = harga;
  
    //jika add after di paling akhir
    if (prev->next == NULL)
    {
        baru->next = NULL;
    }
    // jika addafter di tengah"
    else
    {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;
}

void add_last(char nama[], int harga, list *L){
    if ((*L).first == NULL)     //jika list kosong
    {
        add_first(nama, harga, L);
    }
    else
    {
        /* jika list tidak kosong */
        //mencari elemen terakhir pada list;
        elemen* prev = (*L).first;
        while (prev->next != NULL)
        {
            //iterasi
            prev = prev->next;
        }
        add_after(prev, nama, harga, L);
    }
}

void del_first(list *L){
    if ((*L).first != NULL)     //jika list tidak kosong
    {
        elemen* hapus = (*L).first;     //pointer hapus menunjuk elemen pertama dari list
        if (count_elemen(*L) == 1)      //jika cuma 1 elemen saja
        {
            (*L).first = NULL;
        }
        else{
            (*L).first = (*L).first->next;
            hapus->next = NULL;
        }

        free(hapus);        //prosedur melepaskan elemen dari memori yang ditunjuk pointer hapus
    }
    else
    {
        printf("list kosong\n");
    }
}

void del_after(elemen* prev, list *L){
    elemen* hapus = prev->next;
    
    //jika elemen yang ditunjuk setelah prev != NULL / ada elemen yang akan dihapus
    if (hapus != NULL)
    {
        if (hapus->next == NULL)    //jika elemennya di akhir
        {
            prev->next = NULL;
        }
        else                        //jika ditengah
        {       
            prev->next = hapus->next;
            hapus->next = NULL;
        }
        free(hapus);
    }
}

void del_last(list *L){
    if ((*L).first != NULL)     //jika elemen tidak kosong
    {
        if (count_elemen(*L) == 1)  //jika elemen tinggal 1
        {
            del_first(L);
        }
        else
        {
            // mencari elemen terakhir di list
            elemen* last = (*L).first;
            elemen* prev;

            while (last->next != NULL)
            {
                //iterasi
                prev = last;
                last = last->next;
            }

            del_after(prev, L);
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

void swap(char tukar_1[], char tukar_2[], list *L_1, list *L_2){
    char temp_nama1[50];
    int temp_harga1;
    char temp_nama2[50];
    int temp_harga2;
    int cek1 = 0;
    int cek2 = 0;
    int cek;

    elemen* prev1;
    elemen* prev2;
    elemen* pointer1;
    elemen* pointer2;
    
    prev1 = NULL;
    pointer1 = (*L_1).first;
    //data tukar 1 di pengecekan pada list satu 
    while (pointer1 != NULL && cek1 == 0)
    {
        if (strcmp(tukar_1, pointer1->kontainer.nama) == 0)
        {
            cek1 = 1;
            strcpy(temp_nama1, pointer1->kontainer.nama);
            temp_harga1 = pointer1->kontainer.harga;

            add_last(temp_nama1, temp_harga1, L_2);
    
            if (pointer1 == (*L_1).first)
            {
                del_first(L_1);
            }
            if (pointer1->next != NULL)
            {
                del_after(prev1, L_1);
            }
            if (pointer1->next == NULL)
            {
                del_last(L_1);
            }
        }
        
        prev1 = pointer1;
        pointer1 = pointer1->next;
    }
    
    //data tukar 1 di pengecekan pada list 2
    if (cek1 == 0)
    {
        cek = 0;
        pointer2 = (*L_2).first;
        prev2 = NULL;
        while (pointer2 != NULL && cek == 0)
        {
            if (strcmp(tukar_1, pointer2->kontainer.nama) == 0)
            {
                cek = 1;
                strcpy(temp_nama2, pointer2->kontainer.nama);
                temp_harga2 = pointer2->kontainer.harga;

                add_last(temp_nama2, temp_harga2, L_1);

                if (pointer2 == (*L_2).first)
                {
                    del_first(L_2);
                }
                if (pointer2->next != NULL)
                {
                    del_after(prev2, L_2);
                }
                if (pointer2->next == NULL)
                {
                    del_last(L_2);
                }
            }
            prev2 = pointer2;
            pointer2 = pointer2->next;
        }
    }
    

    pointer2 = (*L_2).first;
    prev2 = NULL;
    //data tukar 2 di pengecekan pada list 2 
    while (pointer2 != NULL && cek2 == 0)
    {
        if (strcmp(tukar_2, pointer2->kontainer.nama) == 0)
        {
            cek2 = 1;
            strcpy(temp_nama2, pointer2->kontainer.nama);
            temp_harga2 = pointer2->kontainer.harga;

            add_last(temp_nama2, temp_harga2, L_1);

            if (pointer2 == (*L_2).first)
            {
                del_first(L_2);
            }
            if (pointer2->next != NULL)
            {
                del_after(prev2, L_2);
            }
            if (pointer2->next == NULL)
            {
                del_last(L_2);
            }
        }
        prev2 = pointer2;
        pointer2 = pointer2->next;
    }

    //data tukar 2 di pengecekan pada list 1
    if (cek2 == 0)
    {
        cek = 0;
        prev1 = NULL;
        pointer1 = (*L_1).first;
        while (pointer1 != NULL && cek == 0)
        {
            if (strcmp(tukar_2, pointer1->kontainer.nama) == 0)
            {
                cek = 1;
                strcpy(temp_nama1, pointer1->kontainer.nama);
                temp_harga1 = pointer1->kontainer.harga;

                add_last(temp_nama1, temp_harga1, L_2);


                if (pointer1 == (*L_1).first)
                {
                    del_first(L_1);
                }
                if (pointer1->next != NULL)
                {
                    del_after(prev1, L_1);
                }
                if (pointer1->next == NULL)
                {
                    del_last(L_1);
                }
            }
        
            prev1 = pointer1;
            pointer1 = pointer1->next;
        }
    }
    
}

//prosedur cetak elemen
void print_elemen(list L){
    if (L.first != NULL)
    {
        /* inisialisasi */
        elemen* tunjuk = L.first;
        
        while (tunjuk != NULL)
        {
            printf("%s %d\n", tunjuk->kontainer.nama, tunjuk->kontainer.harga);
            
            // iterasi
            tunjuk = tunjuk->next;
        }
        
    }
    else
    {
        printf("list kosong\n");
        
    }
}