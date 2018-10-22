#include "holberton.h"
#include <stdlib.h>

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
	int length, i;

	str = va_arg(args, char *);
	while (str[length])
	{
		if (!is_printable(str[length]) && str[length] > 0)
		{
			length += 4;
		}
		else
			length++;
	}
	ret = malloc(length + 1);
	while (i < length)
	{
		if (!is_printable(str[i]) && str[length] > 0)
		{
			hex_val = get_hex_n((unsigned int)str[i]);
			if (!hex_val)
				return (NULL);
			ret[i++] = '\\';
			ret[i++] = 'x';
			ret[i++] = hex_val[0];
			ret[i++] = hex_val[1];
			free(hex_val);
		}
		else
		{
			ret[i] = str[i];
			i++;
		}
	}
	ret[length] = '\0';
	return (ret);
}
