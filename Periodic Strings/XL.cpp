#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *Fin, *Fout;
	Fin = fopen("input.txt", "rb");
	Fout = fopen("output.txt", "wb");
	char str[85];
	fscanf(Fin, "%s", str);
	int len = strlen(str);
	int ok = 1;
	for (int T = 1; T <= len; T++)
	{
		if (len % T == 0)
		//字符串长度一定是周期的倍数
		{
			ok = 1;
			for (int j = T; j < len; j++)
			{
				if (str[j] != str[j % T]) //j是后面的串，j%T是前面的串
				//和前面假设可能是周期串的字符串对比，如果有一个字符不对证明这个T不是周期
				{
					ok = 0;
					break;
				}
			}
			if (ok)
			//前面假设的周期串和后面比对起来完全一样，证明T是最小周期
			{
				fprintf(Fout, "%d\n", T);
				break;
			}
		}
	}
	fclose(Fin);
	fclose(Fout);
	system("pause");
	return 0;
}