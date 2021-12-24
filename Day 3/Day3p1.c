#include <stdio.h>
#include <math.h>
#define SIZE 12

int bin_to_dec(int tab[], int size)
{
	int dec = 0;
	for (int i = size - 1, j = 0; i >= 0; i--, j++)
	{
		dec += tab[i] * pow(2, j);
	}
	return dec;
}

int main()
{
	int tab[SIZE] = { 0 };
	int temp;
	int quantity = 0;
	int gamma_rate, epsilon_rate;
	do
	{
		for (int i = 0; i < SIZE; i++)
		{
			scanf("%1d", &temp);
			if (temp == 2) break;
			tab[i] += temp;
		}
		if (temp == 2) break;
		quantity++;
	} while (1);
	for (int i = 0; i < SIZE; i++)
	{
		if (tab[i] > quantity / 2) tab[i] = 1;
		else tab[i] = 0;
	}
	gamma_rate = bin_to_dec(tab, SIZE);
	for (int i = 0; i < SIZE; i++)
	{
		if (tab[i] == 0) tab[i] = 1;
		else if (tab[i] == 1) tab[i] = 0;
	}
	epsilon_rate = bin_to_dec(tab, SIZE);
	printf("\nGamma rate: %d\nEpsilon rate: %d\nOutput: %d", gamma_rate, epsilon_rate, gamma_rate * epsilon_rate);

	return 0;
}

