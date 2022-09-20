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
printf("¬ведите фамилию студента\n");
scanf("%s", &stud[i].famil);
printf("¬ведите им€ студента %s\n", stud[i].famil);
scanf("%s", &stud[i].name);
printf("¬ведите домашний адрес %s %s\n", stud[i].famil, stud[i].name);
scanf("%s", &stud[i].adres);
printf("¬ведите группу обучени€ %s %s\n", stud[i].famil, stud[i].name);
scanf("%s", &stud[i].grup);
}

for (i = 0; i < 3; i++)
{
printf(" Cтудент % s % s проживает по адресу % s,обучаетс€ в группе % s \n " , stud[i].famil, stud[i].name, stud[i].adres, stud[i].grup);
}
printf("¬ведите 1 дл€ поиска по фамилии, 2 дл€ поиска по имени, 3 дл€ поиска по домашнему адресу, 4 дл€ поиска по номеру группы студента.\n");
int c=0;
scanf("%d", &c);

if (c == 1)
{
printf("¬ведите фамилию\n");
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
printf("¬ведите им€\n");
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
printf("¬ведите адрес\n");
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
printf("¬ведите номер группы\n");
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