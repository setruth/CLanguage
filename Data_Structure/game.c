#include <stdio.h>
#include "set_color.h"
typedef struct number
{
	int a;
	int b;
	int c;
	int d;
	int e;
} result;
void P(int a[30])
{
	int i;
	for (i = 0; i < 30; i++)
	{
		if (i == 15)
			break;
		printf( COLOR_SET("%d,", B_WT, F_PL), a[i]);
	}
	printf("\n\n");
}

int calculate(result n)
{
	int re = 0;
	if (n.a == 1)
		re += 1;
	if (n.b == 1)
		re += 2;
	if (n.c == 1)
		re += 4;
	if (n.d == 1)
		re += 8;
	if (n.e == 1)
		re += 16;
	return re;
}

int main(void)
{
	char enter, begin;
	char a;
	result n;
	int A[30] = { 3, 5, 19, 15, 1, 21, 17, 7, 27, 9, 11, 25, 23, 29, 13 };
	int B[30] = { 22, 18, 14, 30, 19, 6, 23, 3, 7, 10, 27, 2, 26, 11, 15 };
	int C[30] = { 6, 21, 7, 14, 12, 22, 4, 20, 29, 28, 23, 15, 13, 30, 5 };
	int D[30] = { 12, 24, 30, 28, 9, 14, 25, 27, 15, 8, 26, 29, 10, 11, 13 };
	int E[30] = { 19, 27, 16, 21, 22, 26, 20, 17, 18, 24, 29, 25, 23, 30, 28 };
	int i;
	printf(COLOR_SET("  这里有A,B,C,D,E五组数,心中想一个30以内的正整数,回答我几句话,看看我能猜出来不,以开发者的名誉保证,我不会遍历他们来找你的数,并且我只会用一个巧妙的式子算出来\n\n",B_WT,F_RD));
	printf("A:");
	P(A);
	printf("B:");
	P(B);
	printf("C:");
	P(C);
	printf("D:");
	P(D);
	printf("E:");
	P(E);
	
	printf("\n想好那个数了吗(y/n):");
	a = getchar();
	scanf("%c", &begin);
	printf("问题1:它在不在A数列里面(y/n):");
	scanf("%c", &enter);
	a = getchar();
	if (enter == 'y')
		n.a = 1;
	else
		n.a = 0;
	printf("问题2:它在不在B数列里面(y/n):");
	scanf("%c", &enter);
	a = getchar();
	if (enter == 'y')
		n.b = 1;
	else
		n.b = 0;
	printf("问题1:它在不在C数列里面(y/n):");
	scanf("%c", &enter);
	a = getchar();
	if (enter == 'y')
		n.c = 1;
	else
		n.c = 0;
	printf("问题1:它在不在D数列里面(y/n):");
	scanf("%c", &enter);
	a = getchar();
	if (enter == 'y')
		n.d = 1;
	else
		n.d = 0;
	printf("问题1:它在不在E数列里面(y/n):");
	scanf("%c", &enter);
	a = getchar();
	if (enter == 'y')
		n.e = 1;
	else
		n.e = 0;
	printf("很高兴你能配合我,你想的是%d对吧", calculate(n));
	return 0;

}
