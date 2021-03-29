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
	//建構子
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
	//功能
	void enterPlayerShow();//輸入球員比賽表現
	void outputPlayerOneShow();//顯示球員單場表現
	void outputPlayerAllShow();//顯示球員季賽所有場次表現
	void outputPlayerAverageShow();//顯示球員季賽平均表現
	void renewseasonMostHigh();//更新季賽最高得分
	void countGameCounter();//計算出場數
private:
	//屬性
	int number;//球員背號
	string name;//球員姓名
	int twoPoint[5];//球員兩分得分(5場比賽)
	int threePoint[5];//球員三分得分(5場比賽)
	int foulPoint[5];//球員罰球得分(5場比賽)
	int totalPoint[5];//球員總得分(5場比賽)
	int foul[5];//球員犯規(5場比賽)
	int play[5];//球員出賽場次 1)出場 0)沒出場  (5場比賽)	
	int seasonMostHigh;//季賽最高得分
	float seasonAverage;//季賽平均得分
	int gamecounter;//比賽場數
	float seasonAverageFoul;//季賽平均犯規數

				 //功能
	void countOnePoint(int game);//計算單場總得分
	void countAveragePoint();//計算季賽平均得分
	void countAverageFoul();//計算季賽平均犯規數

};
#endif