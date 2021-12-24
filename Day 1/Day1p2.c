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
	temp = tab[0] + tab[1] + tab[2];
	for (int i = 1; i < size - 2; i++)
	{
		if ((tab[i] + tab[i + 1] + tab[i + 2]) > temp) increases++;
		printf("\n%d\n", tab[i] + tab[i + 1] + tab[i + 2]);
		temp = tab[i] + tab[i + 1] + tab[i + 2];
	}
	printf("\n\nIncreases: %d", increases);
	return 0;
}