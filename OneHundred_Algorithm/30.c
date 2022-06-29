/*
一个5位数，判断它是不是回文数。
即12321是回文数，
个位与万位相同，
十位与千位相同。
******************************
由于算法简单所以直接搬运菜鸟教程
******************************
核心就是解析每位数,如果想判断的数没长度要求,只需判断长度为奇还是偶
然后分两种算法即可
*/
#include <stdio.h>
 
int main(void)
{
    long ge,shi,qian,wan,x;
    printf("请输入 5 位数字：");
    scanf("%ld",&x);
    wan=x/10000;        /*分解出万位*/
    qian=x%10000/1000;  /*分解出千位*/
    shi=x%100/10;       /*分解出十位*/
    ge=x%10;            /*分解出个位*/
    if (ge==wan&&shi==qian) { /*个位等于万位并且十位等于千位*/
        printf("这是回文数\n");
    } else {
        printf("这不是回文数\n");
    }
}
/*
code from https://www.runoob.com/cprogramming/c-exercise-example30.html
*/