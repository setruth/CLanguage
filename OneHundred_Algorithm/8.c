//99乘法表 (｀・ω・´)
#include<stdio.h>
int main(void)
{
	int a,b;
	for(a=1;a<=9;a++){
		for(b=1;b<=a;b++){
		printf("%d¡Á%d=%d ",b,a,b*a);
		}
		puts("");
	}
return 0;
}

