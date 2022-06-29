//求1+2!+3!+...+20!的和
#include<stdio.h>
int main(void)
{
	long long sum=0,m=1;
	int i=1;
	while(i<21)
	{
		m*=i;
		sum+=m;
		++i;
		}
	printf("%ld",sum);
	return 0;
	}