/*1553449 3班 王志业*/
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

#include <stdio.h>
#include <stdlib.h>		//malloc/realloc函数

#define INSERT_NUM		115		//初始插入表中的元素数量
#define MAX_NUM_PER_LINE 	10		//每行最多输出的元素个数

int line_count = 0;   //打印链表时的计数器

typedef int Status;
typedef int ElemType;

typedef struct LNode {
	ElemType      data;	//存放数据
	struct LNode *next;	//存放直接后继的指针
} LNode, *LinkList;


/* 初始化线性表 */
Status InitList(LinkList *L)
{
	/* 申请头结点空间，赋值给头指针 */
	*L = (LNode *)malloc(sizeof(LNode));
	if (*L == NULL)
		exit(OVERFLOW);

	(*L)->next = NULL;
	return OK;
}

/* 删除线性表 */
Status DestroyList(LinkList *L)
{
	LinkList q, p = *L; //指向首元

						/* 整个链表(含头结点)依次释放 */
	while (p) {    //若链表为空，则循环不执行
		q = p->next; //抓住链表的下一个结点
		free(p);
		p = q;
	}

	*L = NULL;	//头指针置NULL
	return OK;
}

/* 在指定位置前插入一个新元素 */
Status ListInsert(LinkList *L, int i, ElemType e)
{
	LinkList s, p = *L;	//p指向头结点
	int      pos = 0;

	/* 寻找第i-1个结点 */
	while (p && pos<i - 1) {
		p = p->next;
		pos++;
	}

	if (p == NULL || pos>i - 1)  //i值非法则返回
		return ERROR;

	//执行到此表示找到指定位置，p指向第i-1个结点

	s = (LinkList)malloc(sizeof(LNode));
	if (s == NULL)
		return OVERFLOW;

	s->data = e; 	//新结点数据域赋值
	s->next = p->next;	//新结点的next是第i个
	p->next = s;	//第i-1个的next是新结点

	return OK;
}

/* 遍历线性表 */
Status ListTraverse(LinkList L, Status(*visit)(ElemType e))
{
	extern int line_count; //在main中定义的打印换行计数器（与算法无关）
	LinkList p = L->next;

	line_count = 0;		//计数器恢复初始值（与算法无关）
	while (p && (*visit)(p->data) == TRUE)
		p = p->next;

	if (p)
		return ERROR;

	printf("\n");//最后打印一个换行，只是为了好看，与算法无关
	return OK;
}

Status MyVisit(ElemType e)
{
	printf("%3d->", e);

	/* 每输出MAX_NUM_PER_LINE个，打印一个换行 */
	if ((++line_count) % MAX_NUM_PER_LINE == 0)
		printf("\n");

	return OK;
}

/*带头节点，归并线性表，并释放另一个表*/
void union_L(LinkList *La, LinkList Lb)
{
	LinkList p, q, r, temp = Lb;
	for (q = Lb->next; q; q = q->next)
	{
		free(temp);
		for (p = (*La)->next; p; p = p->next)
			if (p->data == q->data)
				break;
		if (!p)
		{
			r = (LinkList)malloc(sizeof(LNode));
			if (!r)
				exit(OVERFLOW);
			r->data = q->data;
			r->next = (*La)->next;
			(*La)->next = r;
		}
		temp = q;
	}
}

int main()
{
	LinkList La, Lb;
	int i;

	InitList(&La);
	InitList(&Lb);

	printf("插入La%d个元素：\n", INSERT_NUM);
	for (i = INSERT_NUM * 2; i > 0; i -= 2)
		ListInsert(&La, 1, i);

	printf("插入Lb%d个元素：\n", INSERT_NUM);
	for (i = INSERT_NUM; i > 0; i--)
		ListInsert(&Lb, 1, i);

	union_L(&La, Lb);
	printf("遍历La：\n");
	ListTraverse(La, MyVisit);//此处传入MyVisit函数名

	DestroyList(&La);
	return 0;
}