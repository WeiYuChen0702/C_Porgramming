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
	printf("輸入字串:");
	gets_s(str);
	while (1)
	{
		printf("\n1)搜尋 2)取代 3)切割 4)結束:");
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
			printf("輸入錯誤!請重新輸入!!");
		}
	}
	system("pause");
	return 0;
}

void search(char str[1000], char find[1000])
{
	char* ptr = 0;
	printf("要搜尋的字串:");
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
		printf("有找到子字串:%s,index是%d\n", find, ptr - str);
		ptr = ptr + strlen(find);
		ptr = strstr(ptr, find);
	}
}

void replace(char str[1000])
{
	char substr1[1000] = {}, substr2[1000] = {}, temp[1000] = {};
	int i = 0, j = 0;
	char* ptr = 0, choice[5] = {};

	printf("要被替換的字:");
	gets_s(substr1);
	gets_s(substr1);

	ptr = strstr(str, substr1);
	if (ptr == NULL)
	{
		printf("no find\n");
		return;
	}

	printf("要替換成的字:");
	gets_s(substr2);

	while (ptr != NULL)
	{
		printf("有找到子字串:%s,index是%d，是否要替換(y/n)?\n", substr1, ptr - str);
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

	printf("切割後:\n");
	for (j = 0; j < i; j++)
	{
		printf("%s\n", cutting[j]);
	}

	printf("全部大寫的字串:\n");
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

	printf("數值字串:\n");
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