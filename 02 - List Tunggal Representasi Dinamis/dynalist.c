#include "header.h"

/* Inisialisasi List. */

// Prosedur untuk membuat list.
void createlist(list *L)
{
    // Inisialisasi elemen pointer pertama.
    (*L).first = NULL;
}

/* Manipulasi List : Add. */

// Prosedur untuk menambah data ke elemen pertama.
void addfirst(value data, list *L)
{
    // Menyiapkan data dan "tempat" yang akan ditambahkan. 
    element *new;
    new = (element*) malloc(sizeof(element));
    new->container = data;

    // Jika list masih kosong...
    if((*L).first == NULL)
    {
        // "Arahkan" pointer elemen baru ini ke NULL.
        new->next = NULL;
    }
    // Jika data sudah ada...
    else
    {
        // "Arahkan" pointer elemen baru ini ke data sebelumnya.
        new->next = (*L).first;
    }

    // "Arahkan" pointer elemen pertama ke data baru.
    (*L).first = new;
    new = NULL;
}

// Prosedur untuk menyisipkan data ke elemen setelah yang ditentukan sebelumnya.
void addafter(element *prev, value data, list *L)
{
    // Menyiapkan data dan "tempat" yang akan ditambahkan. 
    element *new;
    new = (element*) malloc(sizeof(element));
    new->container = data;

    // Jika elemen yang ditentukan berada di akhir...
    if(prev->next == NULL)
    {
        // "Arahkan" pointer elemen baru ini ke NULL.
        new->next = NULL;
    }
    // Jika data masih ada setelahnya...
    else
    {
        // "Berikan" pointer dari elemen sebelumnya, ke data yang dimasukkan ini.
        new->next = prev->next;
    }

    // "Arahkan" pointer elemen sebelumnya ke data baru.
    prev->next = new;
    new = NULL;
}

// Prosedur untuk menambahkan data ke elemen terakhir.
void addlast(value data, list *L)
{
    // Jika list masih kosong...
    if((*L).first == NULL)
    {
        // Prosedur untuk menambahkan data ke elemen pertama dipanggil.
        addfirst(data, L);
    }
    // Jika list sudah ada...
    else
    {
        // Menentukan "prev" ke elemen terakhir.
        element *prev = (*L).first;
        while(prev->next != NULL)
        {
            prev = prev->next;
        }

        // Prosedur untuk menambahkan data ke elemen setelah "prev" dipanggil.
        addafter(prev, data, L);
    }
}

/* Prosedur dan fungsi tambahan. */

// Prosedur untuk menghitung elemen yang sudah ada di list.
int countelement(list L)
{
    // Deklarasi nilai total.
    int total = 0;

    // Menghitung data di elemen list secara berurutan.
    if(L.first != NULL)
    {
        element *current;
        current = L.first;

        while(current != NULL)
        {
            total++;
            current = current->next;
        }
    }

    // Mengembalikan nilai total.
    return total;
}

// Prosedur untuk mengeluarkan seluruh elemen di list.
void printelement(list L)
{
    // Jika list tidak kosong, program dijalankan.
    if(L.first != NULL)
    {
        element *current = L.first;

        // Mengeluarkan elemen di list, hingga pointer menunjuk elemen kosong.
        while(current != NULL)
        {
            // Bagian keluaran.
            printf("%s ", current->container.name);
            printf("%d\n", current->container.price);
            
            current = current->next;
        }
    }
    // Jika list kosong, tampilkan pesan.
    else
    {
        printf("List kosong\n");
    }
}

/* Sat-Modified Code : Fungsi tambahan pribadi. */

