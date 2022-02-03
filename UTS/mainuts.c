/*Saya Alief Muhammad Abdillah 2003623 mengerjakan Kuis Cksg21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

/* Bagian Main */
#include "headuts.h"

int main(){
    list L;                 //declaration list
    create_list(&L);        //call procedure create list

    //declaration for total of row
    int n;
    scanf("%d", &n);

    //declaration for input    
    char nama_res[100];
    char menu[100];
    char harga[100];

    //deklarasi untuk switch
    char res1[100];
    char res2[100];
    char menu_switch[100];
    
    
    int i;
    //perulangan masukan
    for ( i = 0; i < n+1; i++)
    {
        char start[5];
        scanf("%s", start);
        if (strcmp(start, "start") == 0)
        {
            scanf("%s", nama_res);
            add_last_baris(nama_res, &L);
            elemen_baris* now = isi_kolom(nama_res, L);     //menggunakan prosedur isi kolom untuk mengetahui posisi baris untuk masukan" kolom selanjutnya

            scanf("%s", menu);
            while (strcmp(menu, "end") != 0)
            {
                scanf("%s", harga);
                add_last_kolom(menu, harga, now);

                scanf("%s", menu);
            }
        }
        if (strcmp(start, "switch") == 0)
        {
            scanf("%s", res1);
            while (strcmp(res1, "end") != 0)
            {
                scanf("%s %s", menu_switch, res2);
                swap(res1, res2, menu_switch, &L);      //proses swap elemen koolom

                scanf("%s", res1);
            }
        }
    }
    
    print_elemen(L);

    return 0;
    
}
/* 
4
start
restoran1
soto 12000
sate 15000
nasi 5000
lalapan 2000
end
start
restoran2
steakmakaroni 10000
jengkolgoreng 2000
fetucinisausjengkol 20000
bandengisiciwidey 34000
end
start
restoran3
pisangsago 25000
melonsago 25000
semangkasago 25000
end
start
restoran4
tumisbungapepaya 4000
tumisdaunpepaya 4000
pepeskemangi 4000
end
switch
restoran1 soto restoran4
end 
*/
