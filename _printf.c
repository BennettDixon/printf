#include "holberton.h"

/** _printf - Prints variatic arguments based on format string.
  * @format: String passed, may contain zero, or more directives.
  *
  * Return: Number of characters printed to stdout.
  */

int _printf(const char *format, ...)
{
	char *buff, *temp, busy;
	unsigned int ind, buff_i;
	va_list args;

	if (!format)
		return (0);

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
	return (print_buff(buff, buff_i + 1));
}
