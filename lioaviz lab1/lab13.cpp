#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>

int main()
{
setlocale(0, "Russian");

int **a;
int x, y, j, i;

printf(" ¬ведите число строк массива: ");
scanf("%d", &x);
printf(" ¬ведите число столбцов массива: ");
scanf("%d", &y);

a = (int**)malloc(x * sizeof(int*));
for(i = 0; i < y; i++)
{
a[i] = (int*)malloc(y * sizeof(int));
}

srand(time(NULL));

for (i = 0; i < x; i++)
{
for(j = 0; j < y; j++)
{
a[i][j] = rand()%30-10;
}
}

printf("\n ¬аш массив: \n");
for (i = 0; i < x; i++)
{
printf("\n");
for(j = 0; j < y; j++)
{
printf(" %d ", a[i][j]);
}
}
free(a);
getch();
return 0;
}