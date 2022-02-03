#include "headsimque.h"

int main(){
    queue Q;
    create_empty(&Q);

    int n;
    scanf("%d", &n);

    char input[50];
    int input_nilai;
    for (int i = 0; i < n; i++)
    {
        scanf("%s", input);
        if (strcmp(input, "add") == 0)
        {
            scanf("%d", &input_nilai);
            add(input_nilai, &Q);
        }
        else if (strcmp(input, "add_prioritas") == 0)
        {
            int priority;
            scanf("%d", &input_nilai);
            scanf("%d", &priority);
            prioriy_add(input_nilai, priority, &Q);
        }
        else if (strcmp(input, "del") == 0)
        {
            out(&Q);
        }
        else if (strcmp(input, "print_queue") == 0)
        {
            print_queue(Q);
        }
    }

    return 0;
    
}