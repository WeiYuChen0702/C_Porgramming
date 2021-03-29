#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct mission
{
	char name[50], cosplay[50];
};

void add(struct  mission** team, int* num, int n);
void replace(struct  mission** team, int* num, int n);
void resize(struct  mission** team, int n, int newer);

int main(void)
{
	struct  mission** team;
	int i = 0, j = 0, k = 0, c = 0, x = 0, a = 0;
	int n = 0, * num, choice = 0, count = 0;
	char find[50];

	printf("組數:");
	scanf("%d", &n);

	while (n <= 0)
	{
		printf("不可小於0!\n組數:");
		scanf("%d", &n);
	}
	num = (int*)malloc(sizeof(int) * n);//人數
	team = (mission**)malloc(sizeof(mission*) * n);//組別

	for (i = 0; i < n; i++)
	{
		c = 0;
		printf("\n輸入第%d組人數:", i + 1);
		scanf("%d", &num[i]);

		while (num[i] <= 0)
		{
			printf("人數不可小於等於0\n輸入第%d組人數:", i + 1);
			scanf("%d", &num[i]);
		}


		team[i] = (mission*)malloc(sizeof(mission) * num[i]);//配置人數大小
		for (j = 0; j < num[i]; j++)
		{
			printf("名字:");
			scanf("%s", team[i][j].name);
			printf("(1)輸入1是組長 (2)輸入2是組員:");
			scanf("%d", &count);
			if (count == 1)
			{
				if (c == 0)
				{
					strcpy(team[i][j].cosplay, "組長");
					c = 1;
				}
				else
				{
					while (count != 2)
					{
						printf("(1)輸入1是組長 (2)輸入2是組員:");
						scanf("%d", &count);
						strcpy(team[i][j].cosplay, "組員");
					}
				}
			}

			else if (count == 2)
			{
				strcpy(team[i][j].cosplay, "組員");
			}

		}
		if (c == 0)
		{
			while (c == 0)
			{
				printf("無組長\n請輸入一個組員名字並修改成隊長!\n");
				scanf("%s", find);
				for (a = 0; a < num[i]; a++)
				{
					if (strcmp(find, team[i][a].name) == 0)
					{
						strcpy(team[i][a].cosplay, "組長");
						c = 1;
						break;
					}
				}
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		printf("\n第%d組:\n", i + 1);
		for (j = 0; j < num[i]; j++)
		{
			printf("%s\t%s\n", team[i][j].name, team[i][j].cosplay);
		}
	}
	while (1)
	{
		printf("選擇功能: 1)新增 2)更改 -1)結束:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			add(team, num, n);
			break;
		case 2:
			replace(team, num, n);
			break;
		case -1:
			free(num);
			for (i = 0; i < n; i++)
				free(team[i]);
			free(team);
			return 0;
		}
	}

	system("pause");
	return 0;
}

void add(struct  mission** team, int* num, int n)
{
	char enter[50] = {};
	int i = 0, j = 0, hold = 0, count = 0, c = 0;

	printf("\n要新增小組成員的小組的組長的姓名:");
	gets_s(enter);
	gets_s(enter);

	for (i = 0; i < n; i++)
	{
		for (j = 1; j < num[i]; j++)
		{
			if (strcmp(enter, team[i][0].name) == 0)
			{
				resize(&team[i], num[i], num[i] + 1);//加一格
				printf("新組員:\n");
				scanf("%s", team[i][num[i]].name);
				strcpy(team[i][num[i]].cosplay, "組員");
				hold = 1;
				num[i] = num[i] + 1;//人數加一
				break;
			}
		}
	}

	if (hold == 0)
		printf("no find\n");
	if (hold == 1)
	{
		for (i = 0; i < n; i++)//印出
		{
			printf("\n第%d組:\n", i + 1);

			for (j = 0; j < num[i]; j++)
			{
				printf("%s\t%s\n", team[i][j].name, team[i][j].cosplay);
			}
		}
	}
}

void replace(struct  mission** team, int* num, int n)
{
	char find[50] = {}, cho[3] = {};
	int i = 0, j = 0, hold = 0, temp = 0;

	printf("\n要修改的人名:");
	gets_s(find);
	gets_s(find);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < num[i]; j++)
		{
			if (strcmp(find, team[i][j].name) == 0)
			{
				printf("第%d組\t%s\t%s\n", i + 1, team[i][j].name, team[i][j].cosplay);

				printf("是否更換(y/n):");
				gets_s(cho);

				if (strcmp(cho, "y") == 0 || strcmp(cho, "Y") == 0)
				{
					printf("新組員:\n");
					scanf("%s", team[i][j].name);

					temp = 1;
				}
				else
				{
					hold = 1;
					break;
				}

				hold = 1;

				if (temp == 1)
					break;
			}
		}
		if (temp == 1)
			break;
	}
	if (hold == 0)
		printf("no find\n");

	for (i = 0; i < n; i++)//印出
	{
		printf("\n第%d組:\n", i + 1);

		for (j = 0; j < num[i]; j++)
		{
			printf("%s\t%s\n", team[i][j].name, team[i][j].cosplay);
		}
	}
}

void resize(struct  mission** team, int n, int newer)
{
	struct  mission* temp = *team, * hold;
	int i = 0;
	hold = (struct  mission*)malloc(sizeof(struct  mission) * newer);//開新位置

	for (i = 0; i < n; i++)//複製
		hold[i] = temp[i];

	free(*team);

	*team = hold;//取代
}