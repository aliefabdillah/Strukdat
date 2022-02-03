#include "headtp4.h"

void create_empty(queue *Q){
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int count_elemen(queue Q){
    int hasil = 0;

    if (Q.first != NULL)
    {
        /* if queue not null */
        elemen* tunjuk;

        //initialization
        tunjuk = Q.first;

        while (tunjuk != NULL)
        {
            hasil = hasil + 1;

            //iteration
            tunjuk = tunjuk->next;
        }   
    }
    return hasil;
}

void add(char name[], char member[], int time, queue *Q){
    elemen* baru;                               //declartion pointer for new element
    baru = (elemen*) malloc (sizeof (elemen));    
    strcpy(baru->kontainer.name, name);
    strcpy(baru->kontainer.member, member);
    baru->kontainer.time = time;
    baru->next = NULL;

    if ((*Q).first == NULL)
    {
        (*Q).first = baru;
    }
    else
    {
        (*Q).last->next = baru;
    }
    (*Q).last = baru;
    baru = NULL;
}

void out(queue *Q)
{
    
    if ((*Q).first != NULL)     //if queue not null
    {
        elemen* hapus = (*Q).first;     //the delete pointer points to the first element of the queue
        if (count_elemen(*Q) == 1)      //if just 1 element in queue
        {
            (*Q).first = NULL;
            (*Q).last = NULL;
        }
        else{

            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }
        free(hapus);        //proecduer to remove elemen from queue
    }
    else
    {
        printf("queue kosong\n");
    }
}

// priority add
void prioriy_add(char name[], char member[], int time, queue *Q)
{
    //declaration variabel for new element
    elemen* baru;                               
    baru = (elemen*) malloc (sizeof (elemen));    
    strcpy(baru->kontainer.name, name);
    strcpy(baru->kontainer.member, member);
    baru->kontainer.time = time;

    //if queue null then call procedure add
    if ((*Q).first == NULL)
    {
        add(name, member, time, Q);
    }
    else
    {
        // if member from input equal "platinum"
        if (strcmp(member, "platinum") == 0)
        {
            elemen* pointer = (*Q).first;
            elemen* prev = NULL;
            int stop = 0;

            //loop to find where to put the element in the queue
            while (pointer != NULL && stop == 0)
            {
                if ((strcmp(pointer->kontainer.member, "gold") == 0) || (strcmp(pointer->kontainer.member, "silver") == 0) || (strcmp(pointer->kontainer.member, "nonmember") == 0))
                {
                    stop = 1;        
                }
                else
                {
                    prev = pointer;
                    pointer = pointer->next;
                }
            }

            //if stop = 1
            if (stop == 1)
            {
                //if just one element
                if (prev == NULL)
                {
                    baru->next = (*Q).first;
                    (*Q).first = baru;
                }
                //else
                else
                {
                    baru->next = prev->next;
                    prev->next = baru;
                }
                baru = NULL;
            }
            else
            {
                add(name, member, time, Q);
            }
        }
         // if member from input equal "gold"
        else if (strcmp(member, "gold") == 0)
        {
            elemen* pointer = (*Q).first;
            elemen* prev = NULL;
            int stop = 0;

            //loop to find where to put the element in the queue
            while (pointer != NULL && stop == 0)
            {
                if ((strcmp(pointer->kontainer.member, "silver") == 0) || (strcmp(pointer->kontainer.member, "nonmember") == 0))
                {
                    stop = 1;
                }
                else
                {
                    prev = pointer;
                    pointer = pointer->next;
                }
            }

            
            if (stop == 1)
            {
                if (prev == NULL)
                {
                    baru->next = (*Q).first;
                    (*Q).first = baru;
                }
                else
                {
                    baru->next = prev->next;
                    prev->next = baru;
                }
                baru = NULL;
            }
            else
            {
               add(name, member, time, Q);
            }
        }
        // if member from input equal "gold"
        else if (strcmp(member, "silver") == 0)
        {
            elemen* pointer = (*Q).first;
            elemen* prev = NULL;
            int stop = 0;

            //loop to find where to put the element in the queue
            while (pointer != NULL && stop == 0)
            {
                if (strcmp(pointer->kontainer.member, "nonmember") == 0)
                {
                    stop = 1;
                }
                else
                {
                    prev = pointer;
                    pointer = pointer->next;
                }
            }

            if (stop == 1)
            {
                if (prev == NULL)
                {
                    baru->next = (*Q).first;
                    (*Q).first = baru;
                }
                else
                {
                    baru->next = prev->next;
                    prev->next = baru;
                }
                baru = NULL;
            }
            else
            {
               add(name, member, time, Q);
            }
        }
        //if member from input equal "nonmember"
        else
        {
            //just add to queue
            add(name, member, time, Q);
        }       
    }
}

//function to count total time in quueue
int count_time(queue Q)
{
    elemen* ptr = Q.first;

    int total = 0;
    while (ptr != NULL)
    {
        total = total + ptr->kontainer.time;
        ptr = ptr->next;
    }
    
    return total;
}

void print_queue(queue Q)
{
    if (Q.first != NULL)
    {
        // if total all time more than 6 hours
        if (count_time(Q) > 360)
        {
            elemen* pointer = Q.first;
            int total = 0;
            //looking for elements that not include to schedule
            while (pointer != NULL)
            {
                total = total + pointer->kontainer.time;

                //if total is more than 6 hours print name
                if (total > 360)
                {
                    printf("%s\n", pointer->kontainer.name);
                }
                pointer = pointer->next;
            }
        }
        //else; print "Antrian kosong."
        else
        {
            printf("Antrian kosong.\n");
        }
    }
    else
    {
        //if empty
        printf("Antrian kosong.\n");
    }
}

