/*1553449 王志业 3班*/
#include <stdio.h>
#include <stdlib.h>		//malloc/realloc函数

#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define LOVERFLOW	-2		//因为<math.h>中已有 OVERFLOW 的定义，因此换一下

typedef int Status;

typedef struct student {
	int   num;
	char  name[10];
	char  sex;
	float score;
	char  addr[30];
} ET, *ElemType;

typedef struct LNode {
	ElemType      data;	//存放数据
	struct LNode *next;	//存放直接后继的指针
	struct LNode *prior;//存放直接前继指针
} LNode, *LinkList;

/* 初始化线性表 */
Status InitList(LinkList *L)
{
	/* 申请头结点空间，赋值给头指针 */
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L == NULL)
		exit(LOVERFLOW);

	(*L)->next = NULL;
	(*L)->prior = NULL;
	return OK;
}

/* 删除线性表 */
Status DestroyList(LinkList *L)
{
	LinkList q, p = *L; //指向首元

						/* 整个链表(含头结点)依次释放 */
	while (p) {    //若链表为空，则循环不执行
		q = p->next; //抓住链表的下一个结点
		if (p != *L)
			free(p->data);
		free(p);
		p = q;
	}

	*L = NULL;	//头指针置NULL
	return OK;
}

/* 取表中元素 */
LinkList GetElemP_DuL(LinkList L, int i)
{
	LinkList p = L;	//指向头结点
	int    pos = 0;		//初始位置为1

						/* 链表不为NULL 且 未到第i个元素 */
	while (p != NULL && pos < i - 1) {
		p = p->next;
		pos++;
	}

	if (!p || pos > i - 1)
		return NULL;
	return p;
}

/*在表的第i个位置之前插入元素e*/

Status ListInsert_DuL(LinkList L, int i, ElemType e)
{
	LinkList p = L->next, s;
	if (!(p = GetElemP_DuL(L, i)))
		return ERROR;

	if (!(s = (LinkList)malloc(sizeof(LNode))))
		return LOVERFLOW;
	s->data = e;
	s->prior = p;
	if (p->next != NULL)
		p->next->prior = s;
	s->next = p->next;
	p->next = s;
	return OK;
}

/*在表的第i个位置删除元素e*/

Status ListDelete_DuL(LinkList L, int i, ElemType *e)
{
	LinkList p;
	if (!(p = GetElemP_DuL(L, i)->next))
		return ERROR;

	*e = p->data;
	p->prior->next = p->next;
	if (p->next != NULL)
		p->next->prior = p->prior;
	return OK;
}

/* 遍历线性表 */
Status ListTraverse(LinkList L)
{

	LinkList p = L->next;


	while (p)
	{
		printf("%d-%s-%c-%f-%s->\n", p->data->num, p->data->name, p->data->sex, p->data->score, p->data->addr);
		p = p->next;


	}

	if (p)
		return ERROR;

	printf("\n");//最后打印一个换行，只是为了好看，与算法无关
	return OK;
}
/* 求表的长度 */
int ListLength(LinkList L)
{
	LinkList p = L->next; //指向首元结点
	int len = 0;

	/* 循环整个链表，进行计数 */
	while (p) {
		p = p->next;
		len++;
	}
}
int main()
{
	LinkList L;
	int      i;
	ElemType e1;
	ET e[] = { { 1001, "张三", 'M', 76.5, "上海市杨浦区" },
	{ 1002, "李四", 'F', 87, "上海市普陀区" },
	{ 1003, "王五", 'M', 80, "浙江省杭州市" },
	{ 1004, "赵六", 'M', 54, "浙江省绍兴市" },
	{ 1005, "牛七", 'F', 85, "江苏省南京市" },
	{ 1006, "马八", 'M', 60, "江苏省苏州市" } };
	InitList(&L);
	printf("建立初始链表，插入六个元素后遍历如下：\n");
	for (i = 0; i < 6; i++)
	{
		e1 = (ElemType)malloc(sizeof(ET));
		if (e1 == NULL)
			exit(LOVERFLOW);
		*e1 = *(e + i);
		ListInsert_DuL(L, i + 1, e1);
	}
	ListTraverse(L);
	//插入元素


	printf("删除头：\n");
	ListDelete_DuL(L, 1, &e1);
	ListTraverse(L);
	printf("删除中间：\n");
	ListDelete_DuL(L, ListLength(L) / 2 + 1, &e1);
	ListTraverse(L);
	printf("删除末尾：\n");
	ListDelete_DuL(L, ListLength(L), &e1);
	ListTraverse(L);

	DestroyList(&L);
	printf("已回收全部内存");
	return 0;
}
