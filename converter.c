#include "main.h"

/**
 * converter - converts into various number bases
 * @num: value to be converted
 * @base: base value
 * Return: ptr
 */

char *converter(unsigned int num, int base)
{
	static const char Rep[] = "0123456789ABCDEF";

	static const char buffer[50];

	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	do {
		*--ptr = Rep[num % base];
		num /= base;
	} while (num != 0);
	return (ptr);
}
