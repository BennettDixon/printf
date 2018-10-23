#include "holberton.h"
#include <stdlib.h>

void print_helper(const char *format, unsigned int *, char *, unsigned int *,
		char *, unsigned int *, int *, va_list);

char *perform_flag_funcs(int *flags, char *str, char spec);
/**
  * _printf - Prints variatic arguments based on format string.
  * @format: String passed, may contain zero, or more directives.
  *
  * Return: Number of characters printed to stdout.
  */

int _printf(const char *format, ...)
{
	char *buff, busy;
	unsigned int ind, beg_ind, buff_i, length;
	va_list args;
	int flags[3] = {0};

	buff = create_buff(BUFF_SIZE);
	if (!format || !buff)
		return (-1);
	va_start(args, format);
	length = 0;
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
					&beg_ind, flags, args);
		}
		else
			buff[buff_i++] = format[ind];
		ind++;
	}
	if (buff_i > BUFF_SIZE)
		buff_i = BUFF_SIZE;
	length = print_buff(buff, buff_i);
	free(buff);
	va_end(args);
	return (length);
}
/**
 * print_helper - print helper function to split up logic of _printf
 * @format: pointer to format string
 * @f_index: pointer to index of format string
 * @buff: pointer to buffer
 * @b_index: pointer to index of buffer
 * @busy: pointer to printf isbusy
 * @beg_index: pointer to beginning index (where % was found)
 * @flags: pointer to int array pertaining to flag's being used
 * @args: va_list to get argument from
 *
 * Return: always void
 */
void print_helper(const char *format, unsigned int *f_index, char *buff,
		unsigned int *b_index, char *busy, unsigned int *beg_index,
		int *flags, va_list args)
{
	char *temp;
	int flag_index;

	if (_isalpha(format[*f_index]) || format[*f_index] == '%'
		|| format[(*f_index) + 1] == '\0')
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
			if (temp[0] == '\0' && format[*f_index] == 'c')
				buff[(*b_index)++] = temp[0];
			else
				temp = perform_flag_funcs(flags, temp,
							format[*f_index]);
			copy_buff(temp, b_index, buff, BUFF_SIZE);
			*busy = 0;
		}
		else
		{
			*f_index = *beg_index;
			buff[(*b_index)++] = format[*f_index];
			*busy = 0;
		}
	}
	flag_index = is_flag(format[*f_index]);
	if (flag_index > -1)
		flags[flag_index] = 1;
	else
	{
		/* percision */
	}
}

/**
 * perform_flag_funcs - Perform flag functions that were encountered on the
 * string.
 * @flags: An array int to keep track of which flags were encountered. 1 if
 * encountered, otherwise 0.
 * @temp: The string to perform functions on.
 * @spec: The specifier.
 * Return: char pointer to the formatted string.
 */

char *perform_flag_funcs(int *flags, char *temp, char spec)
{
	int i;
	char *(*f)(char *);

	for (i = 0; i < 3; i++)
	{
		if (flags[i])
		{
			f = get_flag_func(i, spec);
			flags[i] = 0;
			if (f)
				temp = f(temp);
		}
	}
	return (temp);
}
