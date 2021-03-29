#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define SIZE 260


void strtoHex(char str[], char strh[]);

int main(void)
{
	char str[100], strh[220];
	printf("Please input a string: ");
	gets_s(str, 100);
	strtoHex(str, strh);
	printf("HEX: %s\n", strh);

	system("pause");
	return 0;
}


void strtoHex(char str[100], char strh[220])
{
	char temp[4];
	int i, j = 0, code;

	for (i = 0; str[i] != '\0'; i++)
	{
		code = str[i];
		sprintf_s(temp, 4, "%X", code);
		strh[j++] = temp[0];
		strh[j++] = temp[1];
	}
	strh[j] = '\0';
}