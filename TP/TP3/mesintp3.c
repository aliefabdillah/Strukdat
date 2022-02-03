#include "headtp3.h"

void create_empty(stack *S){
    (*S).top = NULL;
}

int count_elemen(stack S){
    int total = 0;

    if (S.top != NULL)
    {
        /* if stack not empty */
        elemen* pointer;

        //inisialitation
        pointer = S.top;

        while (pointer != NULL)
        {
            total = total + 1;

            //iteration
            pointer = pointer->next;
        }   
    }
    return total;
}


void push(int year, char title[], char band[], stack *S){
    elemen* new;                               //declartion pointer for new element
    new = (elemen*) malloc (sizeof (elemen));    //to call element from memory
    strcpy(new->kontainer.title, title);
    strcpy(new->kontainer.band, band);
    new->kontainer.year = year;

    if ((*S).top == NULL)
    {
        new->next = NULL;
    }
    else
    {
        new->next = (*S).top;
    }
    (*S).top = new;
    new = NULL;
}

void pop(stack *S)
{
    
    if ((*S).top != NULL)     //if stack not empty
    {
        elemen* erase = (*S).top;     //erase pointer pointing to element top of stack
        if (count_elemen(*S) == 1)      //if just one element in stack
        {
            (*S).top = NULL;
        }
        else{

            (*S).top = (*S).top->next;
        }
        erase->next = NULL;
        free(erase);        //procedure for release element who pointing by erase pointer
    }

}

void print_stack(stack S)
{
        
        //inisialisasi
        elemen* pointer = S.top;
        
        int i = 1;
        while (pointer != NULL)      //looping until pointer null
        {
            printf("%d. %s\n", i, pointer->kontainer.title);
            pointer = pointer->next;
            i++;      
        }
}

void input_rock_pop(stack S_all, stack *S_rock, stack *S_pop){
    int sum;
    int len;
    elemen* ptr = S_all.top;

    //checking tittle
    while (ptr != NULL)
    {
        len = strlen(ptr->kontainer.title);     //variabel len for hold value of string length

        sum = 0;                                //initialization sum from 0
        for (int i = 0; i < len; i++)           //looping until i = len
        {
            sum = sum + ptr->kontainer.title[i];        //enter ascii value from each letter in string
        }

        //if sum is even
        if (sum % 2 == 0)
        {
            push(ptr->kontainer.year, ptr->kontainer.title, ptr->kontainer.band, S_rock);
        }
        //if sum is odd
        else
        {
            push(ptr->kontainer.year, ptr->kontainer.title, ptr->kontainer.band, S_pop);
        }

        //iteration
        ptr = ptr->next;
    }
}