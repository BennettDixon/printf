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
	unsigned int ind, buff_i, length;
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
			busy = 1;
		}
		else if (busy)
		{
			if (is_flag(format[ind]))
			{
				/* flags */
			}
			else if (is_specifier(format[ind]))
			{
				temp = get_string_func(format[ind])(args);
				if (!temp)
				{
					free(buff);
					va_end(args);
					return (0);
				}
				printf("temp: %s\n", temp);
				copy_buff(temp, &buff_i, buff, BUFF_SIZE);
				busy = 0;
			}
			else /* percision */
			{
			}
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
