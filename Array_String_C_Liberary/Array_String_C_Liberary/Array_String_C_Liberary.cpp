#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void search(char str[1000], char find[1000]);
void replace(char str[1000]);
void cut(char str[1000]);

int main(void)
{
	char str[1000] = {}, find[1000] = {};
	int choice = 0;
	//gets_s(find);
	printf("��J�r��:");
	gets_s(str);
	while (1)
	{
		printf("\n1)�j�M 2)���N 3)���� 4)����:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			search(str, find);
			break;
		case 2:
			replace(str);
			break;
		case 3:
			cut(str);
			break;
		case 4:
			return 0;
		default:
			printf("��J���~!�Э��s��J!!");
		}
	}
	system("pause");
	return 0;
}

void search(char str[1000], char find[1000])
{
	char* ptr = 0;
	printf("�n�j�M���r��:");
	//((char*)find);
	gets_s(find,1000);
	gets_s(find, 1000);
	ptr = strstr(str, find);
	while (ptr == NULL)
	{
		printf("NOTHING\n");
		return;
	}

	while (ptr != NULL)
	{
		printf("�����l�r��:%s,index�O%d\n", find, ptr - str);
		ptr = ptr + strlen(find);
		ptr = strstr(ptr, find);
	}
}

void replace(char str[1000])
{
	char substr1[1000] = {}, substr2[1000] = {}, temp[1000] = {};
	int i = 0, j = 0;
	char* ptr = 0, choice[5] = {};

	printf("�n�Q�������r:");
	gets_s(substr1);
	gets_s(substr1);

	ptr = strstr(str, substr1);
	if (ptr == NULL)
	{
		printf("no find\n");
		return;
	}

	printf("�n���������r:");
	gets_s(substr2);

	while (ptr != NULL)
	{
		printf("�����l�r��:%s,index�O%d�A�O�_�n����(y/n)?\n", substr1, ptr - str);
		scanf("%s", choice);

		if (strcmp(choice, "y") == 0 || strcmp(choice, "Y") == 0)
		{
			strcpy(temp, ptr + strlen(substr1));
			strcpy(ptr, substr2);
			strcat(ptr, temp);
			ptr += strlen(substr1);
		}
		else
		{
			ptr++;
		}
		ptr = strstr(ptr + 1, substr1);
	}
	puts(str);
}

void cut(char str[1000])
{
	char copy[1000] = {}, cutting[1000][1000] = {};
	char* ptr = 0;
	int i = 0, j = 0, k = 0, temp = 0, hold = 0;

	strcpy(copy, str);

	ptr = strtok(copy, " ,.!()");
	while (ptr != NULL)
	{
		strcpy(cutting[i], ptr);
		i++;
		ptr = strtok(NULL, " ,.!()");
	}

	printf("���Ϋ�:\n");
	for (j = 0; j < i; j++)
	{
		printf("%s\n", cutting[j]);
	}

	printf("�����j�g���r��:\n");
	for (j = 0; j < i; j++)
	{
		temp = 0;
		for (k = 0; k < strlen(cutting[j]); k++)
		{
			if (isupper(cutting[j][k]) != 0)
				temp++;
		}
		if (temp == strlen(cutting[j]))
			puts(cutting[j]);
	}

	printf("�ƭȦr��:\n");
	for (j = 0; j < i; j++)
	{
		hold = 0;
		for (k = 0; k < strlen(cutting[j]); k++)
		{
			if (isdigit(cutting[j][k]) != 0)
				hold++;
		}

		if (hold == strlen(cutting[j]))
			puts(cutting[j]);
	}
}