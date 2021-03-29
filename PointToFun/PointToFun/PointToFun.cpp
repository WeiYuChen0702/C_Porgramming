#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100
void MaxScore(int computer[], int program[], int MaxComIndex[], int MaxProgIndex[], int* MaxComNum, int* MaxProgNum, int* MaxComScore, int* MaxProgScore, int stuComIndex[], int stuProgIndex[]);

void Graph(int average[]);

int main(void)
{

	srand(time(NULL));
	int computer[SIZE], program[SIZE], average[SIZE], MaxComIndex[SIZE], MaxProgIndex[SIZE];
	int MaxComNum = 0, MaxProgNum = 0, MaxComScore = 0, MaxProgScore = 0;
	int stuComIndex[SIZE], stuProgIndex[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		computer[i] = rand() % 101;
		program[i] = rand() % 101;
		stuComIndex[i] = 109000000 + i + 1;
		stuProgIndex[i] = 109000000 + i + 1;
		average[i] = (computer[i] + program[i]) / 2;
	}
	printf("學號			平均成績\n");
	/*for (int i = 0; i < SIZE; i++)
	{
		if (average[i] < 60)
		{
			printf("%d		%d\n", stuComIndex[i], average[i]);
		}
	}*/
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d		%d\n", stuComIndex[i], average[i]);
	}
	printf("\n");
	MaxScore(computer, program, MaxComIndex, MaxProgIndex, &MaxComNum, &MaxProgNum, &MaxComScore, &MaxProgScore, stuComIndex, stuProgIndex);


	for (int i = 0; i < MaxComNum; i++)
	{
		printf("計概最高分同學為%d 成績為 %d\n", MaxComIndex[i], MaxComScore);
	}

	for (int i = 0; i < MaxProgNum; i++)
	{
		printf("程規最高分同學為%d 成績為%d\n", MaxProgIndex[i], MaxProgScore);
	}

	Graph(average);

	system("pause");
	return 0;
}
void Graph(int average[])
{
	int num[11] = { 0 }, n, i, j;
	
	for (n = 1; n <= SIZE; n++) {
		for (i = 1; i <= 10; i++) {
			if (1 + 10 * (i - 1) <= average[n - 1] && average[n - 1] <= 10 * i) {
				num[i - 1]++;
				break;
			}
		}
	}
	for (i = 1; i <= 10; i++) {
		printf("%3d-%3d:", 1 + 10 * (i - 1), i * 10);
		for (n = 1; n <= num[i - 1]; n++) {
			printf("*");
		}
		printf("\n");
	}
}

void MaxScore(int computer[], int program[], int MaxComIndex[], int MaxProgIndex[], int* MaxComNum, int* MaxProgNum, int* MaxComScore, int* MaxProgScore, int stuComIndex[], int stuProgIndex[])
{
	//int computer[], int program[] 分別是二科學生成績
	//int MaxComIndex[], int MaxProgIndex[] 分別是二科最高分的學生
	//int* MaxComNum, int* MaxProgNum 分別是二科最高分的學生人數
	//int* MaxComScore, int* MaxProgScore分別是二科最高分的分數
	int count_Com = 0, count_Prog = 0;
	int Max_Com = INT_MIN, Max_Pro = INT_MIN;
	for (int i = 0; i < SIZE; i++)
	{
		if (computer[i] >= Max_Com)
		{
			Max_Com = computer[i];
			*MaxComScore = computer[i];
		}
	}

	for (int i = 0; i < SIZE; i++)
	{
		if (computer[i] == *MaxComScore)
		{
			MaxComIndex[*MaxComNum] = stuComIndex[i];
			*MaxComNum += 1;
		}
	}
	//=====================================
	for (int i = 0; i < SIZE; i++)
	{
		if (program[i] >= Max_Pro)
		{
			Max_Com = program[i];
			*MaxProgScore = program[i];
		}
	}


	for (int i = 0; i < SIZE; i++)
	{
		if (program[i] == *MaxProgScore)
		{
			MaxProgIndex[*MaxProgNum] = stuProgIndex[i];
			*MaxProgNum += 1;
		}
	}

}