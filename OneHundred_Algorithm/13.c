// 水仙花数.这玩意写过好多遍了ㅍ_ㅍ
// 一个三位数各个位数立方和等于本身的数
#define MAX 1000
#include<stdio.h>
int main(void)
{
	int start, Count = 0;		// 开始数,计数数
	int a, b, c;
	for (start = 100; start < MAX; start++)
	{
		a = (int)(start / 100);	// 百位
		b = (int)(start / 10)-a*10;	// 十位
		c = start - a * 100 - b * 10;	// 个位
		if ((a * a * a + b * b * b + c * c * c) == start)
		{
		    ++Count;
			printf("水仙花数:%d\n", start);
		}
	}
	printf("一共有%d个水仙花数",Count);
	return 0;
}
