#include "headtp3.h"

int main(){
    int i;
    //declaration stack
    stack S_rock, S_pop, S_all;
    create_empty(&S_rock);
    create_empty(&S_pop);
    create_empty(&S_all);

    //declaration variabel for total input user
    int n;
    scanf("%d", &n);

    int year[n];
    char title[n][50];
    char band[n][50];

    //procces input user
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &year[i]);
        scanf("%s", title[i]);
        scanf("%s", band[i]);

        push(year[i], title[i], band[i], &S_all);       //enter user input to stack overall music data)
    }
    
    input_rock_pop(S_all, &S_rock, &S_pop);         //procedure for input the data to stack rock music or stack pop music
    
    //print stack
    printf("Playlist Musik Rock:\n");
    printf("===================\n");
    if (count_elemen(S_rock) == 0)
    {
        printf("BUKAN ANAK ROCK!\n");
    }
    else
    {
        print_stack(S_rock);
    }

    printf("\nPlaylist Musik Pop:\n");
    printf("===================\n");
    if (count_elemen(S_pop) == 0)
    {
        printf("BUKAN ANAK POP!\n");
    }
    else
    {
        print_stack(S_pop);
    }
    

    return 0;
}