#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int readchar()
{
}

int readint(int c) //��ȡcλ�������ַ�����ת��Ϊʮ��������
{
}

int code[8][1 << 8];

int readcodes() //��ȡ����
{
}

int main()
{
	while (readcodes()) //�޷���ȡ�������ͷʱ�˳�
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