#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <time.h>

void Puzirec(double* num, int size, clock_t* s, clock_t* e)
{
	*s = clock();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--)
		{
			if (num[j - 1] > num[j])
			{
				double temp = num[j - 1];
				num[j - 1] = num[j];
				num[j] = temp;
			}
		}
	}
	*e = clock();
}

void Vstavki(double* num, int size, clock_t* s, clock_t* e)
{
	double newElement;
	int location;
	*s = clock();
	for (int i = 1; i < size; i++)
	{
		newElement = num[i];
		location = i - 1;
		while (location >= 0 && num[location] > newElement)
		{
			num[location + 1] = num[location];
			location = location - 1;
		}
		num[location + 1] = newElement;
	}
	*e = clock();
}

void qSort(double* data, int first, int last)
{
	double temp = 0;
	if (first < last)
	{
		int left = first, right = last;
		double middle = data[(left + right) / 2];
		do
		{
			while (data[left] < middle)
			{
				left++;
			}
			while (data[right] > middle)
			{
				right--;
			}
			if (left <= right)
			{
				temp = data[left];
				data[left] = data[right];
				data[right] = temp;
				left++;
				right--;
			}
		} while (left < right);
		qSort(data, first, right);
		qSort(data, left, last);
	}
}

int main()
{
	
	int p = 0;
	int n = 0;
	clock_t start, end;
	while (p != 4) 
	{
		FILE* fin;
		fin = fopen("input.txt", "r");
		fscanf_s(fin, "%d", &n);
		double* Arr = NULL;
		Arr = (double*)malloc(n * sizeof(double));
		for (int i = 0; i < n; i++)
		{
			fscanf_s(fin, "%lf", &Arr[i]);
		}
		printf("Choose a sorting method:\n1-Puzirec\n2-Vstavki\n3-QuickSort\n4-Exit\nInput:");
		scanf("%d", &p);
		printf("\n");
		if (p == 1)
		{
			Puzirec(Arr, n, &start, &end);
			printf("Pyzur\n");
			for (int i = 0; i < n; i++)
				printf("Arr[%d] = %lf\n", i, Arr[i]);
			printf("start = %lf end = %lf Time = %lf\n", (double)start, (double)end, (double)(end - start) / CLOCKS_PER_SEC);
			printf("-------\n");
		}

		if (p == 2)
		{
			printf("Vstavka\n");
			Vstavki(Arr, n, &start, &end);
			for (int i = 0; i < n; i++)
				printf("Arr[%d] = %lf\n", i, Arr[i]);
			printf("start = %lf end = %lf Time = %lf\n", (double)start, (double)end, (double)(end - start) / CLOCKS_PER_SEC);
			printf("-------\n");
		}

		if (p == 3)
		{
			printf("QuickSort\n");
			start = clock();
			qSort(Arr, 0, n-1);
			end = clock();
			for (int i = 0; i < n; i++)
				printf("Arr[%d] = %lf\n", i, Arr[i]);
			printf("start = %lf end = %lf Time = %lf\n", (double)start, (double)end, (double)(end - start) / CLOCKS_PER_SEC);
			printf("-------\n");
		}

		if (p == 4) break;
	}

	return 0;
}
