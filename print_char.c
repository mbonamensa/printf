#include "main.h"

/**
 * print_char - prints character
 * @ap: input argument
 * @buf: pointer to buffer
 * @ibuf: index of pointer
 * Return: 1 on success
 */
int print_char(va_list ap, char *buf, unsigned int ibuf)
{
	char c;

	c = va_arg(ap, int);
	handlebuf(buf, c, ibuf);
	return (1);
}
