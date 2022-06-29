// 因数分解
#include<stdio.h>
int main(void)
{
	int number;
	int i;
	printf("输入要因数分解的数");
	scanf("%d", &number);
	printf("%d=", number);
	for (i = 2; i <= number;)
	{
		if (number % i == 0)
		{
			printf("%d", i);
			if ((i / number) != 1)
				printf("*");
			number /= i;
			i = 2;
			continue;
		}
		i++;
	}
}
