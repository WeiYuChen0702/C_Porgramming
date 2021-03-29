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
listnodeptr add(listnodeptr startptr);//新增修改
listnodeptr dele(listnodeptr startptr);//刪除

int main(void)
{
	listnodeptr startptr = NULL;
	int cho = 0;
	while (1)
	{
		printf("選擇功能: (1)印出 (2)新增&修改 (3)刪除 (-1)結束:");
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
		printf("無人預約\n");
	}
	printf("身分證號\t姓名\t預約時間\t電話\n");
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

	printf("輸入ID:");
	gets_s(find);
	gets_s(find);

	while (tempptr != NULL)
	{
		if (strcmp(tempptr->id, find) == 0)
			break;

		tempptr = tempptr->nextptr;
	}

	if (tempptr == NULL)//新增
	{
		printf("輸入姓名:");
		gets_s(b);
		printf("輸入預約時間:");
		gets_s(c);
		printf("輸入電話:");
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
	else//修改
	{
		printf("是否修改: 1)是 2)否:");
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
			if (previousptr == NULL)//刪除頭
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


			printf("輸入姓名:");
			gets_s(b);
			gets_s(b);
			printf("輸入預約時間:");
			gets_s(c);
			printf("輸入電話:");
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

	printf("輸入ID:");
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
		printf(" 1)是 2)否:");
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
			if (previousptr == NULL)//刪除頭
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