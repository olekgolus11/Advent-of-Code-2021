#include <stdio.h>
#include <string.h>

int main()
{
	char temp;
	char word[8];
	int count = 0;
	do
	{
		do
		{
			scanf("%c", &temp);
			if (temp == 'Q') return count;
		} while (temp != '|');
		for (int i = 0; i < 4; i++)
		{
			scanf("%s", word);
			if (strlen(word) == 2 || strlen(word) == 3 || strlen(word) == 4 || strlen(word) == 7) count++;
		}
	} while (1);
	return 0;
}