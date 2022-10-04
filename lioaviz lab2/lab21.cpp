#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>

int main(void)
{
	setlocale(0, "Russian");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	int i=0, j=0, r, x, y;
	int **a, **b, **c, elem_c;

	printf(" ¬ведите число строк массива: ");
	scanf("%d", &x);
	printf(" ¬ведите число столбцов массива: ");
	scanf("%d", &y);

	a = (int**)malloc(x * sizeof(int*));
	for(i = 0; i < y; i++)
	{
		a[i] = (int*)malloc(y * sizeof(int));
	}
	b = (int**)malloc(x * sizeof(int*));
	for(i = 0; i < y; i++)
	{
		b[i] = (int*)malloc(y * sizeof(int));
	}
	c = (int**)malloc(x * sizeof(int*));
	for(i = 0; i < y; i++)
	{
		c[i] = (int*)malloc(y * sizeof(int));
	}

	double time_spend = 0.0;
	clock_t begin = clock();

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while(i<1000)
	{
		while(j<1000)
		{
			a[i][j]=rand()% 100 + 1; // заполн€ем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i=0; j=0;
	while(i<1000)
	{
		while(j<1000)
		{
			b[i][j]=rand()% 100 + 1; // заполн€ем массив случайными числами
			j++;
		}
		i++;
	}

	for(i=0;i<1000;i++)
	{
		for(j=0;j<1000;j++)
		{
			elem_c=0;
			for(r=0;r<1000;r++)
			{
				elem_c=elem_c+a[i][r]*b[r][j];
				c[i][j]=elem_c;
			}
		}
	}

	clock_t end = clock();
	time_spend += (double)(end-begin)/1000.0;
	printf("«атраченное врем€ на выполнение программы - %f секунд \n", time_spend);
	getch();
	return(0);
}
