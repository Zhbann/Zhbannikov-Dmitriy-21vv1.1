#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <Windows.h>
#include <locale.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>

struct a
{
char famil[50], name[50], adres[50], grup[50];
}
stud[3];

int main(void)
{
SetConsoleCP (1251);
SetConsoleOutputCP (1251);

int i;

for (i = 0; i < 3; i++)
{
printf("������� ������� ��������\n");
scanf("%s", &stud[i].famil);
printf("������� ��� �������� %s\n", stud[i].famil);
scanf("%s", &stud[i].name);
printf("������� �������� ����� %s %s\n", stud[i].famil, stud[i].name);
scanf("%s", &stud[i].adres);
printf("������� ������ �������� %s %s\n", stud[i].famil, stud[i].name);
scanf("%s", &stud[i].grup);
}

for (i = 0; i < 3; i++)
{
printf(" C������ % s % s ��������� �� ������ % s,��������� � ������ % s \n " , stud[i].famil, stud[i].name, stud[i].adres, stud[i].grup);
}
printf("������� 1 ��� ������ �� �������, 2 ��� ������ �� �����, 3 ��� ������ �� ��������� ������, 4 ��� ������ �� ������ ������ ��������.\n");
int c=0;
scanf("%d", &c);

if (c == 1)
{
printf("������� �������\n");
char g[20];
scanf("%s", g);
int k = 0;
for (int i = 0; i < 3; i++)
{
int flag=1;
if (strcmp(g, stud[i].famil) == 0)
{
printf("%s %s %s", stud[i].name, stud[i].adres, stud[i].grup);
}

}
}
else if ( c ==2)
{
printf("������� ���\n");
char g[20];
scanf("%s", g);
int k = 0;
for (int i = 0; i < 3; i++)
{
int flag=1;
if (strcmp(g, stud[i].name) == 0)
{
printf("%s %s %s", stud[i].famil, stud[i].adres, stud[i].grup);
}

}
}
else if ( c ==3){
printf("������� �����\n");
char g[20];
scanf("%s", g);
int k = 0;
for (int i = 0; i < 3; i++)
{
int flag=1;
if (strcmp(g, stud[i].adres) == 0)
{
printf("%s %s %s", stud[i].name, stud[i].famil, stud[i].grup);
}

}
}
else if ( c ==4)
{
printf("������� ����� ������\n");
char g[20];
scanf("%s", g);
int k = 0;
for (int i = 0; i < 3; i++)
{
int flag=1;
if (strcmp(g, stud[i].grup) == 0)
{
printf("%s %s %s", stud[i].name, stud[i].adres, stud[i].famil);
}

}
}
getchar();
getchar();
return 0;
}