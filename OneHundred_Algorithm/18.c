/* 求s=a+aa+aaa+aaaa+aa...a的值,其中a是一个数字.
   例如2+22+222+2222+22222(此时共有5个数相加) */
// 两种算法
#include<stdio.h>
void one(void)
{
	int a, b = 0, n, d;
	int r = 0;
	printf("输入a和n空格隔开:");
	scanf("%d %d", &a, &n);
	b = a;
	if (n == 1)
		printf("%d", a);
	while (n > 1)
	{

		b = a + b * 10;
		r += b;
		--n;
	}

	printf("a+aa+aaa...等于:%d", r + a);
}

int two()
{
	int a, b = 0, n, d;
	int r = 0;
	printf("输入a和n空格隔开:");
	scanf("%d %d", &a, &n);
	b = a;
	while (n > 0)
	{
		r += b;
		b = a + b * 10;
		--n;
	}

	printf("a+aa+aaa...等于:%d", r);
}

int main(void)
{
	two();						// 第一种
	// one(); /;第二种
	return 0;
}


