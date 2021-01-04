/*3班 王志业 1553449*/
#include "90-b4.h"
#include "cmd_console_tools.h"
//***********************************************************

/*以下为迦洛华域运算部分函数*/

//***********************************************************
unsigned int GFadd(unsigned int a, unsigned int b)
{
	unsigned int c = alphato(a) ^ alphato(b);
	return powerof(c);
}
unsigned int GFmulti(unsigned int a, unsigned int b)
{
	unsigned int c = (a + b) % 255;
	return c;
}
unsigned int alphato(unsigned int n)
{
	int N = n % 255;
	return AlphaTo[N];
}
unsigned int powerof(unsigned int n)
{
	return PowerOf[n - 1];
}
//***********************************************************

/*以下为多项式操作部分函数*/

//***********************************************************


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
/*删除指定的节点*/
Status delete_node(polynomial L, polynomial node)
{
	polynomial temp = NULL;
	if (L == NULL)
		return ERROR;
	while (L->next)
	{
		if ((node->coef == L->coef) && (node->expn == L->expn))
		{
			temp = L->next;
			L->next = L->next->next;
			free(temp);
			return OK;
		}
		L = L->next;
	}
	return ERROR;
}
/*求链表元素个数*/
int Node_count(polynomial L)
{
	int i = 0;
	if (L->next == NULL)
		return 0;
	while (L->next)
	{
		i++;
		L = L->next;
	}
	return i;
}
/* 按指数从小到大排序在指定的位置插入一个新元素 */
Status ListInsert(polynomial *L, polynomial e)
{
	polynomial  p = *L;	//p指向头结点

						/*找到适合放e->expn的位置*/
	while (p->next) {
		if (p->next->expn < e->expn)
		{
			e->next = p->next;
			p->next = e;
			break;
		}
		if (p->next->expn == e->expn)
		{
			p->next->coef = GFadd(p->next->coef, e->coef);
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
/*多项式的乘法*/
Status MultiplyPoly(polynomial *La, polynomial *Lb)
{
	polynomial data;
	polynomial pnew = NULL;
	polynomial pa = *La, pb = *Lb;
	InitList(&pnew);
	if (Node_count(*La) == 0 || Node_count(*Lb) == 0)
		return ERROR;
	while (pa->next)
	{
		while (pb->next)
		{
			data = (polynomial)malloc(sizeof(polynode));
			data->coef = GFmulti(pa->next->coef, pb->next->coef);
			data->expn = pa->next->expn + pb->next->expn;
			ListInsert(&pnew, data);
			pb = pb->next;
		}
		pb = *Lb;
		pa = pa->next;
	}
	DestroyList(La);
	DestroyList(Lb);
	*La = pnew;
	return OK;
}
/*多项式归并操作，La,Lb归并入La，并入操作为^*/
Status ListUnion(polynomial *La, polynomial Lb)
{

	polynomial p = (*La)->next, q = Lb->next, pre = *La, temp;
	int flag = 0;
	while (p&&q)
	{
		if (p->expn == q->expn)
		{
			if ((alphato(p->coef) ^ alphato(q->coef)) != 0 || flag == 1)
			{
				p->coef = powerof(alphato(p->coef) ^ alphato(q->coef));
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
				flag = 1;
			}
		}

	}
	free(Lb);
	pre->next = p ? p : q;
	return OK;
}
//遍历线性表
Status ListTraverse(polynomial L)
{

	polynomial p = L->next;


	while (p)
	{
		printf("%u*x^(%u)+", alphato(p->coef), p->expn);
		p = p->next;
	}
	printf("\n");
	if (p)
		return ERROR;

	printf("\n");//最后打印一个换行，只是为了好看，与算法无关
	return OK;
}
//生成多项式。。。
polynomial genaretor(int version)
{
	polynomial La, Lb, e;
	InitList(&La);
	switch (version)
	{
		case 17:
		{
			InitList(&La);
			for (int i = 0; i < 2; i++)
			{
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = 0;
				e->expn = i;
				ListInsert(&La, e);
			}

			for (int i = 0; i < 6; i++)
			{
				InitList(&Lb);
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = 0;
				e->expn = 1;
				ListInsert(&Lb, e);
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = i + 1;
				e->expn = 0;
				ListInsert(&Lb, e);
				MultiplyPoly(&La, &Lb);
			}
			return La;
		}
		case 32:
		{
			InitList(&La);
			for (int i = 0; i < 2; i++)
			{
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = 0;
				e->expn = i;
				ListInsert(&La, e);
			}

			for (int i = 0; i < 9; i++)
			{
				InitList(&Lb);
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = 0;
				e->expn = 1;
				ListInsert(&Lb, e);
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = i + 1;
				e->expn = 0;
				ListInsert(&Lb, e);
				MultiplyPoly(&La, &Lb);
			}
			return La;
		}
		case 53:
		{
			InitList(&La);
			for (int i = 0; i < 2; i++)
			{
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = 0;
				e->expn = i;
				ListInsert(&La, e);
			}

			for (int i = 0; i < 14; i++)
			{
				InitList(&Lb);
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = 0;
				e->expn = 1;
				ListInsert(&Lb, e);
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = i + 1;
				e->expn = 0;
				ListInsert(&Lb, e);
				MultiplyPoly(&La, &Lb);
			}
			return La;
		}
		case 78:
		{
			InitList(&La);
			for (int i = 0; i < 2; i++)
			{
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = 0;
				e->expn = i;
				ListInsert(&La, e);
			}

			for (int i = 0; i < 19; i++)
			{
				InitList(&Lb);
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = 0;
				e->expn = 1;
				ListInsert(&Lb, e);
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = i + 1;
				e->expn = 0;
				ListInsert(&Lb, e);
				MultiplyPoly(&La, &Lb);
			}
			return La;
		}
		case 106:
		{
			InitList(&La);
			for (int i = 0; i < 2; i++)
			{
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = 0;
				e->expn = i;
				ListInsert(&La, e);
			}

			for (int i = 0; i < 25; i++)
			{
				InitList(&Lb);
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = 0;
				e->expn = 1;
				ListInsert(&Lb, e);
				e = (polynomial)malloc(sizeof(polynode));
				e->coef = i + 1;
				e->expn = 0;
				ListInsert(&Lb, e);
				MultiplyPoly(&La, &Lb);
			}
			return La;
		}

	}
	return La;
}
//消息多项式。。。size 是多项式的系数的个数
polynomial messege(int version, unsigned int data[], int size)
{
	polynomial L, e;
	InitList(&L);
	switch (version)
	{
		case 17:
			for (int i = 0; i < size; i++)
			{

				e = (polynomial)malloc(sizeof(polynode));
				e->coef = powerof(data[i]);
				e->expn = size - i - 1 + 7;
				ListInsert(&L, e);
			}
			break;
		case 32:
			for (int i = 0; i < size; i++)
			{

				e = (polynomial)malloc(sizeof(polynode));
				e->coef = powerof(data[i]);
				e->expn = size - i - 1 + 10;
				ListInsert(&L, e);
			}
			break;
		case 53:
			for (int i = 0; i < size; i++)
			{

				e = (polynomial)malloc(sizeof(polynode));
				e->coef = powerof(data[i]);
				e->expn = size - i - 1 + 15;
				ListInsert(&L, e);
			}
			break;
		case 78:
			for (int i = 0; i < size; i++)
			{

				e = (polynomial)malloc(sizeof(polynode));
				e->coef = powerof(data[i]);
				e->expn = size - i - 1 + 20;
				ListInsert(&L, e);
			}
			break;
		case 106:
			for (int i = 0; i < size; i++)
			{

				e = (polynomial)malloc(sizeof(polynode));
				e->coef = powerof(data[i]);
				e->expn = size - i - 1 + 26;
				ListInsert(&L, e);
			}
			break;
		case 14:
			for (int i = 0; i < size; i++)
			{

				e = (polynomial)malloc(sizeof(polynode));
				e->coef = powerof(data[i]);
				e->expn = size - i - 1 + 10;
				ListInsert(&L, e);
			}
			break;
	}
	return L;
}
//求纠错码,size是信息多项式的个数
polynomial correct(polynomial Lme, int size, int version)
{
	unsigned int r;
	for (int i = 0; i < size; i++)
	{
		polynomial pm = Lme->next, Lge = genaretor(version), pg = Lge->next;
		r = pm->expn - pg->expn;
		while (pg)
		{
			pg->expn += r;
			pg->coef = GFmulti(pg->coef, pm->coef);
			pg = pg->next;
		}
		ListUnion(&Lme, Lge);

	}

	polynomial pm = Lme->next;
	return Lme;
}
//将纠错多项式转化为纠错数组
unsigned int *trans(polynomial L)
{
	unsigned int *data;
	polynomial p = L->next;
	data = (unsigned int *)malloc(Node_count(L)*sizeof(unsigned int));
	for (int i = 0; i < Node_count(L); i++)
	{
		data[i] = alphato(p->coef);
		p = p->next;
	}
	return data;
}

//***********************************************************

/*以下为信息与二进制流的转化部分函数*/

//***********************************************************
//释放创建的信息流
void BitStream_free(BitStream *bstream)
{
	if (bstream != NULL) {
		free(bstream->data);
		free(bstream);
	}
}
//创建新的新的比特流
BitStream *BitStream_new(void)
{
	BitStream *bstream;

	bstream = (BitStream *)malloc(sizeof(BitStream));
	if (bstream == NULL) return NULL;

	bstream->length = 0;
	bstream->data = NULL;

	return bstream;
}

//为申请的比特流创建空间
int BitStream_allocate(BitStream *bstream, int version)
{
	unsigned char *cdata;

	if (bstream == NULL) {
		return -1;
	}

	cdata = (unsigned char *)malloc(int((version + 2) * 8));
	if (cdata == NULL) {
		return -1;
	}

	if (bstream->data) {
		free(bstream->data);
	}
	bstream->length = (version + 2) * 8;
	bstream->data = cdata;

	return 0;
}
//将输入信息转化为比特流,包括选择的模式，信息长度，结束符
BitStream *BitStream_newFromBytes(int version, unsigned int size, unsigned char *data)
{
	unsigned char mask;
	int i, j;
	unsigned char *p, mode[4] = { 0,1,0,0 }, app1[8] = { 1,1,1,0,1,1,0,0 }, app2[8] = { 0,0,0,1,0,0,0,1 };
	BitStream *bstream;

	bstream = BitStream_new();
	if (bstream == NULL) return NULL;

	if (BitStream_allocate(bstream, version)) {
		BitStream_free(bstream);
		return NULL;
	}
	p = bstream->data;
	for (i = 0; i < 4; i++)
	{
		*p = mode[i];
		p++;
	}
	mask = 0x80;
	for (i = 0; i < 8; i++)
	{
		if (char(size) & mask) {
			*p = 1;
		}
		else {
			*p = 0;
		}
		p++;
		mask = mask >> 1;
	}
	for (i = 0; (unsigned int)i < size; i++) {
		mask = 0x80;
		for (j = 0; j < 8; j++) {
			if (data[i] & mask) {
				*p = 1;
			}
			else {
				*p = 0;
			}
			p++;
			mask = mask >> 1;
		}
	}
	if (8 * (version + 2) - 8 * size + 12  >0)
	{
		int stop = (8 * (version + 2) - 8 * size + 12) < 4 ? (8 * (version + 2) - 8 * size + 12) : 4;
		for (i = 0; i < stop; i++)
		{
			*p = 0;
			p++;
		}
	}
	if (8 * (version + 2) - 8 * size + 12 > 4)
	{
		int stop = version - size;
		while (stop > 0)
		{
			for (i = 0; i < 8; i++)
			{
				*p = app1[i];
				p++;
			}
			stop--;
			if (stop > 0)
			{
				for (i = 0; i < 8; i++)
				{
					*p = app2[i];
					p++;
				}
				stop--;
			}
		}
	}
	return bstream;
}
//将比特流转化成消息多项式系数
unsigned int *BitStream_toByte(BitStream * &bstream)
{
	int i, j, size, bytes;
	unsigned char *p, v;
	unsigned int *data;

	size = bstream->length;
	if (size == 0) {
		return NULL;
	}
	data = (unsigned int *)malloc(int((size + 7) / 8 * sizeof(unsigned int)));
	if (data == NULL) {
		return NULL;
	}
	bytes = int((size + 7) / 8);

	p = bstream->data;
	for (i = 0; i < bytes; i++) {
		v = 0;
		for (j = 0; j < 8; j++) {
			v = v << 1;
			v |= *p;
			p++;
		}
		data[i] = unsigned int(v);
	}
	return data;
}
//将纠错多项式系数转化为比特流
BitStream *BitStream_tobit(polynomial L)
{
	unsigned char mask, *p;
	int i, j;
	BitStream *bstream;
	unsigned int *cdata;
	cdata = trans(L);
	bstream = BitStream_new();
	if (bstream == NULL) return NULL;

	if (BitStream_allocate(bstream, Node_count(L) - 2)) {
		BitStream_free(bstream);
		return NULL;
	}

	p = bstream->data;
	for (i = 0; i < Node_count(L); i++) {
		mask = 0x80;
		for (j = 0; j < 8; j++) {
			if (cdata[i] & mask) {
				*p = 1;
			}
			else {
				*p = 0;
			}
			p++;
			mask = mask >> 1;
		}
	}
	free(cdata);
	return bstream;
}
//获取输入的信息的长度
unsigned int strlength(unsigned char *mess)
{
	unsigned int len = 0;
	while (*mess != '\0')
	{
		len++;
		mess++;
	}
	return len;
}
//根据输入的信息选择合适的version
int choose_version(unsigned int size)
{
	if (size > 0 && size <= 17)
		return L_1;
	else if (size > 17 && size <= 32)
		return L_2;
	else if (size > 32 && size <= 53)
		return L_3;
	else if (size > 53 && size <= 78)
		return L_4;
	else if (size > 78 && size <= 106)
		return L_5;
	else
		return -1;
}
//将信息多项式和纠错多项式的比特流合在一起
unsigned char *BitStream_Union(BitStream *bstream, BitStream *obstream, int version)
{
	unsigned char *data, *p;
	if (version == 17)
	{
		data = (unsigned char*)malloc(bstream->length + obstream->length);
		p = data;
		memcpy(p, bstream->data, bstream->length);
		p = p + bstream->length;
		memcpy(p, obstream->data, obstream->length);

	}
	else
	{
		data = (unsigned char*)malloc(bstream->length + obstream->length + 7);
		p = data;
		memcpy(p, bstream->data, bstream->length);
		p = p + bstream->length;
		memcpy(p, obstream->data, obstream->length);
		char *zero;
		zero = (char *)malloc(7);

		for (int i = 0; i < 7; i++)
		{
			zero[i] = 0;
		}
		p = p + obstream->length;
		memcpy(p, zero, 7);
		free(zero);
	}
	return data;
}


//***********************************************************

/*以下为0-1矩阵操作部分函数*/

//***********************************************************

//0->white 1->black
int ver_to_size(int version)
{
	int v;
	switch (version)
	{
		case 17:
			v = 1;
			break;
		case 32:
			v = 2;
			break;
		case 53:
			v = 3;
			break;
		case 78:
			v = 4;
			break;
		case 106:
			v = 5;
			break;
	}
	return v;
}
QRarray **newarray(int v)
{
	QRarray **array;
	array = new QRarray*[(v - 1) * 4 + 21];
	for (int i = 0; i < (v - 1) * 4 + 21; i++)
	{
		array[i] = new QRarray[(v - 1) * 4 + 21];
	}
	return array;
}
/*在x,y位置处添加一个 Finder Pattern*/
void Finder_pattern(int x, int y, QRarray **array, int v)
{
	array[x][y].col = 1;
	array[x][y].ocu = 1;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = -i; j <= i; j++)
		{
			if (x + i < (v - 1) * 4 + 21 && y + j >= 0 && y + j < (v - 1) * 4 + 21)
			{
				array[x + i][y + j].col = i % 2;
				array[x + i][y + j].ocu = 1;
			}
			if (x - i >= 0 && y + j >= 0 && y + j < (v - 1) * 4 + 21)
			{
				array[x - i][y + j].col = i % 2;
				array[x - i][y + j].ocu = 1;
			}
			if (y + i < (v - 1) * 4 + 21 && x + j >= 0 && x + j < (v - 1) * 4 + 21)
			{
				array[x + j][y + i].col = i % 2;
				array[x + j][y + i].ocu = 1;
			}
			if (y - i >= 0 && x + j >= 0 && x + j < (v - 1) * 4 + 21)
			{
				array[x + j][y - i].col = i % 2;
				array[x + j][y - i].ocu = 1;
			}
		}
	}
}
/*在x,y位置处添加一个Alignment Patterns*/
void Alignment_Patterns(int x, int y, QRarray **array)
{
	array[x][y].col = 1;
	array[x][y].ocu = 1;
	for (int i = 1; i <= 2; i++)
	{
		for (int j = -i; j <= i; j++)
		{
			array[x + i][y + j].col = (i + 1) % 2;
			array[x + i][y + j].ocu = 1;
			array[x - i][y + j].col = (i + 1) % 2;
			array[x - i][y + j].ocu = 1;
			array[x + j][y + i].col = (i + 1) % 2;
			array[x + j][y + i].ocu = 1;
			array[x + j][y - i].col = (i + 1) % 2;
			array[x + j][y - i].ocu = 1;
		}
	}
}
/*在x,y位置添加一个Timing Pattern 和dark module*/
void Timing_Patterns(QRarray **array, int v)
{
	array[(v - 1) * 4 + 21 - 8][8].col = 1;
	array[(v - 1) * 4 + 21 - 8][8].ocu = 1;
	for (int i = 0; i < (v - 1) * 4 + 21; i++)
	{
		if (array[6][i].ocu == 0)
		{
			if (i % 2 == 0)
				array[6][i].col = 1;
			else
				array[6][i].col = 0;
			array[6][i].ocu = 1;
		}
		if (array[i][6].ocu == 0)
		{
			if (i % 2 == 0)
				array[i][6].col = 1;
			else
				array[i][6].col = 0;
			array[i][6].ocu = 1;
		}
	}
}
/*版本信息放置占位*/
void version_patterns(QRarray **array, int v)
{
	for (int i = 0; i < 9; i++)
		array[i][8].ocu = 1;
	for (int i = 0; i < 9; i++)
		array[8][i].ocu = 1;
	for (int i = (v - 1) * 4 + 21 - 1; i >= (v - 1) * 4 + 21 - 8; i--)
		array[8][i].ocu = 1;
	for (int i = (v - 1) * 4 + 21 - 1; i >= (v - 1) * 4 + 21 - 7; i--)
		array[i][8].ocu = 1;
}
/*数据码放置*/
void data_patterns(QRarray **array, int v, unsigned char data[])
{

	int len = (v - 1) * 4 + 21 - 1, count = 0;
	for (int j = len; j >= 0; j -= 2)
	{
		if (j == 6)
		{
			j++;
			continue;
		}
		if (count % 2 == 0)
		{
			for (int i = len; i >= 0; i--)
			{
				for (int k = j; k >= j - 1; k--)
				{
					if (array[i][k].ocu == 0)
					{
						array[i][k].col = int(*data);
						data++;
					}
					else
						continue;
				}
			}
		}
		else
		{
			for (int i = 0; i <= len; i++)
			{
				for (int k = j; k >= j - 1; k--)
				{
					if (array[i][k].ocu == 0)
					{
						array[i][k].col = int(*data);
						data++;
					}
					else
						continue;
				}
			}
		}
		count++;
	}
}
/*输出二维码图形*/
void output(HANDLE hout, QRarray **array, int v)
{
	system("cls");
	setconsoleborder(hout, 100, 50);
	showstr(hout, 0, 0, "  ", COLOR_HWHITE, 0);
	showstr(hout, 2 * ((v - 1) * 4 + 20) + 4, 0, "  ", COLOR_HWHITE, 0);
	showstr(hout, 0, 1, "  ", COLOR_HWHITE, 0);
	showstr(hout, 2 * ((v - 1) * 4 + 20) + 4, 1, "  ", COLOR_HWHITE, 0);
	for (int i = 0; i < (v - 1) * 4 + 21; i++)
	{
		for (int j = 0; j < (v - 1) * 4 + 21; j++)
		{
			gotoxy(hout, j, i);
			if (array[i][j].col == 0)
				showstr(hout, 2 * j + 2, i + 1, "  ", COLOR_HWHITE, 0);
			else
				showstr(hout, 2 * j + 2, 1 + i, "  ", COLOR_BLACK, 0);
			showstr(hout, 2 * j + 2, 0, "  ", COLOR_HWHITE, 0);
			showstr(hout, 2 * j + 2, (v - 1) * 4 + 21 + 1, "  ", COLOR_HWHITE, 0);
		}
		showstr(hout, 0, i + 2, "  ", COLOR_HWHITE, 0);
		showstr(hout, 2 * ((v - 1) * 4 + 20) + 4, i + 2, "  ", COLOR_HWHITE, 0);

	}
}
//创建基本二维码矩阵
QRarray **QRcode(int version)
{
	QRarray **array;
	int v;
	v = ver_to_size(version);
	array = newarray(v);
	Finder_pattern(3, 3, array, v);
	Finder_pattern(3, (v - 1) * 4 + 21 - 4, array, v);
	Finder_pattern((v - 1) * 4 + 21 - 4, 3, array, v);
	switch (v)
	{
		case 1:
			break;
		case 2:
			Alignment_Patterns(18, 18, array);
			break;
		case 3:
			Alignment_Patterns(22, 22, array);
			break;
		case 4:
			Alignment_Patterns(26, 26, array);
			break;
		case 5:
			Alignment_Patterns(30, 30, array);
			break;
	}
	Timing_Patterns(array, v);
	version_patterns(array, v);



	return array;
}
//掩模
/*int mark_mask(QRarray **array, int mode, int v)
{
int mark = 0;
switch (mode)
{
case 0:
for (int i = 0; i < (v - 1) * 4 + 21; i++)
for (int j = 0; j < (v - 1) * 4 + 21; j++)
{
if ((i + j) % 2 == 0 && array[i][j].ocu == 0)
{
if (array[i][j].col == 0)
array[i][j].col = 1;
else
array[i][j].col = 0;
}
}

break;
case 1:
for (int i = 0; i < (v - 1) * 4 + 21; i++)
for (int j = 0; j < (v - 1) * 4 + 21; j++)
{
if (i % 2 == 0 && array[i][j].ocu == 0)
{
if (array[i][j].col == 0)
array[i][j].col = 1;
else
array[i][j].col = 0;
}
}

break;
case 3:
for (int i = 0; i < (v - 1) * 4 + 21; i++)
for (int j = 0; j < (v - 1) * 4 + 21; j++)
{
if (j % 3 == 0 && array[i][j].ocu == 0)
{
if (array[i][j].col == 0)
array[i][j].col = 1;
else
array[i][j].col = 0;
}
}

break;

}

}
unsigned char* mask(QRarray **array,int v)
{
for (int i = 0; i < (v - 1) * 4 + 21; i++)
for (int j = 0; j < (v - 1) * 4 + 21; j++)
{
if ((i + j) % 2 == 0)
{
if (array[i][j].col == 0)
array[i][j].col = 1;
else
array[i][j].col = 0;
}
}
}*/
//掩模纠错码
//填充纠错级别，掩模信息码
QRarray **cor_mask_bit(unsigned char *data, QRarray **array, int v)
{
	for (int i = 0; i < 6; i++)
		array[i][8].col = (unsigned int)(data[i]);
	for (int i = 0; i < 8; i++)
		array[8][(v - 1) * 4 + 21 - 1 - i].col = unsigned int(data[i]);
	array[7][8].col = (unsigned int)data[6];
	array[8][8].col = (unsigned int)data[7];
	array[8][7].col = (unsigned int)data[8];
	for (int i = 0; i < 6; i++)
		array[8][i].col = (unsigned int)data[14 - i];
	for (int i = 0; i < 7; i++)
		array[(v - 1) * 4 + 21 - 1 - i][8].col = (unsigned int)data[14 - i];
	return array;
}