#include <iostream>
#include <string>
#include <ctime>
using namespace std;
class PM//�ŧiclass
{
private:
	string name;
	int lv;
	int life;
	int atk;
	int def;
	int blood;
	int heal;
public:
	string getname()//�H�U�X����X��
	{
		return name;
	}

	int getlv()
	{
		return lv;
	}

	int getlife()
	{
		return life;
	}

	int getatk()
	{
		return atk;
	}

	int getdef()
	{
		return def;
	}

	int getblood()
	{
		return blood;
	}

	int getheal()
	{
		return heal;
	}

	void setname(string temp)//�H�U�X�浹��
	{
		name = temp;
	}

	void setlv(int temp)
	{
		lv = temp;
	}

	void setlife(int temp)
	{
		life = temp;
	}

	void setatk(int temp)
	{
		atk = temp;
	}

	void setdef(int temp)
	{
		def = temp;
	}

	void setblood(int temp)
	{
		blood = temp;
	}

	void setheal(int temp)
	{
		heal = temp;
	}

	void atkboost()
	{
		atk = atk + 3;
		if (atk > 99)
			atk = 99;
	}

	void defboost()
	{
		def = def + 3;
		if (def > 99)
			def = 99;
	}

	int heath(class PM& E)
	{
		int temp;
		if (heal == 3)
		{
			cout << "�Χ��F" << endl;
			temp = attack(E);
			return temp;
		}
		life = life + 200;
		if (life > blood)
			life = blood;
		heal++;
		return 0;
	}

	int attack(class PM& E)//����!
	{
		int damage;
		damage = rand() % atk;
		E.setlife(E.getlife() - damage);
		if (E.getlife() <= 0)
			return 1;
		else
			return 0;
	}

};

int main(void)
{
	srand(time(NULL));
	string hold;
	int temp;
	PM a[2];
	for (int i = 0; i < 2; i++)
	{
		cout << "�_�i�ڪ��W�r:";
		cin >> hold;
		a[i].setname(hold);
		cout << "LV(1~3):";
		while (1)
		{
			cin >> temp;
			if (temp <= 3 && temp >= 1)
				break;
			else
				cout << "���s��J:";
		}
		a[i].setlv(temp);
		cout << "��q:(0~500):";
		while (1)
		{
			cin >> temp;
			if (temp <= 500 && temp >= 0)
				break;
			else
				cout << "���s��J:";
		}
		a[i].setblood(temp);
		cout << "�����O:(0~99)";
		while (1)
		{
			cin >> temp;
			if (temp <= 99 && temp >= 0)
				break;
			else
				cout << "���s��J:";
		}
		a[i].setatk(temp);
		cout << "���m�O(0~99):";
		while (1)
		{
			cin >> temp;
			if (temp <= 99 && temp >= 0)
				break;
			else
				cout << "���s��J:";
		}
		a[i].setdef(temp);
		a[i].setlife(a[i].getblood());
		a[i].setheal(0);
	}

	while (1)
	{
		cout << "��1���_�i��:" << a[0].getname() << "\t����:" << a[0].getlv() << "\t�ɦ妸��:" << a[0].getheal() << "\t�ͩR��:" << a[0].getlife() << "\t�����O:" << a[0].getatk() << "\t���m�O:" << a[0].getdef() << endl;
		cout << "��2���_�i��:" << a[1].getname() << "\t����:" << a[1].getlv() << "\t�ɦ妸��:" << a[1].getheal() << "\t�ͩR��:" << a[1].getlife() << "\t�����O:" << a[1].getatk() << "\t���m�O:" << a[1].getdef() << endl;
		cout << "��1���_�i��:" << a[0].getname() << "(1)���� (2)�^�� (3)�j�Ƨ��� (4)�W�j���u:";
		cin >> temp;
		if (temp == 1)
			temp = a[0].attack(a[1]);
		if (temp == 2)
			temp = a[0].heath(a[1]);
		if (temp == 3)
			a[0].atkboost();
		if (temp == 4)
			a[0].defboost();
		if (temp == 1)
		{
			cout << a[0].getname() << "�ӧQ" << endl;
			cout << "�O�_��L(1�O2�_):";
			cin >> temp;
			if (temp == 2)
				break;
			if (temp == 1)
			{
				a[0].setlife(a[0].getblood());
				a[1].setlife(a[1].getblood());
			}
		}
		cout << "��1���_�i��:" << a[0].getname() << "\t����:" << a[0].getlv() << "\t�ɦ妸��:" << a[0].getheal() << "\t�ͩR��:" << a[0].getlife() << "\t�����O:" << a[0].getatk() << "\t���m�O:" << a[0].getdef() << endl;
		cout << "��2���_�i��:" << a[1].getname() << "\t����:" << a[1].getlv() << "\t�ɦ妸��:" << a[1].getheal() << "\t�ͩR��:" << a[1].getlife() << "\t�����O:" << a[1].getatk() << "\t���m�O:" << a[1].getdef() << endl;
		cout << "��2���_�i��:" << a[1].getname() << "(1)���� (2)�^�� (3)�j�Ƨ��� (4)�W�j���u:";
		cin >> temp;
		if (temp == 1)
			temp = a[1].attack(a[0]);
		if (temp == 2)
			temp = a[1].heath(a[0]);
		if (temp == 3)
			a[1].atkboost();
		if (temp == 4)
			a[1].defboost();
		if (temp == 1)
		{
			cout << a[1].getname() << "�ӧQ";
			cout << "�O�_��L(1�O2�_):";
			cin >> temp;
			if (temp == 2)
				break;
			if (temp == 1)
			{
				a[0].setlife(a[0].getblood());
				a[1].setlife(a[1].getblood());
			}
		}
	}
	return 0;
}