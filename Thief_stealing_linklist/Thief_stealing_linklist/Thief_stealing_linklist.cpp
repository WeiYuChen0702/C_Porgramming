#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

struct node
{
	char name[80];
	int value;
	float weight;
	struct node* next;
	node();
	float cpvalue();
};

float node::cpvalue()
{
	return value / weight;
}

node::node()
{
	name[0] = '\0';
	value = 0;
	weight = 0.0;
}


class Queue
{
protected:
	struct node* frontptr, * backptr;
	int count;
public:
	Queue()
	{
		frontptr = backptr = NULL;
		count = 0;
	}
	void insert();
	void insert1(char* name, int value, float weight);
	void show();
	void del();
	node* front()
	{
		return frontptr;
	}
};
void Queue::insert1(char* name, int value, float weight)
{
	struct node* ptr;

	ptr = new node;
	strcpy(ptr->name, name);
	ptr->value = value;
	ptr->weight = weight;
	ptr->next = NULL;
	if (frontptr == NULL)
		frontptr = ptr;
	else
		backptr->next = ptr;
	backptr = ptr;
}

void Queue::del()
{
	if (frontptr == NULL)
	{
		cout << "空了" << endl;
		return;
	}
	struct node* temp;
	temp = frontptr;
	frontptr = frontptr->next;
	delete temp;
}

void Queue::insert()
{
	char name[80];
	int value;
	float weight;

	cout << "輸入物品名稱：";
	cin >> name;
	cout << "輸入物品價值：";
	cin >> value;
	cout << "輸入物品重量：";
	cin >> weight;
	insert1(name, value, weight);
}
void Queue::show()
{
	struct node* ptr1 = frontptr;
	if (frontptr == NULL)
	{
		cout << "空的!!";
		return;
	}
	while (ptr1 != NULL)
	{
		cout << ptr1->name << " ";
		ptr1 = ptr1->next;
	}
	cout << endl;
}

class priority : public Queue
{
	float totalWeight;
public:
	priority()
	{
		totalWeight = 0.0;
	}
	void insert1(char* name, int value, float weight);
	void sortcp(char* name, int value, float weight);
	float getTotalWeight()
	{
		return totalWeight;
	}

	int getTotalValue();
	void del();
};

void priority::insert1(char* name, int value, float weight)
{
	Queue::insert1(name, value, weight);
	totalWeight += weight;
}

void priority::del()
{
	totalWeight -= frontptr->weight;
	Queue::del();
}

void priority::sortcp(char* name, int value, float weight)
{
	if (frontptr == NULL)
	{
		insert1(name, value, weight);
		return;
	}

	float cp = value / weight;
	node* tempptr = frontptr;
	node* previousptr = NULL;
	while (tempptr != NULL && tempptr->cpvalue() <= cp)
	{
		previousptr = tempptr;
		tempptr = tempptr->next;
	}
	struct node* ptr;
	ptr = new node;
	strcpy(ptr->name, name);
	ptr->value = value;
	ptr->weight = weight;

	if (previousptr == NULL)
	{
		frontptr = ptr;
		ptr->next = tempptr;
	}
	else if (tempptr == NULL)
	{
		previousptr->next = ptr;
		ptr->next = NULL;
		backptr = ptr;
	}
	else
	{
		previousptr->next = ptr;
		ptr->next = tempptr;
	}
	totalWeight += weight;
}

int priority::getTotalValue()
{
	struct node* ptr = frontptr;
	int v = 0;
	if (frontptr == NULL)
	{
		return 0;
	}

	while (ptr != NULL)
	{
		v += ptr->value;
		ptr = ptr->next;
	}
	return v;
}

int main()
{
	Queue gallery;
	priority bag;
	int choice;

	while (1)
	{
		cout << "1:新增 2:印出  3:開始行動:";
		cin >> choice;
		if (choice == 1)
			gallery.insert();
		else if (choice == 2)
			gallery.show();
		else if (choice == 3)
			break;
		else
			continue;
	}

	node* ptr;
	ptr = gallery.front();
	while (ptr != NULL)
	{
		if (ptr->weight + bag.getTotalWeight() <= 20)
		{
			bag.sortcp(ptr->name, ptr->value, ptr->weight);
		}
		else
		{
			node* temp = bag.front();
			float kg = bag.getTotalWeight();
			int find = 0;
			while (temp != NULL && temp->cpvalue() < ptr->cpvalue())
			{
				kg = kg - temp->weight;
				if (kg + ptr->weight <= 20)
				{
					find = 1;
					temp = temp->next;
					break;
				}
				else if (kg + ptr->weight >= 20)
				{
					find = 2;
					temp = temp->next;
					break;
				}
				temp = temp->next;
			}
			if (find == 1)
			{
				node* hold = bag.front();
				while (hold != temp)
				{
					hold = hold->next;
					bag.del();
				}
				bag.sortcp(ptr->name, ptr->value, ptr->weight);
			}
			else if (find == 2)
			{
				node* it = bag.front();
				while (it != temp)
				{
					it = it->next;
					bag.del();
				}
			}
		}
		ptr = ptr->next;
	}
	bag.show();
	int total_value = bag.getTotalValue();
	int total_weight = bag.getTotalWeight();
	cout << "總重量：" << total_weight << endl;
	cout << "總價值：" << total_value << endl;
	system("pause");
	return 0;
}