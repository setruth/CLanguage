#include<stdio.h>
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

 