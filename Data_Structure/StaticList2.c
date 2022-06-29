// 静态线性表
#include<stdio.h>

#define MAXLONG 10000
struct NODE
{
	char End;					// 判断当前节点是否被应用
	// y为运用 y为未运用
	int Data;					// 数据域
	int Cur;					// 下标
} StaticLineList[MAXLONG];

// 初始化表
int InitializationList(struct NODE List[])
{
	int i;
	for (i = 0; i < MAXLONG - 1; )
	{
		List[i].End = '#';
		List[i].Data = 0;
		List[i].Cur = i + 1;
		i++;
	}
		List[MAXLONG - 1].Cur = 0;
		
	return 1;
}

// 从备用空间里申请一个空间
int REIdleStaticCur(struct NODE List[])
{
	int i;
	if (List[0].Cur)
	{
		i = List[0].Cur;
		List[0].Cur = List[i].Cur;
		return i;
	}
	else
	{
		return 0;
	}
}
//添加一个节点
int AddNode(struct NODE List[], int i, int d)
{
	int k, j, g = 1, a;
	k = MAXLONG - 1;
	// 插入位置是否违规
	if (i < 1 || i > ListLenght(List) + 1)
		return 0;
	// 新空间申请
	j = REIdleStaticCur(List);
	if (j == 0)
	{
		printf("表备用空间不足无法分配");
		return 0;
	}
	else if (i == 1)
	{
		List[j].End = 'y';
		List[j].Data = d;
		List[j].Cur = List[k].Cur;
		List[k].Cur = j;
		return 1;
	}
	else
	{
		List[j].End = 'y';
		List[j].Data = d;

		for (a = 1; a <= i - 1; a++)
			k = List[k].Cur;
		List[j].Cur=List[k].Cur;
		List[k].Cur=j;
		return 1;
	}

}

// 删除节点
void DeNode(struct NODE List[], int i)
{
	int k, g = 1, a;
	k = MAXLONG - 1;
	// 插入位置是否违规
	if (i < 1 || i > ListLenght(List) + 1)
		return 0;
	// 删除节点
	for (a = 1; a < i; a++)
	{
		k = List[k].Cur;
	}
	List[k].Cur = List[List[k].Cur].Cur;
	return 0;
}

// 获取链表长度
int ListLenght(struct NODE List[])
{
	int i = 1;
	int j = List[MAXLONG - 1].Cur;
	while (j)
	{
		j = List[j].Cur;
		i++;
	}
	return i;
}

// 打印列表
void PrintList(struct NODE List[])
{
	int i = MAXLONG - 1;
	int k = 1;
	while (k<50)
	{
		i = List[i].Cur;
		if (List[i].End == '#')
			break;
		printf("%d %d\n", List[i].Data, List[i].Cur);

		k++;
	}
}

int main(void)
{
	int Enter, NowLong, i, k = 0;
	char a;
	InitializationList(StaticLineList);
		PrintList(StaticLineList);
	printf("输入(空格隔开):");
	for (i = 1; i < MAXLONG - 1;)
	{
		scanf("%d", &Enter);
		StaticLineList[i].End = 'y';
		StaticLineList[i].Data = Enter;
		NowLong = i;
		i = StaticLineList[i].Cur;
		a = getchar();
		//printf("%d %d\n",StaticLineList[i].Data,StaticLineList[i].Cur);
		if (a == '\n')
		{
			StaticLineList[NowLong].Cur = 0;
			StaticLineList[0].Cur = i;
			StaticLineList[MAXLONG - 1].Cur = 1;
			break;
		}
	}
	PrintList(StaticLineList);
	AddNode(StaticLineList, 1, 10);
	puts("");
	PrintList(StaticLineList);
	AddNode(StaticLineList, 3, 9);
	puts("");
	PrintList(StaticLineList);
	puts("");
	DeNode(StaticLineList, 3);
	PrintList(StaticLineList);
}