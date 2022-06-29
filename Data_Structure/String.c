//暴力匹配
#include <stdio.h>
#define MAXLONG 30

int StrLenght(char S[])
{
	char now = '1';
	int len = 0;
	while (1)
	{
		now = S[len];
		if (now == '\0')
			return len;
		++len;
	}
}

int Index(char S[MAXLONG], char T[MAXLONG])
{
	int len_1 = StrLenght(S);
	int len_2 = StrLenght(T);
	printf("第一个长%d\n第二个长%d\n",len_1,len_2);
	int i = 0, j = 0;
	while (1)
	{
		if (S[i] == T[j])
		{
			++j;
			++i;
		}
		else
		{
			++i;
			j = 0;
		}
		if (j == len_2 )
			return i - j+1;

	}
}

int main()
{
	char a[MAXLONG];
	char b[MAXLONG];
	char c;
	printf("输入第一个:");
	c=getchar();
	scanf("%s",a);
	printf("\n输入第二个;");
	scanf("%s",b);
	int size=Index(a,b);
	printf("第%d个位置后是%s",size,b);
	return 0;
	}
