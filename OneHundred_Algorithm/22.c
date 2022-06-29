//1+2+3+4+...+100=？
//递归
#include<stdio.h>
int add(int i)
{
	if(i<1)
	return i;
	return add(i-1)+i;
	}
int main(void)
{
	int max=100;
	int result=0;
	result=add(100);
	printf("%d",result);
	return 0;
	}
