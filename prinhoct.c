#include "main.h"
/**
 * prinhoct - prints long decimal number in octal
 * @ap: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int prinhoct(va_list ap, char *buf, unsigned int ibuf)
{
	short int int_input, i, isnegative, count, first_digit;
	char *octal, *binary;

	int_input = va_arg(ap, int);
	isnegative = 0;
	if (int_input == 0)
	{
		ibuf = handlebuf(buf, '0', ibuf);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isnegative = 1;
	}

	binary = malloc(sizeof(char) * (16 + 1));
	binary = fill_binary_arr(binary, int_input, isnegative, 16);
	octal = malloc(sizeof(char) * (6 + 1));
	octal = fill_short_oct_array(binary, octal);
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handlebuf(buf, octal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}
