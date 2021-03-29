#include "Player.h"

Player::Player(int numberIn, string nameIn)
{
	setnumber(numberIn);//�y���I��
	name = nameIn;//�y���m�W
	for (int i = 0; i < 5; i++)
	{
		twoPoint[i] = 0;//�y������o��(5������)
		threePoint[i] = 0;//�y���T���o��(5������)
		foulPoint[i] = 0;//�y���@�y�o��(5������)
		totalPoint[i] = 0;//�y���`�o��(5������)
		foul[i] = 0;//�y���ǳW(5������)
		play[i] = 0;//�y���X�ɳ��� 1)�X�� 0)�S�X��  (5������)

	}
	seasonMostHigh = 0;//�u�ɳ̰��o��
	seasonAverage = 0;//�u�ɥ����o��
	gamecounter = 0;//���ɳ���
	seasonAverageFoul = 0;//�u�ɥ����ǳW��
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
		cout << "�榡��J���~�I�y�����X���p��0�I" << endl;
		number = 0;
	}
	else
		number = numberIn;
}
void Player::settwoPoint(int twoPointIn, int game)
{
	if (twoPointIn < 0)
		cout << "�榡��J���~�I����y�i�y�Ƥ��p��0�I" << endl;
	else
		twoPoint[game] = twoPointIn;
}
void Player::setthreePoint(int threePointIn, int game)
{
	if (threePointIn < 0)
		cout << "�榡��J���~�I�T���y�i�y�Ƥ��p��0�I" << endl;
	else
		threePoint[game] = threePointIn;
}
void Player::setfoulPoint(int foulPointIn, int game)
{
	if (foulPointIn < 0)
		cout << "�榡��J���~�I�@�y�i�y�Ƥ��p��0�I" << endl;
	else
		foulPoint[game] = foulPointIn;
}
void Player::setfoul(int foulIn, int game)
{
	if (foulIn < 0 || foulIn>5)
		cout << "�榡��J���~�I�ǳW���Ƥ��p��0�I���j��5�I" << endl;
	else
		foul[game] = foulIn;
}
void Player::setseasonMostHigh(int seasonMostHighIn)
{
	if (seasonMostHighIn < 0)
		cout << "�榡��J���~�I�u�ɳ̰��o�����p��0�I" << endl;
	else
		seasonMostHigh = seasonMostHighIn;
}
void Player::setseasonAverage(float seasonAverageIn)
{
	if (seasonAverageIn < 0)
		cout << "�榡��J���~�I�u�ɥ����o�����p��0�I" << endl;
	else
		seasonAverage = seasonAverageIn;
}
void Player::setplay(int playIn, int game)
{
	if (playIn != 0 && playIn != 1)
		cout << "�榡��J���~�I1)�X�� 0)�S�X���I" << endl;
	else
		play[game] = playIn;
}
//�\��
void Player::enterPlayerShow()
{
	int game, two, three, foul, foulball, rebound, steal;
	cout << "��J���ɳ���(1~5��)�G";
	cin >> game;
	cout << "��������  2���o���y�ơG";
	cin >> two;
	cout << "��������  3���o���y�ơG";
	cin >> three;
	cout << "��������  �@�y�o���y�ơG";
	cin >> foul;
	cout << "��������  �ǳW���ơG";
	cin >> foulball;
	settwoPoint(two, game - 1);//�]�w
	setthreePoint(three, game - 1);
	setfoulPoint(foul, game - 1);
	setfoul(foulball, game - 1);


	play[game - 1] = 1;//�����X�ɳ���
	countOnePoint(game - 1);//��������`�o��
	renewseasonMostHigh();//��s����̰��o��
	countAveragePoint();//�p�⥭���o��
	countAverageFoul();//�p�⥭���ǳW��



}//��J�y�����ɪ�{
void Player::outputPlayerOneShow()
{
	int game;
	cout << "��ܲy��" << number << "�����ĴX�����ɡG";
	cin >> game;
	if (play[game - 1] == 1)
	{
		cout << "��" << game << "�����ɡG" << endl;
		cout << "����y�o���G" << right << setw(6) << (twoPoint[game - 1]) * 2 << "��" << endl;
		cout << "�T���y�o���G" << right << setw(6) << (threePoint[game - 1]) * 3 << "��" << endl;
		cout << "�@�y�o���G" << right << setw(8) << foulPoint[game - 1] << "��" << endl;
		cout << "�`�o���G" << right << setw(10) << totalPoint[game - 1] << "��" << endl;
		cout << "�ǳW���ơG" << right << setw(8) << foul[game - 1] << "��" << endl;
	}
	else
		cout << "�S���o�����ɪ����";
}//��ܲy�������{
void Player::outputPlayerAllShow()
{
	for (int i = 0; i < 5; i++)
	{
		if (play[i] == 1)
		{
			cout << "��" << i + 1 << "�����ɡG" << endl;
			cout << "����y�o���G" << right << setw(6) << (twoPoint[i]) * 2 << "��" << endl;
			cout << "�T���y�o���G" << right << setw(6) << (threePoint[i]) * 3 << "��" << endl;
			cout << "�@�y�o���G" << right << setw(8) << foulPoint[i] << "��" << endl;
			cout << "�`�o���G" << right << setw(10) << totalPoint[i] << "��" << endl;
			cout << "�ǳW���ơG" << right << setw(8) << foul[i] << "��" << endl;
		}
	}
}//��ܲy���u�ɩҦ�������{
void Player::outputPlayerAverageShow()
{
	cout << "�u�ɳ̰��o���G" << right << setw(4) << seasonMostHigh << "��" << endl;
	cout << "�u�ɥ����o���G" << right << setw(4) << seasonAverage << "��" << endl;
	cout << "�����ǳW�ơG" << right << setw(6) << seasonAverageFoul << "��" << endl;
}//��ܲy���u�ɥ�����{
void Player::countOnePoint(int game)
{
	totalPoint[game] = 2 * twoPoint[game] + 3 * threePoint[game] + foulPoint[game];
}//�p�����`�o��(private)
void Player::countAveragePoint()
{
	countGameCounter();
	float average = 0;
	for (int i = 0; i < 5; i++)
	{
		average = average + totalPoint[i];
	}
	seasonAverage = average / (float)gamecounter;
}//�p��u�ɥ����o��(private)
void Player::countAverageFoul()
{
	countGameCounter();
	float average = 0;
	for (int i = 0; i < gamecounter; i++)
	{
		average = average + foul[i];
	}
	seasonAverageFoul = average / (float)gamecounter;
}//�p��u�ɥ����ǳW��(private)
void Player::renewseasonMostHigh()//��s�u�ɳ̰��o��
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
}//�p��X����
