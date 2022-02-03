#include "headlistgg.h"

int main(){
    list L;
    create_list(&L);

    //masukan list besar 1 dan 2
    add_first_baris(2, &L);
    add_first_baris(1, &L);

    //jumlah masukan
    int i, n;
    scanf("%d", &n);

    int input;
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &input);
        if (input % 2 != 0)
        {
            if (L.first->col == NULL)
            {
                add_first_kolom(input, L.first);
            }
            else
            {
                add_last_kolom(input, L.first);
            }
        }
        else
        {
            if (L.first->next->col == NULL)
            {
                add_first_kolom(input, L.first->next);
            }
            else
            {
                add_last_kolom(input, L.first->next);
            }
        }
    }

    print_elemen(L);

    return 0;
}