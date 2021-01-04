/*1553449 王志业 3班*/
#include "90-b4.h"
#include "cmd_console_tools.h"
int main()
{

	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	QRarray **array;
	/*输入信息，构建信息比特流*/
	unsigned char *bit_mess;
	BitStream *bstream, *obstream;
	cout << "输入要转换为二维码的信息（100字符以内，纠错级别L)：";
	char me[100], utf[100];
	cin.get(me, 100);
	GBKToUTF8(me, utf);
	unsigned char mess[100];
	for (int i = 0; i < strlen(utf) + 1; i++)
	{
		mess[i] = (unsigned char)utf[i];
	}
	int version;
	version = choose_version(strlength(mess));
	array = QRcode(version);
	int v = ver_to_size(version);
	bstream = BitStream_newFromBytes(version, strlength(mess), mess);//转化为01比特流
	unsigned int *mess_data;
	mess_data = BitStream_toByte(bstream);
	polynomial La;
	InitList(&La);
	La = messege(version, mess_data, version + 2);
	ListTraverse(La);
	La = correct(La, version + 2, version);
	ListTraverse(La);
	obstream = BitStream_tobit(La);
	bit_mess = BitStream_Union(bstream, obstream, version);
	array = QRcode(version);
	data_patterns(array, ver_to_size(version), bit_mess);
	unsigned char mask_data[] = { 1,1,1,1,0,1,0,0,0,1,1,0,0,1,1 };
	for (int i = 0; i < (v - 1) * 4 + 21; i++)
		for (int j = 0; j < (v - 1) * 4 + 21; j++)
		{
			if ((i / 2 + j / 3) % 2 == 0 && array[i][j].ocu == 0)
			{
				if (array[i][j].col == 0)
					array[i][j].col = 1;
				else
					array[i][j].col = 0;
			}
		}
	cor_mask_bit(mask_data, array, v);
	output(hout, array, ver_to_size(version));

	BitStream_free(bstream);
	BitStream_free(obstream);
	free(mess_data);
	free(bit_mess);
	delete[]array;
	DestroyList(&La);
	system("pause");
	return 0;
}