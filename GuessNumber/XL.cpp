#include <stdio.h>
const int maxn = 1010;
int main()
{
	int n = 0, a[maxn], b[maxn];
	int kase = 0;
	while (scanf("%d", &n) == 1 && n) //输入数字的序列长度
	{
		printf("Game %d:\n", ++kase);
		for (int i = 0; i < n; i++) //输入数字序列的答案序列
			scanf("%d", &a[i]);
		for (;;)
		{
			int A = 0, B = 0;
			for (int i = 0; i < n; i++)
			{
				scanf("%d", &b[i]); //输入猜测序列
				if (a[i] == b[i])	//判断输入的数字和位置都一致
					A++;
			}
			if (b[0] == 0) //判断第一个数是0代表已经结束猜测了
				break;
			for (int d = 1; d <= 9; d++) //开始看不懂了
			{
				int c1 = 0, c2 = 0; //统计数字d在答案序列和猜测序列中各出现了多少次
				for (int i = 0; i < n; i++)
				{
					if (a[i] == d)
						c1++;
					if (b[i] == d)
						c2++;
				}
				if (c1 < c2)
					B += c1;
				else
					B += c2;
			}
			printf("    (%d,%d)\n", A, B - A);
		}
	}
	return 0;
}