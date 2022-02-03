#include "headertp2.h"

void create_list(list *L){
    (*L).first = NULL;      //NULL artinya pointer first mengaskses elemen kosong di sebuah memori
    (*L).tail = NULL;
}

int count_elemen(list L){
    int total = 0;

    if (L.first != NULL)
    {
        /* List tidak kosong */
        elemen* ptr;

        //inisialiasi
        ptr = L.first;

        while (ptr != NULL)
        {
            total = total + 1;

            ptr = ptr->next;
        }   
    }
    return total;
}

void add(char nama[], int harga, int kode, list *L){
    elemen* new;                               //deklarasi pointer bernama new
    new = (elemen*) malloc (sizeof (elemen));    //perintah untuk mengalokasikan satu elemen dari memory lalu di acu oleh pointer new
    strcpy(new->kontainer.nama, nama);
    new->kontainer.harga = harga;
    new->kontainer.kode = kode;

    if ((*L).first == NULL)
    {
        new->next = NULL;
        new->prev = NULL;
        (*L).tail = new;
        
    }
    else
    {
        new->next = (*L).first;
        new->prev = NULL;
        (*L).first->prev = new;
    }
    (*L).first = new;
    new = NULL;
}

void del_first(list *L)
{
    
    if ((*L).first != NULL)     //jika list tidak kosong
    {
        elemen* erase = (*L).first;     //pointer hapus menunjuk elemen pertama dari list
        if (count_elemen(*L) == 1)      //jika cuma 1 elemen saja
        {
            (*L).first = NULL;
            (*L).tail = NULL;
        }
        else{
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            erase->next = NULL;
        }

        free(erase);        //prosedur melepaskan elemen dari memori yang ditunjuk pointer hapus
    }
}

void del_after(elemen* before, list *L)
{
    if (before != NULL)
    {
        elemen* erase = before->next;
    
        //jika elemen yang ditunjuk setelah prev != NULL / ada elemen yang akan dihapus
        if (erase != NULL)
        {
            if (erase->next == NULL)    //jika elemennya di akhir
            {
                before->next = NULL;
                (*L).tail = before;
            }
            else                        //jika ditengah
            {       
                before->next = erase->next;         //pointer next dari before menjadi menunjuk ke next dari erase
                erase->next->prev = before;         //pointer prev dari data setelah prev menunjuk before
                erase->next = NULL;                 //pointer next dari elemen yang akan dihapus di null kan
            }
            erase->prev = NULL;
            free(erase);
        }
    }
}

void del_last(list *L)
{
    if ((*L).first != NULL)     //jika elemen tidak kosong
    {
        if (count_elemen(*L) == 1)  //jika elemen tinggal 1
        {
            del_first(L);
        }
        else
        {
            del_after((*L).tail->prev, L);
        }
    }
}

void cek(list *L)
{
    if ((*L).first != NULL)
    {
        int total = 0;
        
        elemen* count = (*L).first;

        //pengecekan jumlah kode yang ganjil
        while (count != NULL)
        {
            if (count->kontainer.kode % 2 != 0)
            {
                total++;
            }
            count = count->next;
        }
        
        //jika semua elemen data merupakan kode ganjil
        if (total == count_elemen(*L))
        {
            int i;

            for ( i = count_elemen(*L); i >= 1; i--)
            {
                del_last(L);
            }
        }
        else
        {
            elemen* ptr = (*L).first;
            do
            {
                if (ptr->kontainer.kode % 2 != 0)
                {
                    elemen* erase;
                    elemen* before;
                    erase = ptr;
                    if (erase == (*L).first)
                    {
                        (*L).first = (*L).first->next;
                        ptr = (*L).first;
                        (*L).first->prev = NULL;
                        erase->next = NULL;
                        free(erase); 
                    }
                    else
                    {
                        before = erase->prev;
                        if (erase->next == NULL)    //jika elemennya di akhir
                        {
                            before->next = NULL;
                            ptr = before->next;
                            (*L).tail = before;
                        }
                        else                        //jika ditengah
                        {       
                            before->next = erase->next;         //pointer next dari before menjadi menunjuk ke next dari erase
                            ptr = before->next;
                            erase->next->prev = before;         //pointer prev dari data setelah prev menunjuk before
                            erase->next = NULL;                 //pointer next dari elemen yang akan dihapus di null kan
                        }
                        erase->prev = NULL;
                        free(erase);
                    }
                }
                else
                {
                    ptr = ptr->next;
                }
            }while (ptr != NULL);
        }
    }
}

