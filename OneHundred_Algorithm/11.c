// 兔子数列也就是斐波那契数列
// 递归和普通算法两种
#include<stdio.h>
// 提示获取
int InPut(void)
{
	int Enter;
	printf("\033[;31m你想显示几个月的兔子:\033[0m");
	scanf("%d", &Enter);
	return Enter;
}

// 普通算法 最优的算法哦(͔▪̆ω▪̆)͕

int main(void)
{
	int Max = InPut();
	int i, a = 1, b = 1, c;
	if (Max == 1)
	{
		printf("第\033[;32m1\033[0m个月有\033[;36m1\033[0m对\n");
		return 0;
	}
	else if (Max == 2)
	{
		printf
			("第\033[;32m1\033[0m个月有\033[;36m1\033[0m对\n第\033[;32m2\033[0m个月有\033[;36m1\033[0m对\n");
		return 0;
	}
	printf
		("第\033[;32m1\033[0m个月有\033[;36m1\033[0m对\n第\033[;32m2\033[0m个月有\033[;36m1\033[0m对\n");
	for (i = 2; i < Max; i++)
	{
		c = a + b;
		printf("第\033[;32m%d\033[0m个月有\033[;36m%d\033[0m对\n", i + 1, c);
		a = b;
		b = c;
	}
	return 0;
}
//递归
/*
int Fibonacci(int i)
{
	if (i == 1 || i == 0)
		return 1;
	return Fibonacci(i-2)+Fibonacci(i-1);
}

int main(void)
{
	int Max = InPut();
	int i;
	for (i = 0; i < Max; i++)
		printf("第\033[;32m%d\033[0m个月有\033[;36m%d\033[0m对\n", i + 1, Fibonacci(i));
	return 0;
}
*/