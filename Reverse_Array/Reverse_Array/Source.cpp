#include<stdio.h>
#include<stdlib.h>
#define SIZE 100

int main(void)
{
	int i, len1;
	char str1[SIZE], str2[SIZE];

	printf("�п�J�@�Ӧr��G");
	scanf_s("%20s", str1, 21);
	for (i = 0; i < SIZE; i++)
	{
		if (str1[i] == '\0')
			break;
	}
	len1 = i;
	for (i = 0; i < len1; i++)
	{
		str2[i] = str1[len1 - 1 - i];
	}
	str2[len1] = '\0';
	printf("��l�r��  �G %s\n", str1);
	printf("�����r��G %s\n", str2);

	system("pause");
	return 0;
}