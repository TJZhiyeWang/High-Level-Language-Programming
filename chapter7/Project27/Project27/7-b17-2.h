/*Õı÷æ“µ 3∞‡ 1553449*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <io.h>
#include <experimental/filesystem>
using namespace std;
enum ITEM_TYPE
{
	TYPE_INT, TYPE_DOUBLE, TYPE_STRING, TYPE_CHARACTER, TYPE_NULL
};
int group_add(FILE *fp, const char *group_name);
int group_del(FILE *fp, const char *group_name);
int item_add(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM);
int item_del(FILE *fp, const char *group_name, const char *item_name);
int item_update(FILE *fp, const char *group_name, const char *item_name, const void *item_value, const enum ITEM_TYPE item_type);
int item_get_value(FILE *fp, const char *group_name, const char *item_name, void *item_value, const enum ITEM_TYPE item_type);
