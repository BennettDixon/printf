#include "holberton.h"

char *(*get_flag_func(int flag_index, char spec))(char *)
{
	char only_ints[] = {'d', 'i', NULL };
	char only_hex[] = {'o', 'x', 'X', NULL };
	flag_t flags[] = {
		{ '+', only_ints, get_plus_flag },
		{ ' ', only_ints, get_spc_flag },
		{ '#', only_hex, get_hash_flag },
		{ 0, NULL, NULL },
		};

	if (ch_in_array(spec, flags[flag_index].specs))
		return (flags[flag_index].f);
	return (NULL);
}
