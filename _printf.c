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
			if (_isalpha(format[ind]) || format[ind] == '%')
			{
				if (is_specifier(format[ind]))
				{
					temp = get_string_func(format[ind])(args);
					if (!temp)
					{
						free(buff);
						va_end(args);
						return (0);
					}
					/* check if flag function null*/
					/* check if precision function null */
					copy_buff(temp, &buff_i, buff, BUFF_SIZE);
					busy = 0;
				}
				else
				{
					ind = beg_ind;
					buff[buff_i++] = format[ind];
					busy = 0;
				}
			}
			if (is_flag(format[ind]))
			{
				/* flags */
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
