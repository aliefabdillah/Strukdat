/*
   ============================================================
   | Saya Ghifari Octaverin 2000952 mengerjakan TP2           |
   | dalam mata kuliah Struktur Data                          |
   | untuk keberkahanNya maka saya tidak melakukan kecurangan |
   | seperti yang telah dispesifikasikan. Aamiin              |
   ============================================================
*/

#include "header.h"

void createList(list *L){
    (*L).first = NULL;
    (*L).tail = NULL;
}

int countElement(list L){
    int result = 0;
    if (L.first != NULL)
    {   // jika list tidak kosong
        element* ptr;
        ptr = L.first;
        while (ptr != NULL)
        {
            result++;
            ptr = ptr->next;    // iterasi
        }
    }
    return result;
}

void addFirst(char name[], int price, int productCode, list *L){
    element* new;
    new = (element*) malloc (sizeof(element));

    // memasukan data ke list
    strcpy(new->container.name, name);
    new->container.price = price;
    new->container.productCode = productCode;

    if ((*L).first == NULL)
    {   // jika list kosong
        new->next = NULL;
        new->prev = NULL;
        (*L).tail = new;
    }else
    {   // jika list tidak kosong
        new->next = (*L).first;
        new->prev = NULL;
        (*L).first->prev = new;
    }
    (*L).first = new;
    new = NULL;
}

void addAfter(element* before, char name[], int price, int productCode, list *L){
    if (before != NULL)
    {
        element* new;
        new = (element*) malloc (sizeof(element));

        // memasukan data ke list
        strcpy(new->container.name, name);
        new->container.price = price;
        new->container.productCode = productCode;

        if (before->next == NULL)
        {   // jika menjadi element terakhir
            new->next = NULL;
            (*L).tail = new;
        }else
        {   // jika bukan menjadi element terakhir
            new->next = before->next;
            new->next->prev = new;
        }
        new->prev = before;
        before->next = new;
        new = NULL;
    }
}

void delFirst(list *L){
    if ((*L).first != NULL)
    {   // jika bukan list kosong
        element* delete = (*L).first;
        if (countElement(*L) == 1)
        {   // jika list hanya terdiri dari satu element
            (*L).first = NULL;
            (*L).tail = NULL;
        }else
        {   // jika banyak element
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            delete->next = NULL;
        }
        free(delete);
    }
}

void delAfter(element* before, list *L){
    if (before != NULL)
    {
        element* delete = before->next;
        if (delete != NULL)
        {
            if (delete->next == NULL)
            {   // jika yang dihapus adalah element terakhir
                before->next = NULL;
                (*L).tail = before;
            }else
            {   // jika bukan element terakhir
                before->next = delete->next;
                delete->next->prev = before;
                delete->next = NULL;
            }
            delete->prev = NULL;
            free(delete);
        }
    }
}

void delLast(list *L){
    if ((*L).first != NULL)
    {   // jika list tidak kosong
        if (countElement(*L) == 1)
        {   // jika list hanya terdiri dari satu element
            delFirst(L);
        }else
        {   // jika lebih dari satu element
            delAfter((*L).tail->prev, L);
        }
    }
}

void delAll(list *L){
    if (countElement(*L) != 0)
    {   // jika list tidak kosong
        for (int i = countElement(*L); i >= 1; i--)
        {
            delLast(L);
        }
    }
}

void checkingProduct(list *L){
    element* ptr;
    int delete, flag, count = 0;
    
    // inisialisasi
    ptr = (*L).first;
    while (ptr != NULL)
    {
        if (ptr->container.productCode % 2 != 0) // jika productCodenya ganjil
        {
            count++;
        }
        ptr = ptr->next; // iterasi
    }
    
    if (countElement(*L) == count)
    {   // jika semua element memiliki productCode ganjil
        delAll(L);
    }else
    { // jika tidak semua element memiliki productCode ganjil
        do
        {
            delete = 0;
            ptr = (*L).first;
            flag = 1;
            while (ptr != NULL && flag != 0)
            {
                if (ptr->container.productCode % 2 != 0)
                {   // jika productCodenya ganjil
                    delAfter(ptr->prev, L);
                    delete = 1;
                    flag = 0;
                }else
                {   // jika genap
                    ptr = ptr->next;
                }
            }
        } while (delete == 1); // looping selama masih ada yang bisa dihapus
    }
}

void bubbleSort(list *L, char sortMode[], int arr[], int count, char sortBy){
    int swap, i, temp;
    element* ptr;
    if (strcmp(sortMode, "Asc") == 0)
    {   // mode ascending
        do
        {
            swap = 0;
            for ( i = 0; i < count - 1; i++)
            {
                if (arr[i] > arr[i+1])
                {   // ascending
                    // swap pointer
                    swapPtr(L, arr[i], arr[i+1], sortBy);
                    // swap acuan sorting
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    swap = 1;
                }
            }
        } while (swap == 1);
    }else
    {   // mode descending
        do
        {
            swap = 0;
            for ( i = 0; i < count - 1; i++)
            {
                if (arr[i] < arr[i+1])
                {   // descending
                    // swap pointer
                    swapPtr(L, arr[i], arr[i+1], sortBy);
                    // swap acuan sorting
                    temp = arr[i];
                    arr[i] = arr[i+1];
                    arr[i+1] = temp;
                    swap = 1;
                }
            }
        } while (swap == 1);
    }
}

void swapPtr(list *L, int valueA, int valueB, char sortBy){
    element* ptr = (*L).first;
    element* ptrA, *ptrB;
    
    if (sortBy == 'H')
    {   // berdasarkan harga
        while (ptr != NULL && ptr->container.price != valueA)
        {   // proses mencari data ke 1
            ptr = ptr->next;
        }
        // simpan pointer
        ptrA = ptr;
        ptr = (*L).first;
        while (ptr != NULL && ptr->container.price != valueB)
        {   // proses mencari data ke 2
            ptr = ptr->next;
        }
        // simpan pointer
        ptrB = ptr;
    }else
    {   // berdasarkan kode produk
        while (ptr != NULL && ptr->container.productCode != valueA)
        {   // proses mencari data ke 1
            ptr = ptr->next;
        }
        // simpan pointer
        ptrA = ptr;
        ptr = (*L).first;
        while (ptr != NULL && ptr->container.productCode != valueB)
        {   // proses mencari data ke 2
            ptr = ptr->next;
        }
        // simpan pointer
        ptrB = ptr;
    }

    if (ptrA->prev == NULL)
    {   // jika data 1 merupakan element pertama
        (*L).first = ptrB;
    }else
    {   // jika data 1 bukan element pertama
        ptrA->prev->next = ptrB;
    }
    if (ptrB->next == NULL)
    {   // jika data 2 merupakan element terakhir
        (*L).tail = ptrA;
    }else
    {   // jika data 2 bukan element terakhir
        ptrB->next->prev = ptrA;
    }

    // swap pointer
    ptrB->prev = ptrA->prev;
    ptrA->prev = ptrB;
    ptrA->next = ptrB->next;
    ptrB->next = ptrA;
}

void printElement(list L){
    if (L.first != NULL)
    {   // jika list tidak kosong
        element* ptr = L.first;
        while (ptr != NULL)
        {
            printf("%s %d %d\n", ptr->container.name, ptr->container.price, ptr->container.productCode);
            ptr = ptr->next; // iterasi
        }
    }else
    {   // jika list kosong
        printf("=================\n Loh kok gaada:(\n=================\n");
    }
}
