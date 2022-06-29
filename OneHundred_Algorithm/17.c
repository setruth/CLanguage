/* 输入一行字符
   分别统计出其中英文字母、空格、数字和其它字符的个数 
   */
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int Letters = 0, Digits = 0, Space = 0, Others = 0;
	char a;
	printf("输入要解析的话:");
	while ((a = getchar()) && a != '\n')
	{
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
			++Letters;
		else if (a >= '0' && a <= '9')
			++Digits;
		else if (a == ' ')
			++Space;
		else
			++Others;
	printf("%c",a);
	fflush(stdin);
	}
	printf("\n这句话中有字母%d个,数字%d个,空格%d个,和其他符号%d个\n",Letters,Digits,Space,Others);
	return 0;
}
