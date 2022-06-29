// 虚拟机
#include<stdio.h>
#include<stdlib.h>
// 代码指令
#define CONST 1					/* 定义变量 */
#define GO    2					/* 赋值 */
#define ADD   3					/* 计算 */
#define PRINT 4					/* 打印 */
#define END   5					/* 结束 */
				// 指令结构
struct vm_instruction
{								// 虚拟机指令结构
	int opcode;					// 操作码
	
	void *operand;				// 操作码数
};

typedef struct					// 静态栈
{
	void *stack;				// 栈堆
	int sp;						// 栈顶
} vm;

void stack_vm(vm * stack);		
// 初始化
int Initialization_stack(struct vm_instruction *code, vm * spstack);
// 执行器