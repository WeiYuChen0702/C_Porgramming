#include "Player.h"

void enterPlayerData(string& name, int& number)
{
	cout << "輸入球員姓名(跳過打-1)：";
	cin >> name;
	cout << "輸入球員背號(跳過打-1)：";
	cin >> number;
}//輸入球員基本資料

int main()
{
	string name;
	int op = 0, number = 0, game = 0, opplayer = 0, player;
	Player play[5];
	cout << "輸入球員基本資料：" << endl;
	for (int i = 0; i < 5; i++)
	{
		enterPlayerData(name, number);
		if (name != "-1")
			play[i].setname(name);
		if (number != -1)
			play[i].setnumber(number);
	}
	cout << "選擇功能：1)輸入球員基本資料 2)輸入球員單場表現 3)顯示球員單場表現 4)顯示季賽所有場次表現 5)顯示球員季賽平均表現  -1)exit：";
	cin >> op;
	while (op != -1)
	{
		if (op == 1)
		{
			cout << "球員有" << play[0].getnumber() << "、" << play[1].getnumber() << "、" << play[2].getnumber() << "、" << play[3].getnumber() << "、" << play[4].getnumber() << endl;
			cout << "選擇一位球員(背號)：";
			cin >> opplayer;
			for (int i = 0; i < 5; i++)
			{
				if (play[i].getnumber() == opplayer)
					player = i;
			}
			play[player].enterPlayerShow();
		}
		if (op == 2)
		{
			cout << "球員有" << play[0].getnumber() << "、" << play[1].getnumber() << "、" << play[2].getnumber() << "、" << play[3].getnumber() << "、" << play[4].getnumber() << endl;
			cout << "選擇一位球員(背號)：";
			cin >> opplayer;
			for (int i = 0; i < 5; i++)
			{
				if (play[i].getnumber() == opplayer)
					player = i;
			}
			play[player].outputPlayerOneShow();
		}
		if (op == 3)
		{
			cout << "球員有" << play[0].getnumber() << "、" << play[1].getnumber() << "、" << play[2].getnumber() << "、" << play[3].getnumber() << "、" << play[4].getnumber() << endl;
			cout << "選擇一位球員(背號)：";
			cin >> opplayer;
			for (int i = 0; i < 5; i++)
			{
				if (play[i].getnumber() == opplayer)
					player = i;
			}
			play[player].outputPlayerAllShow();
		}
		if (op == 4)
		{
			cout << "球員有" << play[0].getnumber() << "、" << play[1].getnumber() << "、" << play[2].getnumber() << "、" << play[3].getnumber() << "、" << play[4].getnumber() << endl;
			cout << "選擇一位球員(背號)：";
			cin >> opplayer;
			for (int i = 0; i < 5; i++)
			{
				if (play[i].getnumber() == opplayer)
					player = i;
			}
			play[player].outputPlayerAverageShow();
		}

		cout << "選擇功能：1)輸入球員單場表現 2)顯示球員單場表現 3)顯示季賽所有場次表現 4)顯示球員季賽平均表現 -1)exit：";
		cin >> op;
	}

	system("pause");
	return 0;
}