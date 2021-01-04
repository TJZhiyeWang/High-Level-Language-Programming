/*王志业 3班 1553449*/
#include <iostream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define myOVERFLOW	-2

typedef int Status;

template <class ElemType>
class LinkList;

template <class ElemType>
class LNode {
protected:
	ElemType data;	//数据域
	LNode   *next;	//指针域
public:
	friend class LinkList<ElemType>;
	//不定义任何函数，相当于struct LNode
};


template <class ElemType>
class LinkList {
protected:
	LNode<ElemType> *head;	//头指针
public:
	/* P.19-20的抽象数据类型定义转换为实际的C++语言 */
	LinkList();	//构造函数，替代InitList
	~LinkList();	//析构函数，替代DestroyList
	Status	ClearList();
	Status	ListEmpty();
	int	ListLength();
	Status	GetElem(int i, ElemType &e);
	int	LocateElem(ElemType e, Status(*compare)(ElemType e1, ElemType e2));
	Status	PriorElem(ElemType cur_e, ElemType &pre_e);
	Status	NextElem(ElemType cur_e, ElemType &next_e);
	Status	ListInsert(int i, ElemType e);
	Status	ListDelete(int i, ElemType &e);
	Status	ListTraverse(Status(*visit)(ElemType e));
};
