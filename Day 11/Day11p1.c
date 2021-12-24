#include <stdio.h>
#define FLASHES 100

void addEnergy(int tab[10][10], int y, int x);
void flash(int tab[10][10], int y, int x);
void clearAfter(int tab[10][10]);
void printTable(int tab[10][10]);
int checkHugeFlash(int tab[10][10]);
int flashes = 0;

int main()
{
	int tab[10][10];
	int when = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			scanf("%1d", &tab[i][j]);
		}
	}
	for (int k = 0; k < FLASHES; k++)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				addEnergy(tab, i, j);
			}
		}
		if (checkHugeFlash(tab) == 0 && when == 0) when = k + 1;
		clearAfter(tab);
	}

	printf("Flashes: %d\nFirst moment of big flash: %d", flashes, when);
	return 0;
}

void addEnergy(int tab[10][10], int y, int x)
{
	tab[y][x]++;
	if (tab[y][x] == 10)
	{
		flash(tab, y, x);
	}
}
void flash(int tab[10][10], int y, int x)
{
	flashes++;
	for (int i = y - 1; i <= y + 1; i++)
	{
		if (i < 0) i++;
		if (i > 9) break;
		for (int j = x - 1; j <= x + 1; j++)
		{
			if (j < 0) j++;
			if (j > 9) break;
			if (i == y && j == x) continue;
			addEnergy(tab, i, j);
		}
	}
}
void clearAfter(int tab[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (tab[i][j] > 9) tab[i][j] = 0;
		}
	}
}
void printTable(int tab[10][10])
{
	printf("\n");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			printf("%d", tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int checkHugeFlash(int tab[10][10])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (tab[i][j] < 10) return 1;
		}
	}
	return 0;
}