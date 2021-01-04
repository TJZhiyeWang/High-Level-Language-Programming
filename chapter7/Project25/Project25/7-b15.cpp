/*1553449 3班 王志业*/
#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;
struct character
{
	int set;
	int big;
}character[26] = { {0,16},{16,2},{18,2}, {20,2}, {22,2}, {24,4}, {28,4},{ 32,4}, {36,8}, {44,1},{45,1},{46,1},{47,1},{48,2},{ 50,2},{ 52,1},{ 53,1},{ 54,1},{ 55,1},{ 56,2},{ 58,1},{ 59,1},{ 60,1},{ 61, 1},{62,1},{ 63,1} };
void menu()
{
	cout << "请选择要修改的项目：\n0.玩家的昵称\n1.生命值\n2.力量值\n3.体质\n4.灵巧"
		<< "\n5.金钱数量\n6.名声值\n7.魅力值\n8.预留值\n9.移动速度\n10.攻击速度"
		<< "\n11.攻击范围\n12.预留值\n13.攻击力\n14.防御力\n15.敏捷度"
		<< "\n16.智力\n17.经验\n18.等级\n19.魔法值\n20.使用魔法时每次的消耗\n21.魔法伤害力"
		<< "\n22.命中率\n23.魔法防御力\n24.暴击率\n25.耐力";
		
}
int main()
{
	int choice;
	fstream fout;
	menu();
	fout.open("game.dat",ios::in|ios::out|ios::binary);
	if (fout.is_open() == 0)
	{
		cout << "can't open";
		return -1;
	}
	cout << "请输入要修改的选项" << endl;
	cin >> choice;
	fout.seekp(character[choice].set, ios::beg);
	if (choice == 0)
	{
		char *ch = new(nothrow) char[character[choice].big + 1];
		if (ch == NULL)
			return -1;
		cin >> ch;
		fout.write(ch, character[choice].big);
		delete ch;
	}
	if (character[choice].big == 1)
	{
		char *pch = new(nothrow) char;
		if (pch == NULL)
			return -1;
		cin >> pch;
		
		fout.write(pch, character[choice].big);
		delete pch;
	}
	if (character[choice].big == 2)
	{
		cout << "fa ";
		short ch;
		cin >> ch;
		fout.write((char *)ch,sizeof(ch));
	}
	if (character[choice].big == 4)
	{
		int ch1;
		cin >> ch1;
		fout.write((char *)ch1,sizeof(ch1));
	}
		fout.close();
		return 0;
}