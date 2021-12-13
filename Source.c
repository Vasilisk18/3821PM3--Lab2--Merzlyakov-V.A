#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include<string.h>

int main()
{
	int n = 0;
	int k = 0;
	double c = 0;
	FILE* kek;
	srand(time(NULL));

	kek = fopen("C:/Users/User/source/repos/project_0.1/project_0.1/input.txt", "w");

	printf_s("Enter the quantity of numbers:");
	scanf_s("%d", &n);
	fprintf(kek, "%d\n", n);

	printf_s("How would you like to enter the numbers?\nPress 1, if you want to enter yourself\nPress 2, if you wanna get a random numbers\nYour choice:");
	scanf_s("%d", &k);

	if (k == 1)
	{
		double a = 0.0;
		for (int i = 0; i < n; i++)
		{
			scanf_s("%lf", &a);
			fprintf(kek, "%lf\n", a);
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			double a = rand();
			int b = rand();
			while (b>1)
			{
				c += b % 10;
				b = b / 10;
				c = c * 0.1;
			}
			a = a + c;
			fprintf(kek, "%lf\n", a);
			c = 0;
		}
	}

	return 0;
}
	