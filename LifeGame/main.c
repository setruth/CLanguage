/*
By:Setruth
Email:1607908758@qq.com
*/
#include "color_set.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define WIDTH 42
#define HEIGHT 30
#define CLEAR() printf("\033[2J");
void Init(_Bool(*m)[WIDTH])
{
	int r = time(NULL);
	int i, b;
	for (i = 0; i < HEIGHT; i++)
	{
		for (b = 0; b < WIDTH; b++)
		{
			srand(r);
			m[i][b] = rand() % 2;
			++r;
		}
		b = 0;
	}
}

int Pmap(_Bool(*m)[WIDTH])
{

	int i, b;
	int live=0;
	for (i = 0; i < HEIGHT; i++)
	{
		for (b = 0; b < WIDTH; b++)
		{
			if (m[i][b] == 0)
				printf(COLOR_STR("□", B_WT, F_BK));
			else if (m[i][b] == 1){
				++live;
				printf(COLOR_STR("■", B_WT, F_BK));
			}
		}
		puts("");
		b = 0;
	}
	return live;
}

_Bool Check(_Bool(*m)[WIDTH], int i, int b)
{
	int aroundcell = 0;
	_Bool now = m[i][b];
	/* 第一轮判断 */
	b = b - 1;
	i = i + 1;
	if (b > 0 && i > 0 && b < WIDTH && i < HEIGHT)
	{
		if (m[i][b])
			++aroundcell;
	}
	/* 第二轮判断 */
	b = b + 1;
	if (b > 0 && i > 0 && b < WIDTH && i < HEIGHT)
	{
		if (m[i][b])
			++aroundcell;
	}
	/* 第三轮判断 */
	b = b + 1;
	if (b > 0 && i > 0 && b < WIDTH && i < HEIGHT)
	{
		if (m[i][b])
			++aroundcell;
	}
	/* 第四轮判断 */
	i = i - 1;
	if (b > 0 && i > 0 && b < WIDTH && i < HEIGHT)
	{
		if (m[i][b])
			++aroundcell;
	}
	/* 第五轮判断 */
	i = i - 1;
	if (b > 0 && i > 0 && b < WIDTH && i < HEIGHT)
	{
		if (m[i][b])
			++aroundcell;
	}
	/* 第六轮判断 */
	b = b - 1;
	if (b > 0 && i > 0 && b < WIDTH && i < HEIGHT)
	{
		if (m[i][b])
			++aroundcell;
	}
	/* 第七轮判断 */
	b = b - 1;
	if (b > 0 && i > 0 && b < WIDTH && i < HEIGHT)
	{
		if (m[i][b])
			++aroundcell;
	}
	/* 第八轮判断 */
	i = i + 1;
	if (b > 0 && i > 0 && b < WIDTH && i < HEIGHT)
	{
		if (m[i][b])
			++aroundcell;
	}
	if (aroundcell == 3)
		return 1;
	else if (aroundcell == 2)
		return now;
	/*else if (aroundcell == 6)
		return 1;*/
	else
		return 0;
}

void Start(_Bool(*m)[WIDTH])
{

	int i, b;
	for (i = 0; i < HEIGHT; i++)
	{
		for (b = 0; b < WIDTH; b++)
		{
			m[i][b] = Check(m, i, b);
		}
	}
}

int main(void)
{
	int i = 0;
	int m;
	_Bool map[HEIGHT][WIDTH];
	Init(map);
	printf("\033[?25l");
	printf("初始化完成\n");
	sleep(2);
	printf("\033[H");
	while (1)
	{

		m=Pmap(map);
		Start(map);
		printf("第%d次刷新,现存活%d个细胞\n", ++i,m);
		sleep(2);
		printf("\033[H");
		
		// 开头
	}
	return 0;
}
