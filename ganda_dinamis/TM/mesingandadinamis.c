#include "headgandadinamis.h"

void create_list(list *L){
    (*L).first = NULL;      //NULL artinya pointer first mengaskses elemen kosong di sebuah memori
    (*L).tail = NULL;
}

int count_elemen(list L){
    int total = 0;

    if (L.first != NULL)
    {
        /* List tidak kosong */
        elemen* tunjuk;

        //inisialiasi
        tunjuk = L.first;

        while (tunjuk != NULL)
        {
            total = total + 1;

            tunjuk = tunjuk->next;
        }   
    }
    return total;
}

void add_first(char nama[], char matkul[], char nilai[], list *L){
    elemen* new;                               //deklarasi pointer bernama new
    new = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer new
    strcpy(new->kontainer.nama, nama);
    strcpy(new->kontainer.matkul, matkul);
    strcpy(new->kontainer.nilai, nilai);

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

void add_after(elemen* before, char nama[], char matkul[], char nilai[], list *L){
    elemen* new;
    new = (elemen*) malloc (sizeof (elemen));
    strcpy(new->kontainer.nama, nama);
    strcpy(new->kontainer.matkul, matkul);
    strcpy(new->kontainer.nilai, nilai);

    //jika add after di paling akhir
    if (before->next == NULL)
    {
        new->next = NULL;
        (*L).tail = new;
    }
    // jika addafter di tengah"
    else
    {
        new->next = before->next;
        new->next->prev = new; 
    }
    new->prev = before;
    before->next = new;
    new = NULL;
}

void add_before(elemen* after, char nama[], char matkul[], char nilai[], list *L){
    elemen* new;
    new = (elemen*) malloc (sizeof (elemen));
    strcpy(new->kontainer.nama, nama);
    strcpy(new->kontainer.matkul, matkul);
    strcpy(new->kontainer.nilai, nilai);

    //jika add after di paling akhir
    if (after->prev == NULL)
    {
        new->prev = NULL;
        (*L).tail = new;
    }
    // jika addafter di tengah"
    else
    {
        new->prev = after->prev;
        new->prev->next = new; 
    }
    new->next = after;
    after->prev = new;
    new = NULL;
}

void add_last(char nama[], char matkul[], char nilai[], list *L)
{
    if ((*L).first == NULL)     //jika list kosong
    {
        add_first(nama, matkul, nilai, L);
    }
    else
    {
        /* jika list tidak kosong */
        add_after((*L).tail, nama, matkul, nilai, L);
    }
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
    else
    {
        printf("List Kosong\n");
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
    else
    {
        printf("List Kosong\n");
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
        printf("List Kosong\n");
    }
}

void print_forward(list L){
    if (L.first != NULL)
    {
        /* inisialisasi */
        elemen* tunjuk = L.first;
        
        int i = 0;
        while (tunjuk != NULL)
        {
        
            printf("%s %s %s\n", tunjuk->kontainer.nama, tunjuk->kontainer.matkul, tunjuk->kontainer.nilai);
            // iterasi
            tunjuk = tunjuk->next;
            i++;
        
        }
    }
    else
    {
        printf("List Kosong\n");
    }
    printf("========\n");
}

void print_reverse(list L){
    if (L.first != NULL)
    {
        /* inisialisasi */
        elemen* tunjuk = L.tail;
        
        //int i = count_elemen(L);

        while (tunjuk != NULL)
        {
        
            printf("%s ", tunjuk->kontainer.nama);
            printf("%s ", tunjuk->kontainer.matkul);
            printf("%s\n", tunjuk->kontainer.nilai);
            // iterasi
            tunjuk = tunjuk->prev;
            //i--;
        }
    }
    else
    {
        printf("List Kosong\n");
    }
    printf("========\n");
}