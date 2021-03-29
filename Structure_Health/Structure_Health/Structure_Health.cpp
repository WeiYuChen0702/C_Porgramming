#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void display(int count, struct people user);
void search(int count, struct people user);
void over(int count, struct people user);
int add(int count, struct people user);
void replace(int count, struct people user);
void dele(int count, struct people user);
void save(int count, struct people user);

struct  people
{
	char name[100], id[100], num[100];
	int height, weight;
	float bmi;
};

int main(void)
{
	FILE* cfptr, * dfptr;
	struct  people user, no = { " "," ",0,0,0,0.0 };
	char str[100] = { " " };
	int i = 1, count = 0, c = 0, usernum = 0;

	if ((cfptr = fopen("BMI1.txt", "r")) == NULL)//開檔,讀檔
	{
		printf("no find\n");
	}
	else
	{
		if ((dfptr = fopen("BMI1.dat", "wb")) == NULL)//bin存檔
		{
			printf("no find\n");
		}
		else
		{

			fscanf(cfptr, "%s", &str);

			while (!feof(cfptr))
			{
				strcpy(user.num, str);

				fscanf(cfptr, "%s%s%d%d%f", &user.name, &user.id, &user.height, &user.weight, &user.bmi);//存入資料
				usernum = atoi(user.num);

				if (usernum == i)
				{
					fwrite(&user, sizeof(struct people), 1, dfptr);//寫入
					//fseek(dfptr,i*sizeof(struct people),SEEK_SET);//找位置
					//fread(&user,sizeof(struct people),1,dfptr);//讀入
					count++;
				}
				else
				{
					fwrite(&no, sizeof(struct people), 1, dfptr);//初始化
				}
				fscanf(cfptr, "%s", &str);
				i++;
			}
		}
	}

	fclose(dfptr);
	fclose(cfptr);

	while (1)
	{
		printf("(1)顯示資料 2)搜尋 3)胖瘦 4)新增 5)修改 6)刪除 7)儲存 -1)結束:");//選功能
		scanf("%d", &c);
		switch (c)
		{
		case 1:
			display(count, user);
			break;
		case 2:
			search(count, user);
			break;
		case 3:
			over(count, user);
			break;
		case 4:
			count = add(count, user);
			break;
		case 5:
			replace(count, user);
			break;
		case 6:
			dele(count, user);
			break;
		case 7:
			save(count, user);
			break;
		case -1:
			return 0;
		}
	}

	system("pause");
	return 0;
}


void display(int count, struct people user)
{
	FILE* dfptr;
	int i = 0;

	if ((dfptr = fopen("BMI1.dat", "rb")) == NULL)//bin存檔
	{
		printf("no find\n");
	}
	else
	{
		for (i = 0; i < count; i++)
		{
			fread(&user, sizeof(struct people), 1, dfptr);
			if (user.height != 0)
			{
				printf("%s\t%s\t%s\t%d\t%d\t%.1f\n", user.num, user.name, user.id, user.height, user.weight, user.bmi);
			}
		}
	}
	fclose(dfptr);
}

void search(int count, struct people user)
{
	FILE* dfptr;
	int i = 0, temp = 0;
	char m[2] = { " " };

	printf("搜尋編號:");
	gets_s(m);
	gets_s(m);

	while (m[0] < 1)
		gets_s(m);

	if ((dfptr = fopen("BMI1.dat", "rb")) == NULL)//bin存檔
	{
		printf("no find\n");
	}
	else
	{
		fseek(dfptr, 0, SEEK_SET);
		for (i = 0; i < count; i++)//國民資料
		{
			fseek(dfptr, i * sizeof(struct people), SEEK_SET);
			fread(&user, sizeof(struct people), 1, dfptr);

			if (strcmp(m, user.num) == 0)
			{
				printf("%s\t%s\t%s\t%d\t%d\t%.1f\n", user.num, user.name, user.id, user.height, user.weight, user.bmi);
				temp++;
			}
		}
	}

	fclose(dfptr);

	if (temp == 0)
		printf("無此會員\n");
}

void over(int count, struct people user)
{
	FILE* dfptr;
	struct people fat[100] = { " "," ",0,0,0,0.0 }, thin[100] = { " "," ",0,0,0,0.0 };
	int i = 0, p = 0, q = 0, m = 0, n = 0;

	if ((dfptr = fopen("BMI1.dat", "rb")) == NULL)//bin存檔
	{
		printf("no find\n");
	}
	else
	{
		printf("find\n");

		fseek(dfptr, 0, SEEK_SET);
		for (i = 0; i < 100; i++)//國民資料
		{
			fseek(dfptr, i * sizeof(struct people), SEEK_SET);
			fread(&user, sizeof(struct people), 1, dfptr);

			if (user.height != 0)
			{
				if (user.bmi >= 24)
				{
					fat[p] = user;
					p++;
				}

				if (user.bmi < 18.5)
				{
					thin[q] = user;
					q++;
				}
			}
		}
	}
	printf("過重\n");
	for (m = 0; m < p; m++)
		printf("%s\t%s\t%s\t%d\t%d\t%.1f\n", fat[m].num, fat[m].name, fat[m].id, fat[m].height, fat[m].weight, fat[m].bmi);

	printf("過輕\n");
	for (n = 0; n < q; n++)
		printf("%s\t%s\t%s\t%d\t%d\t%.1f\n", thin[n].num, thin[n].name, thin[n].id, thin[n].height, thin[n].weight, thin[n].bmi);


	fclose(dfptr);
}

