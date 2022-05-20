#include "main.h"

/**
 * fill_binary_arr - prints binary
 * @binary: pointer to the binary
 * @in: input value
 * @neg: checks for negatives
 * @limit: size of the binary
 * Return: number of chars to be printed
 */
char *fill_binary_arr(char *binary, long int in, int neg, int limit)
{
	int i;

	for (i = 0; i < limit; i++)
		binary[i] = '0';
	binary[limit] = '\0';
	for (i = limit - 1; in > 1; i--)
	{
		if (in == 2)
			binary[i] = '0';
		else
			binary[i] = (in % 2) + '0';
		in /= 2;
	}
	if (in != 0)
		binary[i] = '1';
	if (neg)
	{
		for (i = 0; binary[i]; i++)
			if (binary[i] == '0')
				binary[i] = '1';
			else
				binary[i] = '0';
	}
	return (binary);
}
