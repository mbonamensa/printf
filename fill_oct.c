#include "main.h"

/**
 * fill_oct - prints the character to stdout
 * @bnr: binary array
 * @oct: octal array
 * Return: oct array
 */
char *fill_oct(char *bnr, char *oct)
{
	int op, i, j, k, limit;

	oct[11] = '\0';
	for (i = 31, k = 10; i >= 0; i--, k--)
	{
		if (i > 1)
			limit = 4;
		else
			limit = 2;
		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		oct[k] = op + '0';
	}
	return (oct);
}
