#include "main.h"

/**
 * print_string - prints string argument
 * @ap: inputer string
 * @buf: pointer to buffer
 * @ibuf: index of pointer
 * Return: 1 on success
 */
int print_string(va_list ap, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int i;
	char null[] = "(null)";

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		for (i = 0; null[i]; i++)
			ibuf = handlebuf(buf, null[i], ibuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
		ibuf = handlebuf(buf, str[i], ibuf);
	return (i);
}