void sort(char komponen[], char methode[], list *L){
    int swapped;             
    elemen* pointer = (*L).first;                //pointer untuk elemen sekarang
    elemen* sorted = NULL;                       //pointer sorted untuk menandakan elemen yang paling awal dari daftar elemen yang telah di sort
    elemen* next;              //pointer untuk elemen setelah elemen sekarang
    elemen* temp;              //pointer untuk penahan saat pertukarann

    //jika list tidak kosong
    if((*L).first != NULL)
    {
        // jika harga
        if (strcmp(komponen, "H") == 0)
        {
            //sorting secara ascending
            if (strcmp(methode, "Asc") == 0)
            {
                //sorting pointer next
               while (pointer != NULL)
               {
                   next = pointer->next;                                                                    //next menunjuk ke elemen setelah sekarang
                   if ((sorted == NULL) || (sorted->kontainer.harga >= pointer->kontainer.harga))           //jik sorted nya masih kosong atau elemen yang ditunjuk oleh sorted >= elemen yang ditunjuk pointer
                   {
                       pointer->next = sorted;              //next dari elemen sekarang di NULL kan
                       sorted = pointer;                    //pointer sorted menunjuk elemen sekarang
                   }
                   else
                   {
                       temp = sorted;                       //temp menunjuk sorted
                       while ((temp->next != NULL) && (temp->next->kontainer.harga < pointer->kontainer.harga))     //pencarian elemen dimana jika elemen setelah temp NULL atau elemen setelah temp tidak kurang dari elemen sekarang maka berhenti
                       {
                           temp = temp->next;
                       }
                       
                       pointer->next = temp->next;          //elemen setelah sekarang menunjuk elemen setelah temp
                       temp->next = pointer;                //elemen setelah temp menunjuk elemen sekarang
                   }
                   
                   pointer = next;                          //iterasi while
               }

               (*L).first = sorted;                         //ketika semua sudah tersorting maka first ditunjukan ke sorted (karena sorted selalu paling awal)

                //sort prev
               if ((*L).first != NULL)
               {
                   elemen* tunjuk = (*L).first;             //deklarasi pointer tunjuk  ke data awal
                   tunjuk->prev = NULL;                     //prev dari elemen awal di NULL kan

                   while (tunjuk->next != NULL)             //perulangan selama elemen setelah tunjuk tidak sama dengan NULL
                   {
                       tunjuk->next->prev = tunjuk;         //pointer prev dari elemen setelah elemen tunjuk = elemen tunjuk saat ini
                       
                       //jika elemen setelah tunjuk = NUll
                       if (tunjuk->next == NULL)           
                       {
                           (*L).tail = tunjuk;              //maka tail nunjuk ke akhir
                       }
                       tunjuk = tunjuk->next;               //iterasi while
                   }
                   
               }
            }
            //jika descending
            if (strcmp(methode, "Desc") == 0)
            {
                //sorting pointer next
                while (pointer != NULL)
               {
                   next = pointer->next;
                   if ((sorted == NULL) || (sorted->kontainer.harga <= pointer->kontainer.harga))
                   {
                       pointer->next = sorted;
                       sorted = pointer;
                   }
                   else
                   {
                       temp = sorted;
                       while ((temp->next != NULL) && (temp->next->kontainer.harga > pointer->kontainer.harga))
                       {
                           temp = temp->next;
                       }
                       
                       pointer->next = temp->next;
                       temp->next = pointer;
                   }
                   
                   pointer = next;
               }

               (*L).first = sorted;

                //sort prev
               if ((*L).first != NULL)
               {
                   elemen* tunjuk = (*L).first;
                   tunjuk->prev = NULL;

                   while (tunjuk->next != NULL)
                   {
                       tunjuk->next->prev = tunjuk;
                       if (tunjuk->next == NULL)
                       {
                           (*L).tail = tunjuk;
                       }
                       tunjuk = tunjuk->next;
                   }
               }
            }
        }
        else
        {
            if (strcmp(methode, "Asc") == 0)
            {
                //sorting pointer next
                while (pointer != NULL)
               {
                   next = pointer->next;
                   if ((sorted == NULL) || (sorted->kontainer.kode >= pointer->kontainer.kode))
                   {
                       pointer->next = sorted;
                       sorted = pointer;
                   }
                   else
                   {
                       temp = sorted;
                       while ((temp->next != NULL) && (temp->next->kontainer.kode < pointer->kontainer.kode))
                       {
                           temp = temp->next;
                       }
                       
                       pointer->next = temp->next;
                       temp->next = pointer;
                   }
                   
                   pointer = next;
               }

               (*L).first = sorted;

                //sort prev
               if ((*L).first != NULL)
               {
                   elemen* tunjuk = (*L).first;
                   tunjuk->prev = NULL;

                   while (tunjuk->next != NULL)
                   {
                       tunjuk->next->prev = tunjuk;
                       if (tunjuk->next == NULL)
                       {
                           (*L).tail = tunjuk;
                       }
                       tunjuk = tunjuk->next;
                   }
               }
            }
            if (strcmp(methode, "Desc") == 0)
            {
                //sorting pointer next
                while (pointer != NULL)
               {
                   next = pointer->next;
                   if ((sorted == NULL) || (sorted->kontainer.kode <= pointer->kontainer.kode))
                   {
                       pointer->next = sorted;
                       sorted = pointer;
                   }
                   else
                   {
                       temp = sorted;
                       while ((temp->next != NULL) && (temp->next->kontainer.kode > pointer->kontainer.kode))
                       {
                           temp = temp->next;
                       }
                       
                       pointer->next = temp->next;
                       temp->next = pointer;
                   }
                   
                   pointer = next;
               }

               (*L).first = sorted;

                //sorting pointer prev
               if ((*L).first != NULL)
               {
                   elemen* tunjuk = (*L).first;
                   tunjuk->prev = NULL;

                   while (tunjuk->next != NULL)
                   {
                       tunjuk->next->prev = tunjuk;
                       if (tunjuk->next == NULL)
                       {
                           (*L).tail = tunjuk;
                       }
                       tunjuk = tunjuk->next;
                   }
               }
            }
        }
    }
    //jkika list kosong
    else
    {
        printf("=================\n");
        printf(" Loh kok gaada:(\n");
        printf("=================\n");
    }
}

 
void print(list L){
    if(L.first != NULL)
    {
        /* inisialisasi */
        elemen* tunjuk = L.first;
        
        while (tunjuk != NULL)
        {
            printf("%s %d %d\n", tunjuk->kontainer.nama, tunjuk->kontainer.harga, tunjuk->kontainer.kode);
            
            // iterasi
            tunjuk = tunjuk->next;
        }
    }
    
}