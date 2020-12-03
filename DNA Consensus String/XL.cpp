#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//×Ö·û´®Æ¥Åä
void StringMatch(char str[][1000], int m, int n)
{
	int Hamming[50], max = -100;
	memset(Hamming, 0, sizeof(int) * 50);
	for (int i = 0; i < m; i++)
	{
		for (int j = 1; j < m; j++)
			for (int k = 0; k < n; k++)
			{
				if (str[i][k] != str[j][k])
				{
					Hamming[i]++;
					Hamming[j]++;
				}
			}
		m--;
	}

	for (int i = 0; i < m; i++)
	{
		if (Hamming[i] > max)
			max = i;
	}
	printf("%d: %s", Hamming[max], str[max]);
}

int main()
{
	FILE *Fin, *Fout;
	Fin = fopen("input.txt", "rb");
	Fout = fopen("output.txt", "wb");
	char str[50][1000];
	memset(str, '0', sizeof(str) / sizeof(char));
	int m = 0, n = 0;
	if (fscanf(Fin, "%d %d", &m, &n) == 2)
	{
		for (int i = 0; i < m; i++)
			for (;;)
			{
				fscanf(Fin, "%s", str[i]);
				break;
			}
	}
	StringMatch(str, m, n);
	fclose(Fin);
	fclose(Fout);
	system("pause");
	return 0;
}