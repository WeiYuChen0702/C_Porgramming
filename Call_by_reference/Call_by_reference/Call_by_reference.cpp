#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

void print_grade1(int stu[], int PG_com[], int PG_pd[], float average[], int len, int ch);
void average_grade(int stu[], int PG_com[], int PG_pd[], float average[], int len);
void sortBioGrade(int stu[], int PG_com[], int PG_pd[], float average[], int len);
void sortCalGrade(int stu[], int PG_com[], int PG_pd[], float average[], int len);
void sortAvgGrade(int stu[], int PG_com[], int PG_pd[], float average[], int len);
void selectsort(int[], int);
void swap(int* const element1Ptr, int* const element2Ptr);
void swapfloat(float* const element1Ptr, float* const element2Ptr);




int main(void)
{
	int i, len, ch = 0, freq, value;
	int stu[SIZE];
	int PG_com[SIZE];
	int PG_pd[SIZE];
	float average[SIZE];

	srand(time(NULL));
	do {
		printf("請輸入人數(1~30): ");
		scanf("%d", &len);
	} while (len < 1 || len>30);
	average_grade(stu, PG_com, PG_pd, average, len);

	do {
		printf("選項: 1)依生物成績排名 2)依微積分成績排名 3)依平均成績排名 -1)結束: ");
		scanf("%d", &ch);
	} while (ch > 3 || ch == 0 || ch < -1);
	while (ch != -1)
	{
		switch (ch)
		{
		case 1:
			sortBioGrade(stu, PG_com, PG_pd, average, len);
			break;
		case 2:
			sortCalGrade(stu, PG_com, PG_pd, average, len);
			break;
		case 3:
			sortAvgGrade(stu, PG_com, PG_pd, average, len);
			break;
		default:
			break;
		}
		print_grade1(stu, PG_com, PG_pd, average, len, ch);
		do {
			printf("選項: 1)依生物成績排名 2)依微積分成績排名 3)依平均成績排名 -1)結束: ");
			scanf("%d", &ch);
		} while (ch > 3 || ch == 0 || ch < -1);
	}


	system("pause");
	return 0;
}
void print_grade1(int stu[], int PG_com[], int PG_pd[], float average[], int len, int ch)
{
	int i, rank = 1;
	printf("學生\t生物\t微積分\t平均\t排名\n");
	printf("%d\t%d\t%d\t%.2f\t%d\n", stu[0], PG_com[0], PG_pd[0], average[0], rank);
	for (i = 1; i < len; i++)
	{
		switch (ch)
		{
		case 1:
			if (PG_com[i] != PG_com[i - 1])
				rank = i + 1;
			break;
		case 2:
			if (PG_pd[i] != PG_pd[i - 1])
				rank = i + 1;
			break;
		case 3:
			if (average[i] != average[i - 1])
				rank = i + 1;
			break;
		default:
			break;
		}

		printf("%d\t%d\t%d\t%.2f\t%d\n", stu[i], PG_com[i], PG_pd[i], average[i], rank);
	}

	printf("\n");
}

void average_grade(int stu[], int PG_com[], int PG_pd[], float average[], int len)
{
	int i, count = 0;
	printf("學生\t生物\t微積分\t平均\n");
	for (i = 0; i < len; i++)
	{
		stu[i] = i + 1;
		PG_com[i] = rand() % 101;
		PG_pd[i] = rand() % 101;
		average[i] = (float)(PG_com[i] + PG_pd[i]) / 2;
		printf("%d\t%d\t%d\t%.2f\n", stu[i], PG_com[i], PG_pd[i], average[i]);
	}
}

void sortBioGrade(int stu[], int PG_com[], int PG_pd[], float average[], int len)
{
	int biggest, index, i;

	for (i = 0; i < len - 1; i++)
	{
		biggest = i;
		for (index = i + 1; index <= len; index++)
		{
			if (PG_com[index] > PG_com[biggest])
			{
				biggest = index;
			}
		}
		swapfloat(&average[i], &average[biggest]);
		swap(&stu[i], &stu[biggest]);
		swap(&PG_com[i], &PG_com[biggest]);
		swap(&PG_pd[i], &PG_pd[biggest]);
	}
}

void sortCalGrade(int stu[], int PG_com[], int PG_pd[], float average[], int len)
{
	int biggest, index, i;


	for (i = 0; i < len - 1; i++)
	{
		biggest = i;
		for (index = i + 1; index <= len; index++)
		{
			if (PG_pd[index] > PG_pd[biggest])
			{
				biggest = index;
			}
		}
		swapfloat(&average[i], &average[biggest]);
		swap(&stu[i], &stu[biggest]);
		swap(&PG_com[i], &PG_com[biggest]);
		swap(&PG_pd[i], &PG_pd[biggest]);
	}
}

void sortAvgGrade(int stu[], int PG_com[], int PG_pd[], float average[], int len)
{
	int biggest, index, i;
	int temp;
	float tempavg;

	for (i = 0; i < len - 1; i++)
	{
		biggest = i;
		for (index = i + 1; index <= len; index++)
		{
			if (average[index] > average[biggest])
			{
				biggest = index;
			}
		}
		swapfloat(&average[i], &average[biggest]);
		swap(&stu[i], &stu[biggest]);
		swap(&PG_com[i], &PG_com[biggest]);
		swap(&PG_pd[i], &PG_pd[biggest]);
	}
}

void swapfloat(float* const element1Ptr, float* const element2Ptr)
{
	float hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}

void swap(int* const element1Ptr, int* const element2Ptr)
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}