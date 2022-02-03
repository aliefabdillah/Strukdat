//bagian mesin

#include "headdinamis.h"

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

void add_first(char nama[], char rumus[], char kons[], list *L){
    elemen* baru;                               //deklarasi pointer bernama baru
    baru = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.rumus, rumus);
    strcpy(baru->kontainer.kons, kons);

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

void add_after(elemen* prev, char nama[], char rumus[], char kons[])
{
    elemen* baru;
    baru = (elemen*) malloc (sizeof (elemen));
    strcpy(baru->kontainer.nama, nama);
    strcpy(baru->kontainer.rumus, rumus);
    strcpy(baru->kontainer.kons, kons);

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

void add_last(char nama[], char rumus[], char kons[], list *L)
{
    if ((*L).first == NULL)     //jika list kosong
    {
        add_first(nama, rumus, kons, L);
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
        add_after(prev, nama, rumus, kons);
    }
}

void del_first(list *L)
{
    
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

void del_after(elemen* prev, list *L)
{
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

void del_all(list *L)
{
    if (count_elemen(*L) != 0)      //jika list tidak kosong
    {
        int i;

        for ( i = count_elemen(*L); i >= 1; i--)
        {
            del_last(L);
        }
    }
    else
    {
        printf("list kosong\n");
    }
}

void print_elemen(list L)
{

    if (L.first != NULL)
    {
        /* inisialisasi */
        elemen* tunjuk = L.first;
        
        while (tunjuk != NULL)
        {
            printf("%s %s %s\n", tunjuk->kontainer.nama, tunjuk->kontainer.rumus, tunjuk->kontainer.kons);
            
            // iterasi
            tunjuk = tunjuk->next;
        }
        
    }
    else
    {
        printf("list kosong\n");
        
    }
     printf("======\n");
}