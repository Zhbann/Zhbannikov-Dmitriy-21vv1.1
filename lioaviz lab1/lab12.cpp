#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <time.h>

#define SIZE 20
int main() {

int a[SIZE];
for (int i = 0; i<SIZE; i++)
{
a[i] = rand() % 100;
printf("%d ", a[i]);
}
getch();
return 0;
}