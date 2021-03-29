#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

#define SIZE 100

int strconvert(char arr[], char tarr[]);

int main(void)
{
	char arr[SIZE] = { '\0' }, tarr[SIZE] = { '\0' };
	int len;

	printf("請輸入一個字串: ");
	scanf_s("%s", arr, 31);
	len = strconvert(arr, tarr);
	printf("加密後的字串: %s\n", tarr);

	system("pause");
	return 0;
}

int strconvert(char arr[], char tarr[])
{
	int i, len = 0;

	for (i = 0; arr[i] != '\0'; i++)
	{
		if (islower(arr[i]))
			tarr[len++] = 'A' + ((toupper(arr[i]) - 'A') + 5) % 26;
		else if (isupper(arr[i]))
			tarr[len++] = 'a' + ((tolower(arr[i]) - 'a') + 5) % 26;
		else if (isdigit(arr[i]))
			tarr[len++] = arr[i] - 15;
		else
		{
			tarr[len++] = '/';
			tarr[len++] = arr[i];
		}
	}
	tarr[len++] = '\0';
	return len;
}
