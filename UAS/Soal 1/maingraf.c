/*Saya Alief Muhammad Abdillah 2003623 mengerjakan UAS grmmt21 dalam mata kuliah Struktur Data
untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin*/

#include "headgraf.h"

int main()
{
    graph G;
    createEmpty(&G);

    char simp;
    char dest;

    //input user
    do
    {
        scanf(" %c", &simp);
        if (simp != '0')
        {
            scanf(" %c", &dest);

            addNode(simp, &G);

            node *begin = findNode(simp, G);
            node *end = findNode(dest, G);
            if ((begin != NULL) && (end != NULL))
            {
                addArc(begin, end); 
            }
        }
    }while(simp != '0');
    
    //function to find cycle in graph
    if(check_cycle(G.first) == 1)
    {
        printf("ada jalur memutar\n");
    }
    else
    {
        printf("tidak ada jalur memutar\n");
    }
    
}