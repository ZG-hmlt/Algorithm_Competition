#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void xxx(int a, int b, int Remainder[], int Answer[], FILE *Fout)
{
	int Sum = 0; //�����ܺ�
	int Ok = 0;
	int i = 1; //��¼С����������
	//ֻ��ʵ�ֲ�ѭ��С��,��ûʵ������ѭ��С��(�ж������Ƿ�ǰ����ֹ������ֹ���֤����ʼѭ����)
	for (; Ok == 0 && i < 100; i++)
	{
		if (i == 1)
		{
			Answer[i] = a / b;
			Remainder[i] = a % b;
		}
		else
		{
			Answer[i] = Remainder[i - 1] * 10 / b;
			Remainder[i] = ((Remainder[i - 1] * 10) % b);
		}
		if (((Remainder[i] % b) == 0)) //���þ�֤����������
			break;
		else //������Ϊ0���ж������Ƿ���ֹ������ֹ���Ϊѭ��С���ĵڶ��ο�ʼ
		{
			for (int j = 1; j < i; j++)
			{
				if (Remainder[j] == Remainder[i])
				{
					Ok = 1;
					goto A;
				}
			}
		}
	}

A:
	for (int j = 1; j < i + 1; j++)
	{
		if (j == 1)
			fprintf(Fout, "%d.", Answer[j]);
		else
			fprintf(Fout, "%d", Answer[j]);
	}
	fprintf(Fout, "\n");
	fprintf(Fout, "length: %d", i - 1);
}

int main()
{
	FILE *Fin, *Fout;
	Fin = fopen("input.txt", "rb");
	Fout = fopen("output.txt", "wb");

	int Remainder[10000];
	memset(Remainder, 0, sizeof(Remainder));
	int Answer[10000];
	memset(Answer, 0, sizeof(Answer));
	int a = 0, b = 0;

	fscanf(Fin, "%d %d", &a, &b);
	xxx(a, b, Remainder, Answer, Fout);
	fclose(Fin);
	fclose(Fout);
	system("pause");
	return 0;
}