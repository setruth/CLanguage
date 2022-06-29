//打印个楼梯试试
#include<stdio.h>
const char a = '@';
const char b = '#';
int main(void)
{
	int i, j;
	printf("%c%c\n", a, a);
	for (i = 1; i < 15; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%c%c", b, b);
		}
		printf("\n");
	}
	return 0;
}