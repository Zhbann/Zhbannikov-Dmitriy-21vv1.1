//С-матрица смежности,с расстониями 
//xn-начальная точка
//xk-конечнаяточка
#include"locale.h"

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include"locale.h"
#define word unsigned int
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(suppress : 4996)
using namespace std;
void deikstra();
void no();
void komponenta(int i);
void eiler();
void poisk(int i);
int a[50][50];
int i, j, p, xn, xk, z, k = 1, Mas[100][100], ch = 0;
int vert[10000];//степеньвершин
int way[10000];//Эйлеровцикл
int flag[10000];//компоненты связности
int x, y, w;
int n, m;// m - число дуг, n - число вершин
int count;// число компонент связности
word c[50][50], l[50];
char s[80], path[80][50];
struct st {
	char put[50];
	int x1;
	int x2;
	int ves;
};
st mas[100];
int min(int n)
{
	int i, result;
	for (i = 0; i < n; i++)
		if (!(flag[i])) result = i;
	for (i = 0; i < n; i++)
		if ((l[result] > l[i]) && (!flag[i])) result = i;
	return result;
}
word minim(word x, word y)
{
	if (x < y) return x;
	return y;
}
void global()
{
	int startik;
	setlocale(LC_ALL, "Rus");
	printf("  ________________________________________________________ \n");
	printf("|__________________________ПГУ____________________________|\n");
	printf("|_________________________________________________________|\n");
	printf("|_______________________Кафедра ВТ________________________|\n");
	printf("|_________________________________________________________|\n");
	printf("|____________________КУРСОВАЯ РАБОТА______________________|\n");
	printf("|_________________________________________________________|\n");
	printf("|___________________________На тему_______________________|\n");
	printf("|_________________________________________________________|\n");
	printf("|____________Реализация алгоритма нахождения______________|\n");
	printf("|_________________________________________________________|\n");
	printf("|____________________Эйлеровых циклов_____________________|\n");
	printf("|_________________________________________________________|\n");
	printf("|_________________________________________________________|\n");
	printf("|_________________________________________________________|\n");
	printf("|_________________________________________________________|\n");
	printf("|________________________________________________Выполнил:|\n");
	printf("|_________________________________________________________|\n");
	printf("|_____________________________________студент группы 21вв1|\n");
	printf("|_________________________________________________________|\n");
	printf("|___________________________________________Жбанников Д.Н.|\n");
	printf("|_________________________________________________________|\n");
	printf("|__________________________________________________Принял:|\n");
	printf("|_________________________________________________________|\n");
	printf("|_____________________________________________Акифьев И.В.|\n");
	printf("|_________________________________________________________|\n");
	printf("|_________________________________________________________|\n");
	printf("|_________________________________________________________|\n");
	printf("|_________________________________________________________|\n");
	printf("|________________________Пенза 2022_______________________|\n");
	printf("|_________________________________________________________|\n");
	printf(" _________________________________________________________ \n");

	printf("Нажмите 1, если желаете продолжить: ");
	scanf_s("%d", &startik);

	if (startik == 1)
	{
		st();
	}
	else
	{
		exit(0);
	}

	_getch();
}
void main(int argc, char* argv[])
{
	global();
	setlocale(LC_ALL, "Russian");
	cout << "введите количество вершин в графе: ";
	cin >> n;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) c[i][j] = 0;
	for (i = 0; i < n; i++)
		for (j = i + 1; j < n; j++)
		{
			cout << "введите расстояние x" << i + 1 << " до x" << j + 1 << ":";//
			cin >> c[i][j];//записываем расстояния в матрицу с
		}
	cout << " ";
	for (i = 0; i < n; i++) cout << " X" << i + 1;
	cout << endl << endl;
	for (i = 0; i < n; i++)
	{
		printf("X%d", i + 1);
		for (j = 0; j < n; j++)
		{
			printf("%3d", c[i][j]);
			c[j][i] = c[i][j];
		}
		printf("\n\n");
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			if (c[i][j] == 0)
				c[i][j] = 65535;
	}//бесконечность
	for (i = 0; i < n; i++)
	{
		z = 0;
		for (j = 0; j < n; j++) {
			if (c[i][j] != 65535)
				z++;
		}
		if (z % 2 == 1)//ищем вершины с нечетными степенями
		{
			Mas[k][0] = i;//сохраняем номера этих вершин
			Mas[0][k] = i;
			k++;
		}
	}
	for (int m = 1; m < k; m++) {
		xn = Mas[0][m];
		for (j = m; j < k - 1; j++)
		{
			xk = Mas[j + 1][0];
			if (xn != xk)
				deikstra();
		}
	}
	eiler();
	_getch();
}

