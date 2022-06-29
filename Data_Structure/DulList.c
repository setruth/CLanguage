#include<stdio.h>
#include<stdlib.h>
int ListLong = 1;
struct DulNode
{
	int Date;					// 数据域
	struct DulNode *Next;		// 下一个节点
	struct DulNode *Prior;		// 上一个节点
} DulNode, *HeadNode;
// **********************************************************
/* 函数作用:打印链表 */
/* 参数条件:head为一个指向链表头节点的指针 */
/* 结果:打印成功返回1否则返回0 */
int PrintList(struct DulNode *Head)
{
	int a = 0;					// 循环
	struct DulNode *Middle;	// 指向链表节点指针
	if (Head == NULL)			// 如果链表为空
		return 0;				// 打印失败
	Middle = Head;				// 使middle指向把链表头地址
	for (;;)
	{							// 循环count次(并没什么用)
		if (Middle == NULL)		// 如果当前的结构是空 则返回1
			break;
		printf("%d  ", Middle->Date);	// 打印结构的数据域
		Middle = Middle->Next;	// 指向下一个节点
	}
	return 1;
}
int InsertNode(void)
{
	struct DulNode *TemporaryNode,*Node;
	// 临时节点(要插入的那个节点)
	int Size,Date,Count;
	char a;
	printf("输入你要插入的数据以及插入的位置:");
	scanf("%d %d",&Date,&Size);
	while ((a = getchar()) != EOF && a != '\n');
	if (HeadNode == NULL || Size>ListLong) 
		return 0;
	Node=HeadNode;
	if(Size==1)
	{
	TemporaryNode=malloc(sizeof(struct DulNode));
	TemporaryNode->Date=Date;
	TemporaryNode->Next=Node;
	Node->Prior=TemporaryNode;
	TemporaryNode->Prior=NULL;
	HeadNode=TemporaryNode;
	return 0;
		return 1;
		}
	for(Count=2;Count<Size;Count++){
		Node=Node->Next;
	}
		TemporaryNode=malloc(sizeof(struct DulNode));
		TemporaryNode->Date=Date;
		TemporaryNode->Next=Node->Next;
		TemporaryNode->Prior=Node;
		Node->Next->Prior=TemporaryNode;
		Node->Next=TemporaryNode;
	return 1;
	}
	// 主函数 
int main(void)
{
	struct DulNode  *TemporaryNode, *TailNode;
	HeadNode=NULL;
	int Enter;
	char a;
	puts("输入你要储存的数据每个用空格隔开");
	while (scanf("%d", &Enter) == 1)
	{
		//while ((a = getchar()) != EOF && a != '\n');
		TemporaryNode = malloc(sizeof(struct DulNode));
		if (HeadNode == NULL)
		{
			HeadNode = TemporaryNode;	// 头的下一个节点指向TempraryNode内存块
		  TemporaryNode->Prior = NULL;	// 头的上一个节点为空
		}
		else
		{
			TailNode ->Next = TemporaryNode;	// TailNode下一个节点指向TemporaryNode
			TemporaryNode->Prior = TailNode;	// TailNode的下一个节点(TemporaryNode)的prior指向自己
		}
		TemporaryNode->Date = Enter;
		TemporaryNode->Next = NULL;
		TailNode = TemporaryNode;
		ListLong++;
		a=getchar();
		if(a=='\n')
	           break;
	}
	PrintList(HeadNode);
	InsertNode();
	PrintList(HeadNode);
	return 0;
}