/*1553449 王志业 3班*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>		//malloc/realloc函数
#include <conio.h>
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define LOVERFLOW	-2		//因为<math.h>中已有 OVERFLOW 的定义，因此换一下

typedef int Status;

typedef struct polynode
{
	double coef;
	int expn;
	struct polynode *next;
}polynode, *polynomial;

/* 初始化线性表 */
Status InitList(polynomial *L)
{
	/* 申请头结点空间，赋值给头指针 */
	*L = (polynomial)malloc(sizeof(polynode));
	if (*L == NULL)
		exit(LOVERFLOW);
	(*L)->next = NULL;
	return OK;
}

/* 删除线性表 */
Status DestroyList(polynomial *L)
{
	polynomial q, p = *L; //指向首元

						  /* 整个链表(含头结点)依次释放 */
	while (p) {    //若链表为空，则循环不执行
		q = p->next; //抓住链表的下一个结点
		free(p);
		p = q;
	}
	*L = NULL;	//头指针置NULL
	return OK;
}

/* 按指数从小到大排序在指定的位置插入一个新元素 */
Status ListInsert(polynomial *L, polynomial e)
{
	polynomial  p = *L;	//p指向头结点

						/*找到适合放e->expn的位置*/
	while (p->next) {
		if (p->next->expn > e->expn)
		{
			e->next = p->next;
			p->next = e;
			break;
		}
		if (p->next->expn == e->expn)
		{
			p->next->coef += e->coef;
			break;
		}
		p = p->next;
	}
	if (p->next == NULL)
	{
		e->next = p->next;
		p->next = e;
	}

	return OK;
}

/*多项式归并操作，La,Lb归并入La*/
Status ListUnion(polynomial *La, polynomial Lb)
{
	polynomial p = (*La)->next, q = Lb->next, pre = *La, temp;
	while (p&&q)
	{
		if (p->expn > q->expn)
		{
			pre->next = q;
			pre = q;
			q = q->next;
		}
		else if (p->expn == q->expn)
		{
			if ((p->coef + q->coef) != 0)
			{
				p->coef = p->coef + q->coef;
				pre->next = p;
				pre = p;
				temp = q;
				q = q->next;
				p = p->next;
				free(temp);
			}
			else
			{
				temp = q;
				q = q->next;
				free(temp);
				temp = p;
				p = p->next;
				free(temp);
			}
		}
		else
		{
			pre->next = p;
			pre = p;
			p = p->next;
		}
	}
	pre->next = p ? p : q;
	return OK;
}
/* 遍历线性表 */
Status ListTraverse(polynomial L)
{

	polynomial p = L->next;


	while (p)
	{
		printf("%.1f*x^(%d)+", p->coef, p->expn);
		p = p->next;
	}
	printf("\n");
	if (p)
		return ERROR;

	printf("\n");//最后打印一个换行，只是为了好看，与算法无关
	return OK;
}
void menu()
{
	printf("1.建立多项式La，Lb（进行完运算后需要重新建立多项式）\n2.La+Lb\n3.La-Lb\n0.退出");
}
int main()
{
	polynomial La, Lb, e;
	InitList(&La);
	InitList(&Lb);
	while (1)
	{
		system("cls");
		menu();
		
		switch (_getch())
		{
			
			case '1':

				system("cls");
				InitList(&La);
				InitList(&Lb);
				printf("请按照指数，系数的顺序输入多项式,每输入一项请按回车确认。输入完一项后想继续输入请按回车，完毕后按Esc键结束\n");
				while (1)
				{

					e = (polynomial)malloc(sizeof(polynode));
					scanf("%d%lf", &e->expn, &(e->coef));
					ListInsert(&La, e);
					char ch = _getch();
					if (ch == 27)
						break;
					else if (ch == 13)
						continue;

				}
				ListTraverse(La);
				printf("请按照指数，系数的顺序输入多项式,每输入一项请按回车确认。输入完一项后想继续输入请按回车，完毕后按Esc键结束\n");
				while (1)
				{
					e = (polynomial)malloc(sizeof(polynode));

					scanf("%d%lf", &e->expn, &(e->coef));
					ListInsert(&Lb, e);
					char ch = _getch();
					if (ch == 27)
						break;
					else if (ch == 13)
						continue;
				}

				ListTraverse(Lb);
				continue;

			case '2':

				system("cls");
				ListUnion(&La, Lb);
				printf("结果为：\n");
				ListTraverse(La);
				printf("回车键返回");
				while (_getch() != 13);
				DestroyList(&La);
				continue;

			case '3':

				system("cls");
				polynomial p=Lb->next;
				while (p)
				{
					p->coef = -(p->coef);
					p = p->next;
				}
				ListUnion(&La, Lb);
				printf("结果为：\n");
				ListTraverse(La);
				printf("回车键返回");
				while (_getch() != 13);
				DestroyList(&La);
				continue;
			case '0':

				printf("已释放内存...");
				break;

		}
		break;
	}


	return 0;
}

/*链表倒置
polynomial InverseList(polynomial L)
{
	if (L->next == NULL)
		return L;
	polynomial p = L->next, q = NULL;
	while (1)
	{
		q = p->next;
		if (!q)
			break;
		p->next = q->next;
		q->next = L->next;
		L->next = q;
	}
	return L;
}
polynomial MultiplyPoly(polynomial La, polynomial Lb)
{
polynomial pa = La->next, pb = Lb->next, Lc, pc, newnode;
int pmax;//指数之和最大值
if (pa&&pb)
pmax = pa->expn*pb->expn;
if (!InitList(&Lc))
return NULL;
pc = Lc;
InverseList(Lb);
double coef = 0.0;
for (int k = pmax; k >= 0; k++)
{
pa = La->next;
while (pa != NULL&&pa->expn > k)
pa = pa->next;
pb = Lb->next;
while (pa != NULL&&pb != NULL&&pa->expn + pb->expn < k)
pb = pb->next;
while (pa != NULL&&pb != NULL)
{
if (k == pa->expn + pb->expn)
{
coef = pa->coef*pb->coef;
pa = pa->next;
pb = pb->next;
}
else
{
if (pa->expn + pb->expn < k)
pb = pb->next;
else
pa = pa->next;
}
}
if (coef != 0.0)
{
if (NULL == (newnode = (polynomial)malloc(sizeof(polynode))))
exit(-1);

newnode->next = NULL;
newnode->coef = coef;
newnode->expn = k;
pc->next = newnode;
pc = newnode;
coef = 0.0;
}

}
InverseList(Lb);
return Lc;


}
链表排序，幂数相同的项合并
Status list_sort(polynomial L)
{
	int sorted = 0;
	polynomial node, temp, head = L;
	if (L == NULL)
		return ERROR;
	if (Node_count(L) < 2)
		return OK;
	node = head->next;
	head->next = NULL;
	while (node != NULL)
	{
		sorted = 0;
		L = head;
		while (L->next)
		{
			if (node->coef == L->next->coef)
			{
				L->next->coef += node->coef;
				node = node->next;
				sorted = 1;
				break;
			}
			else if (node->expn > L->next->expn)
			{
				temp = node;
				node = node->next;
				temp->next = L->next;
				L->next = temp;
				sorted = 1;
				break;
			}
			L = L->next;
		}
		if (sorted == 0)
		{
			temp = node;
			node = node->next;
			L->next = temp;
			temp->next = NULL;
		}
	}

	return OK;

}*/