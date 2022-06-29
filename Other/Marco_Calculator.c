#include<stdio.h>
#define PI  3.14
#define Sum(a,b) (a+b)
#define Division(a,b) (a/b)
#define Multiply(a,b) (a*b)
#define RoundArea(r) (r*r*PI)
#define Subtraction(a,b) (a-b)
int main(void)
{
	int Enter;
	float a, b, r, Result;
	char k;
	printf("              ***************************** \n"
		   "              *   1.对应加法  2.对应减法  * \n"
		   "              *   3.对应乘法  4.对应除法  * \n"
		   "              *       5对应圆面积计算     * \n"
		   "              *    输入对应编号进入计算   * \n"
		   "              *****************************\n");
	for(;;){
	printf("              你想进行什么运算(输入序号):");
	scanf("%d", &Enter);
	while ((k = getchar()) != EOF && k != '\n');
	switch (Enter)
	{
	case 1:
		printf("              输入两个数,空格隔开计算,他们的和:");
		scanf("%f %f", &a, &b);
		while ((k = getchar()) != EOF && k != '\n');
		Result = Sum(a, b);
		break;
	case 2:
		printf("              输入两个数,空格隔开计算,他们的减:");
		scanf("%f %f", &a, &b);
		while ((k = getchar()) != EOF && k != '\n');
		Result = Subtraction(a, b);
		break;
	case 3:
		printf("              输入两个数,空格隔开计算他们的乘:");
		scanf("%f %f", &a, &b);
		while ((k = getchar()) != EOF && k != '\n');
		Result = Multiply(a, b);
		break;
	case 4:
		printf("              输入两个数,空格隔开计算他们的除:");
		scanf("%f %f", &a, &b);
		while ((k = getchar()) != EOF && k != '\n');
		Result = Division(a, b);
		break;
	case 5:
		printf("              输入圆的半径,计算它的面积:");
		scanf("%f", &r);
		while ((k = getchar()) != EOF && k != '\n');
		Result = RoundArea(r);
		break;
	default:
		puts("              未输入任何对应序号");
		break;
	}
	printf("              最后结果:%f\n", Result);
	Result=0;
	}
	return 0;

}