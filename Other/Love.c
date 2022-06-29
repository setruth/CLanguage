#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<conio.h>
#define I 20
#define R 340
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define I 20
#define R 340
#include <string.h>
int main()
{
	char answer[4];
	float y, x, z, f;
	long time;
	printf("遇到你\n");
	sleep(1);
	printf("我才发现\n");
	sleep(1);
	printf("曾经所有的条件\n");
	sleep(1);
	printf("似乎都成了我等你的借口\n\n");
	sleep(1);
	printf("我对你的感情已经决堤\n");
	sleep(1);
	printf("所以\n");
	sleep(1);

	for (y = 1.5f; y > -1.5f; y -= 0.1f)
	{
		for (x = -1.5f; x < 1.5f; x += 0.05f)
		{
			z = x * x + y * y - 1;
			f = z * z * z - x * x * y * y * y;
			putchar(f <= 0.0f ? "*********"[(int)(f * -8.0f)] : ' ');
		}
		putchar('\n');
	}

	for (;;)
	{
		system("color a");
		for (time = 0; time < 99999999; time++);
		system("color b");
		for (time = 0; time < 99999999; time++);
		system("color c");
		for (time = 0; time < 99999999; time++);
		system("color d");
		for (time = 0; time < 99999999; time++);
		system("color e");
		for (time = 0; time < 99999999; time++);
		system("color f");
		for (time = 0; time < 99999999; time++);
		system("color 0");
		for (time = 0; time < 99999999; time++);
		system("color 1");
		for (time = 0; time < 99999999; time++);
		system("color 2");
		for (time = 0; time < 99999999; time++);
		system("color 3");
		for (time = 0; time < 99999999; time++);
		system("color 4");
		for (time = 0; time < 99999999; time++);
		system("color 5");
		for (time = 0; time < 99999999; time++);
		system("color 6");
		for (time = 0; time < 99999999; time++);
		system("color 7");
		for (time = 0; time < 99999999; time++);
		system("color 8");
		for (time = 0; time < 99999999; time++);
		system("color 9");
	}

	getchar();
	return 0;
}
