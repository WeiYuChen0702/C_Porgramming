#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct booking
{
	char name[50], time[50], number[50];
	int phone;
};

booking* resize(struct booking* guest, int n, int lengh);
void display(struct booking* guest, int* cptr, int* nptr);
booking* del(struct booking* guest, int* cptr, int* nptr);
booking* add(struct booking* guest, int* cptr, int* nptr);
booking* sort(struct booking* guest, int* cptr);
void save(struct booking* guest, int* cptr);

int main(void)
{
	struct booking* guest;
	FILE* cfptr;
	char str[10] = {}, str1[] = "日期:", str2[] = "2016/3/29", str3[] = "組數:", str4[] = "訂位紀錄:";
	int i = 0, n = 4, temp = 0, count = 0, choice = 0;
	int* nptr = &n, * cptr = &count;

	guest = (booking*)malloc(sizeof(booking) * n);
	cfptr = fopen("booking.txt", "r");

	if (cfptr == NULL)
		printf("no find\n");
	else
	{
		fscanf(cfptr, "%s", str);

		while (strcmp(str, str4) != 0)
		{
			fscanf(cfptr, "%s", str);

			if (strcmp(str, str3) == 0)
				fscanf(cfptr, "%d", &temp);
		}
		while (!feof(cfptr))
		{
			fscanf(cfptr, "%s%s%s%d", guest[count].name, guest[count].time, guest[count].number, &guest[count].phone);

			if (count == (n - 1))
			{
				guest = resize(guest, n, 2 * n);
				n = 2 * n;
			}
			count++;
		}
		count--;
		if (count <= (n / 2) && n >= 4)
		{
			guest = resize(guest, n, n / 2);
			n = n / 2;
		}
	}
	while (1)
	{
		printf("(1)顯示 (2)刪除 (3)新增 (4)存檔 (-1)跳出:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			display(guest, &count, &n);
			break;
		case 2:
			guest = del(guest, &count, &n);
			break;
		case 3:
			guest = add(guest, &count, &n);
			break;
		case 4:
			save(guest, &count);
			break;
		case -1:
			free(guest);
			return 0;
		}
	}

	system("pause");
	return 0;
}
booking* resize(struct booking* guest, int n, int lengh)
{
	struct booking* temp;
	int i = 0;

	temp = (booking*)malloc(sizeof(booking) * lengh);

	for (i = 0; i < lengh; i++)
		temp[i] = guest[i];

	free(guest);
	return temp;
}
void display(struct booking* guest, int* cptr, int* nptr)
{
	char str1[] = "日期:", str2[] = "2016/3/29", str3[] = "組數:", str4[] = "訂位紀錄:";
	int i = 0;

	printf("\n");
	printf("%s %s\n", str1, str2);
	printf("%s %d\n", str3, *cptr);
	printf("%s\n", str4);
	printf("目前n的變化為%d\n", *nptr);
	for (i = 0; i < *cptr; i++)
		printf("%s\t%s\t%s\t0%d\n", guest[i].name, guest[i].time, guest[i].number, guest[i].phone);
	printf("\n");
}
booking* del(struct booking* guest, int* cptr, int* nptr)
{
	int search = 0, temp = 0, i = 0, j = 0;
	int& n = *nptr, & count = *cptr;
	char cho[3] = {};

	printf("輸入訂位者電話:");
	scanf("%d", &search);

	for (i = 0; i < count; i++)
	{
		if (search == guest[i].phone)
		{
			printf("確定刪除(y/n):");
			gets_s(cho);
			gets_s(cho);

			if (strcmp(cho, "y") == 0 || strcmp(cho, "Y") == 0)
			{
				for (j = i; j < count; j++)
					guest[j] = guest[j + 1];

				count--;
			}
			temp = 1;
		}
	}

	if (temp == 0)
		printf("無此人員\n");

	if (count <= (n / 2) && n >= 4)
	{
		guest = resize(guest, n, n / 2);
		n = n / 2;
	}

	display(guest, &count, &n);

	return guest;
}
booking* add(struct booking* guest, int* cptr, int* nptr)
{
	struct booking user;
	int choice = 0;
	int i = 0, temp = 0;
	int& n = *nptr, & count = *cptr;

	printf("輸入訂位人:");
	scanf("%s", user.name);
	printf("輸入訂位時間:");
	scanf("%s", user.time);
	printf("輸入人數:");
	scanf("%s", user.number);
	printf("輸入聯絡電話:");
	scanf("%d", &user.phone);

	for (i = 0; i < count; i++)
	{
		if (user.phone == guest[i].phone)
		{
			printf("確定是否要(1)刪除舊訂位資料，改成新訂位資料 (2) 不要新增訂位:");
			scanf("%d", &choice);
			if (choice == 1)
			{
				strcpy(guest[i].time, user.time);
				strcpy(guest[i].number, user.number);
				temp = 1;
			}
			else
			{
				temp = 1;
			}
		}
	}

	if (temp == 0)
	{
		guest[count] = user;
		count++;
	}

	if (count == n)
	{
		guest = resize(guest, n, 2 * n);
		n = 2 * n;
	}

	guest = sort(guest, &count);
	display(guest, &count, &n);

	return guest;
}
booking* sort(struct booking* guest, int* cptr)
{
	struct booking temp;
	int i = 0, j = 0, min = 0;

	for (i = 0; i < *cptr - 1; i++)//selection sort
	{
		min = i;
		for (j = i; j < *cptr; j++)
		{
			if (strcmp(guest[min].time, guest[j].time) > 0)
				min = j;
		}

		temp = guest[i];
		guest[i] = guest[min];
		guest[min] = temp;
	}

	return guest;
}
void save(struct booking* guest, int* cptr)
{
	FILE* cfptr;
	cfptr = fopen("booking.txt", "w");
	char str1[] = "日期:", str2[] = "2016/3/29", str3[] = "組數:", str4[] = "訂位紀錄:";
	int i = 0;

	if (cfptr == NULL)
		printf("no find\n");
	else
	{
		fprintf(cfptr, "%s %s\n", str1, str2);
		fprintf(cfptr, "%s %d\n", str3, *cptr);
		fprintf(cfptr, "%s\n", str4);
		for (i = 0; i < *cptr; i++)
			fprintf(cfptr, "%s\t%s\t%s\t0%d\n", guest[i].name, guest[i].time, guest[i].number, guest[i].phone);
	}

	fclose(cfptr);
}