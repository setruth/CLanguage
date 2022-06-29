//递归算5!/(ㄒoㄒ)/~~
#include<stdio.h>
long f(int i){
	if(i<1)
		return 1;
	return i*f(i-1);
	}
int main(void)
{
	int i;
	for(i=0;i<6;i++)
	{
		printf("%d!=%ld\n",i,f(i));
		}
	return 0;
	}