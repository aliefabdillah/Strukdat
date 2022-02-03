#include "headkij.h"

int main()
{
    tree T;

    int n;
    scanf("%d", &n);

    int number;
    int parent;
    char direction[50];

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %s", &number, &parent, direction);
        input(number, parent, direction, T);
    }
    

    return 0;
}