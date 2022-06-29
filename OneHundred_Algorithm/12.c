// 判断Start到End之间的素数╭(๑´^`๑)╮别输入负数 那块还没弄
// 
#include<stdio.h>
int main(void)
{
	int Start, End, i, Count = 0;
	printf
		("\033[;31m你想求多少之间有多少个素数 范围用空格隔开\n例如\033[;32m(20 100)\033[0m\033[;31m:\033[0m");
	scanf("%d %d", &Start, &End);
	printf("\033[;32m%d\033[0m到\033[;32m%d\033[0m的素数有:\n", Start, End);
	for (; Start <= End; Start++)
	{
		 for (i = 2; i <=Start; i++)
		{
			if (Start % i == 0)
				break;
		}
		if(Start<=i){
			++Count;
			printf("\033[;36m%d   \033[0m", Start);
			if(Count%7==0)
			puts("");
			}
	}
	printf("\n素数一共有\033[;32m%d\033[0m个",Count);
	return 0;
}