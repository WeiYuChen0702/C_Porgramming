#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct listnode
{
	char id[50], name[50], time[50], phone[50];
	struct listnode* nextptr;
};

typedef struct listnode* listnodeptr;

void display(listnodeptr startptr);
listnodeptr add(listnodeptr startptr);//�s�W�ק�
listnodeptr dele(listnodeptr startptr);//�R��

int main(void)
{
	listnodeptr startptr = NULL;
	int cho = 0;
	while (1)
	{
		printf("��ܥ\��: (1)�L�X (2)�s�W&�ק� (3)�R�� (-1)����:");
		scanf("%d", &cho);

		if (cho == 1)
			display(startptr);
		else if (cho == 2)
			startptr = add(startptr);
		else if (cho == 3)
			startptr = dele(startptr);
		else if (cho == -1)
			break;
		else
			continue;
	}

	system("pause");
	return 0;
}

void display(listnodeptr startptr)
{

	if (startptr == NULL)
	{
		printf("�L�H�w��\n");
	}
	printf("�����Ҹ�\t�m�W\t�w���ɶ�\t�q��\n");
	while (startptr != NULL)
	{

		printf("%s\t%s\t%s\t\t%s\n", startptr->id, startptr->name, startptr->time, startptr->phone);
		startptr = startptr->nextptr;
	}
}

listnodeptr add(listnodeptr startptr)
{
	listnodeptr tempptr = startptr, newnode;
	listnodeptr currentptr, previousptr;
	char find[50] = {}, b[50] = {}, c[50] = {}, input[50];
	int cho;

	printf("��JID:");
	gets_s(find);
	gets_s(find);

	while (tempptr != NULL)
	{
		if (strcmp(tempptr->id, find) == 0)
			break;

		tempptr = tempptr->nextptr;
	}

	if (tempptr == NULL)//�s�W
	{
		printf("��J�m�W:");
		gets_s(b);
		printf("��J�w���ɶ�:");
		gets_s(c);
		printf("��J�q��:");
		scanf("%s", input);

		newnode = (listnodeptr)malloc(sizeof(listnode));

		if (newnode != NULL)
		{
			strcpy(newnode->phone, input);
			strcpy(newnode->id, find);
			strcpy(newnode->name, b);
			strcpy(newnode->time, c);

			newnode->nextptr = NULL;

			currentptr = startptr;
			previousptr = NULL;

			while (currentptr != NULL && strcmp(c, currentptr->time) > 0)
			{
				previousptr = currentptr;
				currentptr = currentptr->nextptr;
			}

			if (previousptr == NULL)
			{
				newnode->nextptr = startptr;
				startptr = newnode;
			}
			else
			{
				previousptr->nextptr = newnode;
				newnode->nextptr = currentptr;
			}
		}
	}
	else//�ק�
	{
		printf("�O�_�ק�: 1)�O 2)�_:");
		scanf("%d", &cho);

		if (cho == 1)
		{
			currentptr = startptr;
			previousptr = NULL;

			while (currentptr != NULL && strcmp(find, currentptr->id) != 0)
			{
				previousptr = currentptr;
				currentptr = currentptr->nextptr;
			}
			if (previousptr == NULL)//�R���Y
			{
				tempptr = currentptr;//
				currentptr = currentptr->nextptr;//
				startptr = currentptr;//
			}
			else if (currentptr != NULL)
			{
				tempptr = currentptr;
				previousptr->nextptr = currentptr->nextptr;
				free(tempptr);
			}


			printf("��J�m�W:");
			gets_s(b);
			gets_s(b);
			printf("��J�w���ɶ�:");
			gets_s(c);
			printf("��J�q��:");
			scanf("%s", input);

			newnode = (listnodeptr)malloc(sizeof(listnode));

			if (newnode != NULL)
			{
				strcpy(newnode->phone, input);
				strcpy(newnode->id, find);
				strcpy(newnode->name, b);
				strcpy(newnode->time, c);

				newnode->nextptr = NULL;

				currentptr = startptr;
				previousptr = NULL;

				while (currentptr != NULL && strcmp(c, currentptr->time) > 0)
				{
					previousptr = currentptr;
					currentptr = currentptr->nextptr;
				}

				if (previousptr == NULL)
				{
					newnode->nextptr = startptr;
					startptr = newnode;
				}
				else
				{
					previousptr->nextptr = newnode;
					newnode->nextptr = currentptr;
				}
			}
		}
	}
	return startptr;
}

listnodeptr dele(listnodeptr startptr)
{
	listnodeptr tempptr = startptr, currentptr, previousptr;
	char find[50] = {};
	int input, cho;

	printf("��JID:");
	gets_s(find);
	gets_s(find);
	while (tempptr != NULL)
	{
		if (strcmp(tempptr->id, find) == 0)
			break;

		tempptr = tempptr->nextptr;
	}

	if (tempptr == NULL)
		printf("no find\n");
	else
	{
		printf(" 1)�O 2)�_:");
		scanf("%d", &cho);

		if (cho == 1)
		{
			currentptr = startptr;
			previousptr = NULL;

			while (currentptr != NULL && strcmp(find, currentptr->id) != 0)
			{
				previousptr = currentptr;
				currentptr = currentptr->nextptr;
			}
			if (previousptr == NULL)//�R���Y
			{
				tempptr = currentptr;//
				currentptr = currentptr->nextptr;//
				startptr = currentptr;//
			}
			else if (currentptr != NULL)
			{
				tempptr = currentptr;
				previousptr->nextptr = currentptr->nextptr;
				free(tempptr);
			}
		}
	}
	return startptr;
}