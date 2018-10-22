#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

/** _printf - Prints variatic arguments based on format string.
  * @format: String passed, may contain zero, or more directives.
  *
  * Return: Number of characters printed to stdout.
  */

int _printf(const char *format, ...)
{
	char *buff, *temp, busy;
	unsigned int ind, beg_ind, buff_i, length;
	va_list args;

	if (!format)
		return (-1);

	buff = create_buff(BUFF_SIZE);
	va_start(args, format);
	ind = 0;
	buff_i = 0;
	busy = 0;

	while (format[ind])
	{
		if (format[ind] == '%' && !busy)
		{
			beg_ind = ind;
			busy = 1;
		}
		else if (busy)
		{
			print_helper(format, &ind, buff, &buff_i, &busy,
					&beg_ind, args);
		}
		else
			buff[buff_i++] = format[ind];
		ind++;
	}
	length = print_buff(buff, buff_i);
	free(buff);
	va_end(args);
	return (length);
}
void print_helper(char *format, int *f_index, char *buff, int *b_index,
		int *busy, int *beg_index, va_list args)
{
	char *temp;

	if (_isalpha(format[*f_index]) || format[*f_index] == '%')
	{
		if (is_specifier(format[*f_index]))
		{
			temp = get_string_func(format[*f_index])(args);
			if (!temp)
			{
				free(buff);
				va_end(args);
				return;
			}
			copy_buff(temp, b_index, buff, BUFF_SIZE);
			*busy = 0;
		}
		else
		{
			*f_index = *beg_index;
			buff[*b_index++] = format[*f_index];
			*busy = 0;
		}
	}
	if (is_flag(format[*f_index]))
	{
		/* flags */
	}
	else
	{
		/* percision */
	}
}
