

/**
 *                             _ooOoo_
 *                            o8888888o
 *                            88" . "88
 *                            (| -_- |)
 *                            O\  =  /O
 *                         ____/`---'\____
 *                       .'  \\|     |//  `.
 *                      /  \\|||  :  |||//  \
 *                     /  _||||| -:- |||||-  \
 *                     |   | \\\  -  /// |   |
 *                     | \_|  ''\---/''  |   |
 *                     \  .-\__  `-`  ___/-. /
 *                   ___`. .'  /--.--\  `. . __
 *                ."" '<  `.___\_<|>_/___.'  >'"".
 *               | | :  `- \`.;`\ _ /`;.`/ - ` : | |
 *               \  \ `-.   \_ __\ /__ _/   .-` /  /
 *          ======`-.____`-.___\_____/___.-`____.-'======
 *                             `=---='
 *          ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 *                     佛祖保佑        永无BUG
 *            佛曰:
 *                   写字楼里写字间，写字间里程序员；
 *                   程序人员写程序，又拿程序换酒钱。
 *                   酒醒只在网上坐，酒醉还来网下眠；
 *                   酒醉酒醒日复日，网上网下年复年。
 *                   但愿老死电脑间，不愿鞠躬老板前；
 *                   奔驰宝马贵者趣，公交自行程序员。
 *                   别人笑我忒疯癫，我笑自己命太贱；
 *                   不见满街漂亮妹，哪个归得程序员？
*/		
	// 解析器;
#include"exec.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INSMAX 100				// 指令最大个数
int main(void)
{
	vm *exe;
	struct vm_instruction vm_ins[INSMAX];
	int VM_size = 0, Str_size = 0;
	char a;
	char str[30];
	while (str[Str_size] = getchar())
	{

		// 赋值
		if (str[Str_size] == '=')
		{


			vm_ins[VM_size].opcode = GO;
			++Str_size;
			while ((str[Str_size] = getchar()))
			{
				if (str[Str_size] == ';')
				{
					str[Str_size] = '\0';
					char *copystr = malloc(sizeof(char) * Str_size);
					int a;
					for (a = 0; str[a] != '\0'; a++)
						copystr[a] = str[a];
					vm_ins[VM_size].operand = copystr;
					a = 0;
					str[0] = '\0';
					Str_size = -1;
					VM_size += 1;
					while ((a = getchar()) && a != '\n');
					break;
				}
				++Str_size;
			}
		}
		if (str[Str_size] == '.')
		{
			/*============各种指令判断=============*/
			str[Str_size] = '\0';
			// 打印
			if (strcmp(str, "print") == 0 || strcmp(str, "PRINT") == 0)
			{
				vm_ins[VM_size].opcode = PRINT;
				str[0] = '\0';
				Str_size = 0;
				while ((str[Str_size] = getchar()))
				{
					if (str[Str_size] == ';')
					{
						str[Str_size] = '\0';
						char *copystr = malloc(sizeof(char) * Str_size);
						int a;
						for (a = 0; str[a] != '\0'; a++)
							copystr[a] = str[a];
						vm_ins[VM_size].operand = copystr;
						a = 0;
						str[0] = '\0';
						Str_size = -1;
						VM_size += 1;
						while ((a = getchar()) && a != '\n');
						break;
					}
					++Str_size;
				}
			}
			// 计算
			if (strcmp(str, "add") == 0 || strcmp(str, "ADD") == 0)
			{
				vm_ins[VM_size].opcode = ADD;
				str[0] = '\0';
				Str_size = 0;
				while ((str[Str_size] = getchar()))
				{
					if (str[Str_size] == ';')
					{
						str[Str_size] = '\0';
						char *copystr = malloc(sizeof(char) * Str_size);
						int a;
						for (a = 0; str[a] != '\0'; a++)
							copystr[a] = str[a];
						vm_ins[VM_size].operand = copystr;
						a = 0;
						str[0] = '\0';
						Str_size = -1;
						VM_size += 1;
						while ((a = getchar()) && a != '\n');
						break;
					}
					++Str_size;
				}
			}
			// 
		}
		// 变量定义;
		else if (str[Str_size] == ' ')
		{
			str[Str_size] = '\0';

			if (strcmp(str, "const") == 0 || strcmp(str, "CONST") == 0)
			{
				vm_ins[VM_size].opcode = CONST;
				str[0] = '\0';
				Str_size = 0;
				while ((str[Str_size] = getchar()))
				{
					if (str[Str_size] == ';')
					{
						str[Str_size] = '\0';
						char *copystr = malloc(sizeof(char) * Str_size);
						int a;
						for (a = 0; str[a] != '\0'; a++)
							copystr[a] = str[a];
						vm_ins[VM_size].operand = copystr;
						a = 0;
						str[0] = '\0';
						Str_size = -1;
						VM_size += 1;
						while ((a = getchar()) && a != '\n');
						break;
					}
					++Str_size;
				}
			}
		}
		else if (str[Str_size] == ';')
		{
			// *********结束***********
			str[Str_size] = '\0';
			if (strcmp(str, "END") == 0 || strcmp(str, "end") == 0)
				vm_ins[VM_size].opcode = END;
			break;
		}
		++Str_size;
	}
	// 结构测试
	int k = 0;
	for (k = 0; k < 8; k++)
		printf("\n%d,,,,%s\n", vm_ins[k].opcode, (char *)vm_ins[k].operand);
	// 运行代码
	//stack_vm(exe);
	//Initialization_stack(vm_ins, exe);
	return 0;
}