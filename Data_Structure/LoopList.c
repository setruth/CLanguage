// 循环动态链表
#include<stdio.h>
#include<stdlib.h>

struct NODE
{
	int Data;
	struct NODE *Next;
} *Head;
void PrintList(struct NODE *Head){
	int k=0;
	while(1){
		printf("%d ",Head->Data);
		if(Head->Next==NULL)break;
		Head=Head->Next;
		}
	}
int main(void)
{
	struct NODE *Middle, *Tail;
	int Enter;
	char a;
	Head = NULL;
	printf("输入数据(空格隔开):");
	while (1) 
	{
		scanf("%d",&Enter);
		Middle = (struct NODE *)malloc(sizeof(struct NODE));
		if (Head == NULL)
		{
			Head= Middle;
			Head->Next=NULL;
		}
		else{
			Tail->Next= Middle;
		}
		Middle->Data=Enter;
		Middle->Next=NULL;
		Tail=Middle;
		a = getchar();
		if (a == '\n')
			break;
	}
	Tail->Next=Head;
	PrintList(Head);
}