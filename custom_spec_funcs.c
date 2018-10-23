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

/**
 * get_rot - Gets the Rot13'd copy of the string
 * @args: va_list containing the string
 *
 * Return: char pointer to newly allocated and rot13'd string
 */
char *get_rot(va_list args)
{
	int index;
	char is_upper;
	char *str, *ret;

	str = va_arg(args, unsigned char *);
	ret = malloc(_strlen + 1);
	if (!ret)
		return (NULL);
	index = 0;
	while (str[index])
	{
		is_upper = (str[index] >= 'A' && str[index] <= 'Z');
		str[index] += 13;
		if (is_upper)
		{
			if (str[index] > 'Z')
				str[index] -= 26;
		}
		else
		{
			if (str[index] > 'z')
				str[index] -= 26;
		}
		index++;
	}
	return (ret);
}
