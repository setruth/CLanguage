//利用递归将输入的五个字符,以相反的顺序打印出来
#include<stdio.h>
void sort(int i)
{
	char next;
	if(i<=1){
		next=getchar();
		putchar(next);
	}
	else{
		next=getchar();
		sort(i-1);
		putchar(next);
		}
	}
int main(void)
{
	int i=5;
	printf("请输入五个字符\40:\40");
	sort(i);
	printf("\n");
	return 0;
	}