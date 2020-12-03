#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int readchar()
{
}

int readint(int c) //读取c位二进制字符，并转化为十进制整数
{
}

int code[8][1 << 8];

int readcodes() //读取编码
{
}

int main()
{
	while (readcodes()) //无法读取更多编码头时退出
	{
		for (;;)
		{
			int len = readint(3);
			if (len == 0)
				break;
			for (;;)
			{
				int v = readint(len);
				if (v == (1 << len) - 1)
					break;
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
	system("pause");
	return 0;
}