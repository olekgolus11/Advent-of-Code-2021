#include <stdio.h>

int main()
{
	char direction;
	int value;
	int posH = 0;
	int posV = 0;
	do
	{
		scanf("%c%*s", &direction);
		if (direction == '0') break;
		scanf("%d%*c", &value);
		switch (direction)
		{
		case 'u':
			posV -= value;
			break;
		case 'd':
			posV += value;
			break;
		case 'f':
			posH += value;
			break;
		default:
			break;
		}
	} while (1);
	printf("\n\nDepth = %d\nPosH = %d", posV, posH);
	printf("\nDepth times horizontal position = %d", posH * posV);
	return 0;
}