//有一分数序列：2/1，3/2，5/3，8/5，13/8，21/13...
//求出这个数列的前20项之和
#include<stdio.h>
int main(void)
{
    float a=1,b=2,sum=0,m;
    int i;
    for(i=0;i<20;i++)
    {
    	sum+=b/a;
    	m=b;
    	b=a+b;
    	a=m;
    	}
    printf("%f",sum);
    return 0;
	}