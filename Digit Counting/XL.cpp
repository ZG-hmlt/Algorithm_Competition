#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *Fin, *Fout;
	Fin = fopen("input.txt", "rb");
	Fout = fopen("output.txt", "wb");
	char n = 0;
	int sum[10];
	memset(sum, 0, sizeof(int) * 10);
	while (fscanf(Fin, "%c", &n) == 1)
	{
		if (n == '0')
			sum[0]++;
		else if (n == '1')
			sum[1]++;
		else if (n == '2')
			sum[2]++;
		else if (n == '3')
			sum[3]++;
		else if (n == '4')
			sum[4]++;
		else if (n == '5')
			sum[5]++;
		else if (n == '6')
			sum[6]++;
		else if (n == '7')
			sum[7]++;
		else if (n == '8')
			sum[8]++;
		else if (n == '9')
			sum[9]++;
	}

	for (int i = 0; i < 10; i++)
	{
		fprintf(Fout, "%d: %d\n", i, sum[i]);
	}

	fclose(Fin);
	fclose(Fout);
	system("pause");
	return 0;
}