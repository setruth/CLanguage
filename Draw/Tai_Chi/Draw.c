//太极
#include<stdio.h>
#include <stdlib.h>
#include"Canvas.h"
#include<math.h>
#define CA 540
#define CB 960
#define CR 540
void drawPoint(double x, double y)
{
	CanvasDrawPoint(x, y);
}

int Print1(double x, double y)
{
	if (x > 540)
	{
		CanvasSetColor(255, 255, 255, 255);
		drawPoint(x, y);
	}
	else
	{
		CanvasSetColor(0, 0, 0, 255);
		drawPoint(x, y);
	}
}

int Print2(double x, double y)
{
	if (x < 540)
	{
		CanvasSetColor(255, 255, 255, 255);
		drawPoint(x, y);
	}
	else
	{
		CanvasSetColor(0, 0, 0, 255);
		drawPoint(x, y);
	}
}

int Print4(double x, double y)
{
	CanvasSetColor(255, 255, 255, 255);
	drawPoint(x, y);
}

int Print3(double x, double y)
{
	CanvasSetColor(0, 0, 0, 255);
	drawPoint(x, y);
}

void DrawCircle(double A, double B, double R, int k)
{
	for (int x = A - R; x < A + R; x++)
	{

		for (int y = B - R; y < R + B; y++)
		{
			if (sqrt((A - x) * (A - x) + (B - y) * (B - y)) <= R)
			{
				switch (k)
				{
				case 1:
					Print1(x, y);
					break;
				case 0:
					Print2(x, y);
					break;
				case 3:
					Print3(x, y);
					break;
				case 4:
					Print4(x, y);
					break;
				default:
					break;
				}
			}
		}
	}
}

void DrawBK(double A, double B, double R)
{
	for (int x = A - R; x < A + R; x++)
	{

		for (int y = B - R; y < R + B; y++)
		{
			if (sqrt((A - x) * (A - x) + (B - y) * (B - y)) > R)
			{
				CanvasSetColor(192, 192, 192, 255);
				drawPoint(x, y);
			}
		}
	}
}

void Circle2(void)
{
	double x1, y1, x2, y2, r;
	x1 = CA;
	y1 = CB - CR / 2;
	x2 = CA;
	y2 = CB + CR / 2;
	r = CR / 2;
	DrawCircle(x1, y1, r, 3);
	DrawCircle(x2, y2, r, 4);
}

void Circle3(void)
{
	double x1, y1, x2, y2, r;
	x1 = CA;
	y1 = CB - CR / 2;
	x2 = CA;
	y2 = CB + CR / 2;
	r = CR / 4;
	DrawCircle(x1, y1, r, 4);
	DrawCircle(x2, y2, r, 3);
}

int main(void)
{
	// 500x600的画布
	CanvasInit(1080, 1920, "太极");
	// 设置白色
	DrawBK(CA,CB,CR);
	DrawCircle(CA, CB, CR, 1);
	Circle2();
	Circle3();

	// 下面是固定的*/
	CanvasUpdate();
	CanvasDeserty();


}
