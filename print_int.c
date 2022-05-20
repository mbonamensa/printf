#include "main.h"

/**
 * print_int - prints a decimal or integer
 * @ap: input value
 * @buf: pointer to buffer
 * @ibuf: index of pointer
 * Return: numbers of characters printed
 */
int print_int(va_list ap, char *buf, unsigned int ibuf)
{
	int input;
	unsigned int in, temp, div, i, neg;

	input = va_arg(ap, int);
	neg = 0;
	if (input < 0)
	{
		in = input * -1;
		ibuf = handlebuf(buf, '-', ibuf);
		neg = 1;
	}
	else
	{
		in = input;
	}
	temp = in;
	div = 1;
	while (temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handlebuf(buf, ((in / div) % 10) + '0', ibuf);
	}
	return (i + neg);
}
