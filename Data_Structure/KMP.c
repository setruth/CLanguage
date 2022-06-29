//KMP算法 Next数组初始化
#include<stdio.h>
#define MAXLONG 5

struct STR
{
	char Data;
	int Cur;
};


// 匹配
int Matching_String(int T, int N, struct STR S[MAXLONG])
{
	int i;
	int j = T - N;
	for (i = 0; i <= N&&j <= T; i++, j++)
	{
		if (S[i].Data != S[j].Data)
			return -1;
	}
	return 1;
}

// 公共最长前后缀
int Length_Prefix_suffix(int Tail, struct STR S[MAXLONG])
{
	int Now = 0;
	int Key = 0;
	int Result = 0;
	while (Now < Tail)
	{
		if (Matching_String(Tail, Now, S) == 1)
		{
			if (Key < Now+1)
				Key = Now+1;
		}
		++Now;
	}

	return Key;
}

// Next数组化
int Next(struct STR *S, int L)
{
	int i = 2;
	S[0].Cur = 0;
	S[1].Cur = 0;
	while (i < L)
	{
		S[i].Cur = Length_Prefix_suffix(i - 1, S);
		++i;
	}
	return 0;
}

// int InitString()
int main(void)
{
	struct STR String[MAXLONG];
	String[0].Data = 'b';
	String[1].Data = 'k';
	String[2].Data = 'b';
	String[3].Data = 'b';
	String[4].Data = 'b';
	Next(String, 5);
	printf("%d %d %d %d %d", String[0].Cur, String[1].Cur, String[2].Cur, String[3].Cur,
		   String[4].Cur);
	return 0;
}
