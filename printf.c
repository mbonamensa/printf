#include "main.h"

/**
 * _printf - printf function
 * @format: format
 * Return: counter
 */

int _printf(const char *format, ...)
{
	va_list ap;

	char *str;

	int i, counter = 0;

	const char *conv;

	va_start(ap, format);
	for (conv = format; *conv != '\0'; conv++)
	{
		while (*conv != '%')
		{
			if (*conv == '\0')
				return (counter);
			_putchar(*conv);
			conv++;
			counter++;
		}
		conv++;
		switch (*conv)
		{
			case 'c':
				i = va_arg(ap, int);
				_putchar(i);
				break;
			case 's':
				str = va_arg(ap, char *);
				fputs(str, stdout);
				break;
			case 'i':
			case 'd':
				i = va_arg(ap, int);
				fputs(converter(i, 10), stdout);
				break;
		}
	}
	va_end(ap);
	return (counter);
}
