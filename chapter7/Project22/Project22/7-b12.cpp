/*1553449 3班 王志业*/
#include <iostream>
#include <iomanip>
#include <conio.h>
using namespace std;
const struct KFC
{
	char mark;
	char *name;
	float price;
}list[] = {
	{ 'A', "香辣鸡腿堡",         17.0 },
	{ 'B', "劲脆鸡腿堡",         17.0 },
	{ 'C', "新奥尔良烤鸡腿堡",   17.0 },
	{ 'D', "牛油果香辣鸡腿堡",   18.0 },
	{ 'E', "藤椒肯大大鸡排",     11.0 },
	{ 'F', "老北京鸡肉卷",       15.0 },
	{ 'G', "吮指原味鸡(一块)",   10.5 },
	{ 'H', "吮指原味鸡(二块)",   20.0 },
	{ 'I', "新奥尔良烤翅",       10.5 },
	{ 'J', "劲爆鸡米花",         10.5 },
	{ 'K', "香辣鸡翅",           9.5 },
	{ 'L', "黄金鸡块(五块)",     9.0 },
	{ 'M', "鲜蔬色拉",           12.0 },
	{ 'N', "薯条(小)",           8.5 },
	{ 'O', "薯条(中)",           10.0 },
	{ 'P', "薯条(大)",           12.0 },
	{ 'Q', "芙蓉蔬荟汤",         7.5 },
	{ 'R', "骨肉相连",           7.0 },
	{ 'S', "醇香土豆泥",         6.0 },
	{ 'T', "香甜粟米棒",         7.0 },
	{ 'U', "脆皮甜筒",           7.5 },
	{ 'V', "百事可乐(小)",       6.5 },
	{ 'W', "百事可乐(中)",       8.0 },
	{ 'X', "百事可乐(大)",       9.5 },
	{ 'Y', "九珍果汁饮料",       10.5 },
	{ 'Z', "纯纯玉米饮",         9.5 },
	{ '\0', NULL,                0 }
};

const struct SPECIAL
{
	char *sp_mark;
	char *sp_name;
	float sp_price;
}special[] = {
	{ "ANV", "香辣汉堡工作日午餐",    20 },
	{ "GGGGGJJJSTWWW", "超值全家桶",  82 },
	{ "ZZ", "玉米饮第2件半价",        14.5 },
	{ "UUU","脆皮甜筒买2送1",         15 },
	{ NULL, NULL, 0 }
};
struct food
{
	char m;
	int num = 0;
	food *next;
};
void menu(int *count)
{
	int i = 0;
	food *head = NULL, *p = NULL, *q = NULL;
	while (list[i].name != NULL)
	{
		cout << setw(2) << list[i].mark << " " << setw(20) << list[i].name << setw(10) << list[i].price;
		i++;
		(*count)++;
		if (list[i].name == NULL)
			break;
		cout << setw(5) << "|";
		cout << setw(2) << list[i].mark << " " << setw(20) << list[i].name << setw(10) << list[i].price << endl;
		i++;
		(*count)++;
	}
	cout << "【" << "优惠信息" << "】" << "：" << endl;
	i = 0;
	while (special[i].sp_name != NULL)
	{
		int len, j, n, flag;
		len = strlen(special[i].sp_mark);
		p = new(nothrow) food;
		head = p;
		p->m = special[i].sp_mark[0];
		for (j = 0; j < len; j++)
		{
			flag = 0;

			for (n = 0; n < j; n++)
			{
				if (special[i].sp_mark[j] == special[i].sp_mark[n])
					flag = 1;
			}
			if (flag == 0)
			{
				q = p;
				p = new(nothrow) food;
				p->m = special[i].sp_mark[j];
				q->next = p;
			}
		}
		p->next = NULL;
		p = head;
		cout << special[i].sp_name << "=";
		while (p != NULL)
		{
			for (j = 0; j < len; j++)
			{
				if (special[i].sp_mark[j] == p->m)
					p->num++;
			}
			for (j = 0; j < *count; j++)
			{
				if ((p->m) == list[j].mark)
					cout << list[j].name << "*" << p->num;
			}
			if (p->next != NULL)
				cout << "+";
			p = p->next;
		}
		cout << "=" << special[i].sp_price << endl;

		i++;
		p = head;
		while (p != NULL)
		{
			q = p->next;
			delete p;
			p = q;
		}
	}
}
int main()
{
	while (1)
	{
		system("cls");
		int len, j, n, flag, count = 0;
		menu(&count);
		float price = 0;

		cout << endl << "请点单";
		char check[999];

		cin >> check;
		if (strcmp(check,"0")==0)
			break;
		len = strlen(check);
		food *p = NULL, *q = NULL, *head = NULL;
		for (j = 0; j < len; j++)
		{
			if (check[j] <= 'z'&&check[j] >= 'a')
				check[j] = check[j] - 'a' + 'A';
		}

		p = new(nothrow) food;
		head = p;
		p->m = check[0];
		for (j = 0; j < len; j++)
		{
			flag = 0;

			for (n = 0; n < j; n++)
			{
				if (check[j] == check[n])
					flag = 1;
			}
			if (flag == 0)
			{
				q = p;
				p = new(nothrow) food;
				p->m = check[j];
				q->next = p;
			}
		}
		p->next = NULL;
		p = head;
		cout << "您的点单" << "=";
		while (p != NULL)
		{
			for (j = 0; j < len; j++)
			{
				if (check[j] == p->m)
					p->num++;
			}
			for (j = 0; j < count; j++)
			{
				if ((p->m) == list[j].mark)
				{
					cout << list[j].name << "*" << p->num;
					price = price + p->num*list[j].price;
				}
			}
			if (p->next != NULL)
				cout << "+";
			p = p->next;
		}
		cout << endl << "共计：" << price;


		p = head;
		while (p != NULL)
		{
			q = p->next;
			delete p;
			p = q;
		}
		cout << "按任意键继续，按0键退出";
		getchar();
	}
	return 0;
}