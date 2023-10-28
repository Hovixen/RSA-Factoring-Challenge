#include "main.h"
/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: return 0 successful
 */
int main(int ac, char **av)
{
	char ln[LINE_SIZE];
	FILE *fd;
	int num, factor_a, factor_b, i;

	if (ac != 2)
	{
		printf("Usage: %s<file>\n", av[0]);
		return (1);
	}

	fd = fopen(av[1], "r");
	while (fgets(ln, sizeof(ln), fd))
	{
		num = atoi(ln);
	//	printf("%d\n", num);
		factor_a = defactor(num);
	//	printf("%d\n", a);

		if (factor_a)
		{
			factor_b = num / factor_a;
			printf("%d=%d*%d\n", num, factor_b, factor_a);
		}
		else
		{
			if (num < 1000)
			{
				for (i = 2; i * i <= num; i++)
					if (num % i == 0)
					{
						printf("%d=%d*%d\n", num, i, num / i);
						break;
					}
			}
			else
				printf("Unable to factorize %d\n", num);
		}
	}
	fclose(fd);
	return (0);
}
