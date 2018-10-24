#include "holberton.h"
#include <stdlib.h>
/**
 * do_width - Applies spaces or '0's in front of strings if their length is
 * less than the specified minimum width.
 * @str: The string to modify.
 * @width: The minimum width the string should have.
 * @space: if 0, pad with 0's, pad with space if 1.
 *
 * Return: char pointer to the new string.
 */

char *do_width(char *str, int width, int space)
{
	int len;
	int i, j;
	char *ret;
	char pad;

	len = _strlen(str);
	if (len > width)
		return (str);

	ret = malloc(len + 1);
	if (!ret)
		return (NULL);

	i = width;
	j = len;

	while (j >= 0)
		ret[i--] = str[j--];

	if (space)
		pad = ' ';
	else
		pad = '0';

	while (i >= 0)
		ret[i--] = pad;
	free(str);
	return (ret);
}
