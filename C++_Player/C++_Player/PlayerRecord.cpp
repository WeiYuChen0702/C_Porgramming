#include "Player.h"

void enterPlayerData(string& name, int& number)
{
	cout << "��J�y���m�W(���L��-1)�G";
	cin >> name;
	cout << "��J�y���I��(���L��-1)�G";
	cin >> number;
}//��J�y���򥻸��

int main()
{
	string name;
	int op = 0, number = 0, game = 0, opplayer = 0, player;
	Player play[5];
	cout << "��J�y���򥻸�ơG" << endl;
	for (int i = 0; i < 5; i++)
	{
		enterPlayerData(name, number);
		if (name != "-1")
			play[i].setname(name);
		if (number != -1)
			play[i].setnumber(number);
	}
	cout << "��ܥ\��G1)��J�y���򥻸�� 2)��J�y�������{ 3)��ܲy�������{ 4)��ܩu�ɩҦ�������{ 5)��ܲy���u�ɥ�����{  -1)exit�G";
	cin >> op;
	while (op != -1)
	{
		if (op == 1)
		{
			cout << "�y����" << play[0].getnumber() << "�B" << play[1].getnumber() << "�B" << play[2].getnumber() << "�B" << play[3].getnumber() << "�B" << play[4].getnumber() << endl;
			cout << "��ܤ@��y��(�I��)�G";
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
			cout << "�y����" << play[0].getnumber() << "�B" << play[1].getnumber() << "�B" << play[2].getnumber() << "�B" << play[3].getnumber() << "�B" << play[4].getnumber() << endl;
			cout << "��ܤ@��y��(�I��)�G";
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
			cout << "�y����" << play[0].getnumber() << "�B" << play[1].getnumber() << "�B" << play[2].getnumber() << "�B" << play[3].getnumber() << "�B" << play[4].getnumber() << endl;
			cout << "��ܤ@��y��(�I��)�G";
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
			cout << "�y����" << play[0].getnumber() << "�B" << play[1].getnumber() << "�B" << play[2].getnumber() << "�B" << play[3].getnumber() << "�B" << play[4].getnumber() << endl;
			cout << "��ܤ@��y��(�I��)�G";
			cin >> opplayer;
			for (int i = 0; i < 5; i++)
			{
				if (play[i].getnumber() == opplayer)
					player = i;
			}
			play[player].outputPlayerAverageShow();
		}

		cout << "��ܥ\��G1)��J�y�������{ 2)��ܲy�������{ 3)��ܩu�ɩҦ�������{ 4)��ܲy���u�ɥ�����{ -1)exit�G";
		cin >> op;
	}

	system("pause");
	return 0;
}