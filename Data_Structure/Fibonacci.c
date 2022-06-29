//斐波那契数列
#include<stdio.h>
#include<stdlib.h>
//普通写法
/*
int main(void)
{
	int l;
	printf("你想显示多少个斐波那契数列:");
	scanf("%d",&l);
	int str[l+1];
	int i,a; 
	str[0]=0;
	str[1]=1;
	for(i=2;i<=l;i++){
		str[i]=str[i-1]+str[i-2];
	}
	for(a=1;a<i;a++)
		printf("%d ",str[a]);
return 0;
}*/
//递归
//递归函数
int Fbi(int i)
{
	if(i<2)
		return i==0 ? 0:1;
	return Fbi(i-1)+Fbi(i-2);
}
int main(void){
	int a,b;
	printf("你想显示多少个斐波那契数列:");
	scanf("%d",&b);
	for(a=1;a<=b;a++)
		printf("%d, ",Fbi(a));
	return 0;
}