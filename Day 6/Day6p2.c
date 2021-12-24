#include <stdio.h>
#define DAYS 256

int main()
{
	long long populationTimer[9] = { 0 };
	long long count = 0;
	long long temp;
	do
	{
		scanf("%llu%*c", &temp);
		if (temp == -1) break;
		populationTimer[temp]++;

	} while (1);

	/*printf("Initial state: ");
	for (int i = 0; i < 9; i++) printf("%d ", populationTimer[i]);
	printf("\n");*/

	int check = 0;
	for (int i = 0; i < DAYS; i++)
	{
		check = 0;
		if (populationTimer[0] != 0)
		{
			temp = populationTimer[0];
			populationTimer[0] = 0;
			populationTimer[7] += temp;
			check = 1;
		}
		populationTimer[0] = populationTimer[1];
		populationTimer[1] = populationTimer[2];
		populationTimer[2] = populationTimer[3];
		populationTimer[3] = populationTimer[4];
		populationTimer[4] = populationTimer[5];
		populationTimer[5] = populationTimer[6];
		populationTimer[6] = populationTimer[7];
		populationTimer[7] = populationTimer[8];
		if (check == 1)populationTimer[8] = temp;
		if (check == 0)populationTimer[8] = 0;
		/*printf("After %2d days: ", i + 1);
		for (int i = 0; i < 9; i++) printf("%d ", populationTimer[i]);
		printf("\n");*/
	}
	for (int i = 0; i < 9; i++)
	{
		count += populationTimer[i];
	}
	printf("Lanternfish count: %llu", count);

	return 0;
}