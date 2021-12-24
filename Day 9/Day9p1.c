#include <stdio.h>
#define SIZEY 100
#define SIZEX 100

int main()
{
	int risk = 0;
	int tab[SIZEY][SIZEX];
	for (int i = 0; i < SIZEY; i++)
	{
		for (int j = 0; j < SIZEX; j++)
		{
			scanf("%1d", &tab[i][j]);
		}
	}
	for (int i = 0; i < SIZEY; i++)
	{
		for (int j = 0; j < SIZEX; j++)
		{
			//TOP
			if (i == 0)
			{
				if (j == 0)
				{
					if (tab[i][j] < tab[i + 1][j] && tab[i][j] < tab[i][j + 1]) risk += tab[i][j] + 1;
				}
				else if (j == SIZEX - 1)
				{
					if (tab[i][j] < tab[i + 1][j] && tab[i][j] < tab[i][j - 1]) risk += tab[i][j] + 1;
				}
				else
				{
					if (tab[i][j] < tab[i + 1][j] && tab[i][j] < tab[i][j - 1] && tab[i][j] < tab[i][j + 1]) risk += tab[i][j] + 1;
				}
			}
			//BOTTOM
			else if (i == SIZEY - 1)
			{
				if (j == 0)
				{
					if (tab[i][j] < tab[i - 1][j] && tab[i][j] < tab[i][j + 1]) risk += tab[i][j] + 1;
				}
				else if (j == SIZEX - 1)
				{
					if (tab[i][j] < tab[i - 1][j] && tab[i][j] < tab[i][j - 1]) risk += tab[i][j] + 1;
				}
				else
				{
					if (tab[i][j] < tab[i - 1][j] && tab[i][j] < tab[i][j - 1] && tab[i][j] < tab[i][j + 1]) risk += tab[i][j] + 1;
				}
			}
			//LEFT
			else if (j == 0)
			{
				if (tab[i][j] < tab[i - 1][j] && tab[i][j] < tab[i + 1][j] && tab[i][j] < tab[i][j + 1]) risk += tab[i][j] + 1;
			}
			//RIGHT
			else if (j == SIZEX - 1)
			{
				if (tab[i][j] < tab[i - 1][j] && tab[i][j] < tab[i + 1][j] && tab[i][j] < tab[i][j - 1]) risk += tab[i][j] + 1;
			}
			//MIDDLE
			else
			{
				if (tab[i][j] < tab[i - 1][j] && tab[i][j] < tab[i + 1][j] && tab[i][j] < tab[i][j + 1] && tab[i][j] < tab[i][j - 1]) risk += tab[i][j] + 1;
			}
		}
	}
	printf("Risk: %d", risk);
	return 0;
}