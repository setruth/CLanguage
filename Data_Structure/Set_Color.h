//设置颜色.
/* 定义区 */
// 背景定义区
#define B_BK "40"				// 黑色背景
#define B_DKRD "41"				// 深红背景
#define B_GN "42"				// 绿色背景
#define B_YL "43"				// 黄色背景
#define B_BU "44"				// 蓝色背景
#define B_PL "45"				// 紫色背景
#define B_DKGN "46"				// 深绿背景
#define B_WT "47"				// 白色背景
// #define B_
// 字颜色定义区
#define F_BK "30"				// 黑色前景
#define F_RD "31"				// 红色色前景
#define F_GN "32"				// 绿色前景
#define F_YL "33"				// 黄色前景
#define F_BU "34"				// 蓝色前景
#define F_PL "35"				// 紫色前景
#define F_DKGN "36"				// 青色前景
#define F_WT "37"				// 白色前景
// 函数定义
#define COLOR_SET(STR, BGD, FGD) "\033[" BGD ";" FGD "m" STR "\033[0m"