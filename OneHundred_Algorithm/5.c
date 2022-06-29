//三个整数排序
#include <stdio.h>
int main(void) {
  int x, y, z;
  printf("输入你要比较的三个整数 空格隔开:");
  scanf("%d %d %d", &x, &y, &z);
  if (x > y)
    printf("%d %d %d", z < x ? x : z,(z < x ? z : x) > y ? ((z < x) ? z : x) : y,(z < x ? x : z) > y ? y : (z < x ? x : z));
  else if (y > x)
    printf("%d %d %d", z < y ? y : z, ((z < y )? z : y) < x ? x : (z < y ? z : y),(z < y ? z : y) < x ? (z < y ? z : y) : x);
  return 0;
}