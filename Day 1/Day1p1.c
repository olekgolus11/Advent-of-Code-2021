#include <stdio.h>

int main()
{
	int tab[3000];
	int temp;
	int size = 0;
	int increases = 0;
	for (int i = 0; i < 3000; i++)
	{
		scanf("%d", &temp);
		if (temp == '\0') break;
		else tab[i] = temp;
		size++;
	}
	temp = tab[0];
	for (int i = 1; i < size; i++)
	{
		if (tab[i] > temp) increases++;
		temp = tab[i];
	}
	printf("\n\nIncreases: %d", increases);
	return 0;
}