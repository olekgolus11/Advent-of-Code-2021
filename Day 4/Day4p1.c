#include <stdio.h>

void clearBuffer()
{
	while (getch() != '\n');
}

int checkNumber(int tab[5][5], int numbers[], int index)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (tab[i][j] == numbers[index])
			{
				tab[i][j] = -1;
			}
		}
	}
	if (bingoCheck(tab) == 1)
	{
		printf("Bingo!");
		return 1;
	}
	return 0;
}

int scanTable(int tab[5][5])
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &tab[i][j]);
			if (tab[i][j] == -1) return -1;
		}
	}
	return 0;
}

void printTable(int tab[5][5])
{
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%2d ", tab[i][j]);
		}
		printf("\n");
	}
}

int bingoCheck(int tab[5][5])
{
	int temp = 0;
	for (int i = 0; i < 5; i++)
	{
		temp = 0;
		for (int j = 0; j < 5; j++)
		{
			temp += tab[i][j];
		}
		if (temp == -5) return 1;
	}
	for (int j = 0; j < 5; j++)
	{
		temp = 0;
		for (int i = 0; i < 5; i++)
		{
			temp += tab[i][j];
		}
		if (temp == -5) return 1;
	}
	return 0;
}

int totalValue(int tab[5][5], int numbers[], int index)
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (tab[i][j] == -1) continue;
			sum += tab[i][j];
		}
	}
	return sum * numbers[index];
}


int main()
{
	int numbers[] = { 67,31,58,8,79,18,19,45,38,13,40,62,85,10,21,96,56,55,4,36,76,42,32,34,39,89,6,12,24,57,93,47,41,52,83,61,5,37,28,15,86,23,69,92,70,27,25,53,44,80,65,22,99,43,66,26,11,72,2,98,14,82,87,20,73,46,35,7,1,84,95,74,81,63,78,94,16,60,29,97,91,30,17,54,68,90,71,88,77,9,64,50,0,49,48,75,3,59,51,33 };
	//int numbers[] = { 7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1 };
	int tab[5][5];
	int index;
	int check;
	int min = sizeof(numbers);
	int value;

	do
	{
		check = scanTable(tab);
		if (check == -1) break;
		for (int i = 0; i < sizeof(numbers); i++)
		{
			index = i;
			if (checkNumber(tab, numbers, index) == 1)
			{
				printTable(tab);
				printf("\nNumber: %d\nValue: %d", numbers[index], totalValue(tab, numbers, index));
				if (index < min)
				{
					min = index;
					value = totalValue(tab, numbers, index);
				}
				break;
			}
			printTable(tab);
		}
	} while (check != -1);
	printf("\n%d", value);

	return 0;
}