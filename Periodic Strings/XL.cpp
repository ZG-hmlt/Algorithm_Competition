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
		//�ַ�������һ�������ڵı���
		{
			ok = 1;
			for (int j = T; j < len; j++)
			{
				if (str[j] != str[j % T]) //j�Ǻ���Ĵ���j%T��ǰ��Ĵ�
				//��ǰ�������������ڴ����ַ����Աȣ������һ���ַ�����֤�����T��������
				{
					ok = 0;
					break;
				}
			}
			if (ok)
			//ǰ���������ڴ��ͺ���ȶ�������ȫһ����֤��T����С����
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