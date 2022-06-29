// 打印出菱形
#include<stdio.h>
int main(void)
{
	int k, j, m = 1;
	for (k = 0; k < 20; k++)
	{
		for (j = 1; j < 21 - k; j++)
		{
			printf(" ");
		}
		for (m = -1; m < k * 2; m++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (; k > -1; k--)
	{
		for (j = 1; j < 21 - k; j++)
			printf(" ");
		for (m = -1; m < k * 2;m++)
			printf("*");
		printf("\n");
	}
}
