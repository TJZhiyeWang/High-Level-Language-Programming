/*1553449 3班 王志业*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE 
#define MAX_RESULT 256
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "cmd_console_tools.h"
#include <iostream>
#include <fstream>
#include <direct.h>
#include <conio.h>
using namespace std;
struct sdk
{
	int num;
	sdk *rnext = NULL;
	sdk *lnext = NULL;
	char p = '0';//判断是更改过的数字还是初始的数字,1代表不可更改
	int try_num = 1;//穷举算法中的尝试数字
	int x;
	int y;
};
int conflict(sdk sdkarray[][9]);
void turn_red(sdk sdkarray[][9], int i, int j);
void turn_white(sdk sdkarray[][9], int i, int j);
void read_file(sdk sdkarray[][9], char *s);
int conflict1(sdk sdkarray[][9], int tar_x, int tar_y);
char** EnumFiles(int *count);
void draw(sdk sdkarray[][9]);
void plot(sdk sdkarray[][9], char *s, int *row, int *line, int *num);
void chain(sdk sdkarray[][9], int row, int line, sdk **p, sdk **q, sdk **head);
void back(sdk **p, sdk **q);
char* display(char **result, const int count);
void draw1(sdk sdkarray[][9]);
void mark(sdk sdkarray[][9], int i, int j);
void mark_back(sdk sdkarray[][9], int i, int j);
void find(sdk sdkarray[][9], sdk **p, sdk **q, sdk **head);
void keyboard(sdk sdkarray[][9], sdk **p, sdk **q, sdk **head);
void menu();

void q1(char *filename);
void q2();

void q3();

void q4();