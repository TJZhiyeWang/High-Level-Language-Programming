/*1553449 王志业 3班*/
#pragma once
#include <iostream>
#include <cstdio>
#include <ctime>
#include <Windows.h>
#include <conio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include "mmsystem.h"//导入声音头文件 
#pragma comment(lib,"winmm.lib")//导入声音头文件库 
#define pi 3.14
using namespace std;
struct alarm
{
	int hour = 0;
	int min = 0;
	alarm *next;
	char type;
};
void face();
void delete_second_hand(tm tt);
void second_hand(tm tt);
void minute_hand(tm tt);
void delete_minute_hand(tm tt);
void hour_hand(tm tt);
void delete_hour_hand(tm tt);
void hand_clock();
void show_digit_shine();
void alarm_menu();
void save_file(alarm *head);
alarm *read_file();
void digit_clock();
void is_time(tm tt);
void show_digit_0();
void show_digit_1();
void show_digit_2();
void show_digit_3();
void show_digit_4();
void show_digit_5();
void show_digit_6();
void show_digit_7();
void show_digit_8();
void show_digit_9();
void show_num(int num, int x, int y);
void show_digit_void();
void show_void(int x, int y);
void show_y_m_d(tm tt, int x, int y);
void show_digit_sys(int x, int y);
void alarm_clock();