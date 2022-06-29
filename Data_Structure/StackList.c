//单栈链表
#include <stdio.h>
#include <stdlib.h>
#define MAXLONG 1000
typedef int SElemType;
typedef struct
{
	SElemType Data[MAXLONG];
	int top;
} StackList;
// 初始化栈
int InitializationList(StackList * List)
{
	int Cur;
	for (Cur = 0; Cur < MAXLONG - 1; Cur++)
	{
		List->Data[Cur] = -1;
	}
	List->top = 0;
	return 1;
}

// 获取栈顶
int GetTop(StackList List, SElemType * e)
{
	if (List.top == -1)
	{
		puts("栈内无数据");
		return 0;
	}
	e = &List.Data[List.top];
	return 1;
}

// 判断栈是否为空
int StackEmtype(StackList List)
{
	if (List.top == -1)
		return 0;
	else
		return 1;
}

// 压入栈
int PushList(StackList * List, SElemType e)
{
	if (List->top == MAXLONG - 1)
	{
		printf("栈已经满,无法压入数据\n");
		return 0;
	}
	else
	{
		List->Data[List->top + 1] = e;
		++List->top;
		return 1;
	}
}

// 弹出top
int PopList(StackList * List)
{
	int D;
	if (List->top == -1)
	{
		printf("栈内无数据,无法弹出");
		return 0;
	}
	else
	{
		D = List->Data[List->top];
		--List->top;
		return D;
	}
}

// 清空栈
void ClearList(StackList * List)
{
	int i = 0;
	if (List->top == -1)
		return 0;
	else
	{
		for (; i <= List->top; List->top--)
			List->Data[List->top] = 0;
		List->top=-1;
	}
	
	return 0;
}
//获取栈长度
int StackLenght(StackList List){
	if(List.top==-1)
	return 0;
	return List.top+1;
	}
// main
int main(void)
{
	char a;
	SElemType Enter;
	StackList SList;
	StackList *PList;
	PList = &SList;
	int count = 0,l;
	InitializationList(&SList);
	printf("输入你要存入数(空格隔开)");
	while (scanf("%d", &Enter))
	{
		SList.Data[count] = Enter;
		a = getchar();
		if (a == '\n')
		{
			SList.top = count;
			break;
		}
		count++;
	}
	GetTop(SList, PList);
	printf("%d\n", Enter);
	PushList(PList, 6);
	Enter = PopList(PList);
	printf("%d\n", Enter);
	ClearList(PList);
	printf("%d\n",SList.top);
	printf("%d",StackLenght(SList));
	return 0;
}