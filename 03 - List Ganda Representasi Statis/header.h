// Deklarasi pustaka.
#include <stdio.h>
#include <string.h>

// Deklarasi alokasi data, agar mudah dalam mengubahnya.
#define DATA_SIZE 100

// Deklarasi tipe bentukan untuk data.
typedef struct
{
    char str[52];
} value;

// Deklarasi tipe bentukan untuk elemen list.
typedef struct
{
    value container;
    int prev, next;
} element;

// Deklarasi tipe bentukan untuk "list".
typedef struct
{
    // Saya ganti "first" jadi "head", biar serasi aja gitu "kepala-ekor" hehe :)
    // * Meski ngikut sama forum-forum luar juga, kebanyakan pake istilah head.
    int head, tail;
    element data[DATA_SIZE];
} list;

/* Penggunaan setiap prosedur dan fungsi dijelaskan di bagian pustaka
   utama (machine.c). */

// Inisialisasi list.
void createlist(list *L);

// Modifikasi list: Add.
void addfirst(value data, list *L);
void addafter(int before, value data, list *L);
void addlast(value data, list *L);

// Prosedur dan fungsi tambahan.
int countelement(list L);
int emptyelement(list L);
void printelement(list L);