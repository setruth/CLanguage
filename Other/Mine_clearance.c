#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_LINE	100 		//�������
#define MAX_COLUMN	100 	    //�������
//===========================��Ҫ����==================================//
//��Ϸ��ͼ��С���ö�ά��������
char str_Ture_Distribution[MAX_LINE][MAX_COLUMN];	//��ʵ������
//��Ϸʱ�ĵ�ͼ״̬
char str_Print_Distribution[MAX_LINE][MAX_COLUMN];	//���������������
//��Ҷ�����Ϸ����,����,����
int i_Line=0,i_Column=0,i_mine=0;
//============================����=====================================//
void set_mine(void);		//������
int set_map(void);			//���õ�ͼ
void print_map(void);
void player(void);			//��ʼ��Ϸ
///����
int set_map(void){
	int a,b;
	//��Ϸ��ʼ��ʾ
	printf("\t==========================\n");
	printf("\t========��ӭ����ɨ��=========\n");
	printf("\t==========================\n");
	printf("��������Ҫ������Ϸ������(���100)������(���100)������(���ܳ�����������С1)\n:");
	scanf("%d %d %d",&i_Line,&i_Column,&i_mine);
	//�ж������ֵ�Ƿ�������
	if(i_Line>100 || i_Column>100 || i_mine>i_Column || i_mine>i_Line){
		printf("'��Ǹ,�������ֵ������,���ܿ�ʼ��Ϸ");
		return -1;
	}
	//��ʼ��ͼ��С��ʼ��
	for(a=0;a<=i_Line;a++){
		for(b=0;b<=i_Column;b++){
			//��Ϊ��һ�л����һ��,�ӿ�ʼ��ĩβ��λ����Ϊ���±߿�
			if((a==0 || a==i_Line ) && (b>0 || b<i_Column))	
				str_Print_Distribution[a][b]='-';
			//����Ϊ��һ�������һ����ʼ����β��λ��ʱ����Ϊ���߱߿�
			else if((a>=0 && a<=i_Line) && (b==0 || b==i_Column) )
				str_Print_Distribution[a][b]='|';
			//���õ�ͼ�ڵ�λ��
			else
				str_Print_Distribution[a][b]='0';
		}
	}

	//�������
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
//��ӡ��ͼ
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


//==========================��������===============================//
//������
int main(void){
	if(set_map()==-1)
		return 1;
	print_map();

	return 0;
}
