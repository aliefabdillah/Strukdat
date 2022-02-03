#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    char nim[10];
    char nama[50];
    char nilai[2];
}nilaimatkul;

typedef struct elmt* alamat;
typedef struct elmt
{
    nilaimatkul kontainer;
    alamat prev;
    alamat next;
}elemen;

typedef struct 
{
    elemen *first;
    elemen *tail;
}list;


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

void add_first(char nim[], char nama[], char nilai[], list *L){
    elemen* new;                               //deklarasi pointer bernama new
    new = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer new
    strcpy(new->kontainer.nim, nim);
    strcpy(new->kontainer.nama, nama);
    strcpy(new->kontainer.nilai, nilai);

    if ((*L).first == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        (*L).tail = new;
        
        ;
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

void add_after(elemen* before, char nim[], char nama[], char nilai[], list *L){
    elemen* new;
    new = (elemen*) malloc (sizeof (elemen));
    strcpy(new->kontainer.nim, nim);
    strcpy(new->kontainer.nama, nama);
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

void add_last(char nim[], char nama[], char nilai[], list *L){
    if ((*L).first == NULL)     //jika list kosong
    {
        add_first(nim, nama, nilai, L);
    }
    else
    {
        /* jika list tidak kosong */
        add_after((*L).tail, nim, nama, nilai, L);
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
        printf("LIST KOSONG\n");
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
        printf("LIST KOSONG\n");
    }
}

void print_elemen(list L)
{
    if (L.first != NULL)    //jika list tidak kosong
    {
        //inisialisasi
        elemen* tunjuk = L.first;
        
        int i = 1;
        while (tunjuk != NULL)      //perulangan selemen pointer tunjuk tidak bernilai null
        {
            printf("elemen ke : %d\n",i);
            printf("nim : %s\n",tunjuk->kontainer.nim);
            printf("nama : %s\n",tunjuk->kontainer.nama);
            printf("nilai : %s\n",tunjuk->kontainer.nilai);
            printf("-------------\n");

            tunjuk = tunjuk->next;
            i++;        
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }

}


int main(){
    list L;
    create_list(&L);
    print_elemen(L);
    printf("============\n");
    
    add_first("1","orang_1","A", &L);
    add_after(L.first, "2","orang_2","A",&L);
    add_last("3", "orang_3","A", &L);
    print_elemen(L);

    printf("============\n");

    //del_all(&L);
    del_last(&L);
    del_after(L.first, &L);
    del_first(&L);
    print_elemen(L);

    printf("============\n");
    
    return 0;
}