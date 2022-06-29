/*
一球从100米高度自由落下，
每次落地后反跳回原高度的一半；再落下，
求它在第10次落地时，共经过多少米？第10次反弹多高？
*/
#include<stdio.h>
int main(void){
    int i;
    double height=0,a=100;
    for(i=0;i<10;i++){
        height+=(a+a/2);
        a=a/2;
        }
        height-=a;
        printf("十次后经过:%lf\n第十次反弹%lf",height,a);
        return 0;
    }