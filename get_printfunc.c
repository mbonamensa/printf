#include "main.h"

/**
 * get_printfunc - checks which function to perform based on argument
 * @s: argument iden
 * @ind: index for identifier
 * Return: pointer to a particular function
 */
int (*get_printfunc(const char *s, int ind))(va_list, char *, unsigned int)
{
	print_t op[] = {
		{"c", print_char}, {"s", print_string}, {"i", print_int},
		{"d", print_int}, {"b", print_binary}, {"r", print_rev},
		{"R", print_rot13}, {"o", print_octal}, {"u", print_uns},
		{"x", print_hex}, {"X", print_uphex}, {"S", print_S},
		{"p", print_addr}, {"+i", prinpint}, {"+d", prinpint},
		{"+o", print_octal}, {"+u", print_uns}, {"+x", print_hex},
		{"+X", print_uphex}, {" i", prinsint}, {" d", prinsint},
		{" o", print_octal}, {" x", print_hex}, {" X", print_uphex},
		{"#i", print_int}, {"#d", print_int}, {"#o", prinnoct},
		{"#u", print_uns}, {"#x", prinnhex}, {"#X", prinnupx},
		{"li", prinlint}, {"ld", prinlint}, {"lu", prinlunt},
		{"lo", prinloct}, {"lx", prinlhex}, {"lX", prinlupx},
		{"hi", prinhint}, {"hd", prinhint}, {"hu", prinhunt},
		{"ho", prinhoct}, {"hx", prinhhex}, {"hX", prinhupx},
		{NULL, NULL},
	};
	int i = 0, j = 0, index;

	index = ind;
	while (op[i].arg_type)
	{
		if (s[ind] == op[i].arg_type[j])
		{
			if (op[i].arg_type[j + 1] != '\0')
				ind++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			ind = index;
		}
	}
	return (op[i].p);
}
