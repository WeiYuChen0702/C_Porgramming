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

	if ((cfptr = fopen("BMI1.txt", "r")) == NULL)//�}��,Ū��
	{
		printf("no find\n");
	}
	else
	{
		if ((dfptr = fopen("BMI1.dat", "wb")) == NULL)//bin�s��
		{
			printf("no find\n");
		}
		else
		{

			fscanf(cfptr, "%s", &str);

			while (!feof(cfptr))
			{
				strcpy(user.num, str);

				fscanf(cfptr, "%s%s%d%d%f", &user.name, &user.id, &user.height, &user.weight, &user.bmi);//�s�J���
				usernum = atoi(user.num);

				if (usernum == i)
				{
					fwrite(&user, sizeof(struct people), 1, dfptr);//�g�J
					//fseek(dfptr,i*sizeof(struct people),SEEK_SET);//���m
					//fread(&user,sizeof(struct people),1,dfptr);//Ū�J
					count++;
				}
				else
				{
					fwrite(&no, sizeof(struct people), 1, dfptr);//��l��
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
		printf("(1)��ܸ�� 2)�j�M 3)�D�G 4)�s�W 5)�ק� 6)�R�� 7)�x�s -1)����:");//��\��
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

	if ((dfptr = fopen("BMI1.dat", "rb")) == NULL)//bin�s��
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

	printf("�j�M�s��:");
	gets_s(m);
	gets_s(m);

	while (m[0] < 1)
		gets_s(m);

	if ((dfptr = fopen("BMI1.dat", "rb")) == NULL)//bin�s��
	{
		printf("no find\n");
	}
	else
	{
		fseek(dfptr, 0, SEEK_SET);
		for (i = 0; i < count; i++)//������
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
		printf("�L���|��\n");
}

void over(int count, struct people user)
{
	FILE* dfptr;
	struct people fat[100] = { " "," ",0,0,0,0.0 }, thin[100] = { " "," ",0,0,0,0.0 };
	int i = 0, p = 0, q = 0, m = 0, n = 0;

	if ((dfptr = fopen("BMI1.dat", "rb")) == NULL)//bin�s��
	{
		printf("no find\n");
	}
	else
	{
		printf("find\n");

		fseek(dfptr, 0, SEEK_SET);
		for (i = 0; i < 100; i++)//������
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
	printf("�L��\n");
	for (m = 0; m < p; m++)
		printf("%s\t%s\t%s\t%d\t%d\t%.1f\n", fat[m].num, fat[m].name, fat[m].id, fat[m].height, fat[m].weight, fat[m].bmi);

	printf("�L��\n");
	for (n = 0; n < q; n++)
		printf("%s\t%s\t%s\t%d\t%d\t%.1f\n", thin[n].num, thin[n].name, thin[n].id, thin[n].height, thin[n].weight, thin[n].bmi);


	fclose(dfptr);
}

int add(int count, struct people user)
{
	FILE* dfptr;
	struct people newone, no;
	int i = 0, temp = 0, newnum = 0, usernum;
	printf("��J�s��:");
	scanf("%s", &newone.num);
	printf("��J�m�W:");
	scanf("%s", &newone.name);
	printf("��J������:");
	scanf("%s", &newone.id);
	printf("��J����:");
	scanf("%d", &newone.height);
	printf("��J�魫:");
	scanf("%d", &newone.weight);
	newone.bmi = (float)newone.weight / (float)(newone.height * 0.01) / (float)(newone.height * 0.01);

	newnum = atoi(newone.num);

	if ((dfptr = fopen("BMI1.dat", "rb+")) == NULL)//bin�s��
	{
		printf("no find\n");
	}
	else
	{
		fseek(dfptr, (newnum - 1) * sizeof(struct people), SEEK_SET);
		fread(&user, sizeof(struct people), 1, dfptr);

		if (strcmp(newone.num, user.num) == 0)
		{
			printf("���Ʀ��|��\n");
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
	printf("��J�s��:");
	scanf("%s", &newone.num);
	printf("��J�m�W:");
	scanf("%s", &newone.name);
	printf("��J������:");
	scanf("%s", &newone.id);
	printf("��J����:");
	scanf("%d", &newone.height);
	printf("��J�魫:");
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
			printf("�L���|��\n");
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

	printf("�j�M�s��:");
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
					printf("�T�{�O�_�n�R��?(y/n)");
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
		printf("�L���|��\n");
}

void save(int count, struct people user)
{
	FILE* cfptr, * dfptr;
	int i = 0, usernum = 0;

	if ((dfptr = fopen("BMI1.dat", "rb")) == NULL)//�}��,Ū��
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
					fprintf(cfptr, "%s\t%s\t%s\t%d\t%d\t%f\n", user.num, user.name, user.id, user.height, user.weight, user.bmi);//�s�J���
			}
		}
	}
	fclose(dfptr);
	fclose(cfptr);
}