#define RESULTS_MAX 150;
#define RESULTS_MIN 0;
#define NAME_LONG 18
/*--------------属性--------------------*/
//单个学生
struct ScmStudent{
	
	float f_Math;
	float f_China;
	float f_English;
};
//一个班
struct ScmClassL{
	char *p_Gender;
	char *p_Name;
	int n_Number;
	struct ScmStudent People;
	struct ScmClassL *Next;
};
/*--------------函数-------------------*/
//释放链表
/*=====================================*
 *函数作用:******释放链表***************
 *函数参数:一个类型为stctScmClassL链表**
 *返回值:int类型返回值但是无作用********
 *=====================================*/
void Release_List(struct ScmClassL *Cl);
//打印全部信息
/*=====================================*
 *函数作用:******清空链表***************
 *函数参数:一个类型为stctScmClassL链表**
 *返回值:int类型返回值但是无作用********
 *=====================================*/
int Print_Student(struct ScmClassL *Cl);
//添加一个学生成绩
/*=====================================*
 *函数作用:******清空链表***************
 *函数参数:一个类型为stctScmClassL链表**
 *返回值:int类型返回值但是无作用********
 *=====================================*/
int Add_Node(struct ScmClassL *Cl);
//删除某个学生
/*=====================================*
 *函数作用:******清空链表***************
 *函数参数:一个类型为stctScmClassL链表**
 *返回值:int类型返回值但是无作用********
 *=====================================*/
void Delete_Node(struct ScmClassL *Cl);
//显示某个学生
/*=====================================*
 *函数参数:一个类型为stctScmClassL链表**
 *返回值:int类型返回值但是无作用********
 *=====================================*/
void Show_a_cosre(struct ScmClassL *Cl);
//显示菜单
/*=====================================*
 *函数参数:一个类型为stctScmClassL链表**
 *返回值:int类型返回值但是无作用********
 *=====================================*/
void Show_Menu(void);