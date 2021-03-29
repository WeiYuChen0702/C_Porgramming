#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int enter(class scene sce[], int count);
int search(class scene sce[], int count);
void displayall(class scene sce[], int count);
void displaytown(class scene sce[], int count);
void displaytype(class scene sce[], int count);
void twodis(class scene sce[], int& count, int& x, int& index);
void nearby(class scene sce[], int& count, int& x, int& index);

class scene
{
private:
	string name;
	int loc, type;
	float updown, rightleft;

public:
	void setname(string n);
	void setloc(int l);
	void settype(int t);
	void setupdown(float ud);
	void setrightleft(float rl);

	string getname();
	int getloc();
	int gettype();
	float getupdown();
	float getrightleft();
	float dis(float x2, float y2)
	{
		return sqrt(((updown - x2) * (updown - x2)) + ((rightleft - y2) * (rightleft - y2)));
	}
};


void scene::setname(string n)
{
	name = n;
}

void scene::setloc(int l)
{
	while (l > 13 || l < 1)
	{
		cout << "�Э��s��J�m��: 1)�Ὤ�� 2)��L�� 3)�ɨ��� 4)�s���m 5)�N�w�m 6)���׶m 7)���_�m 8)���ضm 9)���J�m 10)�I���m 11)�q�L�m 12)�U�a�m 13)���˶m:";
		cin >> l;
	}

	loc = l;
}

void scene::settype(int t)
{
	while (t > 4 || t < 1)
	{
		cout << "�Э��s��J����: 1)���� 2)���� 3)���� 4)����:";
		cin >> t;
	}

	type = t;
}

void scene::setupdown(float ud)
{
	while (ud > 90 || ud < -90)
	{
		cout << "�Э��s��J�n��:";
		cin >> ud;
	}

	updown = ud;
}

void scene::setrightleft(float rl)
{
	while (rl > 180 || rl < -180)
	{
		cout << "�Э��s��J�g��:";
		cin >> rl;
	}

	rightleft = rl;
}

string scene::getname()
{
	return name;
}

int scene::getloc()
{
	return loc;
}

int scene::gettype()
{
	return type;
}

float scene::getupdown()
{
	return updown;
}

float scene::getrightleft()
{
	return rightleft;
}




int main()
{
	scene sce[100];
	char* str1[] = { (char*)"�Ὤ��",(char*)"��L��",(char*)"�ɨ���",(char*)"�s���m",(char*)"�N�w�m",(char*)"���׶m",(char*)"���_�m",(char*)"���ضm",(char*)"���J�m",(char*)"�I���m",(char*)"�q�L�m",(char*)"�U�a�m",
		(char*)"���˶m" };
	char* str2[] = { (char*)"����",(char*)"����",(char*)"����",(char*)"����" };
	int m = 0, count = 0, index, x;
	float d[100] = { -1.0 };
	while (1)
	{
		int cho = 0;
		cout << "��ܥ\�� 1)�s�W 2)�L�X 3)����@�Ӵ��I 4)�p��ⴺ�I�Z�� -1)����:";
		cin >> cho;

		if (cho == 1)
		{
			m = enter(sce, count);

			if (m == 0)
				count++;
			else
				cout << "�s�W����" << endl;

			displayall(sce, count);
		}

		else if (cho == 2)
		{
			int ans = 0;
			cout << "��ܦL�X�̾� 1)���� 2)�m�� 3)����:";
			cin >> ans;

			if (ans == 1)
				displayall(sce, count);

			else if (ans == 2)
				displaytown(sce, count);

			else if (ans == 3)
				displaytype(sce, count);
		}

		else if (cho == 3)
		{
			nearby(sce, count, x, index);
			cout << sce[index].getname() << "\t" << str1[sce[index].getloc() - 1] << "\t" << str2[sce[index].gettype() - 1] << "\t" << sce[index].getrightleft() << "\t" << sce[index].getupdown() << "\t" << endl;
		}

		else if (cho == 4)
		{
			twodis(sce, count, x, index);
		}

		else if (cho == -1)
			break;
		else
			continue;

	}
}

int enter(class scene sce[], int count)
{
	string n;
	int l, t;
	float ud, rl;

	cout << "��J�s���I�W��:";
	cin >> n;
	sce[count].setname(n);

	cout << "��ܶm�� 1)�Ὤ�� 2)��L�� 3)�ɨ��� 4)�s���m 5)�N�w�m 6)���׶m 7)���_�m 8)���ضm 9)���J�m 10)�I���m 11)�q�L�m 12)�U�a�m 13)���˶m:";
	cin >> l;
	sce[count].setloc(l);

	cout << "������� 1)���� 2)���� 3)���� 4)����:";
	cin >> t;
	sce[count].settype(t);

	cout << "��J�g��:";
	cin >> rl;
	sce[count].setrightleft(rl);

	cout << "��J�n��:";
	cin >> ud;
	sce[count].setupdown(ud);

	int m = 0;
	m = search(sce, count);

	if (m == 1)
		return 1;
	else
		return 0;

}

