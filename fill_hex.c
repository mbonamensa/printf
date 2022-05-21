#include "main.h"

/**
 * fill_hex - prints character to stdout
 * @bnr: binary array
 * @hex: hex array
 * @isupp: checks if should be upper or lowercase
 * @limit: hex array size
 * Return: hex array
 */
char *fill_hex(char *bnr, char *hex, int isupp, int limit)
{
	int op, i, j, letter;

	hex[limit] = '\0';
	if (isupp)
		letter = 55;
	else
		letter = 87;
	for (i = (limit * 4) - 1; i >= 0; i++)
	{
		for (op = 0, j = 1; j <= 8; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		if (op < 10)
			hex[i / 4] = op + 48;
		else
			hex[i / 4] = op + letter;
	}
	return (hex);
}
