//坐标系
#include<stdio.h>
#include <stdlib.h>
#include"Canvas.h"
#include<math.h>
#define CNY 960
#define CNX 540
// 坐标结构
typedef struct POINT
{
	int x;
	int y;
} point;
void DrawPoint(double x, double y)
{
	CanvasSetColor(255, 255, 255, 255);
	CanvasDrawPoint(x, y);
}
void BuildCoordinatec(void)
{
	int i, count = 1;
	int k;
	// x左半轴
	for (i = CNX; i > 0; i--)
	{
		if ((i % 10) == 0)
		{
			if ((50 * count + i) == CNX)
			{
				if ((count % 2) == 0)
				{
					PrintScaleX(i, CNY, 1);
					++count;
					continue;
				}
				PrintScaleX(i, CNY, 2);
				++count;
			}
			PrintScaleX(i, CNY, 0);
		}
		else
		{
			CanvasSetColor(0, 0, 0, 255);
			DrawPoint(i, CNY);
		}
	}
	// x右半轴
	count = 1;
	for (i = CNX; i < CNX * 2; i++)
	{
		if ((i % 10) == 0)
		{
			if ((i - 50 * count) == CNX)
			{
				if ((count % 2) == 0)
				{
					PrintScaleX(i, CNY, 1);
					++count;
					continue;
				}
				PrintScaleX(i, CNY, 2);
				++count;
			}
			PrintScaleX(i, CNY, 0);
		}
		else
		{
			CanvasSetColor(0, 0, 0, 255);
			DrawPoint(i, CNY);
		}
	}
	// y上半轴
	count = 1;
	for (i = CNY; i > 0; i--)
	{
		if ((i % 10) == 0)
		{
			if ((i + count * 50) == CNY)
			{
				if ((count % 2) == 0)
				{
					PrintScaleY(CNX, i, 1);
					++count;
					continue;
				}
				PrintScaleY(CNX, i, 2);
				count++;
			}

			PrintScaleY(CNX, i, 0);
		}
		else
		{
			CanvasSetColor(0, 0, 0, 255);
			DrawPoint(CNX, i);
		}
	}
	// y下半轴
	count = 1;
	for (i = CNY; i < CNY * 2; i++)
	{

		if ((i % 10) == 0)
		{
			if ((i - count * 50) == CNY)
			{
				if ((count % 2) == 0)
				{
					PrintScaleY(CNX, i, 1);
					++count;
					continue;
				}
				PrintScaleY(CNX, i, 2);
				count++;
			}

			PrintScaleY(CNX, i, 0);
		}
		else
		{
			CanvasSetColor(0, 0, 0, 255);
			DrawPoint(CNX, i);
		}
	}
}
void PrintScaleX(int x, int y, int k)
{
	int i;
	if (k == 0)
	{
		for (i = y - 6; i < y + 1; i++)
		{
			CanvasSetColor(0, 0, 0, 255);
			DrawPoint(x, i);
		}
	}
	else if (k == 1)
	{
		for (i = y - 16; i < y + 1; i++)
		{
			CanvasSetColor(0, 0, 0, 255);
			DrawPoint(x, i);
		}
	}
	else if (k == 2)
	{
		for (i = y - 10; i < y + 1; i++)
		{
			CanvasSetColor(0, 0, 0, 255);
			DrawPoint(x, i);
		}
	}
}
void DrawCenter(double A, double B, double R)
{
	for (int x = A - R; x < A + R; x++)
	{

		for (int y = B - R; y < R + B; y++)
		{
			if (sqrt((A - x) * (A - x) + (B - y) * (B - y)) <= R)
			{
				CanvasSetColor(77, 110, 119, 255);
				DrawPoint(x, y);
			}
		}
	}
}
void PrintScaleY(int x, int y, int k)
{
	int i;
	if (k == 0)
	{
		for (i = x + 6; i > x - 1; i--)
		{
			CanvasSetColor(0, 0, 0, 255);
			DrawPoint(i, y);
		}
	}
	else if (k == 1)
	{
		for (i = x + 16; i > x - 1; i--)
		{
			CanvasSetColor(0, 0, 0, 255);
			DrawPoint(i, y);
		}
	}
	else if (k == 2)
	{
		for (i = x + 10; i > x - 1; i--)
		{
			CanvasSetColor(0, 0, 0, 255);
			DrawPoint(i, y);
		}
	}
}
void DrawBK(double W, double H)
{
	int i, j;
	for (i = 0; i < W; i++)
	{
		for (j = 0; j < H; j++)
		{
			CanvasSetColor(255, 255, 255, 255);
			DrawPoint(i, j);
		}
	}
}

void DrawDirection(int x1, int y1, int x2, int y2, int x3, int y3)
{
	point Peak[3];
	int i, k0 = 0, k1 = 1, k2 = 2;
	int m, n;
	int MaxBoundaryX, MinBoundaryX, MaxBoundaryY, MinBoundaryY;
	Peak[0].x = x1;
	Peak[0].y = y1;
	Peak[1].x = x2;
	Peak[1].y = y2;
	Peak[2].x = x3;
	Peak[2].y = y3;
	i = Peak[k0].y > Peak[k1].y ? Peak[k0].y : Peak[k1].y;
	MaxBoundaryY = i > Peak[k2].y ? i : Peak[k2].y;
	m = FindPoint(MaxBoundaryY, Peak);
	i = Peak[k0].y < Peak[k1].y ? Peak[k0].y : Peak[k1].y;
	MinBoundaryY = i < Peak[k2].y ? i : Peak[k2].y;
	n = FindPoint(MinBoundaryY, Peak);

	for (i = MinBoundaryY; i < MaxBoundaryY; i++)
	{
		int x1 = (Peak[m].x - Peak[n].x) * (i - Peak[n].y) / (Peak[m].y - Peak[n].y) + Peak[n].x;
		if (i < Peak[3 - m + n].y)
		{
			int l = 3 - m + n;

			int x2 =
				(Peak[l].x - Peak[n].x) * (i - Peak[n].y) / (Peak[n].y - Peak[n].y) + Peak[n].x;
			int star = x1, end = x2;
			if (x1 > x2)
			{
				star = x2;
				end = x1;
				for (; star <= end; star++)
					DrawPoint(star, i);
			}
		}
		else if (i >= Peak[3 - m + n].y)
		{
			int l = 3 - m + n;
			int x2 =
				(Peak[m].x - Peak[l].x) * (i - Peak[l].y) / (Peak[m].y - Peak[l].y) + Peak[l].x;
			int star = x1, end = x2;
			if (x1 > x2)
			{
				star = x2;
				end = x1;
				for (; star <= end; star++)
					DrawPoint(star, i);
			}
		}
	}
}
int FindPoint(int a, point P[3])
{
	if (a == P[0].y)
		return 0;
	else if (a == P[1].y)
		return 1;
	else if (a == P[2].y)
		return 2;
}

int main(void)
{
	CanvasInit(CNX, CNY, "坐标");
	//DrawBK(CNX*2, CNY*2);
	 BuildCoordinatec(); // 建造一个坐标系
	 DrawCenter(CNX, CNY, 5); // 做一个圆心
	 int y,x;
	 for(x=-540;x<1080;x++)
	 {
	 	CanvasSetColor(113 ,190, 174, 255);
	 	DrawPoint(x+540,x+960);
	 	}
	 //DrawDirection(CNX,30,30); //y轴方向
	 //DrawDirection(CNX*2-30,CNY,30); //x轴方向
	//DrawDirection(8, 9, 100, 6, 200, 4);
	CanvasUpdate();
	CanvasDeserty();
}
