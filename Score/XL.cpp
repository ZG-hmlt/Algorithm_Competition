#include <stdio.h>
int main()
{
	FILE *fin, *fout;
	fin = fopen("input.txt", "rb");
	fout = fopen("output.txt", "wb");

	int sum = 0, Cumulative = 1;
	char x = '0';
	while (fscanf(fin, "%c", &x) == 1)
	{
		if (x == 'O')
		{
			sum += Cumulative;
			Cumulative++;
		}
		else if (x == 'X')
			Cumulative = 1;
	}
	fprintf(fout, "%d", sum);
	fclose(fin);
	fclose(fout);
	return 0;
}