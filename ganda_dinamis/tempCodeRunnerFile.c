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