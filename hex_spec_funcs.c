#include "holberton.h"
/**
 * get_hex - gets a string that is the hex representation of an integer
 * @args: va_list to get integer for conversion from
 *
 * Return: char pointer to new hex string
 */
char *get_hex(va_list args)
{
	unsigned int num;
	int length;
	char *ret;

	num = va_arg(args, unsigned int);
	/* allocate enough memory for conversion */
	length = get_numbase_len(num, 16);
	ret = malloc(length + 1); /* null byte */
	if (!ret)
		return (NULL);
	/* fill the string with conversion */
	fill_numbase_buff(num, 16, ret, length);
	return (ret);
}
/**
 * get_hex_upper - gets a string that is the upper case hex rep of an integer
 * @args: va_list to get integer for conversion from
 *
 * Return: char pointer to new hex string
 */
char *get_hex_upper(va_list args)
{
	char *ret;
	int i = 0;

	ret = get_hex(args);
	while (ret[i])
	{
		if (ret[i] >= 'a' && ret[i] <= 'z')
			ret[i] -= 32;
		i++;
	}
	return (ret);
}
