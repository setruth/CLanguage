// 1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
#include <stdio.h>
int main(void) {
  int Bit, Ten, Hundred;
  int Count=0;
  for (Hundred = 1; Hundred <= 4; Hundred++) {
    for (Ten = 1; Ten <= 4; Ten++) {
      for (Bit = 1;Bit<=4; Bit++) {
        if(Bit==Ten || Bit==Hundred || Ten==Hundred)
          continue;
         else{
           printf("%d%d%d\n",Hundred,Ten,Bit);
           ++Count;
         }
      }
    }
  }
  printf("一共有%d个数",Count);
  return 0;
}
