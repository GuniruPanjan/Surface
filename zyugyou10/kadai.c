#include<stdio.h>



int k(int g)
{
	int num = 0;   //•\¦‚µ‚½*‚Ì”
	scanf_s("%d", &g);
	for (int i = 0; i < g; i++)
	{
		for (int j = 0; j < (i + 1); j++)
		{
			printf("*");
			num++;
		}
		printf("\n");

	}

	return num;  //•\¦‚µ‚½*‚Ì”‚ğ•Ô‚·
}

