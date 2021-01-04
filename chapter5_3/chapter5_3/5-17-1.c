/*1553449 王志业 3班*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define num 10
int main()
{
	char name[num][9];  
	int stunum[num];        
	int grade[num];
	int i;
	for (i = 0; i<num;i++ )
	{
		printf("请输入第%d个人的姓名、学号、成绩\n", i + 1);
		scanf("%s%d%d", &name[i], &stunum[i], &grade[i]);
	}
	printf("\n不及格名单：\n");
	for (i = 0; i < num; i++)
	{
		if (grade[i] < 60)
			printf("%s %d %d", name[i], stunum[i], grade[i]);
	}
	return 0;
}
