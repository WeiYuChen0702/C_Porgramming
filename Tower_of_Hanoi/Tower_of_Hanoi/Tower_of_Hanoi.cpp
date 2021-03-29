#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
void hanoi(int i, char begin, char mid, char dest);

int main(void)
{
	int i;

	printf("�`�@���h�ֽL�l�n�h?\n");
	scanf("%d", &i);
	hanoi(i, 'A', 'B', 'C');
	system("pause");
	return 0;
}

void hanoi(int i, char begin, char mid, char dest)
{
	if (i == 1) /* ���j�פ���� */
		printf("�N�� %d �ӽL�l�q�� %c �Ӷ𲾨�� %c �Ӷ�\n", i, begin, dest);
	else
	{
		hanoi(i - 1, begin, dest, mid);
		printf("�N�� %d �ӽL�l�q�� %c �Ӷ𲾨�� %c �Ӷ�\n", i, begin, dest);
		hanoi(i - 1, mid, begin, dest);
	}
}
/*1.Hanoi�����G
�@a. ��n-1�ӺФl�q�ӷ��W���Ȧs�W(�Y��Ӫ��ت��W�O�Ȧs�W�A�ӭ�Ȧs�W�O�ت��W)
 �@b. ���n�ӺФl�q�ӷ��W���ت��W
  �@c. ��n-1�ӺФl�q�Ȧs�W���ت��W(�Y��Ӫ��ӷ��W�O�Ȧs�W�A�ӭ�ӷ��W�O�Ȧs�W)
   ��X���X������A�HHanoi�ӻ��A����O��Фl���󢰮ɰ���AN �h�e���𪺳̤p���ʦ��ƫ�n�O 2��n���� - 1*/