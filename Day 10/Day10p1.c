#include <stdio.h>
#define SIZE 130

int isOpening(char s);
int isClosing(char s);
void clearTable(char tab[SIZE]);

int main()
{
	int k;
	char temp;
	char brackets[SIZE];
	char br[4] = { 0 };
	int status;
	int total = 0;

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
		for (int j = 0; j < 101; j += 2)
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
	}
	printf("): %d ]: %d }: %d >: %d", br[0], br[1], br[2], br[3]);

	/*
	): 3 points.
	]: 57 points.
	}: 1197 points.
	>: 25137 points.
	*/
	total += br[0] * 3 + br[1] * 57 + br[2] * 1197 + br[3] * 25137;
	printf("\n%d", total);
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
	for (int i = 0; i < SIZE; i++) tab[i] = 0;
}

