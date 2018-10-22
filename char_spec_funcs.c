#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * get_char - gets a pointer to an array containing char and null byte
 * @args: va_list to get argument from of type char
 *
 * Return: pointer to array containing char and null byte
 */
char *get_char(va_list args)
{
	char *str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = va_arg(args, int);
	str[1] = '\0';
	return (str);
}
/**
 * get_string - gets a pointer to a string, null terminated
 * @args: va_list to get argument of type char *
 *
 * Return: pointer to beginning of string
 */
char *get_string(va_list args)
{
	char *str;
	char *ret;

	str = va_arg(args, char *);
	ret = malloc(_strlen(str) + 1);
	if (!ret)
		return (NULL);
	ret = _strcpy(ret, str);
	return (ret);
}
/**
 * get_percent - gets a pointer to a string literal containing "%\0"
 * @args: va_list required for function pointer, voided, not used
 *
 * Return: pointer to string literal containing %
 */
char *get_percent(va_list args)
{
	char *str;

	if (args)
	{
	}

	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = '%';
	str[1] = '\0';
	return (str);
}
char *get_nonprint_string(va_list args)
{
	char *str, *ret, *hex_val;
	int length, i, j;

	str = va_arg(args, char *);
	length = 0;
	i = 0;

	while (str[i])
	{
		if (!is_printable(str[i]))
		{
			length += 4;
		}
		else
			length++;
		i++;

	}
	i = 0;
	j = 0;
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);
	while (i < length)
	{
		if (!is_printable(str[j]) && str[j] > 0)
		{
			hex_val = get_hex_n((unsigned int)str[j]);
			if (!hex_val)
				return (NULL);
			ret[i++] = '\\';
			ret[i++] = 'x';
			if (hex_val[1])
			{
				ret[i++] = hex_val[0];
				ret[i++] = hex_val[1];
			}
			else
			{
				ret[i++] = '0';
				ret[i++] = hex_val[0];
			}
			free(hex_val);
		}
		else
		{
			ret[i] = str[j];
			i++;
		}
		j++;
	}
	ret[length] = '\0';
	return (ret);
}
