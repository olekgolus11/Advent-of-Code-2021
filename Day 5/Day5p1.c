#include <stdio.h>
#define SIZE 1000

int main()
{
    int x1, y1, x2, y2;
    int temp;
    int tab[SIZE][SIZE] = { 0 };

    do
    {
        scanf("%d%*c%d%*c%*c%*c%*c%d%*c%d", &x1, &y1, &x2, &y2);
        if (x1 == -1 || y1 == -1 || x2 == -1 || y2 == -1) break;
        if (x1 != x2 && y1 != y2) continue;
        if (x2 < x1)
        {
            temp = x2;
            x2 = x1;
            x1 = temp;
        }
        if (y2 < y1)
        {
            temp = y2;
            y2 = y1;
            y1 = temp;
        }
        for (int y = y1; y <= y2; y++)
        {
            for (int x = x1; x <= x2; x++)
            {
                tab[y][x]++;
            }
        }
    } while (1);
    int count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (tab[i][j] >= 2) count++;
        }
    }
    printf("Count: %d", count);
    return 0;

}

