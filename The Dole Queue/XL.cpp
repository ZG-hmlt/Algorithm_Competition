#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
const int maxn = 25;
int n, k, m, a[maxn];

int go(int p, int d, int t)
{
	while (--t)
	{
		do
		{
			p = (p + n + d) % n;
			if (p == 0)
				p = 10;
		} while (a[p] == 0);
	}
	return p;
}

int main()
{
	while (scanf("%d%d%d", &n, &k, &m) == 3 && n)
	{
		for (int i = 1; i <= n; i++) //赋值
			a[i] = i;
		int left = n; //剩下的人数
		int p1 = 1, p2 = n;
		while (left)
		{
			p1 = go(p1, 1, k);
			p2 = go(p2, -1, m);
			printf("%3d", p1);
			left--;
			if (p2 != p1)
			{
				printf("%3d", p2);
				left--;
			}
			a[p1] = a[p2] = 0;
			if (left)
			{
				while (a[p1] == 0)
				{
					p1 = (p1 + n + 1) % n;
					if (p1 == 0)
						p1 = 10;
					if (a[p1] != 0)
						break;
				}
				while (a[p2] == 0)
				{
					p2 = (p2 + n - 1) % n;
					if (p2 == 0)
						p2 = 10;
					if (a[p2] != 0)
						break;
				}
				if (left)
					printf(",");
			}
		}
		printf("\n");
	}
	system("pause");
	return 0;
}