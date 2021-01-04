/*3班 王志业 1553449*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <Windows.h>
#define L_1 17//7
#define L_2 32//10
#define L_3 53//15
#define L_4 78//20
#define L_5 106//26

#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define LOVERFLOW	-2

typedef int Status;

using namespace std;

typedef struct {
	int length;
	unsigned char *data;
} BitStream;

typedef struct polynode
{
	unsigned int coef;
	unsigned int expn;
	struct polynode *next;
}polynode, *polynomial;

struct QRarray
{
	int col = 0;//颜色 0白色 1黑色
	int ocu = 0;//是否被使用过
};

static unsigned int AlphaTo[255] = { 1,2,4,8,16,32,64,128,29,58,116,232,205,135,19,38,76,152,45,90,180,117,234,201,143,3,6,12,24,48,96,192,157,39,78,156,37,74,148,53,106,212,181,119,238,193,159,35,70,140,5,10,20,40,80,160,93,186,105,210,185,111,222,161,95,190,97,194,153,47,94,188,101,202,137,15,30,60,120,240,253,231,211,187,107,214,177,127,254,225,223,163,91,182,113,226,217,175,67,134,17,34,68,136,13,26,52,104,208,189,103,206,129,31,62,124,248,237,199,147,59,118,236,197,151,51,102,204,133,23,46,92,184,109,218,169,79,158,33,66,132,21,42,84,168,77,154,41,82,164,85,170,73,146,57,114,228,213,183,115,230,209,191,99,198,145,63,126,252,229,215,179,123,246,241,255,227,219,171,75,150,49,98,196,149,55,110,220,165,87,174,65,130,25,50,100,200,141,7,14,28,56,112,224,221,167,83,166,81,162,89,178,121,242,249,239,195,155,43,86,172,69,138,9,18,36,72,144,61,122,244,245,247,243,251,235,203,139,11,22,44,88,176,125,250,233,207,131,27,54,108,216,173,71,142 };
//AlphaTo[n]的值为a的n次幂 n=0,1,2,...,254
static unsigned int PowerOf[255] = { 0,1,25,2,50,26,198,3,223,51,238,27,104,199,75,4,100,224,14,52,141,239,129,28,193,105,248,200,8,76,113,5,138,101,47,225,36,15,33,53,147,142,218,240,18,130,69,29,181,194,125,106,39,249,185,201,154,9,120,77,228,114,166,6,191,139,98,102,221,48,253,226,152,37,179,16,145,34,136,54,208,148,206,143,150,219,189,241,210,19,92,131,56,70,64,30,66,182,163,195,72,126,110,107,58,40,84,250,133,186,61,202,94,155,159,10,21,121,43,78,212,229,172,115,243,167,87,7,112,192,247,140,128,99,13,103,74,222,237,49,197,254,24,227,165,153,119,38,184,180,124,17,68,146,217,35,32,137,46,55,63,209,91,149,188,207,205,144,135,151,178,220,252,190,97,242,86,211,171,20,42,93,158,132,60,57,83,71,109,65,162,31,45,67,216,183,123,164,118,196,23,73,236,127,12,111,246,108,161,59,82,41,157,85,170,251,96,134,177,187,204,62,90,203,89,95,176,156,169,160,81,11,245,22,235,122,117,44,215,79,174,213,233,230,231,173,232,116,214,244,234,168,80,88,175 };
//PowerOf[n-1]的值是数n对应的a的幂数 n=1,2,...,255
unsigned int alphato(unsigned int n);
unsigned int powerof(unsigned int n);
unsigned int GFadd(unsigned int a, unsigned int b);

unsigned int GFmulti(unsigned int a, unsigned int b);


unsigned int alphato(unsigned int n);

unsigned int powerof(unsigned int n);

/* 初始化线性表 */
Status InitList(polynomial *L);


/* 删除线性表 */
Status DestroyList(polynomial *L);

/*删除指定的节点*/
Status delete_node(polynomial L, polynomial node);

/*求链表元素个数*/
int Node_count(polynomial L);

/* 按指数从小到大排序在指定的位置插入一个新元素 */
Status ListInsert(polynomial *L, polynomial e);

/*多项式的乘法*/
Status MultiplyPoly(polynomial *La, polynomial *Lb);

/*多项式归并操作，La,Lb归并入La*/
Status ListUnion(polynomial *La, polynomial Lb);

//遍历线性表
Status ListTraverse(polynomial L);

//生成多项式。。。
polynomial genaretor(int version);

//消息多项式。。。size 是多项式的系数的个数
polynomial messege(int version, unsigned int data[], int size);

//求纠错码,size是信息多项式的个数
polynomial correct(polynomial Lme, int size, int version);

//将纠错多项式转化为纠错数组
unsigned int *trans(polynomial L);


//释放创建的信息流
void BitStream_free(BitStream *bstream);

//创建新的新的比特流
BitStream *BitStream_new(void);


//为申请的比特流创建空间
int BitStream_allocate(BitStream *bstream, int version);

//将输入信息转化为比特流,包括选择的模式，信息长度，结束符
BitStream *BitStream_newFromBytes(int version, unsigned int size, unsigned char *data);

//将比特流转化成消息多项式系数
unsigned int *BitStream_toByte(BitStream *&bstream);

//将纠错多项式系数转化为比特流
BitStream *BitStream_tobit(polynomial L);

//根据输入的信息选择合适的version
int choose_version(unsigned int size);

//将信息多项式和纠错多项式的比特流合在一起
unsigned char *BitStream_Union(BitStream *bstream, BitStream *obstream, int version);

unsigned int strlength(unsigned char *mess);

int ver_to_size(int version);

QRarray **newarray(int v);

/*在x,y位置处添加一个 Finder Pattern*/
void Finder_pattern(int x, int y, QRarray **array, int v);

/*在x,y位置处添加一个Alignment Patterns*/
void Alignment_Patterns(int x, int y, QRarray **array);

/*在x,y位置添加一个Timing Pattern 和dark module*/
void Timing_Patterns(QRarray **array, int v);

/*版本信息放置占位*/
void version_patterns(QRarray **array, int v);

/*数据码放置*/
void data_patterns(QRarray **array, int v, unsigned char data[]);

/*输出二维码图形*/
void output(HANDLE hout, QRarray **array, int v);

//创建基本二维码矩阵
QRarray **QRcode(int version);

//掩模
/*int mark_mask(QRarray **array, int mode, int v);*/

//掩模纠错码
//填充纠错级别，掩模信息码
QRarray **cor_mask_bit(unsigned char *data, QRarray **array, int v);

void GBKToUTF8(const char* strGBK, char* utf8);