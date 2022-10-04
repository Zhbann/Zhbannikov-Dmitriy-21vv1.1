#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Windows.h"
#include <locale.h>
#include "iostream"

#pragma comment(linker, "/STACK:1468006400")
#define SIZE 50000
clock_t startRand, startPr, startObr, startSmesh,
	endSRand, endQRand, endQsortRand,
	endSPr, endQPr, endQsortPr,
	endSObr, endQObr, endQsortObr,
	endSSm, endQSm, endQsortSm, startSRand, startQRand, startQsortRand;
int comp(const void *, const void *);
using namespace std;
FILE* D1;
void quickSort(int *numbers, int left, int right)
{
	int pivot;
	int l_hold = left;
	int r_hold = right;
	pivot = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= pivot) && (left < right))
			right--;
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}
		while ((numbers[left] <= pivot) && (left < right))
			left++;
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = pivot;
	pivot = left;
	left = l_hold;
	right = r_hold;
	if (left < pivot)
		quickSort(numbers, left, pivot - 1);
	if (right > pivot)
		quickSort(numbers, pivot + 1, right);
}

void shellSort(int *num, int size)
{

	int inc = 3;
	while (inc > 0)
	{
		for (int i = 0; i < size; i++)
		{
			int j = i;
			int temp = num[i];

			while ((j >= inc) && (num[j - inc] > temp))
			{
				num[j] = num[j - inc];
				j = j - inc;
			}
			num[j] = temp;
		}
		if (inc > 1)
			inc = inc / 2;
		else if (inc == 1)
			break;
	}
}

void randfunc(int *mas)
{
	for (int i = 0; i<10000; i++)
	{
		mas[i]=rand()%100+1000;
	}
}

void prfunc(int *mas)
{
	for (int i = 0; i<10000; i++)
	{
		mas[i]=rand()%100+1000 + i;
	}
}

void obrfunc(int *mas)
{
	for (int i = 0; i<10000; i++)
	{
		mas[i]=rand()%100+1000 - i;
	}
}

void smeshfunc(int *mas)
{
for (int i = 0; i<10000; i++)
	{
		if (i<=5000)
			mas[i]=rand()%100+1000 + i;
		else
			mas[i]=rand()%100+1000 - i;
	}
}


int main()
{
	setlocale(0, "Russian");
	int Rand[SIZE];
	int Pr[SIZE];
	int Obr[SIZE];
	int Smesh[SIZE];

	randfunc(Rand);
	startSRand = clock();
	shellSort(Rand, SIZE);
	endSRand = clock();

	randfunc(Rand);
	quickSort(Rand, 0, SIZE-1);
	endQRand = clock();

	randfunc(Rand);
	qsort(Rand, SIZE, sizeof(int), comp);
	endQsortRand = clock();

	//----------------------------------------—

	prfunc(Pr);
	startPr = clock();
	shellSort(Pr, SIZE);
	endSPr = clock();

	prfunc(Pr);
	quickSort(Pr, 0, SIZE-1);
	endQPr = clock();

	prfunc(Pr);
	qsort(Pr, SIZE, sizeof(int), comp);
	endQsortPr = clock();

	//------------------------------------------—

	obrfunc(Obr);
	startObr = clock();
	shellSort(Obr, SIZE);
	endSObr = clock();

	obrfunc(Obr);
	quickSort(Obr, 0, SIZE-1);
	endQObr = clock();

	obrfunc(Obr);
	qsort(Obr, SIZE, sizeof(int), comp);
	endQsortObr = clock();

	//---------------------------------------—

	smeshfunc(Smesh);
	startSmesh = clock();
	shellSort(Smesh, SIZE);
	endSSm = clock();

	smeshfunc(Smesh);
	quickSort(Smesh, 0, SIZE-1);
	endQSm = clock();

	smeshfunc(Smesh);
	qsort(Smesh, SIZE, sizeof(int), comp);
	endQsortSm = clock();

	double timeSRand = (endSRand-startSRand) / 1000.0;
	double timeQRand = (endQRand-endSRand) / 1000.0;
	double timeQsortRand = (endQsortRand-endQRand) / 1000.0;

	double timeSPr = (endSPr-startPr) / 1000.0;
	double timeQPr = (endQPr-endSPr) / 1000.0;
	double timeQsortPr = (endQsortPr-endQPr) / 1000.0;

	double timeSObr = (endSObr-startObr) / 1000.0;
	double timeQObr = (endQObr-endSObr) / 1000.0;
	double timeQsortObr = (endQsortObr-endQObr) / 1000.0;

	double timeSSm = (endSSm-startSmesh) / 1000.0;
	double timeQSm = (endQSm-endSSm) / 1000.0;
	double timeQsortSm = (endQsortSm-endQSm) / 1000.0;

	printf("\n");
	printf("+---------------+--------------------+----------------+----------------------+\n");
	printf("|---------------|----Быстрая сорт.---|---Сорт. Шелла--|---Быстрая сорт(ф-я)--|\n");
	printf("|-Прямая посл.--|      %lf      |    %lf    |       %lf       |\n",timeQPr,timeSPr,timeQsortPr);
	printf("|-Обратная посл.|      %lf      |    %lf    |       %lf       |\n",timeQObr,timeSObr,timeQsortObr);
	printf("|--Смеш. посл.--|      %lf      |    %lf    |       %lf       |\n",timeQSm,timeSSm,timeQsortSm);
	printf("|----Рандом.----|      %lf      |    %lf    |       %lf       |\n",timeQRand,timeSRand,timeQsortRand);
	printf("+---------------+--------------------+----------------+----------------------+\n");

	D1 = fopen("11.txt", "w");
	fprintf(D1,"\n");
	fprintf(D1,"+---------------+--------------------+----------------+----------------------+\n");
	fprintf(D1,"|---------------|----Быстрая сорт.---|---Сорт. Шелла--|---Быстрая сорт(ф-я)--|\n");
	fprintf(D1,"|-Прямая посл.--|      %lf      |    %lf    |       %lf       |\n",timeQPr,timeSPr,timeQsortPr);
	fprintf(D1,"|-Обратная посл.|      %lf      |    %lf    |       %lf       |\n",timeQObr,timeSObr,timeQsortObr);
	fprintf(D1,"|--Смеш. посл.--|      %lf      |    %lf    |       %lf       |\n",timeQSm,timeSSm,timeQsortSm);
	fprintf(D1,"|----Рандом.----|      %lf      |    %lf    |       %lf       |\n",timeQRand,timeSRand,timeQsortRand);
	fprintf(D1,"+---------------+--------------------+----------------+----------------------+\n");
	fclose(D1);
	getchar();
	return 0;
}
int comp(const void *i, const void *j)
{
	return *(int *)i - *(int *)j;
}