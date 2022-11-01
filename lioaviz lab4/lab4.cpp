#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *root;

int viborka(struct Node *root, int data, int k)
{
	if ( root == NULL )
	{
		k = 0;
		return(k);
	}

	if ( data == root->data )
	{
		printf("\n Данный элемент есть в дереве, введите новый!\n");
		k = 1;
		return(k);
	}

	if ( data < root->data )
	{
		return viborka(root->right, data, k);
	}

	if ( data > root->data )
	{
		return viborka(root->left, data, k);
	}
}

struct Node *CreateTree(struct Node *root, struct Node *r, int data, int k)
{

	if (r == NULL)
	{
		r = (struct Node *)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf(" Ошибка выделения памяти");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;

		if (root == NULL)
		{
			return r;
		}

		if (data > root->data)
		{
			root->left = r;
		}
		else
		{
			root->right = r;
		}
		return r;
	}
	else
	{
		if(k == 0)
		{
			k = viborka(root,data,k);
			if(k == 1)
			{
				return root;
			}
		}
	}

	if (data > r->data)
		CreateTree(r, r->left, data, k);
	else
		CreateTree(r, r->right, data, k);

	return root;
}

void print_tree(struct Node *r, int l)
{

	if (r == NULL)
	{
		return;
	}

	print_tree(r->right, l + 1);
	for(int i = 0; i < l; i++)
	{
		printf(" ");
	}

	printf(" %d\n", r->data);
	print_tree(r->left, l+1);
}


struct Node *search(struct Node* root, int number)
{
	if ( root == NULL )
	{
		printf("\n Элемент не найден!");
		return NULL;
	}
	if ( number == root->data )
	{
		printf("\n Элемент дерева найден!");
	}
	if ( number < root->data )
	{
		return search(root->right, number);
	}
	if ( number > root->data )
	{
		return search(root->left, number);
	}
}

int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1;
	int number;
	int k = 0;

	root = NULL;
	printf(" Введите -1 - для окончания построения дерева\n");
	while (start)
	{
		printf(" Введите число: ");
		scanf_s(" %d", &D);
		if (D == -1)
		{
			printf(" Построение дерева окончено\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, D, k);

	}

	print_tree(root,0);
	printf("\n");

	printf(" Введите число для поиска: ");
	scanf("%d", &number);
	search(root, number);

	scanf_s("%d", &D);
	return 0;
}