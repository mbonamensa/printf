#include "main.h"

/**
 * print_rot13 - prints string using ROT13 algorithm
 * @ap: input argument
 * @buf: pointer to string
 * @ibuf: index of pointer
 * Return: rot13 string
 */
int print_rot13(va_list ap, char *buf, unsigned int ibuf)
{
	char *str;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	unsigned int i, j, k;
	char null[] = "(avyy)";

	str = va_arg(ap, char *);
	if (str == NULL)
	{
		for (i = 0; null[i]; i++)
			ibuf = handlebuf(buf, null[i], ibuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
	{
		for (k = j = 0; alpha[j]; j++)
		{
			if (str[i] == alpha[j])
			{
				k = 1;
				ibuf = handlebuf(buf, rot13[j], ibuf);
				break;
			}
		}
		if (k == 0)
			ibuf = handlebuf(buf, str[i], ibuf);
	}
	return (i);
}
