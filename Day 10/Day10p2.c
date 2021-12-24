#include <stdio.h>
#define SIZE 130

int isOpening(char s);
int isClosing(char s);
void clearTable(char tab[SIZE]);
long long findMed(long long tab[]);

int main()
{
	int k;
	char temp;
	char brackets[SIZE];
	char br[4] = { 0 };
	int status;
	long long scores[90] = { 0 };

	for (int q = 0; q < 90; q++)
	{
		k = 0;
		do
		{
			temp = getchar();
			if (temp == '\n')
			{
				brackets[k] = '\0';
				break;
			}
			else
			{
				brackets[k] = temp;
				k++;
			}
		} while (1);
		for (int j = 0; j < 129; j += 2)
		{
			status = 0;
			for (int i = 0; i < k - 1; i++)
			{
				if (i + 1 + j > k - 1) break;
				if (isOpening(brackets[i]) != -1 && isClosing(brackets[i + 1 + j]) != -1 && isOpening(brackets[i]) == isClosing(brackets[i + 1 + j]))
				{
					brackets[i] = 'x';
					brackets[i + 1 + j] = 'x';
				}
				else if (isOpening(brackets[i]) != -1 && isClosing(brackets[i + 1 + j]) != -1 && isOpening(brackets[i]) != isClosing(brackets[i + 1 + j]))
				{
					br[isClosing(brackets[i + 1 + j])]++;
					status = 1;
					break;
				}
			}
			printf("%s\n", brackets);
			if (status == 1) break;
		}
		if (status == 0)
		{
			for (int i = k; i >= 0; i--)
			{
				if (isOpening(brackets[i]) != -1)
				{
					scores[q] = scores[q] * 5 + isOpening(brackets[i]) + 1;
				}
			}
		}
		clearTable(brackets);
	}
	printf("\n): %d ]: %d }: %d >: %d\n", br[0], br[1], br[2], br[3]);
	for (int i = 0; i < 90; i++)
	{
		printf("%d: %llu\n", i, scores[i]);
	}
	findMed(scores);
	return 0;
}

int isOpening(char s)
{
	char br[] = { '(', '[', '{', '<' };
	for (int i = 0; i < 4; i++)
	{
		if (s == br[i]) return i;
	}
	return -1;
}
int isClosing(char s)
{
	char br[] = { ')', ']', '}', '>' };
	for (int i = 0; i < 4; i++)
	{
		if (s == br[i]) return i;
	}
	return -1;
}
void clearTable(char tab[SIZE])
{
	for (int i = 0; i < SIZE; i++) tab[i] = '\0';
}
long long findMed(long long tab[])
{
	long long temp;
	for (int i = 0; i < 90; i++)
	{
		for (int j = 0; j < 90 - i - 1; j++)
		{
			if (tab[j] < tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
		}
	}
	printf("\n");
	for (int i = 0; i < 90; i++)
	{
		printf("%llu\n", tab[i]);
	}
	int quantity = 0;
	do
	{
		quantity++;
	} while (tab[quantity] != 0);
	printf("Quantity: %d\nQuantity/2: %d\ntab[quan/2+1]: %llu\n", quantity, quantity / 2, tab[quantity / 2]);
	return tab[quantity / 2 + 1];
}