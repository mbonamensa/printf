#include "main.h"

/**
 * printbuf - prints buffer
 * @buf: pointer to buffer
 * @nbuf: number of bytes to be printed
 * Return: nbuf
 */
int printbuf(char *buf, unsigned int nbuf)
{
	return (write(1, buf, nbuf));
}
