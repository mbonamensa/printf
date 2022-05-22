#include "main.h"
/**
 * print_S - prints a string and values of
 * non-printed chars
 * @ap: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_S(va_list ap, char *buf, unsigned int ibuf)
{
	unsigned char *str;
	char *hexadecimal, *binary;
	unsigned int i, sum, op;

	str = va_arg(ap, unsigned char *);
	binary = malloc(sizeof(char) * (32 + 1));
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ibuf = handlebuf(buf, '\\', ibuf);
			ibuf = handlebuf(buf, 'x', ibuf);
			op = str[i];
			binary = fill_binary_arr(binary, op, 0, 32);
			hexadecimal = fill_hex(binary, hexadecimal, 1, 8);
			ibuf = handlebuf(buf, hexadecimal[6], ibuf);
			ibuf = handlebuf(buf, hexadecimal[7], ibuf);
			sum += 3;
		}
		else
			ibuf = handlebuf(buf, str[i], ibuf);
	}
	free(binary);
	free(hexadecimal);
	return (i + sum);
}