// Prosedur untuk memindahkan pointer elemen.
void moveelement(list *L1, list *L2, char input1[])
{
    // Deklarasi variabel...
    int set, done = 0;           // Mengatur list dan selesainya pencarian.
    element *prev,               // Mencari elemen terakhir dari list.
            *current, *curtemp;  // Elemen saat ini (yang akan dipindah) dan elemen sebelumnya.

    // Mencari elemen yang akan dipindah di list pertama.
    current = curtemp = (*L1).first; set = 1;
    while((done == 0) && (current != NULL))
    {
        if(strcmp(current->container.name, input1) == 0)
        {
            done = 1;
        }
        else
        {
            curtemp = current;
            current = current->next;   
        }
    }

    // Jika masih tidak ada, mencari elemen yang akan dipindah di list kedua.
    if(done == 0)
    {
        current = (*L2).first; curtemp = (*L2).first; set = 2;
        while((done == 0) && (current != NULL))
        {
            if(strcmp(current->container.name, input1) == 0)
            {
                done = 1;
            }
            else   
            {
                curtemp = current;
                current = current->next;   
            }
        }
    }

    // Jika elemen yang akan dipindah berada sebagai elemen pertama...
    if(current == curtemp)
    {
        // Pindahkan pointer ke elemen pertama, menuju elemen setelah yang dipindah.
        if(set == 1)
        {
            (*L1).first = current->next;
        }
        else if(set == 2)
        {
            (*L2).first = current->next;
        }
    }

    // Jika elemen yang akan dipindah berada di terakhir...
    if((current->next == NULL))
    {
        // Jadikan elemen sebelum ke-(yang akan dipindah) menjadi terakhir.
        curtemp->next = NULL;
        
    }
    // Jika ternyata masih ada elemen setelahnya...
    else
    {
        // Arahkan pointer elemen sebelum ke-(yang akan dipindah)
        //menuju ke-(elemen setelah yang akan dipindah) *kok belibet ya?
        curtemp->next = current->next;
    }

    // Inisialisasi elemen pertama di list baru si elemen yang dipindah.
    if(set == 1)
    {
        prev = (*L2).first;
    }
    else
    {
        prev = (*L1).first; 
    }
    
    // Mencari elemen terakhir di list baru si elemen yang dipindah.
    while(prev->next != NULL)
    {
        prev = prev->next;
    }

    // Arahkan elemen terakhir dari tempat baru si elemen yang dipindah,
    //ke elemen yang dipindah.
    prev->next = current;
    current->next = NULL; // Jadikan elemen pindahan ini di ujung list barunya.

    /* Entahlah, Bu. Satria paham konsepnya, tapi susah ngejelasin lewat kata-katanya :(
       Harus visualisasi langsung, tapi semoga penjelasannya udah cukup ya Bu...
       Tapi masih bingung juga, searching yang efektifnya kayak gimana. Sementara ini kan ada
       dua list terpisah... */
}

// Kode tak terpakai, dia versi awal dari moveelement yang sekarang (lebih ke "copy-and-delete element").
/* void moveelement(list *L1, list *L2, char input1[])
{
    int set, done = 0;
    element *current, *curtemp;
    
    current = (*L1).first; curtemp = (*L1).first; set = 1;
    while((done == 0) && (current != NULL))
    {
        if(strcmp(current->container.name, input1) == 0)
        {
            done = 1;
        }
        else
        {
            curtemp = current;
            current = current->next;   
        }
    }

    if(done == 0)
    {
        current = (*L2).first; curtemp = (*L2).first; set = 2;
        while((done == 0) && (current != NULL))
        {
            if(strcmp(current->container.name, input1) == 0)
            {
                done = 1;
            }
            else   
            {
                curtemp = current;
                current = current->next;   
            }
        }
    }

    if(set == 1)
    {
        addlast(current->container, L2);

        if(current == (*L1).first)
        {
            delfirst(L1);
        }
        else
        {
            delafter(curtemp, L1);
        }
    }
    else
    {
        addlast(current->container, L1);
        
        if(current == (*L2).first)
        {
            delfirst(L2);
        }
        else
        {
            delafter(curtemp, L2);
        }
    }
} */