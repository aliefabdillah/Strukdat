#include "headtp4.h"

int main(){
    //making queue
    queue Q;
    create_empty(&Q);
    
    //declaration variable for input user
    int n = 0;
    char name[50][50];
    char member[50][50];
    int time[50];

    //looping as long input is not equal to "stop" 
    do
    {
        scanf("%s", name[n]);
        if (strcmp(name[n], "stop") != 0)
        {
            scanf("%s", member[n]);
            scanf("%d", &time[n]);
            n++;
        }
    }while (strcmp(name[n], "stop") != 0);
    
    //procedure to add input user to queue using priority add
    for (int i = 0; i < n; i++)
    {
        prioriy_add(name[i], member[i], time[i], &Q);
    }
    
    //procedure print queue
    print_queue(Q);

    return 0;
    
}

