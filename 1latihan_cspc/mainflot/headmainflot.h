
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct 
{
    float bil;
}daftar_float;

typedef struct elmt* almt_elmn;     
typedef struct elmt
{
    daftar_float kontainer;
    almt_elmn next;
}elemen;

typedef struct 
{
    elemen* first;
}list;


void create(list *L);
void add_first(float bil, list *L);
void sort(float sel[], float inp[], int n);
void print_element(list L);


// for ( j = 0; j < n; j++)
//         {
//             if (strcmp(choose_sort, "asc") == 0)
//             {
//                 if (now->kontainer.rate > after->kontainer.rate)
//                 {
//                     temp_rate = now->kontainer.rate;
//                     now->kontainer.rate = after->kontainer.rate;
//                     after->kontainer.rate = temp_rate; 
//                 }
//             }
//             else
//             {
//                 if (now->kontainer.rate > after->kontainer.rate)
//                 {
//                     temp_rate = now->kontainer.rate;
//                     now->kontainer.rate = after->kontainer.rate;
//                     after->kontainer.rate = temp_rate; 
//                 }
//             }
//             after = after->next;
//         }
//         now = now->next;

