#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
	//�غc�l
	Player(int numberIn = 0, string nameIn = "");
	//get
	string getname();
	int getnumber();
	int gettwoPoint(int game);
	int getthreePoint(int game);
	int getfoulPoint(int game);
	int getfoul(int game);
	int getseasonMostHigh();
	float getseasonAverage();
	int getplay(int game);
	//set
	void setname(string nameIn);
	void setnumber(int numberIn);
	void settwoPoint(int twoPointIn, int game);
	void setthreePoint(int threePointIn, int game);
	void setfoulPoint(int foulPointIn, int game);
	void setfoul(int foulIn, int game);
	void setseasonMostHigh(int seasonMostHighIn);
	void setseasonAverage(float seasonAverageIn);
	void setplay(int playIn, int game);
	//�\��
	void enterPlayerShow();//��J�y�����ɪ�{
	void outputPlayerOneShow();//��ܲy�������{
	void outputPlayerAllShow();//��ܲy���u�ɩҦ�������{
	void outputPlayerAverageShow();//��ܲy���u�ɥ�����{
	void renewseasonMostHigh();//��s�u�ɳ̰��o��
	void countGameCounter();//�p��X����
private:
	//�ݩ�
	int number;//�y���I��
	string name;//�y���m�W
	int twoPoint[5];//�y������o��(5������)
	int threePoint[5];//�y���T���o��(5������)
	int foulPoint[5];//�y���@�y�o��(5������)
	int totalPoint[5];//�y���`�o��(5������)
	int foul[5];//�y���ǳW(5������)
	int play[5];//�y���X�ɳ��� 1)�X�� 0)�S�X��  (5������)	
	int seasonMostHigh;//�u�ɳ̰��o��
	float seasonAverage;//�u�ɥ����o��
	int gamecounter;//���ɳ���
	float seasonAverageFoul;//�u�ɥ����ǳW��

				 //�\��
	void countOnePoint(int game);//�p�����`�o��
	void countAveragePoint();//�p��u�ɥ����o��
	void countAverageFoul();//�p��u�ɥ����ǳW��

};
#endif