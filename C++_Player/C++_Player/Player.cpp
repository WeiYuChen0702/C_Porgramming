#include "Player.h"

Player::Player(int numberIn, string nameIn)
{
	setnumber(numberIn);//球員背號
	name = nameIn;//球員姓名
	for (int i = 0; i < 5; i++)
	{
		twoPoint[i] = 0;//球員兩分得分(5場比賽)
		threePoint[i] = 0;//球員三分得分(5場比賽)
		foulPoint[i] = 0;//球員罰球得分(5場比賽)
		totalPoint[i] = 0;//球員總得分(5場比賽)
		foul[i] = 0;//球員犯規(5場比賽)
		play[i] = 0;//球員出賽場次 1)出場 0)沒出場  (5場比賽)

	}
	seasonMostHigh = 0;//季賽最高得分
	seasonAverage = 0;//季賽平均得分
	gamecounter = 0;//比賽場數
	seasonAverageFoul = 0;//季賽平均犯規數
}
//get
string Player::getname()
{
	return name;
}
int Player::getnumber()
{
	return number;
}
int Player::gettwoPoint(int game)
{
	return twoPoint[game];
}
int Player::getthreePoint(int game)
{
	return threePoint[game];
}
int Player::getfoulPoint(int game)
{
	return foulPoint[game];
}
int Player::getfoul(int game)
{
	return foul[game];
}
int Player::getseasonMostHigh()
{
	return seasonMostHigh;
}
float Player::getseasonAverage()
{
	return seasonAverage;
}
int Player::getplay(int game)
{
	return play[game];
}


//set
void Player::setname(string nameIn)
{
	name = nameIn;
}
void Player::setnumber(int numberIn)
{
	if (numberIn < 0)
	{
		cout << "格式輸入錯誤！球員號碼不小於0！" << endl;
		number = 0;
	}
	else
		number = numberIn;
}
void Player::settwoPoint(int twoPointIn, int game)
{
	if (twoPointIn < 0)
		cout << "格式輸入錯誤！兩分球進球數不小於0！" << endl;
	else
		twoPoint[game] = twoPointIn;
}
void Player::setthreePoint(int threePointIn, int game)
{
	if (threePointIn < 0)
		cout << "格式輸入錯誤！三分球進球數不小於0！" << endl;
	else
		threePoint[game] = threePointIn;
}
void Player::setfoulPoint(int foulPointIn, int game)
{
	if (foulPointIn < 0)
		cout << "格式輸入錯誤！罰球進球數不小於0！" << endl;
	else
		foulPoint[game] = foulPointIn;
}
void Player::setfoul(int foulIn, int game)
{
	if (foulIn < 0 || foulIn>5)
		cout << "格式輸入錯誤！犯規次數不小於0！不大於5！" << endl;
	else
		foul[game] = foulIn;
}
void Player::setseasonMostHigh(int seasonMostHighIn)
{
	if (seasonMostHighIn < 0)
		cout << "格式輸入錯誤！季賽最高得分不小於0！" << endl;
	else
		seasonMostHigh = seasonMostHighIn;
}
void Player::setseasonAverage(float seasonAverageIn)
{
	if (seasonAverageIn < 0)
		cout << "格式輸入錯誤！季賽平均得分不小於0！" << endl;
	else
		seasonAverage = seasonAverageIn;
}
void Player::setplay(int playIn, int game)
{
	if (playIn != 0 && playIn != 1)
		cout << "格式輸入錯誤！1)出場 0)沒出場！" << endl;
	else
		play[game] = playIn;
}
//功能
void Player::enterPlayerShow()
{
	int game, two, three, foul, foulball, rebound, steal;
	cout << "輸入比賽場次(1~5場)：";
	cin >> game;
	cout << "本場比賽  2分得分球數：";
	cin >> two;
	cout << "本場比賽  3分得分球數：";
	cin >> three;
	cout << "本場比賽  罰球得分球數：";
	cin >> foul;
	cout << "本場比賽  犯規次數：";
	cin >> foulball;
	settwoPoint(two, game - 1);//設定
	setthreePoint(three, game - 1);
	setfoulPoint(foul, game - 1);
	setfoul(foulball, game - 1);


	play[game - 1] = 1;//紀錄出賽場次
	countOnePoint(game - 1);//紀錄單場總得分
	renewseasonMostHigh();//更新單場最高得分
	countAveragePoint();//計算平均得分
	countAverageFoul();//計算平均犯規數



}//輸入球員比賽表現
void Player::outputPlayerOneShow()
{
	int game;
	cout << "選擇球員" << number << "號的第幾場比賽：";
	cin >> game;
	if (play[game - 1] == 1)
	{
		cout << "第" << game << "場比賽：" << endl;
		cout << "兩分球得分：" << right << setw(6) << (twoPoint[game - 1]) * 2 << "分" << endl;
		cout << "三分球得分：" << right << setw(6) << (threePoint[game - 1]) * 3 << "分" << endl;
		cout << "罰球得分：" << right << setw(8) << foulPoint[game - 1] << "分" << endl;
		cout << "總得分：" << right << setw(10) << totalPoint[game - 1] << "分" << endl;
		cout << "犯規次數：" << right << setw(8) << foul[game - 1] << "次" << endl;
	}
	else
		cout << "沒有這場比賽的資料";
}//顯示球員單場表現
void Player::outputPlayerAllShow()
{
	for (int i = 0; i < 5; i++)
	{
		if (play[i] == 1)
		{
			cout << "第" << i + 1 << "場比賽：" << endl;
			cout << "兩分球得分：" << right << setw(6) << (twoPoint[i]) * 2 << "分" << endl;
			cout << "三分球得分：" << right << setw(6) << (threePoint[i]) * 3 << "分" << endl;
			cout << "罰球得分：" << right << setw(8) << foulPoint[i] << "分" << endl;
			cout << "總得分：" << right << setw(10) << totalPoint[i] << "分" << endl;
			cout << "犯規次數：" << right << setw(8) << foul[i] << "次" << endl;
		}
	}
}//顯示球員季賽所有場次表現
void Player::outputPlayerAverageShow()
{
	cout << "季賽最高得分：" << right << setw(4) << seasonMostHigh << "分" << endl;
	cout << "季賽平均得分：" << right << setw(4) << seasonAverage << "分" << endl;
	cout << "平均犯規數：" << right << setw(6) << seasonAverageFoul << "次" << endl;
}//顯示球員季賽平均表現
void Player::countOnePoint(int game)
{
	totalPoint[game] = 2 * twoPoint[game] + 3 * threePoint[game] + foulPoint[game];
}//計算單場總得分(private)
void Player::countAveragePoint()
{
	countGameCounter();
	float average = 0;
	for (int i = 0; i < 5; i++)
	{
		average = average + totalPoint[i];
	}
	seasonAverage = average / (float)gamecounter;
}//計算季賽平均得分(private)
void Player::countAverageFoul()
{
	countGameCounter();
	float average = 0;
	for (int i = 0; i < gamecounter; i++)
	{
		average = average + foul[i];
	}
	seasonAverageFoul = average / (float)gamecounter;
}//計算季賽平均犯規數(private)
void Player::renewseasonMostHigh()//更新季賽最高得分
{
	int max = 0;
	for (int i = 0; i < 5; i++)
	{
		if (totalPoint[i] > max)
			max = totalPoint[i];
	}
	seasonMostHigh = max;
}
void Player::countGameCounter()
{
	gamecounter = 0;
	for (int i = 0; i < 5; i++)
	{
		if (play[i] == 1)
		{
			gamecounter++;
		}
	}
}//計算出場數
