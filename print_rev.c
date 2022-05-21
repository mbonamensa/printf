#include "main.h"

/**
 * print_rev - prints string argument in reverse
 * @ap: string argument
 * @buf: pointer to buffer
 * @ibuf: index of pointer
 * Return: length of string
 */
int print_rev(va_list ap, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int i;
	int x = 0;
	char null[] = "(llun)";

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		for (i = 0; null[i]; i++)
			ibuf = handlebuf(buf, null[i], ibuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;
	x = i - 1;
	for (; x >= 0; x--)
	{
		ibuf = handlebuf(buf, str[x], ibuf);
	}
	return (i);
}
