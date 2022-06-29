//调用个函数
#include <stdio.h>
void hello_world(void)
{
    printf("Hello, world!\n");
}
void three_hellos(void)
{
    int counter;
    for (counter = 1; counter <= 3; counter++)
        hello_world();/*调用此函数*/
}
int main(void)
{
    three_hellos();/*调用此函数*/
}
/*
code from https://www.runoob.com/cprogramming/c-exercise-example34.html
*/