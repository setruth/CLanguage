/*
学习成绩>=90分的同学用A表示，
60-89分之间的用B表示，
60分以下的用C表示
复制的代码,太简单了不想写╮(‵▽′)╭
核心三目运算符
*/
#include<stdio.h>
int main()
{
	int score;
	char grade;
	printf("请输入分数： ");
	scanf("%d", &score);
	grade = (score >= 90) ? 'A' : ((score >= 60) ? 'B' : 'C');
	printf("%c\n", grade);
	return 0;
}
