#ifndef _PRINTF_
#define _PRINTF_
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct print - structure for the print functions
 * @arg_type: identifies conversion specifiers
 * @p: pointer to print fuctions
 * Description: struct that pointers to the print funcs
 */
typedef struct print
{
	char *arg_type;
	int (*p)(va_list, char *, unsigned int);
} print_t;
int _printf(const char *format, ...);
int ev_print(const char *s, int ind);
int (*get_printfunc(const char *s, int ind))(va_list, char *, unsigned int);
unsigned int handlebuf(char *buf, char c, unsigned int ibuf);
int printbuf(char *buf, unsigned int nbuf);
int print_string(va_list ap, char *buf, unsigned int ibuf);
int print_char(va_list ap, char *buf, unsigned int ibuf);
int print_int(va_list ap, char *buf, unsigned int ibuf);
int print_binary(va_list ap, char *buf, unsigned int ibuf);
int print_rot13(va_list ap, char *buf,unsigned int ibuf);
int print_rev(va_list ap, char *buf, unsigned int ibuf);
char *fill_binary_arr(char *binary, long int in, int neg, int limit);
#endif
