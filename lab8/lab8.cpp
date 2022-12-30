#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include "time.h"
#include <locale.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	queue<int> Queue;
	int size;
	printf("Введите размер матрицы: ");
	scanf("%d", &size);
	int** mas = (int**)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++) {
		mas[i] = (int*)malloc(sizeof(int) * size);
	}
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			mas[i][j] = rand() % 2;
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				mas[i][j] = 0;
			}
			if (mas[i][j] = mas[j][i]) {
				mas[i][j] = mas[j][i];
			}
		}
	}
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j)
			printf("%d ",mas[i][j]);
		printf("\n");
	}
	int *nodes = (int*)malloc(sizeof(int*) * size);
	for (int i = 0; i < size; i++)
		nodes[i] = 0;
	int start = clock();
	Queue.push(0);
	printf("Обход в ширину:\n");
	while (!Queue.empty())
	{
		int node = Queue.front();
		Queue.pop();
		nodes[node] = 2;
		for (int j = 0; j < size; j++)
		{
			if (mas[node][j] == 1 && nodes[j] == 0)
			{ // если вершина смежная и не обнаружена
				Queue.push(j);
				nodes[j] = 1;
			}
		}
		printf(">%d ", node + 1);
	}
	int end = clock();
	double time = (end-start) / 1000.0;
	printf("\nПройденное время: %lf \n", time);
	system("Pause");
	return 0;
}