#include "head_sep.h"

int main()
{
    //deklarasi queue
    queue Q_antrian;
    create_empty(&Q_antrian);

    int n;
    scanf("%d", &n);

    char nama[50];
    int prioritas;
    char kota[50];
    int biaya;

    //perulangan masukan
    for (int i = 0; i < n; i++)
    {
        scanf("%s", nama);
        scanf("%d", &prioritas);
        scanf("%s", kota);
        scanf("%d", &biaya);
        prioriy_add(nama, prioritas, kota, biaya, &Q_antrian);
    }
    
    //masukan jumlah keluar
    int jumlah_keluar;
    scanf("%d", &jumlah_keluar);

    //prosedur print queue
    print_queue(jumlah_keluar, Q_antrian);

    return 0;
}