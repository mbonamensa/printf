#include "main.h"
/**
 * _printf - printf
 * @format: format
 * Return: counter
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, counter = 0, j = 0;
	va_list ap;
	int (*function)(va_list, char *, unsigned int);
	char *buff;

	va_start(ap, format), buff = malloc(sizeof(char) * 1024);
	if (!format || !buff || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				printbuf(buff, j), free(buff), va_end(ap);
				return (-1);
			}
			else
			{	function = print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handlebuf(buff, format[i], j), counter++, i--;
				}
				else
				{	counter += function(ap, buff, j);
					i += ev_print(format, i + 1);
				}
		} i++;
		}
		else
			handlebuf(buff, format[i], j), counter++;
		for (j = counter; j > 1024; j -= 1024)
			;
	}
	printbuf(buff, j), free(buff), va_end(ap);
	return (counter);
}
