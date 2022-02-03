#include "headsimsta.h"

int main(){
    int i;
    stack S;
    create_empty(&S);

    int n;
    scanf("%d", &n);

    char input[50];
    int input_nilai;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", input);
        if (strcmp(input, "push") == 0)
        {
            scanf("%d", &input_nilai);
            push(input_nilai, &S);
        }
        else if (strcmp(input, "pop_cari") == 0)
        {
            scanf("%d", &input_nilai);
            pop_cari(input_nilai, &S);
        }
        else if (strcmp(input, "pop_banyak") == 0)
        {
            scanf("%d", &input_nilai);
            pop_banyak(input_nilai, &S);
        }
        else if (strcmp(input, "print_stack") == 0)
        {
            print_stack(S);
        }
    }
    
    return 0;
}

/* 
15
push 3
push 5
push 5
push 7
print_stack
pop_cari 5
print_stack
push 20
push 13
pop_banyak 3
print_stack
push 2
push 9
pop_cari 1
print_stack
 */


/* 
7
nani 6 bandung 350000
rohaedi 10 cicalengka 400000
darmaji 1 cilacap 250000
siti 2 garut 500000
yolanda 11 garut 500000
anik 13 garut 600000
yayat 5 tasikmalaya 500000
2 
*/