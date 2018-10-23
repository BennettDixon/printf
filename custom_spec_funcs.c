#include "holberton.h"
#include <stdlib.h>

/**
 * get_reverse - Get the reversed copy of the string.
 * @args: va_list containing the string.
 *
 * Return: char pointer to the reversed string.
 */

char *get_reverse(va_list args)
{
	int i;
	int length;
	char *str, *ret;

	str = va_arg(args, char *);
	length = _strlen(str);
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	for (i = 0; i < length; i++)
		ret[i] = str[length - i - 1];
	ret[i] = '\0';

	return (ret);
}
