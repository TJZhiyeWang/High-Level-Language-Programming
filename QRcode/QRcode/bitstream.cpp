#include "90-b4.h"
#include "cmd_console_tools.h"
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

	cdata = (unsigned char *)malloc(int((version+2)*8));
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
	for (i = 0; i < size; i++) {
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
	if (8 * (version + 2)-8 * size + 12  >0)
	{
		int stop = (8 * (version + 2) - 8 * size + 12)<4? (8 * (version + 2) - 8 * size + 12):4;
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
	data = (unsigned int *)malloc(int((size + 7) / 8*sizeof(unsigned int)));
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
BitStream *BitStream_tobit( polynomial L)
{
	unsigned char mask,*p;
	int i, j;
	BitStream *bstream;
	unsigned int *cdata;
	cdata = trans(L);
	bstream = BitStream_new();
	if (bstream == NULL) return NULL;

	if (BitStream_allocate(bstream, Node_count(L)-2)) {
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
unsigned char *BitStream_Union(BitStream *bstream, BitStream *obstream,int version)
{
	unsigned char *data,*p;
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
		data = (unsigned char*)malloc(bstream->length + obstream->length+7);
		p = data;
		memcpy(p, bstream->data, bstream->length);
		p = p + bstream->length;
		memcpy(p, obstream->data, obstream->length);
		char *zero,*m;
		zero = (char *)malloc(7);
		
		for (int i = 0; i < 7; i++)
		{
			zero[i] = 0;
		}
		p = p + obstream->length;
		memcpy(p, zero, 7);

	}
	return data;
}
