#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_LINE	100 		//行数最大
#define MAX_COLUMN	100 	    //最大列数
//===========================主要变量==================================//
//游戏地图大小利用二维数组制作
char str_Ture_Distribution[MAX_LINE][MAX_COLUMN];	//真实的排列
//游戏时的地图状态
char str_Print_Distribution[MAX_LINE][MAX_COLUMN];	//玩家所看到的排列
//玩家定义游戏行数,列数,雷数
int i_Line=0,i_Column=0,i_mine=0;
//============================函数=====================================//
void set_mine(void);		//设置雷
int set_map(void);			//设置地图
void print_map(void);
void player(void);			//开始游戏
///函数
int set_map(void){
	int a,b;
	//游戏开始提示
	printf("\t==========================\n");
	printf("\t========欢迎来到扫雷=========\n");
	printf("\t==========================\n");
	printf("请输入你要设置游戏的行数(最大100)和列数(最大100)和雷数(不能超过长宽且最小1)\n:");
	scanf("%d %d %d",&i_Line,&i_Column,&i_mine);
	//判断输入的值是否有问题
	if(i_Line>100 || i_Column>100 || i_mine>i_Column || i_mine>i_Line){
		printf("'抱歉,你输入的值有问题,不能开始游戏");
		return -1;
	}
	//开始地图大小初始化
	for(a=0;a<=i_Line;a++){
		for(b=0;b<=i_Column;b++){
			//当为第一行或最后一行,从开始到末尾的位置设为上下边框
			if((a==0 || a==i_Line ) && (b>0 || b<i_Column))	
				str_Print_Distribution[a][b]='-';
			//当是为第一竖或最后一竖开始到结尾的位置时设置为两边边框
			else if((a>=0 && a<=i_Line) && (b==0 || b==i_Column) )
				str_Print_Distribution[a][b]='|';
			//设置地图内的位置
			else
				str_Print_Distribution[a][b]='0';
		}
	}

	//再添加雷
	set_mine();	
	return 1;	
}
void set_mine(void)
{
	int i;
	srand(time(0));
	for(;i<i_mine;i++){
		int x=rand()%i_Column;
		int y=rand()%i_Line;
		if(str_Print_Distribution[x][y]=='0')
			str_Print_Distribution[x][y]='*';
		else
			i--;
	}
}
//打印地图
void print_map(void)
{
	int a,b,i;
	char c;
	printf("      ");
		
	for(i=1;i<=i_Column;i++){
		if(i<10)
			printf("%d  ",i);
		if(i>=10)
			printf("%d ",i);
	}
	puts("");
	i=1;
	for(a=0;a<=i_Line;a++){
		if(a==0)
				printf("0  ");
		if(a<10&&i!=1)
				printf("%d  ",i-1);
		else if(a>=10)
				printf("%d ",i-1);
		for(b=0;b<=i_Column;b++){
			printf("%c  ",str_Print_Distribution[a][b]);
		}
		i++;
		printf("\n");
	}
}


//==========================函数定义===============================//
//主函数
int main(void){
	if(set_map()==-1)
		return 1;
	print_map();

	return 0;
}
