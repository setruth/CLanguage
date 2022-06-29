#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdlib.h>
#include"function.h"
/*******************主函数*********************/
int main(void)
{
	int n_Option;				// 接受选项输入 性别
	char a, arr_Name[NAME_LONG], p_Gender[4];	// 清理缓冲区 
	struct ScmClassL *pScm_Tail_Node, *pScm_Temproary_Node, *pScm_Head_Node = NULL;	// 尾结点 
																					// 
	// 临时结点 
	// 头结点
	float f_China, f_English, f_Math;	// 成绩:语文 英语 数学 
	// 提示语
	printf
		("Please enter the student's name and gender and csore \nCsore order is Math China English;\nFor example:( 李华 男 110.5 90 88.5))\n!!a separate Enter end input \n:");
	// 动态链表核心
	while (scanf("%s %s %f %f %f", arr_Name, p_Gender, &f_China, &f_English, &f_Math) != 0)
	{
		pScm_Temproary_Node = (struct ScmClassL *)malloc(sizeof(struct ScmClassL));
		if (pScm_Head_Node == NULL)
		{
			pScm_Head_Node = pScm_Temproary_Node;
		}
		else
			pScm_Tail_Node->Next = pScm_Temproary_Node;
		// 赋值
		pScm_Temproary_Node->p_Name = arr_Name;
		pScm_Temproary_Node->p_Gender = p_Gender;
		pScm_Temproary_Node->People.f_Math = f_Math;
		pScm_Temproary_Node->People.f_China = f_China;
		pScm_Temproary_Node->People.f_English = f_English;
		++pScm_Temproary_Node->n_Number;
		// 指向下一节点
		pScm_Tail_Node = pScm_Temproary_Node;
		while (a = getchar() && a != '\n');	// 清空缓冲区
	}
	puts("Complete input");
	// 选项
	for (;;)
	{
		Show_Menu();
		scanf("%d", &n_Option);
		while (a = getchar() && a != '\n');
		switch (n_Option)
		{
		case 1:
			Add_Node(pScm_Head_Node);
			break;
			/* case 2: Delete_Node(pScm_Head_Node); break; */ 
		case 3:
			Print_Students(pScm_Head_Node);
			break;
			// case 4:Show_a_cosre(pScm_Head_Node);break;
		case 6:
			break;
		default:
			puts("Error you dont't about option number !!!");
			return 0;
		}
	}
	return 0;
}

/***********************函数初始化********************/
// 显示菜单
void Show_Menu(void)
{
	printf("===========================================================\n\t"
		   "=====If you want to add a student  csore input       1=====\n\t"
		   "=====If you want to delete a student  csore input    2=====\n\t"
		   "=====If you want to show all student csore input     3=====\n\t"
		   "=====If you want to show a student csore input       4=====\n\t"
		   "=====If you don't want to do anything intput         6=====\n\t"
		   "===========================================================\n\t");

}

// 显示链表
int Print_Students(struct ScmClassL *Cl)
{
	struct ScmClassL *pScm_Temproary_Node;
	if (Cl == NULL)
	{
		puts("Error:you class is empty");
		return 0;
	}
	pScm_Temproary_Node = Cl;
	printf("\tStudent id    Name     Gender    Math    China   English\n");
	while (1)
	{
		printf("\t %d     %s    %d     %f     %f      %f     ", pScm_Temproary_Node->n_Number,
			   pScm_Temproary_Node->p_Name, pScm_Temproary_Node->p_Gender,
			   pScm_Temproary_Node->People.f_Math, pScm_Temproary_Node->People.f_China,
			   pScm_Temproary_Node->People.f_English);
		if (pScm_Temproary_Node->Next == NULL)
			return 0;
		pScm_Temproary_Node = pScm_Temproary_Node->Next;
	}
	return 0;
}

// 添加一个学生成绩
int Add_Node(struct ScmClassL *Cl)
{
	int i, n_Location;
	char arr_Name[NAME_LONG], p_Gender[4], a;
	float f_China, f_English, f_Math;
	struct ScmClassL *pScm_New_Node, *pScm_Now_Node, *pScm_Now_Next_Node;
	// 判断链表是否为空
	if (Cl == NULL)
	{
		printf("Error:your class student is empty !!!Eend add function");
		return 1;
	}
	// 提示以及输入
	printf
		("Enter the student information(Add it this way:李华 男 110.5(math ) 90(china) 88.5(english))");
	scanf(" %s %s %f %f %f", arr_Name, p_Gender, &f_China, &f_English, &f_Math);
	while (a = getchar() && a != '\n');
	printf("Now enter location:");
	scanf("%d", &n_Location);
	// 新节点及赋值
	pScm_New_Node = (struct ScmClassL *)malloc(sizeof(struct ScmClassL));
	pScm_New_Node->p_Name = arr_Name;
	pScm_New_Node->p_Gender = p_Gender;
	pScm_New_Node->People.f_Math = f_Math;
	pScm_New_Node->People.f_China = f_China;
	pScm_New_Node->People.f_English = f_English;
	// 插入
	pScm_Now_Node = Cl;
	for (i = 0; i < n_Location; i++)
	{
		pScm_Now_Node = pScm_Now_Node->Next;
	}
	pScm_Now_Next_Node = pScm_Now_Node->Next;
	pScm_Now_Node->Next = pScm_New_Node;
	pScm_New_Node->Next = pScm_Now_Next_Node;
	return 0;
}

// 释放链表
void Release_List(struct ScmClassL *Cl)
{
	struct ScmClassL *pScm_Release_Node;
	while (Cl != NULL)
	{
		pScm_Release_Node = Cl;
		Cl = Cl->Next;
		free(pScm_Release_Node);
	}
}