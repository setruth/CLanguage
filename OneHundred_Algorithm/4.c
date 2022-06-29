// 输入某年某月某日，判断这一天是这一年的第几天？
#include <stdio.h>
int Month(int M, int Y)
{
	int i = 1;
	int result = 0;
	for (; i < M; i++)
	{
		if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
			result = result + 31;
		else if (M == 4 || M == 6 || M == 9 || M == 11)
			result = 30 + result;
		else if (M == 2)
		{
			if (Y % 4 != 0)
				result = result + 28;
			else
				result = result + 29;
		}
		else
			result = result + 29;
	}
	return result;
}

int main(void)
{
	int Get_Years, Get_Month, Get_Day;

	printf("输入年月日用空格隔开:");
	scanf("%d %d %d", &Get_Years, &Get_Month, &Get_Day);
	printf("今天是%d的第%d天", Get_Years, Month(Get_Month, Get_Years)+Get_Day);
	return 0;
}