/* 一个数如果恰好等于它的因子之和,这个数就称为"完数".
   例如6=1＋2＋3.编程找出1000以内的所有完数. */

#include<stdio.h>
/* 当时看错题目,搞了一下午意外弄出的产物,就当买一送一了;
   判断1-1000内一个数的因数分解出来的数相加是否等于他; */
/* 
   int main(void) { int max = 1000, d; int i, c, sum = 0; for (i = 2; i <
   1000; i++) { d = i; for (c = 1; c <= d;) { if (d % c == 0) { d = d / c; sum 
   += c; c = 2; continue; } ++c; } if (sum == i) printf("%d\n", sum); sum = 0;
   } printf("\n结束"); } */
/* 正文 */
int main(void)
{
	int max = 100;
	int i=6, b, sum = 0, a;
	printf("1-1000内的完数\n");
	for (i = 1; i < max; i++)
	{
		b = i;
		for (a = 1; a <b;)
		{
			if (b % a == 0)
			{
				sum +=a;
				++a;
				continue;
			}
			++a;
		}
		if (sum == i)
			printf("%d\n", i);
		sum=0;
	}
	return 0;
}

