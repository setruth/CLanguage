				// 十进制的转换
#include<stdio.h>
#include<stdlib.h>
int binary_size(int binary)
{
	int count = 0;				// 计数 
	for (;;)
	{
		if (binary < 2)
		{
			count++;
			return count;
		}
		count++;
		binary = (int)binary / 2;
	}
}

/**   
      *计算二进制 循环计算一个十进制的数然后保存 数组的 
	 *第一个参数是你在主函数里面保存二进制用的数组
	 *第二个参数是你之前用binary算出的你二进制大小的数
	 *第三个参数为你输入的那个数 
**/
void output_binary(int *array, int size, int input)
{
	int remainder, count = 0;
	// 保存余数以及元素计数 
	size-=1;
	if (input == 0)
		{
			array[size] = 0;
			
		}
	for (count = 0; count<=size; size--)
	{
		if (input == 3)
		{
			array[size] = 1;
			array[--size] = 1;
			break;
		}
		else if (input == 2)
		{
			array[size] = 0;
			array[--size] = 1;
			break;
		}
		else if (input == 1)
		{
			array[size] = 1;
			break;
		}
		// 循环次数为二进制的大小 
		remainder = input % 2;	// 获取余数进行判断 
		if (remainder == 0)		// 如果没有余数那么这一位二进制数为1 
			array[size] = 0;
		else if (remainder == 1)	// 如果没有余数那么这一位二进制数为0 
			array[size] = 1;
		input =(int) (input / 2);		// 保存除后的数 
	}
	// 计算二进制函数结束 
}

int main(void)
{
	int *binary;				// 保存二进制
	int result[100];
	int enter, size;			// 保存用户输入的数字以及二进制的位数 
								// 
	// 
	// 
	char empty;					// 清空缓冲区 

	while (1)
	{
		printf("输入你要转换为二进制计算的数:");
		scanf("%d", &enter);
		while ((empty = getchar()) != EOF && empty != '\n');	// 清空缓冲区
		// 如果输入的数小于等于2则二进制为0;
		if (enter < 0)
		{
			puts("兄得你输了个什么鬼?负数?");
			exit(EXIT_FAILURE);
		}
	/** 
	 每次除以2假如得出的商比二小则判断商为0or1最后倒序排列存入binary
	 得出计算出的二进制
	 */
		// output_binary(*binary,enter); 
		size = binary_size(enter);
		printf("%d\n",size);
	//	binary = (int *)malloc(size * sizeof(int));
		binary=result;
		output_binary(binary, size, enter);
		for (int a = 0; a <size; a++){
			if(binary[a]=='\0')
			break;
			printf("%d", binary[a]);
		}
			puts("");
		free(binary);
	}
	return 0;
}