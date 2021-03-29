#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

void sortstrarr(char* strarr[], int len);

int main(void)
{

	int i = 0;
	char* strparr[8] = { (char*)"Pointer variables", (char*)"Array of pointers", (char*)"& is address operator", (char*)"Contain address of variable", (char*)"NULL points to nothing",
	(char*)"* indicates variable is a pointer",(char*)"dereferencing operator", (char*)"Selection sort using pass-by-reference" };

	sortstrarr(strparr, 8);
	for (i = 0; i < 8; i++)
		printf("%s\n", strparr[i]);

	system("pause");
	return 0;
}

void sortstrarr(char* strarr[], int len)
{
	int smallest, index, i;
	char* temp;

	for (i = 0; i < len - 1; i++)
	{
		smallest = i;
		for (index = i + 1; index < len; index++)
		{
			if ((*strarr[index]) < (*strarr[smallest]))
			{
				smallest = index;
			}
		}
		temp = strarr[i];
		strarr[i] = strarr[smallest];
		strarr[smallest] = temp;
	}
}
