#includ "main.h"

/**
 * handlebuf - joins buffer chars
 * @buf: pointer to buffer
 * @c: char to join
 * @ibuf: index
 * Return: index of pointer
 */
unsigned int handlebuf(char *buf, char c, unsigned int ibuf)
{
	if (ibuf == 1024)
	{
		printbuf(buf, ibuf);
		ibuf = 0;
	}
	buf[ibuf] = c;
	ibuf++;
	return (ibuf);
}
