#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define SIZE 260

int main(void)
{
	char name[32], phrase[5][100], temp[132], cmd = 't', tmp;
	int index = 0, i;

	srand(time(NULL));
	printf("請輸入姓名: ");
	scanf_s("%s", name, 32);
	scanf_s("%c", &tmp, 1);
	printf("請輸入5句話:\n");
	for (i = 0; i < 5; i++)
	{
		gets_s(phrase[i], 100);
	}
	printf("<t> 對話, <q> 離開: ");
	scanf_s("%c", &cmd, 1);
	scanf_s("%c", &tmp, 1);
	while (cmd == 't')
	{
		index = rand() % 5;
		i = rand() % 2;
		if (i == 0)
		{
			strcpy_s(temp, name);
			strcat_s(temp, ", ");
			phrase[index][0] = tolower(phrase[index][0]);
			strcat_s(temp, phrase[index]);
			puts(temp);
		}
		else
		{
			phrase[index][0] = toupper(phrase[index][0]);
			puts(phrase[index]);
		}

		printf("<t> 對話, <q> 離開: ");
		scanf_s("%c", &cmd, 1);
		scanf_s("%c", &tmp, 1);
	}

	system("pause");
	return 0;
}