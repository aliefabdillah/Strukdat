/* Bagian Mesin */
#include "headLOL.h"

void create_list(list *L){
    (*L).first = NULL;      //NULL artinya pointer first mengaskses elemen kosong di sebuah memori
}

int count_elemen_baris(list L){
    int hasil = 0;

    if (L.first != NULL)
    {
        /* List tidak kosong */
        elemen_baris* pointer;

        //inisialiasi
        pointer = L.first;

        while (pointer != NULL)
        {
            hasil = hasil + 1;

            pointer = pointer->next;
        }   
    }
    return hasil;
}

int count_elemen_kolom(elemen_baris L){
    int hasil = 0;

    if (L.col != NULL)
    {
        /* List tidak kosong */
        elemen_kolom* pointer;

        //inisialiasi
        pointer = L.col;

        while (pointer != NULL)
        {
            hasil = hasil + 1;

            pointer = pointer->next_kol;
        }   
    }
    return hasil;
}

void add_first_baris(char klub[], int tahun, list *L){
    elemen_baris* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_baris*) malloc (sizeof (elemen_baris));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.klub, klub);
    baru->kontainer.tahun = tahun;
    baru->col = NULL;

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

void add_first_kolom(char nama_pemain[], elemen_baris *L){
    elemen_kolom* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_kolom*) malloc (sizeof (elemen_kolom));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer_kol.nama_pemain, nama_pemain);

    if ((*L).col == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = (*L).col;
    }
    (*L).col = baru;
    baru = NULL;
}

void add_after_baris(elemen_baris *prev, char klub[], int tahun){
    elemen_baris* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_baris*) malloc (sizeof (elemen_baris));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer.klub, klub);
    baru->kontainer.tahun = tahun;
    baru->col = NULL;

    if (prev->next == NULL)
    {
        baru->next = NULL;
    }
    else
    {
        baru->next = prev->next;
    }
    prev->next = baru;
    baru = NULL;   
}

void add_after_kolom(elemen_kolom *prev, char nama_pemain[]){
    elemen_kolom* baru;                               //deklarasi pointer bernama baru
    baru = (elemen_kolom*) malloc (sizeof (elemen_kolom));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer baru
    strcpy(baru->kontainer_kol.nama_pemain, nama_pemain);

    if (prev->next_kol == NULL)
    {
        baru->next_kol = NULL;
    }
    else
    {
        baru->next_kol = prev->next_kol;
    }
    prev->next_kol = baru;
    baru = NULL; 
}

void add_last_baris(char klub[], int tahun, list *L){
    if ((*L).first == NULL)     //jika list kosong
    {
        add_first_baris(klub, tahun, L);
    }
    else
    {
        /* jika list tidak kosong */
        //mencari elemen terakhir pada list;
        elemen_baris* last = (*L).first;
        while (last->next != NULL)
        {
            //iterasi
            last = last->next;
        }
        add_after_baris(last, klub, tahun);
    }
}

void add_last_kolom(char nama_pemain[], elemen_baris *L){
    if ((*L).col == NULL)     //jika list kosong
    {
        add_first_kolom(nama_pemain, L);
    }
    else
    {
        /* jika list kolom tidak kosong */
        //mencari elemen terakhir pada list;
        elemen_kolom* last = (*L).col;
        while (last->next_kol != NULL)
        {
            //iterasi
            last = last->next_kol;
        }
        add_after_kolom(last, nama_pemain);
    }
}

void del_first_kolom(elemen_baris *L)
{
    
    if ((*L).col != NULL)     //jika kolom tidak kosong
    {
        elemen_kolom* hapus = (*L).col;     //pointer hapus menunjuk elemen pertama dari kolom
        if (count_elemen_kolom(*L) == 1)      //jika cuma 1 elemen saja
        {
            (*L).col = NULL;
        }
        else{
            (*L).col = (*L).col->next_kol;
            hapus->next_kol = NULL;
        }

        free(hapus);        //prosedur melepaskan elemen dari memori yang ditunjuk pointer hapus
    }
    else
    {
        printf("LIST KOSONG\n");
    }
}

void del_after_kolom(elemen_kolom *prev)
{
    elemen_kolom* hapus = prev->next_kol;
    
    //jika elemen yang ditunjuk setelah prev != NULL / ada elemen yang akan dihapus
    if (hapus != NULL)
    {
        if (hapus->next_kol == NULL)    //jika elemennya di akhir
        {
            prev->next_kol = NULL;
        }
        else                        //jika ditengah
        {       
            prev->next_kol = hapus->next_kol;
            hapus->next_kol = NULL;
        }
        free(hapus);
    }
}

