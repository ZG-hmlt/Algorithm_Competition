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
	//赋值
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
		{
			fscanf(Fin, "%c", &temp);
			if (temp != '\n' && temp != '\r')
			{
				a[i][j] = temp;
			}
			else //遇到文本里面的换行+回车，让j等于-1，再走一次for的时候j = 0，回到正常位置
				j = -1;
		}
	//吸收剩下的换行+回车
	fscanf(Fin, "%c", &temp);
	fscanf(Fin, "%c", &temp);
	//定位*的位置
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
	//指令
	while (temp != '0')
	{
		fscanf(Fin, "%c", &temp);
		if (temp == 'A')
		//*和所在位置的字符互换，且i和j跟踪*位置
		{
			temp = a[i][j];
			a[i][j] = a[i - 1][j];
			a[i - 1][j] = temp;
			i--;
		}
		else if (temp == 'B')
		{
			temp = a[i][j]; //把*给temp
			a[i][j] = a[i + 1][j];
			a[i + 1][j] = temp;
			i++;
		}
		else if (temp == 'R')
		{
			temp = a[i][j]; //把*给temp
			a[i][j] = a[i][j + 1];
			a[i][j + 1] = temp;
			j++;
		}
		else if (temp == 'L')
		{
			temp = a[i][j]; //把*给temp
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