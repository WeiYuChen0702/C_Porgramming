#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
void hanoi(int i, char begin, char mid, char dest);

int main(void)
{
	int i;

	printf("總共有多少盤子要搬?\n");
	scanf("%d", &i);
	hanoi(i, 'A', 'B', 'C');
	system("pause");
	return 0;
}

void hanoi(int i, char begin, char mid, char dest)
{
	if (i == 1) /* 遞迴終止條件 */
		printf("將第 %d 個盤子從第 %c 個塔移到第 %c 個塔\n", i, begin, dest);
	else
	{
		hanoi(i - 1, begin, dest, mid);
		printf("將第 %d 個盤子從第 %c 個塔移到第 %c 個塔\n", i, begin, dest);
		hanoi(i - 1, mid, begin, dest);
	}
}
/*1.Hanoi公式：
　a. 把n-1個碟子從來源柱放到暫存柱(即原來的目的柱是暫存柱，而原暫存柱是目的柱)
 　b. 把第n個碟子從來源柱放到目的柱
  　c. 把n-1個碟子從暫存柱放到目的柱(即原來的來源柱是暫存柱，而原來源柱是暫存柱)
   找出跳出的條件，以Hanoi來說，條件是當碟子等於１時停止，N 層河內塔的最小移動次數恰好是 2的n次方 - 1*/