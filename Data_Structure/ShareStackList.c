//共享两个链表
#include <stdio.h>
#define MAXLONG 10000
typedef int SElemType;
typedef struct
{
	SElemType Data[MAXLONG];
	int Top1;
	int Top2;
} ShareStackList;
int InitializationList(ShareStackList * List)
{
	int i = -1;
	for (; i < MAXLONG - 1;)
	{
		++i;
		List->Data[i] = 0;
	}
	List->Top1 = -1;
	List->Top2 = MAXLONG / 2 - 1;
	return 1;
}

// PushList(L,data...size));
int PushList(ShareStackList * List, SElemType e, int size /* char str[] */ )
{
	if (size == 1)
	{
		if (List->Top1 + 1 == List->Top2)
		{
			if (List->Top2 == MAXLONG - 1)
			{
				printf("两个栈已满 无法再次存入数据\n");
				return 0;
			}
			List->Data[List->Top2 + 1] = e;
			++List->Top2;
			puts("栈一已满");
			printf("压入第二个栈\n");
			return 1;
		}
		List->Data[List->Top1 + 1] = e;
		++List->Top1;
		printf("压入第一个栈\n");
		return 1;
	}
	else
	{
		List->Data[List->Top2 + 1] = e;
		++List->Top2;
		printf("压入第二个栈\n");
		return 1;
	}
}

// 获取栈顶游标
int GetTopCur(ShareStackList * List, int size)
{
	int Result = size == 1 ? List->Top1 : List->Top2;
	return Result;
}

// 获取栈顶数据
int GetTop(ShareStackList * List, int *e, int size)
{
	if (List->Top1 == -1 || List->Top2 == 4999)
		return 0;
	else if (size == 1)
	{
		e = &List->Data[List->Top1];
		return 1;
	}
	else
	{
		e = &List->Data[List->Top2];
		return 1;
	}
}
//打印栈
void PrintList(ShareStackList * List, int size)
{
	int Count;
	if (size == 1)
	{
		Count = List->Top1;
		while (1)
		{
			if (Count == -1){
				puts("");
				break;
			}
			printf("%d ", List->Data[Count]);
			--Count;
		}
	}
	else
	{
		Count = List->Top2;
		while (1)
		{
			if (Count == MAXLONG / 2 - 1){
				puts("");
				break;
			}
			printf("%d ", List->Data[Count]);
			--Count;
		}

	}
}

// main
int main(void)
{
	ShareStackList SList;
	int Eenter, i = 1,Cur;
	InitializationList(&SList);
	char a;
	printf
		("初始化完成 输入一个数压栈,要选压入的栈空格隔开 例如(45 1)若不需要选则输入一个数回车即可:");
	scanf("%d", &Eenter);
	a = getchar();
	if (a == ' ')
	{
		scanf("%d", &i);
	}
	if (a == '\n')
		puts("你并未选择压入栈默认为栈1");
	PushList(&SList, Eenter, i);
	GetTop(&SList, &Eenter, i);
	Cur = GetTopCur(&SList, i);
	printf("存入的栈顶下标为%d\n", Cur);
	printf("存入的栈顶数据为%d\n", SList.Data[i]);
	PrintList(&SList,i);
	return 0;
}