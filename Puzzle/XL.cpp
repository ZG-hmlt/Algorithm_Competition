#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *Fin, *Fout;
	Fin = fopen("input.txt", "rb");
	Fout = fopen("output.txt", "wb");

	char a[5][5];
	char temp = '0';
	int i = 0, j = 0;

	memset(a, '0', sizeof(a) / sizeof(char));
	//��ֵ
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
		{
			fscanf(Fin, "%c", &temp);
			if (temp != '\n' && temp != '\r')
			{
				a[i][j] = temp;
			}
			else //�����ı�����Ļ���+�س�����j����-1������һ��for��ʱ��j = 0���ص�����λ��
				j = -1;
		}
	//����ʣ�µĻ���+�س�
	fscanf(Fin, "%c", &temp);
	fscanf(Fin, "%c", &temp);
	//��λ*��λ��
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			temp = a[i][j];
			if (temp == '*')
				break;
		}
		if (temp == '*')
			break;
	}
	//ָ��
	while (temp != '0')
	{
		fscanf(Fin, "%c", &temp);
		if (temp == 'A')
		//*������λ�õ��ַ���������i��j����*λ��
		{
			temp = a[i][j];
			a[i][j] = a[i - 1][j];
			a[i - 1][j] = temp;
			i--;
		}
		else if (temp == 'B')
		{
			temp = a[i][j]; //��*��temp
			a[i][j] = a[i + 1][j];
			a[i + 1][j] = temp;
			i++;
		}
		else if (temp == 'R')
		{
			temp = a[i][j]; //��*��temp
			a[i][j] = a[i][j + 1];
			a[i][j + 1] = temp;
			j++;
		}
		else if (temp == 'L')
		{
			temp = a[i][j]; //��*��temp
			a[i][j] = a[i][j - 1];
			a[i][j - 1] = temp;
			j--;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			temp = a[i][j];
			fprintf(Fout, "%c ", temp);
		}
		fprintf(Fout, "\n");
	}

	fclose(Fin);
	fclose(Fout);
	system("pause");
	return 0;
}