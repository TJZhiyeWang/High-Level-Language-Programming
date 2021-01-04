/*王志业 1553449 3班*/
#include "7-ds-b12-linear_list_L.h"



template <class ElemType>
/* 构造函数（初始化线性表） */
LinkList<ElemType>::LinkList()
{
	/* 申请头结点空间，赋值给头指针 */
	head = new LNode<ElemType>;
	if (head == NULL)
		exit(OVERFLOW);

	head->next = NULL;
}
template <class ElemType>
/* 析构函数（删除线性表） */
LinkList<ElemType>::~LinkList()
{
	LNode<ElemType> *q, *p = head;

	/* 从头结点开始依次释放（含头结点） */
	while (p) {    //若链表为空，则循环不执行
		q = p->next; //抓住链表的下一个结点
		delete p;
		p = q;
	}

	head = NULL;	//头指针置NULL
}
template <class ElemType>
/* 清除线性表（保留头结点） */
Status LinkList<ElemType>::ClearList()
{
	LNode<ElemType> *q, *p = head->next;

	/* 从首元结点开始依次释放 */
	while (p) {
		q = p->next;   //抓住链表的下一个结点
		delete p;
		p = q;
	}

	head->next = NULL; //头结点的next域置NULL
	return OK;
}
template <class ElemType>
/* 判断是否为空表 */
Status LinkList<ElemType>::ListEmpty()
{
	/* 判断头结点的next域即可 */
	if (head->next == NULL)
		return TRUE;
	else
		return FALSE;
}
template <class ElemType>
/* 求表的长度 */
int LinkList<ElemType>::ListLength()
{
	LNode<ElemType> *p = head->next; //指向首元结点
	int    len = 0;

	/* 循环整个链表，进行计数 */
	while (p) {
		p = p->next;
		len++;
	}

	return len;
}
template <class ElemType>
/* 取表中元素 */
Status LinkList<ElemType>::GetElem(int i, ElemType &e)
{
	LNode<ElemType> *p = head->next;	//指向首元结点
	int  pos = 1;		//初始位置为1

						/* 链表不为NULL 且 未到第i个元素 */
	while (p != NULL && pos < i) {
		p = p->next;
		pos++;
	}

	if (!p || pos > i)
		return ERROR;

	e = p->data;
	return OK;
}
template <class ElemType>
/* 查找符合指定条件的元素 */
int LinkList<ElemType>::LocateElem(ElemType e, Status(*compare)(ElemType e1, ElemType e2))
{
	LNode<ElemType> *p = head->next;	//指向首元结点
	int  pos = 1;		//初始位置为1

						/* 循环整个链表  */
	while (p && (*compare)(e, p->data) == FALSE) {
		p = p->next;
		pos++;
	}

	return p ? pos : 0;
}
template <class ElemType>
/* 查找符合指定条件的元素的前驱元素 */
Status LinkList<ElemType>::PriorElem(ElemType cur_e, ElemType &pre_e)
{
#if 1
	LNode<ElemType> *p = head->next;	//指向首元结点

	if (p == NULL)	//空表直接返回
		return ERROR;

	/* 从第2个结点开始循环整个链表(如果比较相等，保证有前驱) */
	while (p->next && p->next->data != cur_e)
		p = p->next;

	if (p->next == NULL) //未找到
		return ERROR;

	pre_e = p->data;
	return OK;
#else
	LNode *p = head; //指向头结点

					 /* 循环整个链表并比较值是否相等 */
	while (p->next && p->next->data != cur_e)
		p = p->next;

	if (p->next == NULL || p == head) //未找到或首元结点或空表
		return ERROR;

	pre_e = p->data;
	return OK;
#endif
}
template <class ElemType>
/* 查找符合指定条件的元素的后继元素 */
Status LinkList<ElemType>::NextElem(ElemType cur_e, ElemType &next_e)
{
	LNode<ElemType> *p = head->next;  //首元结点

	if (p == NULL)	//空表直接返回
		return ERROR;

	/* 有后继结点且当前结点值不等时继续 */
	while (p->next && p->data != cur_e)
		p = p->next;

	if (p->next == NULL)
		return ERROR;

	next_e = p->next->data;
	return OK;
}
template <class ElemType>
/* 在指定位置前插入一个新元素 */
Status LinkList<ElemType>::ListInsert(int i, ElemType e)
{
	LNode<ElemType> *s, *p = head;	//p指向头结点
	int   pos = 0;

	/* 寻找第i-1个结点 */
	while (p && pos<i - 1) {
		p = p->next;
		pos++;
	}

	if (p == NULL || pos>i - 1)  //i值非法则返回
		return ERROR;

	//执行到此表示找到指定位置，p指向第i-1个结点

	s = new LNode<ElemType>;
	if (s == NULL)
		return myOVERFLOW;

	s->data = e; 	//新结点数据域赋值
	s->next = p->next;	//新结点的next是第i个
	p->next = s;	//第i-1个的next是新结点

	return OK;
}
template <class ElemType>
/* 删除指定位置的元素，并将被删除元素的值放入e中返回 */
Status LinkList<ElemType>::ListDelete(int i, ElemType &e)
{
	LNode<ElemType> *q, *p = head;	//p指向头结点
	int   pos = 0;

	/* 寻找第i个结点（p->next是第i个结点） */
	while (p->next && pos<i - 1) {
		p = p->next;
		pos++;
	}

	if (p->next == NULL || pos>i - 1)	//i值非法则返回
		return ERROR;

	//执行到此表示找到了第i个结点，此时p指向第i-1个结点

	q = p->next;       //q指向第i个结点
	p->next = q->next; //第i-1个结点的next域指向第i+1个

	e = q->data;      //取第i个结点的值
	delete q;           //释放第i个结点

	return OK;
}
template <class ElemType>
/* 遍历线性表 */
Status LinkList<ElemType>::ListTraverse(Status(*visit)(ElemType e))
{
	extern int line_count; //在main中定义的打印换行计数器（与算法无关）
	LNode<ElemType> *p = head->next;

	line_count = 0;		//计数器恢复初始值（与算法无关）
	while (p && (*visit)(p->data) == TRUE)
		p = p->next;

	if (p)
		return ERROR;

	cout << endl;	//最后打印一个换行，只是为了好看，与算法无关
	return OK;
}





