#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *Fin, *Fout;
	Fin = fopen("input.txt", "rb");
	Fout = fopen("output.txt", "wb");

	char ch = '0';
	int index = 0;
	double sum = 0;
	while (fscanf(Fin, "%c", &ch) != EOF)
	{
		if (fscanf(Fin, "%d", &index) == 1)
		{
			if (ch == 'C')
			{
				sum += 12.01 * index;
			}
			else if (ch == 'H')
			{
				sum += 1.008 * index;
			}
			else if (ch == 'O')
			{
				sum += 16.00 * index;
			}
			else if (ch == 'N')
			{
				sum += 14.01 * index;
			}
		}
		else
		{
			if (ch == 'C')
			{
				sum += 12.01;
			}
			else if (ch == 'H')
			{
				sum += 1.008;
			}
			else if (ch == 'O')
			{
				sum += 16.00;
			}
			else if (ch == 'N')
			{
				sum += 14.01;
			}
		}
	}

	fprintf(Fout, "%.3lf", sum);

	fclose(Fin);
	fclose(Fout);
	system("pause");
	return 0;
}