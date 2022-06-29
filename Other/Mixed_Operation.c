/*=============计算器===========*/
/***
核心: *你输入的表达式比如1+1运算符号两边一定有运算的数据所以只用找到运算符,判断是什么运算符,然后再用运算符相邻的两个元素进行运算得出答案村给那个运算符的下一个元素然后再找下一个运算符进行与之前相同的计算方法最后把答案传到最后一个元素也就是计算完毕最后打印最后一个元素即可得到答案*
****/

#include<stdio.h>
#include<stdlib.h>
/* 最长的输入当然这里是指数字加上运算符的总数
   所以其实只能输入8个数计算 */
#define max 15
/**
*函数名:get_expression;
*保存把用户输入的公式存进来例如1+1
存入为exp[0]=1,exp[1]=+,exp[2]=1;	  *函数参数为一个char类型数组大小为max*函数作用:直接对主函数保存公式的数组赋值 并且计算数组大小;
*函数结果:返还一个int型的数据   数据为用户输入的运算符加上数字的长度(max只是最大可输入的限制实际上输入的已返回的数据为准);
****/
int get_expression(char expression[max])
{
	int count = 0;				// 计数
	char enter = '\0';
	while ((enter = getchar()) != EOF && enter != '\n')	// 如果为换行则结束获取赋值
	{
		expression[count] = enter;
		count++;
	}
	return count;
}

/*===========主函数============*/
int main(void)
{
	char expression[max];		// 定义存入表达式的数组大小为max
	int count, conversion;		// 计数与临时存储计算出的数据
	puts("输入你的表达式(不支持负数)再八位数之间");
	
	 int size = get_expression(expression);
	// 获取表达式长度大小
	for (int a = 0; a < size; a++)
		printf("%c", expression[a]);	// 打印表达式
	printf("你这个表达式的答案是:");
	// 进入循环计算
	for (count = 0; count < size; count++)
	{
		if (expression[count] == '-')	// 如果当前元素是减号
		{
			conversion = (expression[count - 1] - '0') - (expression[count + 1] - '0');	// 把上一个元素与下一个元素转换为int类型然后计算得答案保存在临时的储存变量中
			expression[count + 1] = (conversion + '0');	// 然后再把临时储存的变量转换回int型赋给当前元素元素的下一个元素(也就是count+1)
		}
		else if (expression[count] == '+')
		{
			conversion = (expression[count - 1] - '0') + (expression[count + 1] - '0');	// 把上一个元素与下一个元素转换为int类型然后计算得答案保存在临时的储存变量中
			expression[count + 1] = (conversion + '0');	// 然后再把临时储存的变量转换回int型赋给当前元素元素的下一个元素(也就是count+1)
		}
	}
	printf("%c", expression[size - 1]);	// 最后打印数组的最后一个元素也就是最终算出的答案;
}
//