int add(int count, struct people user)
{
	FILE* dfptr;
	struct people newone, no;
	int i = 0, temp = 0, newnum = 0, usernum;
	printf("輸入編號:");
	scanf("%s", &newone.num);
	printf("輸入姓名:");
	scanf("%s", &newone.name);
	printf("輸入身分證:");
	scanf("%s", &newone.id);
	printf("輸入身高:");
	scanf("%d", &newone.height);
	printf("輸入體重:");
	scanf("%d", &newone.weight);
	newone.bmi = (float)newone.weight / (float)(newone.height * 0.01) / (float)(newone.height * 0.01);

	newnum = atoi(newone.num);

	if ((dfptr = fopen("BMI1.dat", "rb+")) == NULL)//bin存檔
	{
		printf("no find\n");
	}
	else
	{
		fseek(dfptr, (newnum - 1) * sizeof(struct people), SEEK_SET);
		fread(&user, sizeof(struct people), 1, dfptr);

		if (strcmp(newone.num, user.num) == 0)
		{
			printf("重複此會員\n");
		}
		else
		{
			fseek(dfptr, (newnum - 1) * sizeof(struct people), SEEK_SET);
			fwrite(&newone, sizeof(struct people), 1, dfptr);
			count++;
		}
	}
	fclose(dfptr);
	return count;
}

void replace(int count, struct people user)
{
	FILE* dfptr;
	struct people newone;
	int i = 0, temp = 0, newnum = 0;
	printf("輸入編號:");
	scanf("%s", &newone.num);
	printf("輸入姓名:");
	scanf("%s", &newone.name);
	printf("輸入身分證:");
	scanf("%s", &newone.id);
	printf("輸入身高:");
	scanf("%d", &newone.height);
	printf("輸入體重:");
	scanf("%d", &newone.weight);
	newone.bmi = (float)newone.weight / (float)(newone.height * 0.01) / (float)(newone.height * 0.01);
	newnum = atoi(newone.num);
	if ((dfptr = fopen("BMI1.dat", "rb+")) == NULL)
	{
		printf("no find\n");
	}
	else
	{
		fseek(dfptr, (newnum - 1) * sizeof(struct people), SEEK_SET);
		fread(&user, sizeof(struct people), 1, dfptr);
		if (strcmp(newone.num, user.num) == 0)
		{
			fseek(dfptr, (newnum - 1) * sizeof(struct people), SEEK_SET);
			fwrite(&newone, sizeof(struct people), 1, dfptr);
			printf("%s\t%s\t%s\t%d\t%d\t%.1f\n", newone.num, newone.name, newone.id, newone.height, newone.weight, newone.bmi);
		}
		else
		{
			printf("無此會員\n");
		}
	}

	fclose(dfptr);
}

void dele(int count, struct people user)
{
	FILE* dfptr, * efptr;
	struct people no = { " "," "," ",0,0,0.0 };
	int i = 0, temp = 0, usernum = 0;
	char m[1000] = { " " }, cho = 0;

	printf("搜尋編號:");
	gets_s(m);
	gets_s(m);

	while (m[0] < 1)
		gets_s(m);

	if ((dfptr = fopen("BMI1.dat", "rb+")) == NULL)
	{
		printf("no find\n");
	}
	else
	{
		if ((efptr = fopen("deleted.txt", "a")) == NULL)
		{
			printf("no find\n");
		}
		else
		{
			fseek(dfptr, 0, SEEK_SET);
			for (i = 0; i < count; i++)
			{
				fseek(dfptr, i * sizeof(struct people), SEEK_SET);
				fread(&user, sizeof(struct people), 1, dfptr);

				if (strcmp(m, user.num) == 0)
				{
					printf("確認是否要刪除?(y/n)");
					scanf("%c", &cho);

					if (cho == 'y' || cho == 'Y')
					{
						fprintf(efptr, "\n%s\t%s\t%s\t%d\t%d\t%f", user.num, user.name, user.id, user.height, user.weight, user.bmi);
						fseek(dfptr, i * sizeof(struct people), SEEK_SET);
						fwrite(&no, sizeof(struct people), 1, dfptr);

					}
					temp++;

				}
			}
		}
	}
	fclose(efptr);
	fclose(dfptr);

	if (temp == 0)
		printf("無此會員\n");
}

void save(int count, struct people user)
{
	FILE* cfptr, * dfptr;
	int i = 0, usernum = 0;

	if ((dfptr = fopen("BMI1.dat", "rb")) == NULL)//開檔,讀檔
	{
		printf("no find\n");
	}
	else
	{
		if ((cfptr = fopen("BMI1.txt", "w")) == NULL)
		{
			printf("no find\n");
		}
		else
		{
			for (i = 1; i <= count; i++)
			{
				fseek(dfptr, (i - 1) * sizeof(struct people), SEEK_SET);
				fread(&user, sizeof(struct people), 1, dfptr);
				if (user.height != 0)
					fprintf(cfptr, "%s\t%s\t%s\t%d\t%d\t%f\n", user.num, user.name, user.id, user.height, user.weight, user.bmi);//存入資料
			}
		}
	}
	fclose(dfptr);
	fclose(cfptr);
}