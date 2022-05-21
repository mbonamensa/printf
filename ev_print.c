#include "main.h"

/**
 * ev_print - returns number of identifiers
 * @s: argument
 * @ind: identifier index
 * Return: number of identifiers
 */
int ev_print(const char *s, int ind)
{
	print_t op[] = {
		{"c", print_char}, {"s", print_string}, {"i", print_int},
		{"d", print_int}, {"b", print_binary}, {"r", print_rev},
		{"R", print_rot13}, {"o", print_octal}, {"u", print_uns},
		{"X", print_uphex}, {"x", print_hex}, {NULL, NULL},
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
	return (j);
}
