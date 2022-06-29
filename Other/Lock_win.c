#include<stdio.h>
#include<unistd.h>
#define PATH_LENGTH 100
int main(void)
{
	char a,date;
	int i_key;
	char str_Out_Path[PATH_LENGTH ],str_Input_Path[PATH_LENGTH ];
	FILE *fp_Out_File,*fp_Input_File;
	long l_File_Current_Length=0,l_File_Length;
	//////////////////////////////提示以及获取////////////////////////////
	printf("Input your file path\n:");
	scanf("%s",str_Input_Path);
	printf("Input your new file path\n:");
	scanf("%s",str_Out_Path);
	printf("Input your key\n:");
	scanf("%d",&i_key);
	////////////////////////打开文件进行操作//////////////////////////////
	fp_Out_File=fopen(str_Out_Path,"wb");		//打开一个新文件 并且获取它
	fp_Input_File=fopen(str_Input_Path,"rb");	//打开读入的文件
	fseek(fp_Input_File,0,SEEK_END);			//将fp_I_f函数指针移至文件末尾
	/* 	
		int fseek(FILE *stream,long offset,int fromwhere)
		作用:设置函数指针在文件中的位置
		stream函数指针将以fromwhere为基准,偏移offset个单位
		foromwhere参数
		{
			文件起始位置  0 (SEEK_SET)
			当前位置 	   1 (SEEK_CUR)
			文件尾        2 (SEEK_END)
			
		}
	*/
	l_File_Length=ftell(fp_Input_File);	//获取文件内容长度
	/*
	
		long ftell(FiILE *stream)
		作用:返回stream函数指针当前位置
	*/
	fseek(fp_Input_File,0,SEEK_SET);	//将fp_I_f函数指针移至文件开头
	///////////////////进行文件加密////////////////////////////////////
	//printf("\033[?25l");				//隐藏光标
	//printf("[");
	fflush(stdout);
	while(fread(&date,1,1,fp_Input_File)>0){
		date^=i_key;
		fwrite(&date,1,1,fp_Out_File);
		l_File_Current_Length++;
	}
	printf("Finish");
	return 0;
}
/*#include<stdio.h>
#include<unistd.h>
int main(void)
{
	char str_Char[101] = { '\0' };
	char *p_Rotating = "|/-\\";
	int a = 0, b = 0;
	printf("\033[?25l");
	for (; a <= 3; a++){
	int c=1;
		for (; c <100; c++)
		{
			usleep(10000);
			 printf("\033[32m. \033[0m");
			fflush(stdout);
			printf("\033[35m[%c]\033[0m",p_Rotating[b%4]);
			fflush(stdout);
			printf("\b\b\b\b");
			fflush(stdout);
			b++;
		
		}
		if (a == 3)
		{
			//puts("");
			break;
		}
		printf("\r");
			fflush(stdout);
		printf("                                                            ");
		fflush(stdout);
		printf("\r");
		fflush(stdout);
	}
	return 0;
}
*/
 

