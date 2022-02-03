// Deklarasi pustaka.
#include <stdio.h>
#include <malloc.h>
#include <string.h>

// Deklarasi tipe bentukan untuk data.
typedef struct
{
    char name[52];
    int price;
} value;

// Deklarasi tipe bentukan untuk elemen list.
typedef struct elmt *address;
typedef struct elmt
{
    value container;
    address next;
} element;

// Deklarasi tipe bentukan untuk "list".
typedef struct
{
    element *first;
} list;

/* Penggunaan setiap prosedur dan fungsi dijelaskan di bagian pustaka
   utama (machine.c). */

// Inisialisasi list.
void createlist(list *L);

// Modifikasi list: Add.
void addfirst(value data, list *L);
void addafter(element *prev, value data, list *L);
void addlast(value data, list *L);

// Prosedur dan fungsi tambahan.
int countelement(list L);
void printelement(list L);

// Sat-Modified Code: Prosedur dan fungsi pribadi.
void moveelement(list *L1, list *L2, char input1[]);