#include "holberton.h"
/**
 * get_flag_func - gets the proper function for a flag
 * @flag_index: index of flag gotten from _isflag, consistent with struct arr
 * @spec: specifier to make sure flag supports it
 *
 * Return: pointer to a function that takes a char * and returns a char *
 */
char *(*get_flag_func(int flag_index, char spec))(char *)
{
	char only_ints[] = {'d', 'i', NULL };
	char only_hex[] = {'o', 'x', 'X', NULL };
	flag_t flags[] = {
		{ '+', only_ints, do_plus_flag },
		{ ' ', only_ints, do_spc_flag },
		{ '#', only_hex, NULL },
		{ 0, NULL, NULL },
		};

	switch (spec)
	{
		case ('o'):
			flags[2].f = do_octal_flag;
			break;
		case ('x'):
			flags[2].f = do_hex_flag;
			break;
		case ('X'):
			flags[2].f = do_hex_upper_flag;
			break;
		default:
			break;
	}
	if (ch_in_array(spec, flags[flag_index].specs))
		return (flags[flag_index].f);
	return (NULL);
}
