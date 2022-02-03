/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TM1           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createList(list *L){   // membuat list
    (*L).first = NULL;
}

int countElement(list L){   // menghitung element dalam list
    int result = 0;

    if (L.first != NULL)
    {   //list tidak kosong
        element* tunjuk;

        //inisialisasi
        tunjuk = L.first;
        while (tunjuk != NULL)
        {
            result++;
            tunjuk = tunjuk->next;
        }
    }
    
    return result;
}

void addFirst(char name[], int price, float rating, list *L){
    element* new;
    new = (element*) malloc (sizeof (element)); // alokasi memori
    
    // masukan input ke dalam list
    strcpy(new->container.name, name);
    new->container.price = price;
    new->container.rating = rating;

    if ((*L).first == NULL) // jika list kosong
    {
        new->next = NULL;
    }else   // jika list tidak kosong
    {
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

void addAfter(element* prev, char name[], int price, float rating, list *L){
    element *new;
    new = (element*) malloc (sizeof (element)); // alokasi memori

    // masukan input ke dalam list
    strcpy(new->container.name, name);
    new->container.price = price;
    new->container.rating = rating;

    if (prev->next == NULL) // jika list kosong
    {
        new->next = NULL;
    }else   // jika list tidak kosong
    {
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;
}

void addLast(char name[], int price, float rating, list *L){
    if ((*L).first == NULL)
    {   //jika list adalah list kosong
        addFirst(name, price, rating, L);
    }else
    {   //jika list tidak kosong
        //mencari element terakhir list
        element* prev = (*L).first;
        while (prev->next != NULL)
        {
            prev = prev->next;
        }
        /* setelah mendapatkan element terakhir dalam list
        kemudian jalankan prosedur addAfter */
        addAfter(prev, name, price, rating, L);
    }
}

void delFirst(list *L){
    if ((*L).first != NULL)
    {   //jika list bukan list kosong
        element* delete = (*L).first;
        if (countElement(*L) == 1)  // jika isi dari list hanya 1 element
        {
            (*L).first = NULL;
        }else   // jika list memiliki lebih dari 1 element
        {
            (*L).first = (*L).first->next;
            delete->next = NULL;
        }
        free(delete);
    }
}

void delAfter(element* prev, list *L){
    element* delete = prev->next;
    if (delete != NULL) // jika ada element yang bisa dihapus
    {
        if (delete->next == NULL)   // jika element yang ingin dihapus adalah element terakhir
        {
            prev->next = NULL;
        }else   // jika bukan element terakhir
        {
            prev->next = delete->next;
            delete->next = NULL;
        }
        free(delete);
    }
}

void delLast(list *L){
    if ((*L).first != NULL)
    {   //jika list tidak kosong
        if (countElement(*L) == 1)
        {   //list terdiri dari 1 element
            delFirst(L);
        }else   // jika list lebih dari 1 element
        {
            //mencari element terakhir list
            element* last = (*L).first;
            element* prev;
            while (last->next != NULL)
            {
                prev = last;
                last = last->next;
            }
            delAfter(prev, L);
        }
    }
}

void delAll(list *L){
    if (countElement(*L) != 0)  // jika list tidak kosong
    {
        int i;
        for ( i = countElement(*L); i >= 1; i--)
        {
            delLast(L);
        }
    }
}

void printElement(int money, list L){
    // inisialisasi
    element* tunjuk = L.first;
    menu temp[100];
    int count = 0;

    printf("=== Menu Terurut ===\n");
    while (tunjuk != NULL) // looping list
    {
        printf("%s %d %0.1f\n", tunjuk->container.name, tunjuk->container.price, tunjuk->container.rating);
        tunjuk = tunjuk->next; // iterasi
    }
    // inisialisasi
    tunjuk = L.first;
    int found = 0;
    while (tunjuk != NULL && found == 0)
    {
        if ((money - tunjuk->container.price) >= 0) // jika bisa membeli makanan
        {
            money -= tunjuk->container.price;
            strcpy(temp[count].name, tunjuk->container.name);
            temp[count].price = tunjuk->container.price;
            temp[count].rating = tunjuk->container.rating;
            count++;
        }else   // jika tidak bisa membeli
        {
            found = 1;
        }
        tunjuk = tunjuk->next; // iterasi
    }
    
    printf("\n=== Dapat Dibeli ===\n");
    if (count != 0) // jika ada makanan yang dibeli
    {
        int i;
        for ( i = 0; i < count; i++)
        {
            printf("%s %d %0.1f\n", temp[i].name, temp[i].price, temp[i].rating);
        }
    }else   // jika tidak ada makanan yang dibeli
    {
        printf("Tidak ada yang dapat dibeli\n");
    }
    printf("\nSisa uang: %d\n", money);
}

void swapPointer(float rating1, float rating2, list *L){
    // inisialisasi
    element* position, *prev;
    position = (*L).first;
    prev = NULL;
    while (position != NULL && position->container.rating != rating1)
    {   // mencari posisi rating1 pada list
        prev = position;
        position = position->next;
    }
    // menyimpan posisi rating1
    element* positionRating1 = position;
    element* prevRating1 = prev;

    position = (*L).first;
    prev = NULL;
    while (position != NULL && position->container.rating != rating2)
    {   // mencari posisi rating2 pada list
        prev = position;
        position = position->next;
    }
    // menyimpan posisi rating2
    element* positionRating2 = position;
    element* prevRating2 = prev;

    if (prevRating1 != NULL)  // jika rating1 bukan element pertama
    {
        prevRating1->next = positionRating2;
    }else   // jika rating1 adalah element pertama
    {
        (*L).first = positionRating2;
    }
    if (prevRating2 != NULL)  // jika rating2 bukan element pertama
    {
        prevRating2->next = positionRating1;
    }else   // jika rating2 adalah element pertama
    {
        (*L).first = positionRating1;
    }
    // swapping pointer next
    element* temp;
    temp = positionRating2->next;
    positionRating2->next = positionRating1->next;
    positionRating1->next = temp;
}

void sortingList(char mode[], list *L, float arr[], int count){
    float temp;
    int i, swap;

    /* cara kerja sortingnya adalah dengan mensorting data yang telah dimasukan ke dalam array
    kemudian panggil prosedur swapPointer untuk mengubah posisi pointer next data yang ada di dalam list*/

    if (strcmp(mode, "desc") == 0)  // jika input mode adalah descending
    {
        // bubble sort
        do
        {
            swap = 0;
            for ( i = 0; i < count - 1; i++)
            {
                if (arr[i] < arr[i+1])
                {
                    swapPointer(arr[i], arr[i+1], L);   // panggil prosedur swapPointer
                    // swap nilai array
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    swap = 1;
                }
            }
        } while (swap == 1);
    }else   // jika input mode ascending
    {
        // bubble sort
        do
        {
            swap = 0;
            for ( i = 0; i < count - 1; i++)
            {
                if (arr[i] > arr[i+1])
                {
                    swapPointer(arr[i], arr[i+1], L);   // panggil prosedur swapPointer
                    // swap nilai array
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    swap = 1;
                }
            }
        } while (swap == 1);
    }
}