void del_last_kolom(elemen_baris *L)
{
    if ((*L).col != NULL)
    {
        if (count_elemen_kolom(*L) == 1)
        {
            del_first_kolom(L);
        }
        
        else
        {
            elemen_kolom *last = (*L).col;
            elemen_kolom *prev_last;

            while (last->next_kol != NULL)
            {
                prev_last = last;
                last = last->next_kol;
            }
        
            del_after_kolom(prev_last);
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
    
}

void del_all_kolom(elemen_baris *L)
{
    if (count_elemen_kolom(*L) != 0)      //jika list tidak kosong
    {
        int i;

        for ( i = count_elemen_kolom(*L); i >= 1; i--)
        {
            del_last_kolom(L);
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
}

void del_first_baris(list *L)
{
    if ((*L).first != NULL)     //jika baris tidak kosong
    {
        elemen_baris* hapus = (*L).first;     //pointer hapus menunjuk elemen pertama dari baris

        //jika kolom tidak kosong maka di hapus semua terlebih dahulu
        if (hapus->col != NULL)
        {
            del_all_kolom(hapus);
        }
        
        if (count_elemen_baris(*L) == 1)      //jika cuma 1 elemen saja
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
        printf("LIST KOSONG\n");
    }
}

void del_after_baris(elemen_baris *prev)
{   
    if (prev != NULL)
    {
        elemen_baris* hapus = prev->next;
        //jika elemen yang ditunjuk setelah prev != NULL / ada elemen yang akan dihapus
        if (hapus != NULL)
        {
            
            if (hapus->col != NULL)         //jika kolom tidak kosong maka di hapus semua terlebih dahulu
            {
                del_all_kolom(hapus);
            }
            
            if (hapus->next == NULL)    //jika elemennya di akhir
            {
                prev->next = NULL;
            }
            else                        //jika ditengah
            {       
                prev->next = hapus->next;
            }
            hapus->next = NULL;

            free(hapus);
        }
    }
}

void del_last_baris(list *L)
{
    if ((*L).first != NULL)
    {
        if (count_elemen_baris(*L) == 1)
        {
            del_first_baris(L);
        }
        else
        {
            elemen_baris *last = (*L).first;
            elemen_baris *prev_last;

            while (last->next != NULL)
            {
                prev_last = last;
                last = last->next;
            }
            del_after_baris(prev_last);
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
}

void del_all_baris(list *L)
{
    if (count_elemen_baris(*L) != 0)      //jika list tidak kosong
    {
        int i;

        for ( i = count_elemen_baris(*L); i >= 1; i--)
        {
            del_last_baris(L);
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
}

void print_elemen(list L)
{
    if (L.first != NULL)    //if list not null
    {
        //inisialisasi
        elemen_baris* tunjuk = L.first;
        
        while (tunjuk != NULL)      //perulangan selemen pointer tunjuk tidak bernilai null
        {
            printf("%s ",tunjuk->kontainer.klub);
            printf("%d\n",tunjuk->kontainer.tahun);

            elemen_kolom* tunjuk_col = tunjuk->col;                             //pointer tunjuk for coloumn
            while (tunjuk_col != NULL)
            {
                printf("- %s\n",tunjuk_col->kontainer_kol.nama_pemain);
                
                //iterasi kolom
                tunjuk_col = tunjuk_col->next_kol;
            }
            printf("==================\n");
            /* iterasi baris */
            tunjuk = tunjuk->next;   
        }
    }
    else
    {
        printf("LIST KOSONG\n");
    }
    
}

//procedure for check and sorting row
void cek(char klub[], int tahun, list *L){
    elemen_baris* pointer = (*L).first;         //initialisation of pointer
    int stop = 0;                               //variabel to stop looping

    //if first null
    if ((*L).first == NULL)
    {
        add_first_baris(klub, tahun, L);
    }
    //else
    else
    {
        while (pointer != NULL && stop == 0)        //looping untill pointer NULL or stop not 0
        {
            //if tahun less than tahun in list
            if (tahun < pointer->kontainer.tahun)
            {
                if (pointer == (*L).first)
                {
                    add_first_baris(klub, tahun, L);        //call addfirst row
                    stop = 1;
                }
                else
                {
                    add_after_baris(pointer, klub, tahun);      //call add after row
                    stop = 1;
                }
            }
            else
            {
                pointer = pointer->next;                //iteration
                if (pointer == NULL)                    //if pointer was null
                {
                    add_last_baris(klub, tahun, L);     //call addlast row
                    stop = 1;
                }
            }   
        }
    }
}

//procedure input data in column
void cek_kol(char klub[], list *L){
    char nama_pemain[4][50];            //variabel for input player name
    int i;
    //input procces
    for (i = 0; i < 4; i++)
    {
        scanf("%s", nama_pemain[i]);
    }

    //if in list just 1 element
    if (count_elemen_baris(*L) == 1)
    {
        //input the data to ccolumn 
        add_last_kolom(nama_pemain[0], (*L).first);
        add_first_kolom(nama_pemain[1], (*L).first);
        add_after_kolom((*L).first->col ,nama_pemain[2]);
        add_last_kolom(nama_pemain[3], (*L).first);
    }
    else
    {
        //input the data to ccolumn 
        elemen_baris* now = isi_kolom(klub, (*L));
        add_last_kolom(nama_pemain[0], now);
        add_first_kolom(nama_pemain[1], now);
        add_after_kolom(now->col, nama_pemain[2]);
        add_last_kolom(nama_pemain[3], now);
    }
}

//function to find club name in element
elemen_baris* isi_kolom(char klub[], list L)
{
    elemen_baris* now = 0;
    if (L.first != NULL)
    {
        now = L.first;      //inisialisation
        while (now != NULL && strcmp(now->kontainer.klub, klub) != 0)
        {
            now = now->next;
        }
        return now;     //return the value of now
    }
}