int search(class scene sce[], int count)
{
	int i = 0;

	for (i = 0; i < count; i++)
		if (sce[count].getname() == sce[i].getname())
			return 1;

	return 0;
}

void displayall(class scene sce[], int count)
{
	char* str1[] = { (char*)"�Ὤ��",(char*)"��L��",(char*)"�ɨ���",(char*)"�s���m",(char*)"�N�w�m",(char*)"���׶m",(char*)"���_�m",(char*)"���ضm",(char*)"���J�m",(char*)"�I���m",(char*)"�q�L�m",
		(char*)"�U�a�m",(char*)"���˶m" };
	char* str2[] = { (char*)"����",(char*)"����",(char*)"����",(char*)"����" };

	cout << "�W��\t�m��\t����\t�g��\t�n��" << endl;
	for (int i = 0; i < count; i++)
		cout << sce[i].getname() << "\t" << str1[sce[i].getloc() - 1] << "\t" << str2[sce[i].gettype() - 1] << "\t" << sce[i].getrightleft() << "\t" << sce[i].getupdown() << "\t" << endl;

}

void displaytown(class scene sce[], int count)
{
	char* str1[] = { (char*)"�Ὤ��",(char*)"��L��",(char*)"�ɨ���",(char*)"�s���m",(char*)"�N�w�m",(char*)"���׶m",(char*)"���_�m",(char*)"���ضm",(char*)"���J�m",(char*)"�I���m",(char*)"�q�L�m",
		(char*)"�U�a�m",(char*)"���˶m" };
	char* str2[] = { (char*)"����",(char*)"����",(char*)"����",(char*)"����" };
	int temp = 0;

	cout << "��ܶm�� 1)�Ὤ�� 2)��L�� 3)�ɨ��� 4)�s���m 5)�N�w�m 6)���׶m 7)���_�m 8)���ضm 9)���J�m 10)�I���m 11)�q�L�m 12)�U�a�m 13)���˶m";
	cin >> temp;

	cout << "�W��\t�m��\t����\t�g��\t�n��" << endl;
	for (int i = 0; i < count; i++)
		if (sce[i].getloc() == temp)
			cout << sce[i].getname() << "\t" << str1[sce[i].getloc() - 1] << "\t" << str2[sce[i].gettype() - 1] << "\t" << sce[i].getrightleft() << "\t" << sce[i].getupdown() << "\t" << endl;
}

void displaytype(class scene sce[], int count)
{
	char* str1[] = { (char*)"�Ὤ��",(char*)"��L��",(char*)"�ɨ���",(char*)"�s���m",(char*)"�N�w�m",(char*)"���׶m",(char*)"���_�m",(char*)"���ضm",(char*)"���J�m",(char*)"�I���m",(char*)"�q�L�m",
		(char*)"�U�a�m",(char*)"���˶m" };
	char* str2[] = { (char*)"����",(char*)"����",(char*)"����",(char*)"����" };
	int temp = 0;

	cout << "��ܶm�� ������� 1)���� 2)���� 3)���� 4)����";
	cin >> temp;

	cout << "�W��\t�m��\t����\t�g��\t�n��" << endl;
	for (int i = 0; i < count; i++)
		if (sce[i].gettype() == temp)
			cout << sce[i].getname() << "\t" << str1[sce[i].getloc() - 1] << "\t" << str2[sce[i].gettype() - 1] << "\t" << sce[i].getrightleft() << "\t" << sce[i].getupdown() << "\t" << endl;
}

void nearby(class scene sce[], int& count, int& x, int& index)
{
	class scene b;
	int ans, y, a = 0;
	int min = 10000;
	char hold[100];
	do
	{
		cout << "�п�J�@�Ӵ��I�W��:";
		cin >> hold;
		for (int i = 0; i < count; i++)
		{
			if (sce[i].getname() == hold)//�P�_
			{
				a = 1;
				for (int j = 0; j < count; j++)
				{
					if (j != i)
					{
						ans = sce[i].dis(sce[j].getrightleft(), sce[j].getupdown());
						if (min > ans)
						{
							min = ans;
							y = j;
						}
					}
				}
			}
		}
	} while (a == 0);


	x = min;
	index = y;
}

void twodis(class scene sce[], int& count, int& x, int& index)
{
	int y, a = 0;
	int min = 10000;
	double ans;
	class scene b;
	char hold[100], temp[100];

	cout << "�п�J�Ĥ@�Ӵ��I�W��:";
	cin >> hold;
	for (int i = 0; i < count; i++)
	{
		if (sce[i].getname() == hold)//�P�_
		{
			a = 1;
			cout << "�п�J�ĤG�Ӵ��I�W��:";
			cin >> temp;
			for (int j = 0; j < count; j++)
			{
				if (sce[j].getname() == temp)
				{
					ans = sce[i].dis(sce[j].getrightleft(), sce[j].getupdown());
					cout << "�Z����:" << ans << endl;
				}
			}
		}
	}
}