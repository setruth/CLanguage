
#include <stdio.h>
#include <stdlib.h>
typedef int SElemType;
typedef struct Node
{
	SElemType Data;
	struct Node *Next;
} Node, *PNode;
typedef struct
{
	PNode Top;
	int Count;
} StackList;
// 压栈
int PushList(StackList * List, SElemType e)
{
	PNode NNode = (PNode) malloc(sizeof(Node));
	NNode->Data = e;
	NNode->Next = List->Top;
	List->Top = NNode;
	++List->Count;
	return 1;
}

PopList(StackList * List, int *e)
{
	int Result;
	PNode *PL;
	if (List->Count == -1)
		return -1;
	*e =List->Top->Data;
	PL=List->Top;
	List->Top = List->Top->Next;
	free(PL);
	--List->Count;
	return List->Count;
}

// main
int main(void)
{
	StackList DList;
	int Enter, Out, Cur;
	char a;
	DList.Top = NULL;
	DList.Count = -1;
	while (scanf("%d", &Enter) == 1)
	{
		PushList(&DList, Enter);
		a = getchar();
		if (a == '\n')
		{
			break;
		}
	}
	//printf("%d\n", DList.Top->Next->Data);
	while (1)
	{
		Cur = PopList(&DList, &Out);
		printf("%d ", Out);
		if (Cur == -1)
			break;
	}
	puts("");
	return 0;
}