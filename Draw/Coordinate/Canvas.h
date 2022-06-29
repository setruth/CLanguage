//画板接口
#ifndef CANVAS_H
#define CANVAS_H

int CanvasInit(int width, int height, const char *name);
int CanvasSetColor(int r, int g, int b, int a);
void CanvasDrawPoint(double x, double y);
int CanvasUpdate(void);
int CanvasDeserty(void);

#endif
