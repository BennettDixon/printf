#include "holberton.h"
#include <stdlib.h>

/**
 * get_width_precision - gets the width and precision for a format string
 * @help_s: pointer to our helper struct to contain variables for passing
 * @args: va_list of args to advance and use
 *
 * Return: always void
 */

void get_width_precision(printh_t *help_s, va_list args)
{
	char c;
	char dot;

	c = help_s->format[help_s->f_i];
	dot = help_s->dot;

	if (c == '.')
		help_s->dot = 1;
	else if (_isdigit(c))
	{
		c -= '0';
		if (!dot)
			help_s->width = (c + (help_s->width * 10));
		else
			help_s->precision = (c + (help_s->precision * 10));
	}
	else if (c == '*')
	{
		if (!dot)
			help_s->width = va_arg(args, int);
		else
			help_s->precision = va_arg(args, int);
	}
}

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
