#include <iostream>
using namespace std;
struct node
{
	char inf[256]; // �������� ����������
	struct node *next; // ������ �� ��������� �������
};


int size=0;
struct node *head = NULL, *last = NULL, *f = NULL; // ��������� �� ������ � ��������� �������� ������
int dlinna = 0;
void spstore(), review(void), del(char *name);

char find_el[256];
struct node *find(char *name); // ������� ���������� ��������
struct node *get_struct(void); // ������� �������� ��������

void spstore(void)
{
	struct node *p = NULL;
	p = get_struct();
	if (head == NULL && p != NULL) // ���� ������ ���, �� ������������� ������ ������
	{
		head = p;
		last = p;
	}
	else if (head != NULL && p != NULL) // ������ ��� ����, �� ��������� � �����
	{
		last->next = p;
		last = p;
	}
	size++;
	return;
}

struct node *get_struct(void)
{
	struct node *p = NULL;
	char s[256];

	if ((p = (node*)malloc(sizeof(struct node))) == NULL) // �������� ������ ��� ����� ������� ������
	{
		printf("������ ��� ������������� ������\n");
		exit(1);
	}

	printf("������� �������� �������: \n"); // ������ ������
	scanf("%s", s);
	if (*s == 0)
	{
		printf("������ �� ���� �����������\n");
		return NULL;
	}
	strcpy(p->inf, s);

	p->next = NULL;

	return p; // ���������� ��������� �� ��������� �������
}

/* ���������������� ���������� � ������ �������� (� �����)*/

/* �������� ����������� ������. */
void review(void)
{
	struct node *struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		printf("��� - %s, \n", struc->inf);

		struc = struc->next;
	}
	return;
}




/* ����� �������� �� �����������. */
struct node *find()
{
	char name[20];
	scanf("%s",name);
	struct node *struc = head;
	if (head == NULL)
	{
		printf("������ ����\n");
	}
	while (struc)
	{
		if (strcmp(name, struc->inf) == 0)
		{
			printf("������� ������!\n");
			return struc;
		}
		struc = struc->next;
	}
	printf("������� �� ������\n");
	return NULL;
}

/* �������� �������� �� �����������. */
void del()
{
	char name[20];
	scanf("%s",name);
	struct node *struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������
	struct node *prev;// ��������� �� �������������� ���������� �������
	int flag = 0; // ��������� ���������� ���������� �������� � ������

	if (head == NULL) // ���� ������ ������ ����� NULL, �� ������ ����
	{
		printf("������ ����\n");
		return;
	}

	if (strcmp(name, struc->inf) == 0) // ���� ��������� ������� - ������
	{
		flag = 1;
		head = struc->next; // ������������� ������ �� ��������� �������
		free(struc); // ������� ������ �������
		struc = head; // ������������� ��������� ��� ����������� ������
	}
	else
	{
		prev = struc;
		struc = struc->next;
	}

	while (struc) // ������ �� ������ � ����� ���������� ��������
	{
		if (strcmp(name, struc->inf) == 0) // ���� �����, ��
		{
			flag = 1; // ���������� ���������
			if (struc->next) // ���� ��������� ������� �� ��������� � ������
			{
				prev->next = struc->next; // ������ ���������
				free(struc); // ������� �������
				struc = prev->next; // ������������� ��������� ��� ����������� ������
			}
			else // ���� ��������� ������� ��������� � ������
			{
				prev->next = NULL; // �������� ��������� ��������������� ��������
				free(struc); // ������� �������
				return;
			}
			printf("������� �����\n");
		}
		else // ���� �� �����, ��
		{
			prev = struc; // ������������� ��������� ��� ����������� ������
			struc = struc->next;
		}

	}

	if (flag == 0) // ���� ���� = 0, ������ ������ ������� �� ������
	{
		printf("������� �� ������\n");
		return;
	}
	return;

}
void remove(){
	struct node *struc = head; // ���������, ���������� �� ������ ���������� �� ������ ������
	struct node *prev;// ��������� �� �������������� ���������� �������


	if (head->next != NULL) // ���� ��������� ������� ��������� � ������
	{
		head=head->next; // �������� ��������� ��������������� ��������
		free(struc); // ������� �������
		return;
	}
	else
	{
		head = NULL;
		free(struc);
	}
	return;

}


int main() {

	setlocale(LC_ALL, "Russian");
	int k = 1;
	node *Begin, *End;
	node *el = new node;
	el->next = NULL;
	Begin = End = el;
	while (k) {
		cout << "1 - ���������� �������� � ����� �������\n2 - �������� �������� �� �����������\n3 - ����� �������� �� �����������\n4 - ������� ������ ��������� ������� �� �����\n5 - �������� ���������� ��������\n" << "0 - �����" << endl;
		cin >> k;
		if (k == 5){
			remove();
		}
		if (k == 0)
			return 0;
		if (k == 1)
			spstore();
		if (k == 2){
			cout << "������� ������� ������: ";
			del();
		}
		if (k == 3){
			cout << "������� ������� ������: ";
			*find();
		}
		if (k == 4)
			review();
	}
	cout << endl;
	system("pause");
	return 0;
}
