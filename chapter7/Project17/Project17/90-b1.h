/*1553449 3班 王志业*/
#pragma once
#include<iomanip>
#include <conio.h>  
#include <windows.h>
#include <stdlib.h>	
#include <time.h>	
#include <iostream>  
#include "cmd_console_tools.h"
#include <fstream>

using namespace std;
struct ball
{

	int cor;//颜色
	int dis;//是否可消除
	int cha;//是否可互换
};
void int_xy(int *row, int *line);

//初始生成，内部数组
void set_ball(ball inside_array[][9], int row, int line);

//寻找数组中某一位置相邻行列中三个及以上颜色相同的,并统计可消除个数,返回消除球的个数。
int find_dis(ball inside_array[][9], int tar_x, int tar_y, int row, int line);

//输出内部数组至屏幕
void array_out(ball inside_array[][9], int row, int line);

void draw0(ball inside_array[][9], int row, int line);

//指定位置若连成三个及以上将内部数组对应位置置0
void disappear(ball inside_array[][9], int row, int line);

//碰到位置为0则将上面的数组值（不为0）赋值到下面，若上面为0则再往上找,并挪下出现动画
void up_down(ball inside_array[][9], int tar_x, int tar_y, int lowest);

//同上，但无动画
void up_down1(ball inside_array[][9], int tar_x, int tar_y, int lowest);

//从最后一行往前数，若有位置为0，则停下进行up_down判断
void array_iszero(ball inside_array[][9], int row, int line);

//在指定位置重新生成小球
void reload(ball inside_array[][9], int tar_x, int tar_y, int row, int line);

//将一个数组的dis值重置为0
void reset_dis(ball inside_array[][9], int row, int line);

//将一个数组的cha值重置为0
void reset_cha(ball inside_array[][9], int row, int line);

//找出某一位置所有可以互换的彩球
void find_cha(ball inside_array[][9], int tar_x, int tar_y, int row, int line);

//画出界面，无分割线
void draw2(ball inside_array[][9], int row, int line);

//画出界面有分割线
void draw3(ball inside_array[][9], int row, int line);

//可消除小球标明
void draw4(ball inside_array[][9], int row, int line);

//消除并附加动画
void dis_act(ball inside_array[][9], int row, int line);

//落下并填补附加动画
void down_reload(ball inside_array[][9], int row, int line);

//标出可移动的球,若不可移动则变回普通形状
void mark_ball(ball inside_array[][9], int row, int line);

//交换两球的位置并出现动画
void ball_change(ball inside_array[][9], int x, int y, int ex, int ey);

//读取鼠标位置及鼠标指令
int mouse_input(const HANDLE hout, ball inside_array[][9], int*pY, int*pX, int*pEY, int*pEX, int row, int line);


//记录消除的分数（初始消除不得分）
void count_score(const HANDLE hout, ball inside_array[][9], int row, int line, int *pscore);

void menu();

void q1(HANDLE hout, ball inside_array[][9], int *row, int *line);

void q2(HANDLE hout, ball inside_array[][9], int *row, int *line);

void q3(HANDLE hout, ball inside_array[][9], int *row, int *line);

void q4(HANDLE hout, ball inside_array[][9], int *row, int *line);
void q5(HANDLE hout, ball inside_array[][9], int *row, int *line);

void q6(HANDLE hout, ball inside_array[][9], int *row, int *line);

void q7(HANDLE hout, ball inside_array[][9], int *row, int *line);

void q8(HANDLE hout, ball inside_array[][9], int *row, int *line);

void q9(HANDLE hout, ball inside_array[][9]);