void deikstra()
{
	for (i = 0; i < n; i++)
	{
		flag[i] = 0;
		l[i] = 65535;
	}
	
	l[xn] = 0;
	flag[xn] = 1;
	p = xn;
	_itoa_s(xn + 1, s, 10);//преобразование числа в символы
	for (i = 1; i <= n; i++)
	{
		strcpy_s(path[i], "X");
		strcat_s(path[i], s);
	}
	do
	{
		for (i = 0; i < n; i++)
			if ((c[p][i] != 65535) && (!flag[i]) && (i != p))
			{
				if (l[i] > l[p] + c[p][i])
				{
					_itoa_s(i + 1, s, 10);
					strcpy_s(path[i + 1], path[p + 1]);
					strcat_s(path[i + 1], "-X");
					strcat_s(path[i + 1], s);
				}
				l[i] = minim(l[i], l[p] + c[p][i]);
			}
		p = min(n);
		flag[p] = 1;
	} while (p != xk);
	if (l[p] != 65535)
	{
		mas[p].ves = (int)l[p];
		i = 0;
		while (path[p + 1][i] != '\0') {
			mas[ch].put[i] = path[p + 1][i];
			i++;
		}
		mas[ch].x1 = xk;
		mas[ch].x2 = xn;
		printf("%i вес\n", mas[p].ves);
		printf("%s путь \n", mas[ch].put);
	}
	else
		printf( "Эйлеров цикл!");
	ch++;
}
void eiler()
{
	int sum = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			a[i + 1][j + 1] = (int)c[i][j];
			if (a[i + 1][j + 1] == 65535)
				a[i + 1][j + 1] = 0;
		}
	int count = 0;
	for (int i = 1; i < n; i++)
	{
		if (flag[i] == 0)
			count++;
		if (count > 1)
			no();// графнесвязен
			//komponenta(i);
	}
	for (int i = 1; i < n; i++)
		if (vert[i] % 2 == 1)
			no(); // есть вершины нечётной степени
	w = 0;
	poisk(1);
	way[0] = way[1];
	for (int i = 1; i <= w; i++) {
		if ((int)c[way[i] - 1][way[i + 1] - 1] == 65535) {
			for (j = 0; j < ch; j++) {
				if ((mas[j].x1 + 1 == way[i] && mas[j].x2 + 1 == way[i + 1]) || (mas[j].x2 + 1 == way[i] && mas[j].x1 + 1 == way[i + 1])) {
					printf("%s-", mas[p].put);
					sum = sum + mas[p].ves;
					way[0] = mas[p].x1;
				}
			}
		}
		else
			printf("X%i-", way[i]);
	}
	if (way[0] != way[w]) {
		if ((int)c[way[1] - 1][way[w] - 1] != 65535) {
			printf("X%i", way[1]);
			sum = sum + (int)c[way[i] - 1][way[w] - 1];
		}
		else {
			for (j = 0; j < ch; j++) {
				if (mas[p].x1 == way[1] && mas[p].x2 == way[w - 1]) {
					printf("%s-", mas[p].put);
					sum = sum + mas[p].ves;
				}
			}
		}
	}
	for (int i = 0; i <= w; i++) {
		if ((int)c[way[i] - 1][way[i + 1] - 1] != 65535)
			sum = (int)c[way[i] - 1][way[i + 1] - 1] + sum;
	}
	printf("\n");
	printf("веспути %i ", sum);
}
//---------------------------------------------------
void no() {
	printf("Эйлеров цикл не существует!");
	exit(0);
	_getch();
}
void poisk(int i) {
	int j;
	for (int j = 1; j <= n; j++)
		if (a[i][j] != 0) {
			a[i][j] = 0;
			a[j][i] = 0;
			poisk(j);
		}
	w++;
	way[w] = i;
}

