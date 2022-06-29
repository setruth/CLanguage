#include<stdio.h>
#define AND(a,b) ((a&b)&1)
#define OR(a,b) ((a|b)&1)
#define NOT(a) ((~a)&1)
int main(void)
{
	printf("%d\n",AND(1,0));
	printf("%d\n",AND(1,1));
	printf("%d\n",AND(0,0));
	puts("");
	printf("%d\n",OR(1,0));
	printf("%d\n",OR(0,0));
	printf("%d\n",OR(1,1));
	puts("");
	printf("%d\n",NOT(1));
	printf("%d\n",NOT(0));
	return 0;
	}