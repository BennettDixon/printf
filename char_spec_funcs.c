#include "holberton.h"
#include <stdlib.h>
/**
 * get_char - gets a pointer to an array containing char and null byte
 * @args: va_list to get argument from of type char
 * @mods: length modifiers, voided, not used with this specifier
 *
 * Return: pointer to array containing char and null byte
 */
char *get_char(va_list args, char *mods)
{
	char *str;
	char c;

	(void)mods;
	c = va_arg(args, int);
	str = malloc(2);

	if (!str)
		return (NULL);
	if (c)

		str[0] = c;
	else
		str[0] = '\0';
	str[1] = '\0';
	return (str);
}
/**
 * get_string - gets a pointer to a string, null terminated
 * @args: va_list to get argument of type char
 * @mods: length modifiers, voided, not used with this specifier*
 *
 * Return: pointer to beginning of string
 */
char *get_string(va_list args, char *mods)
{
	char *str;
	char *ret;

	(void)mods;
	str = va_arg(args, char *);

	if (str)
	{
		ret = malloc(_strlen(str) + 1);
		if (!ret)
			return (NULL);
		ret = _strcpy(ret, str);
	}
	else
	{
		ret = malloc(6 + 1);
		if (!ret)
			return (NULL);
		ret = _strcpy(ret, "(null)");
	}
	return (ret);
}
/**
 * get_percent - gets a pointer to a string literal containing "%\0"
 * @args: va_list required for function pointer, voided, not used
 * @mods: length modifiers, voided, not used with this specifier
 *
 * Return: pointer to string literal containing %
 */
char *get_percent(va_list args, char *mods)
{
	char *str;

	(void)mods;
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
