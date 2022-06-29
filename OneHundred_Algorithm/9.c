/* 原本是打印国际象棋棋盘的， 但是格子的编码有问题
   所以换了个判断输入的是原音还是福音字母的程序 */
#include<stdio.h>
const char Sounds[10] = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u' };
// 判断输入是不是原音字母
int a(char Enter)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (Sounds[i] == Enter)
			return 1;
	}
	return 0;
}
int main(void)
{
	char Enter;
	printf("输入你的字母并回车:");
	Enter = getchar();
	a(Enter) ? printf("原音字母哦") : printf("辅音字母哦");
}
//两个版本上面是我写的 咳咳
/*
#include <stdio.h>
int main()
{
    char c;
    int isLowercaseVowel, isUppercaseVowel; 
    printf("输入一个字母: ");
    scanf("%c",&c);
    // 小写字母元音
    isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    // 大写字母元音
    isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    // if 语句判断
    if (isLowercaseVowel || isUppercaseVowel)
        printf("%c  是元音", c);
    else
        printf("%c 是辅音", c);
    return 0;
}
*/