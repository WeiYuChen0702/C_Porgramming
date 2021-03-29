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
		cout << "請重新輸入鄉鎮: 1)花蓮市 2)鳳林鎮 3)玉里鎮 4)新城鄉 5)吉安鄉 6)壽豐鄉 7)光復鄉 8)豐濱鄉 9)瑞穗鄉 10)富里鄉 11)秀林鄉 12)萬榮鄉 13)卓溪鄉:";
		cin >> l;
	}

	loc = l;
}

void scene::settype(int t)
{
	while (t > 4 || t < 1)
	{
		cout << "請重新輸入類型: 1)風景 2)美食 3)體驗 4)探索:";
		cin >> t;
	}

	type = t;
}

void scene::setupdown(float ud)
{
	while (ud > 90 || ud < -90)
	{
		cout << "請重新輸入緯度:";
		cin >> ud;
	}

	updown = ud;
}

void scene::setrightleft(float rl)
{
	while (rl > 180 || rl < -180)
	{
		cout << "請重新輸入經度:";
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
	char* str1[] = { (char*)"花蓮市",(char*)"鳳林鎮",(char*)"玉里鎮",(char*)"新城鄉",(char*)"吉安鄉",(char*)"壽豐鄉",(char*)"光復鄉",(char*)"豐濱鄉",(char*)"瑞穗鄉",(char*)"富里鄉",(char*)"秀林鄉",(char*)"萬榮鄉",
		(char*)"卓溪鄉" };
	char* str2[] = { (char*)"風景",(char*)"美食",(char*)"體驗",(char*)"探索" };
	int m = 0, count = 0, index, x;
	float d[100] = { -1.0 };
	while (1)
	{
		int cho = 0;
		cout << "選擇功能 1)新增 2)印出 3)附近一個景點 4)計算兩景點距離 -1)結束:";
		cin >> cho;

		if (cho == 1)
		{
			m = enter(sce, count);

			if (m == 0)
				count++;
			else
				cout << "新增失敗" << endl;

			displayall(sce, count);
		}

		else if (cho == 2)
		{
			int ans = 0;
			cout << "選擇印出依據 1)全部 2)鄉鎮 3)類型:";
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

	cout << "輸入新景點名稱:";
	cin >> n;
	sce[count].setname(n);

	cout << "選擇鄉鎮 1)花蓮市 2)鳳林鎮 3)玉里鎮 4)新城鄉 5)吉安鄉 6)壽豐鄉 7)光復鄉 8)豐濱鄉 9)瑞穗鄉 10)富里鄉 11)秀林鄉 12)萬榮鄉 13)卓溪鄉:";
	cin >> l;
	sce[count].setloc(l);

	cout << "選擇類型 1)風景 2)美食 3)體驗 4)探索:";
	cin >> t;
	sce[count].settype(t);

	cout << "輸入經度:";
	cin >> rl;
	sce[count].setrightleft(rl);

	cout << "輸入緯度:";
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
	char* str1[] = { (char*)"花蓮市",(char*)"鳳林鎮",(char*)"玉里鎮",(char*)"新城鄉",(char*)"吉安鄉",(char*)"壽豐鄉",(char*)"光復鄉",(char*)"豐濱鄉",(char*)"瑞穗鄉",(char*)"富里鄉",(char*)"秀林鄉",
		(char*)"萬榮鄉",(char*)"卓溪鄉" };
	char* str2[] = { (char*)"風景",(char*)"美食",(char*)"體驗",(char*)"探索" };

	cout << "名稱\t鄉鎮\t類型\t經度\t緯度" << endl;
	for (int i = 0; i < count; i++)
		cout << sce[i].getname() << "\t" << str1[sce[i].getloc() - 1] << "\t" << str2[sce[i].gettype() - 1] << "\t" << sce[i].getrightleft() << "\t" << sce[i].getupdown() << "\t" << endl;

}

void displaytown(class scene sce[], int count)
{
	char* str1[] = { (char*)"花蓮市",(char*)"鳳林鎮",(char*)"玉里鎮",(char*)"新城鄉",(char*)"吉安鄉",(char*)"壽豐鄉",(char*)"光復鄉",(char*)"豐濱鄉",(char*)"瑞穗鄉",(char*)"富里鄉",(char*)"秀林鄉",
		(char*)"萬榮鄉",(char*)"卓溪鄉" };
	char* str2[] = { (char*)"風景",(char*)"美食",(char*)"體驗",(char*)"探索" };
	int temp = 0;

	cout << "選擇鄉鎮 1)花蓮市 2)鳳林鎮 3)玉里鎮 4)新城鄉 5)吉安鄉 6)壽豐鄉 7)光復鄉 8)豐濱鄉 9)瑞穗鄉 10)富里鄉 11)秀林鄉 12)萬榮鄉 13)卓溪鄉";
	cin >> temp;

	cout << "名稱\t鄉鎮\t類型\t經度\t緯度" << endl;
	for (int i = 0; i < count; i++)
		if (sce[i].getloc() == temp)
			cout << sce[i].getname() << "\t" << str1[sce[i].getloc() - 1] << "\t" << str2[sce[i].gettype() - 1] << "\t" << sce[i].getrightleft() << "\t" << sce[i].getupdown() << "\t" << endl;
}

void displaytype(class scene sce[], int count)
{
	char* str1[] = { (char*)"花蓮市",(char*)"鳳林鎮",(char*)"玉里鎮",(char*)"新城鄉",(char*)"吉安鄉",(char*)"壽豐鄉",(char*)"光復鄉",(char*)"豐濱鄉",(char*)"瑞穗鄉",(char*)"富里鄉",(char*)"秀林鄉",
		(char*)"萬榮鄉",(char*)"卓溪鄉" };
	char* str2[] = { (char*)"風景",(char*)"美食",(char*)"體驗",(char*)"探索" };
	int temp = 0;

	cout << "選擇鄉鎮 選擇類型 1)風景 2)美食 3)體驗 4)探索";
	cin >> temp;

	cout << "名稱\t鄉鎮\t類型\t經度\t緯度" << endl;
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
		cout << "請輸入一個景點名稱:";
		cin >> hold;
		for (int i = 0; i < count; i++)
		{
			if (sce[i].getname() == hold)//判斷
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

	cout << "請輸入第一個景點名稱:";
	cin >> hold;
	for (int i = 0; i < count; i++)
	{
		if (sce[i].getname() == hold)//判斷
		{
			a = 1;
			cout << "請輸入第二個景點名稱:";
			cin >> temp;
			for (int j = 0; j < count; j++)
			{
				if (sce[j].getname() == temp)
				{
					ans = sce[i].dis(sce[j].getrightleft(), sce[j].getupdown());
					cout << "距離為:" << ans << endl;
				}
			}
		}
	}
}