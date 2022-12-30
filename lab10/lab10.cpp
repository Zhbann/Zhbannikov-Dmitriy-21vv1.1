#define CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<locale.h>
#include<Windows.h>
#include<malloc.h>
#include<time.h>
#include<iostream>
#include<queue>


using namespace std;
void DFS(int v);
int n;
int* vis;
int v = 0;
int** M;
int* maxim;

void main() {
	setlocale(LC_ALL, "rus");
	printf("Введите количество  вершин : ");
	scanf_s("%d", &n);

	srand((unsigned)time(NULL));
	M = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		M[i] = (int*)malloc(sizeof(int) * n);

	}

	vis = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		vis[i] = -1;
	}

	maxim = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		maxim[i] = 0;
	}
	//Задание 1 
	//Генерация матрицы смежности:
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (rand() % 2) {
				M[i][j] = rand() % 10;
			}
			else {
				M[i][j] = 0;
			}

			if (i == j) {
				M[i][j] = 0;
			}
			M[j][i] = M[i][j];
		}
	}
	//Вывод матрицы смежности:
	printf_s("\nМатрица смежности");
	for (int i = 0; i < n; i++) {
		printf_s("\n");
		for (int j = 0; j < n; j++) {
			printf("|%3d|", M[i][j]);
		}
	}
	printf("\n");
	for (int s = 1; s < (n + 1); s++) {
		DFS(s);
		for (int i = 0; i < n; i++) {
			vis[i] = -1;
		}
	}
	printf("\n");
	int maxm = 0;
	int minm = 100;
	for (int i = 0; i < n; i++) {
		if (maxm < maxim[i]) {
			maxm = maxim[i];
		}
		else 
			if (minm > maxim[i] && maxim[i] > 0) {
			minm = maxim[i];
		}
	}
	printf("Радиус: %d, диаметр: %d\n", minm, maxm);
	printf("Периферийные вершины: ");
	for (int i = 0; i < n; i++) {
		if (maxim[i] == maxm) {
			printf("%d ", i + 1);
		}
	}
	printf("\n");
	printf("Центральные вершины: ");
	for (int i = 0; i < n; i++) {
		if (maxim[i] == minm) {
			printf("%d ", i + 1);
		}
	}
	printf("\n");
	system("pause");
}

void DFS(int s) {
	queue<int> q;
	q.push(s - 1);
	vis[s - 1] = 1;
	int st = s;
	while (!q.empty()) {
		s = q.front();
		//printf("%d\n", s+1);
		q.pop();
		for (int i = 0; i < n; i++) {
			if ((M[s][i] != 0) && (vis[i] < 0)) {
				q.push(i);
				vis[i] = vis[s] + M[s][i];
				printf("Расстояние вершины %d от %d: %d\n", i + 1, st, vis[i] - 1);
			}
		}
	}
	maxim[st - 1] = 0;
	for (int i = 0; i < n; i++) {
		if (maxim[st - 1] < vis[i]) {
			maxim[st - 1] = vis[i] - 1;
		}
	}
	printf("Эксцентриситет: %d\n", maxim[st - 1]);

	printf("Расстояние от вершины %d до всех других вершин:\n", st);
	for (int i = 0; i < n; i++) {
		printf("%d ", vis[i] - 1);
	}
	printf("\n");
}


