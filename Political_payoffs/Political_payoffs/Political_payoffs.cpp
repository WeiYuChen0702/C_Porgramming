#include<stdio.h>
#include<stdlib.h>

void sel(int dia[10], int* i);//selecon sort
void swap(int* x, int* y);//selection 的交換
void divide(int dia[10], int* i, int A[10], int B[10]);//平分
int main(void)
{
	int dia[10] = { 0 }, A[10] = { 0 }, B[10] = { 0 }, i = 0;
	printf("總共有幾顆:");
	scanf("%d", &i);
	for (int n = 0; n < i; n++)
	{
		printf("請輸入鑽石克拉:");
		scanf("%d", &dia[n]);
	}
	sel(dia, &i);
	divide(dia, &i, A, B);
	system("pause");
	return 0;
}

void sel(int dia[10], int* i)
{
	int biggest, index;
	for (int a = 0; a < *i - 1; a++)
	{
		biggest = a;
		for (index = a; index < *i; index++)
			if (dia[index] > dia[biggest])
				biggest = index;
		swap(&dia[a], &dia[biggest]);
	}
}

void swap(int* x, int* y)
{
	int hold = *x;
	*x = *y;
	*y = hold;
}

void divide(int dia[10], int* i, int A[10], int B[10])
{
	int s1 = 0, s2 = 0, x1 = 0, x2 = 0;
	for (int h = 0; h < *i; h++)
	{
		printf("偷的鑽石有%d克拉\n", dia[h]);
	}
	for (int g = 0; g < *i; g++)
	{
		if (s1 <= s2)
		{
			A[x1] = dia[g];
			s1 = s1 + A[x1];
			x1++;
		}
		else
		{
			B[x2] = dia[g];
			s2 = s2 + B[x2];
			x2++;
		}
	}
	printf("A:");
	for (int y = 0; y < x1; y++)
	{
		printf("%d,", A[y]);
	}
	printf("B:");
	for (int p = 0; p < x2; p++)
	{
		printf("%d,", B[p]);
	}
	if (s2 > s1)
		printf("\n兩者差距:%d\n", s2 - s1);
	else
		printf("\n兩者差距:%d\n", s1 - s2);
}