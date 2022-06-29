/* 
企业发放的奖金根据利润提成:		
    	   *利润(I)低于或等于10万元时，奖金可提10%；
		   *利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
		   *20万到40万之间时，高于20万元的部分，可提成5%；
    	   *40万到60万之间时高于40万元的部分，可提成3%；
		   *60万到100万之间时，高于60万元的部分，可提成1.5%；
		   *高于100万元时，超过100万元的部分按1%提成。 
从键盘输入当月利润I，求应发放奖金总数？ 
*/
#include <stdio.h>
int main(void)
{
	double Profit;				// 利润
	double Bonus;				// 奖金
	printf("输入你的利润看你能获取多少奖金:");
	scanf("%lf", &Profit);
	if (Profit <= 100000)
		printf("你能获得%.2lf的奖金", Profit * 0.1);
	else if (Profit <= 200000)
		printf("你能获得%.2lf的奖金", (Profit - 100000) * 0.075 + 100000 * 0.1);
	else if (Profit <= 400000)
		printf("你能获得%.2lf的奖金", (Profit - 200000) * 0.05 + 200000 * 0.075);
	else if (Profit <= 600000)
		printf("你能获得%.2lf的奖金", (Profit - 400000) * 0.03 + 400000 * 0.05);
	else if (Profit <= 1000000)
		printf("你能获得%.2lf的奖金", (Profit - 600000) * 0.15 + 600000 * 0.03);
	else if (Profit > 1000000)
		printf("你能获得%.2lf的奖金", Profit * 0.01);

	return 0;
}