
//队列
#include <stdio.h>
#define MAXLONG 4
typedef struct QUEUE
{
	int Data[MAXLONG];
	int Heand;
	int Tail;
} queue;
// 初始化队列
int InitQueue(queue * q)
{
	q->Heand = 0;
	q->Tail = 0;
	return 1;
}

// 判断队列是否以满
int NowFull(queue q)
{
	if ((q.Tail + 1) % MAXLONG == q.Heand)
		return 1;
	else
	{
		return 0;
	}

}

// 获取队列的长度
int QueueLength(queue * q)
{
	if ((q->Tail) > (q->Heand))
		return (q->Tail - q->Heand);
	else if ((q->Tail) < (q->Heand))
		return (q->Heand + MAXLONG - q->Tail);
}

// 添加元素到队列中
int EnQueue(queue * q, int e)
{
	if (((q->Tail + 1) % MAXLONG) == q->Heand)
		return 0;
	q->Data[q->Tail] = e;
	q->Tail = (q->Tail + 1) % MAXLONG;
	return 1;
}

// 取出队列的元素
int DeQueue(queue * q, int *e)
{
	if ((q->Heand) == (q->Tail))
		return 0;
	*e = q->Data[q->Heand];
	q->Data[q->Heand] = -1;
	++q->Heand;
	return 1;
}

// 打印队列
int PrQueue(queue * q)
{

	int length = QueueLength(q);
	int i;
	if ((q->Heand) > (q->Tail))
	{
		for (i = (q->Heand); i < MAXLONG; i++)
			printf("%d ", q->Data[i]);
		for (i = 0; i < q->Heand - 1; i++)
			printf("%d ", q->Data[i]);
	}
	else
	{
		for (i = q->Heand; i < q->Tail; i++)
		{
			printf("%d ", q->Data[i]);
		}
	}
	return 1;
}

// star
int main(void)
{
	queue q;
	int Enter;
	int get;
	char a = '1';
	InitQueue(&q);
	printf("输入你要存的数(空格隔开):");
	while (a != '\n')
	{
		if (NowFull(q) == 1)
		{
			printf("队列已满,不能再存入\n");
			break;
		}
		else if (NowFull(q) == 0)
		{
			scanf("%d", &Enter);
			EnQueue(&q, Enter);
			a = getchar();
		}
	}
	PrQueue(&q);
	puts("");
	printf("当前队列头%d,尾%d \n", q.Heand, q.Tail);
	DeQueue(&q, &get);
	printf("取出放数:%d\n", get);
	printf("当前队列头%d,尾%d\n", q.Heand, q.Tail);
	PrQueue(&q);
	EnQueue(&q, 7);
	puts("\n存入7");
	printf("当前队列头%d,尾%d\n", q.Heand, q.Tail);
	// printf("%d %d %d %d\n", q.Data[0], q.Data[1], q.Data[2], q.Data[3]);
	PrQueue(&q);
	puts("");
	if (EnQueue(&q, 9) == 0)
		printf("队列已满,存入失败\n");
	printf("当前队列头%d,尾%d\n", q.Heand, q.Tail);
	PrQueue(&q);
	return 0;
}
