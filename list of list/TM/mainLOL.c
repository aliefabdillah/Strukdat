/* Bagian Main */
#include "headLOL.h"

int main(){
    list L;                 //declaration list
    create_list(&L);        //call procedure create list

    //declaration for total of row
    int n;
    scanf("%d", &n);

    //declartion for input club name and year
    char klub[n][50];
    int tahun[n];

    int i = 0;
    while (i < n)
    {
        scanf("%s %d", klub[i], &tahun[i]);
        cek(klub[i], tahun[i], &L);             //call procedure check and sort club name
        cek_kol(klub[i], &L);                   //call procedure input to coloumn
        i++;                                    //iteration
    }

    del_after_kolom(L.first->next->col->next_kol);
    del_last_baris(&L);
    del_first_kolom(L.first);
    
    print_elemen(L);                            //procedure for print final data

    return 0;
    
}