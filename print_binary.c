#include "main.h"

/**
 * print_binary - prints binary of argument
 * @ap: input string
 * @buf: pointer to the buffer
 * @ibuf: index of pointer
 * Return: number of characters printed
 */
int print_binary(va_list ap, char *buf, unsigned int ibuf)
{
	int input, count, i, first, neg;
	char *bin;

	input = va_arg(ap, int);
	neg = 0;
	if (input == 0)
	{
		ibuf = handlebuf(buf, '0', ibuf);
		return (1);
	}
	if (input < 0)
	{
		input = (input * -1) - 1;
		neg = 1;
	}
	bin = malloc(sizeof(char) * (32 + 1));
	bin = fill_binary_arr(bin, input, neg, 32);
	first = 0;
	for (count = i = 0; bin[i]; i++)
	{
		if (first == 0 && bin[i] == '1')
			first = 1;
		if (first == 1)
		{
			ibuf = handlebuf(buf, bin[i], ibuf);
			count++;
		}
	}
	free(bin);
	return (count);
}
