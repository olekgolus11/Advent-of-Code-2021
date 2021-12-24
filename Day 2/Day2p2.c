#include <stdio.h>

int main()
{
	char direction;
	int value;
	int posH = 0;
	int posV = 0;
	int aim = 0;
	do
	{
		scanf("%c%*s", &direction);
		if (direction == '0') break;
		scanf("%d%*c", &value);
		switch (direction)
		{
		case 'u':
			aim -= value;
			break;
		case 'd':
			aim += value;
			break;
		case 'f':
			posH += value;
			posV += aim * value;
			break;
		default:
			break;
		}
	} while (1);
	printf("\n\nDepth = %d\nPosH = %d\nAim = %d", posV, posH, aim);
	printf("\nDepth times horizontal position = %d", posH * posV);
	return 0;
}