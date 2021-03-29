#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct Item
{
	int num, money, inventory;
	char name[100];
};
void add(struct Item goods[], int arrayLength);
int enter(struct Item goods[]);
int search(struct Item goods[], int arrayLength, int searchItemNo);
int searchFew(struct Item goods[], int arrayLength, int fewItem[]);
void sort(struct Item goods[], int i);
int replace(struct Item goods[], int arrayLength);

int main(void)
{
	struct Item goods[1000] = { 0 };
	int find = 0, choice = 0, less = 0, fewItem[1000] = { 0 };
	int arrayLength = 0, searchItemNo = 0;
	int i = 0, j = 0;

	arrayLength = enter(goods);

	printf("\n");


	while (1)
	{
		printf("��ܥ\��:(1)�j�M�f�~ (2) �j�M�w�s�q�C��10���f�~ (3)�ק�f�~��� (-1):���}:");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 1:
			find = search(goods, arrayLength, searchItemNo);
			if (find == -1)
			{
				printf("�S��\n");
			}
			else
			{
				printf("�s��:\t���:\t�w�s:\t�~�W:\n");
				printf("%d\t%d\t%d\t%s\n", goods[find].num, goods[find].money, goods[find].inventory, goods[find].name);
			}
			break;
		case 2:
			less = searchFew(goods, arrayLength, fewItem);
			if (less == 0)
				printf("no find\n");
			else
			{
				printf("�s��:\t���:\t�w�s:\t�~�W:\n");
				for (i = 0; i < less; i++)
				{
					j = fewItem[i];
					printf("%d\t%d\t%d\t%s\n", goods[j].num, goods[j].money, goods[j].inventory, goods[j].name);
				}
			}
			break;
		case 3:
			arrayLength = replace(goods, arrayLength);
			break;
		case -1:
			return 0;
		}
	}

	system("pause");
	return 0;
}

int enter(struct Item goods[])
{
	int i = 0, j = 0;
	printf("�s��:");
	scanf("%d", &goods[i].num);
	if (goods[i].num == -1)
		printf("�ʳf��!�y�w��ļ\n");
	while (goods[i].num != -1)
	{
		while (goods[i].num < 0)
		{
			printf("���i�H�p�l���l0!\n�s��:");
			scanf("%d", &goods[i].num);
			while (goods[i].num == -1)
			{
				return i;
			}
		}
		for (j = 0; j < i; j++)
		{
			while (goods[i].num == goods[j].num)
			{
				printf("����!�ШϥΪ̭��s��J�s��:");
				scanf("%d", &goods[i].num);
				while (goods[i].num == -1)
				{
					return i;
				}
			}
			while (goods[i].num <= 0)
			{
				printf("���i�H�p�l���l0!\n�ШϥΪ̭��s��J�s��:");
				scanf("%d", &goods[i].num);
				while (goods[i].num == -1)
				{
					return i;
				}
			}
		}
		printf("���:");
		scanf("%d", &goods[i].money);

		while (goods[i].money <= 0)
		{
			printf("���:");
			scanf("%d", &goods[i].money);
		}
		printf("�w�s:");
		scanf("%d", &goods[i].inventory);
		while (goods[i].inventory <= 0)
		{
			printf("�w�s:");
			scanf("%d", &goods[i].inventory);
		}
		printf("�~�W:");
		gets_s(goods[i].name);
		gets_s(goods[i].name);
		i++;
		printf("�s��:");
		scanf("%d", &goods[i].num);
	}
	sort(goods, i);
	while (goods[i].num != -1)
	{
		printf("�s��:\t���:\t�w�s:\t�~�W:\n");
		for (j = 0; j < i; j++)
		{
			printf("%d\t%d\t%d\t%s\n", goods[j].num, goods[j].money, goods[j].inventory, goods[j].name);
		}
	}
	return i;
}

int search(struct Item goods[], int arrayLength, int searchItemNo)
{
	int i = 0;
	printf("�j�M�s��:");
	scanf("%d", &searchItemNo);

	while (searchItemNo <= 0)
	{
		printf("�j�M�s��:");
		scanf("%d", &searchItemNo);
	}
	for (i = 0; i <= arrayLength; i++)
	{
		if (searchItemNo == goods[i].num)
			return i;
	}
	return -1;
}

int searchFew(struct Item goods[], int arrayLength, int fewItem[])
{
	int i = 0, j = 0;

	for (i = 0; i < arrayLength; i++)
	{
		if (goods[i].inventory <= 10)
		{
			fewItem[j] = i;
			j++;
		}
	}
	return  j;
}

void sort(struct Item goods[], int i)
{
	int a = 0, b = 0;
	int min = 0;
	struct Item temp;
	for (a = 0; a < i - 1; a++)
	{
		min = a;
		for (b = a + 1; b < i; b++)
			if (goods[b].num < goods[min].num)
				min = b;

		temp = goods[a];
		goods[a] = goods[min];
		goods[min] = temp;
	}
}

int replace(struct Item goods[], int arrayLength)
{
	int i = 0, replacenum = 0, temp = 0;
	char replacename[1000] = {}, cho[2] = {};


	printf("�j�M�s��:");
	scanf("%d", &replacenum);

	while (replacenum < 0)
	{
		printf("�j�M�s��:");
		scanf("%d", &replacenum);
	}

	for (int k = 0; k <= arrayLength; k++)
	{
		if (replacenum == goods[k].num)
		{
			printf("\n�Ч�s!\n");
			printf("���:");
			scanf("%d", &goods[k].money);
			printf("�w�s:");
			scanf("%d", &goods[k].inventory);
			printf("�~�W:");
			gets_s(goods[k].name);
			gets_s(goods[k].name);
			temp = 1;
		}
	}
	if (temp == 0)
	{
		printf("�S��!\n");
		printf("�n�s�W��(y/n)?");
		scanf("%s", cho);
	}
	if (cho[0] == 'y' || cho[0] == 'Y')
	{
		add(goods, arrayLength);
		arrayLength++;
		sort(goods, arrayLength);

		printf("�s��:\t���:\t�w�s:\t�~�W:\n");
		for (i = 0; i < arrayLength; i++)
		{
			printf("%d\t%d\t%d\t%s\n", goods[i].num, goods[i].money, goods[i].inventory, goods[i].name);
		}
	}
	else
	{
		printf("�s��:\t���:\t�w�s:\t�~�W:\n");
		for (i = 0; i < arrayLength; i++)
		{
			printf("%d\t%d\t%d\t%s\n", goods[i].num, goods[i].money, goods[i].inventory, goods[i].name);
		}
		return arrayLength;
	}
}

void add(struct Item goods[], int arrayLength)
{
	int i = arrayLength;
	printf("�s��:");
	scanf("%d", &goods[i].num);

	while (goods[i].num <= 0)
	{
		printf("�s��:");
		scanf("%d", &goods[i].num);
	}
	for (int j = 0; j < i; j++)
	{
		while (goods[i].num == goods[j].num || goods[i].num < 0)
		{
			printf("�ШϥΪ̭��s��J�s��:");
			scanf("%d", &goods[i].num);
			j = -1;
		}
	}
	printf("���:");
	scanf("%d", &goods[i].money);

	while (goods[i].money <= 0)
	{
		printf("���:");
		scanf("%d", &goods[i].money);
	}
	printf("�w�s:");
	scanf("%d", &goods[i].inventory);
	while (goods[i].inventory <= 0)
	{
		printf("�w�s:");
		scanf("%d", &goods[i].inventory);
	}
	printf("�~�W:");
	gets_s(goods[i].name);
	gets_s(goods[i].name);
	i++;
}