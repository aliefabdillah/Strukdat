// Deklarasi sumber global.
#include "header.h"

/* Inisialisasi List. */

// Prosedur untuk membuat list.
void createlist(list *L)
{
    // Inisialisasi pointer elemen pertama.
    (*L).head = (-1);
    (*L).tail = (-1);

    // Inisialisasi pointer elemen sisa.
    int i;
    for(i = 0; i < DATA_SIZE; i++)
    {
        (*L).data[i].prev = (-2);
        (*L).data[i].next = (-2);
    }
}

/* Manipulasi List : Add. */

// Prosedur untuk menambah data ke elemen pertama.
void addfirst(value data, list *L)
{
    // Jika alokasi masih tersisa, program dijalankan.
    if(countelement(*L) < DATA_SIZE)
    {
        // Menyiapkan data yang akan ditambahkan.
        int new = emptyelement(*L);
        (*L).data[new].container = data;

        // Jika list masih kosong...
        if((*L).head == (-1))
        {
            // Masukkan data ke elemen pertama.
            (*L).data[new].prev = (-1);
            (*L).data[new].next = (-1);
            (*L).tail = new;
        }
        // Jika data sudah ada...
        else
        {
            // "Arahkan" pointer next elemen baru ini ke data sebelumnya.
            (*L).data[new].prev = (-1);
            (*L).data[new].next = (*L).head;
            (*L).data[(*L).head].prev = new;
        }

        // "Arahkan" pointer elemen pertama ke data baru.
        (*L).head = new;
    }
    // Jika alokasi sudah habis, tampilkan pesan error.
    else
    {
        printf("No empty container.\n");
    }
}

// Prosedur untuk menyisipkan data ke elemen setelah yang ditentukan sebelumnya.
void addafter(int before, value data, list *L)
{
    // Jika alokasi masih tersisa, program dijalankan.
    if(countelement(*L) < DATA_SIZE)
    {
        // Menyiapkan data yang akan ditambahkan.
        int new = emptyelement(*L);
        (*L).data[new].container = data;

        // Jika elemen setelah yang ditambahkan masih ada...
        if((*L).data[before].next != (-1))
        {
            // "Berikan" pointer dari elemen sebelumnya, ke data yang dimasukkan ini.
            (*L).data[new].prev = before;
            (*L).data[new].next = (*L).data[before].next;
            (*L).data[before].next = new;
            (*L).data[(*L).data[new].next].prev = new;
        }
        // Jika elemen yang ditentukan berada di akhir...
        else
        {
            // Masukkan data ke elemen terakhir.
            (*L).data[new].prev = before;
            (*L).data[before].next = new;
            (*L).data[new].next = (-1);
            (*L).tail = new;
        }
    }
    // Jika alokasi sudah habis, tampilkan pesan error.
    else
    {
        printf("No empty container.\n");
    }
}

// Prosedur untuk menambahkan data ke elemen terakhir.
void addlast(value data, list *L)
{
    // Jika list masih kosong...
    if((*L).head == (-1))
    {
        // Prosedur untuk menambahkan data ke elemen pertama dipanggil.
        addfirst(data, L);
    }
    // Jika list sudah ada...
    else
    {
        // Prosedur untuk menambahkan data ke elemen setelah pointer "tail" dipanggil.
        addafter((*L).tail, data, L);
    }
}

/* Algoritma tambahan. */

// Prosedur untuk menghitung elemen yang sudah ada di list.
int countelement(list L)
{
    // Deklarasi nilai total.
    int total = 0;

    // Menghitung data di elemen list secara berurutan.
    if(L.head != (-1))
    {
        int current;
        current = L.head;

        while(current != (-1))
        {
            total++;
            current = L.data[current].next;
        }
    }

    // Mengembalikan nilai total.
    return total;
}

// Prosedur untuk memeriksa elemen yang masih kosong.
int emptyelement(list L)
{
    // Deklarasi hasil dan inisialisasi dengan nilai kosong.
    int result = (-1);

    // Jika elemen yang ada masih kurang dari alokasi, program dijalankan.
    if(countelement(L) < DATA_SIZE)
    {
        int i, found;

        // Mencari elemen yang kosong, dari awal sampai akhir secara berurutan.
        i = 0; found = 0;
        while((found == 0) && (i < DATA_SIZE))
        {
            if(L.data[i].next == (-2))
            {
                result = i;
                found = 1;
            }
            else
            {
                i++;
            }
        }
    }

    // Mengembalikan indeks hasil.
    return result;
}

// [SUDAH DIMODIFIKASI] Prosedur untuk mengeluarkan seluruh elemen dari awal ke akhir.
void printelement(list L)
{
    // Jika list tidak kosong, program dijalankan.
    if(L.head != (-1))
    {
        // Deklarasi variabel...
        int i,                         // Perulangan.
            fspace = 0, midspace = 0,  // Spasi depan (first) dan tengah (middle).
            curhead, curtail;          // String depan dan belakang saat ini.

        // Menghitung spasi tengah yang diperlukan.
        curhead = L.head;
        while(curhead != (-1))
        {
            midspace += strlen(L.data[curhead].container.str);
            curhead = L.data[curhead].next;
        }
        
        // Menampilkan string sesuai yang telah ditentukan.
        curhead = L.head; curtail = L.tail;
        while(curhead <= curtail)
        {
            // Jika string depan dan belakang tidak sama...
            if(curhead != curtail)
            {
                // Menampilkan spasi depan.
                for(i = 0; i < fspace; i++)
                {
                    printf(" ");
                }

                // Menampilkan string belakang.
                printf("%s", L.data[curtail].container.str);

                // Mengurangkan nilai spasi tengah dengan string yang ditampilkan saat ini,
                // lalu menampilkan spasi tengah tersebut.
                midspace -= (strlen(L.data[curhead].container.str) + strlen(L.data[curtail].container.str));
                for(i = 0; i < midspace; i++)
                {
                    printf(" ");
                }

                // Menampilkan string depan.
                printf("%s\n", L.data[curhead].container.str);

                // Menambah nilai spasi depan, sesuai string belakang yang ditampilkan saat ini.
                fspace += strlen(L.data[curtail].container.str);
                
            }
            // Jika string depan dan belakang sama (pertengahan dari list of string)...
            else
            {
                // Menampilkan spasi depan.
                for(i = 0; i < fspace; i++)
                {
                    printf(" ");
                }

                // Menampilkan "perwakilan" string yang ditampilkan.
                printf("%s\n", L.data[curhead].container.str);
            }

            // Memajukan string depan dan memundurkan string belakang, hingga mereka saling melewati.
            curhead = L.data[curhead].next; curtail = L.data[curtail].prev;
        }
    }
}