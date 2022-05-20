#ifndef _PRINTF_
#define _PRINTF_
#include <stdio.h>
#include <stdarg.h>
int _putchar(char c);
int _printf(const char *format, ...);
char *converter(unsigned int num, int base);
#endif
