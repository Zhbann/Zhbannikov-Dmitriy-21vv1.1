#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <string.h>

int main()
{
setlocale(0, "Russian");

int a[4][3];
int i,j;
int k=0;

printf("Заполните матрицу: ");
for (i = 0; i < 4; i++)
{
printf("\n");
for (j = 0; j < 3; j++)
{
scanf("%d", &a[i][j]);
}
}

for (i = 0; i < 4; i++)
{
printf("\n");
for (j = 0; j < 3; j++)
{
printf("%d", a[i][j]);
}
}
printf("\n");
for (i = 0; i < 4; i++)
{
printf("\n");
for (j = 0; j < 3; j++)
{
k=k+a[i][j];
}
printf("Сумма %d строки: %d ", i+1, k);
k=0;
}
printf("\n");
for (j = 0; j < 3; j++)
{
printf("\n");
for (i = 0; i < 4; i++)
{
k=k+a[i][j];
}
printf("Сумма %d столбца: %d ", j+1, k);
k=0;
}
getch();
}