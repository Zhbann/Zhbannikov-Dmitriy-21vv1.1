#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <string.h>

using namespace std;

void main() {

	setlocale(0, "Russian");

	int k, min, max;
	int a[10]={10,50,-5,94,5,21,43,12,3,91};

	max = a[0];
	min = max;

	printf(" Массив: ");

	for (int i = 0; i<10; i++)
	{
		printf("%d ", a[i]);
		if(a[i] <= min)
		{
			min = a[i];
		}
		if(a[i] >= max)
		{
			max = a[i];
		}
	}
	printf("\n max - min = %d", k=max-min);
	getch();
}