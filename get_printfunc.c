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
		{"d", print_int}, {NULL, NULL},
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
