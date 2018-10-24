#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
int print_helper(printh_t *help_s, va_list args);

void get_width_precision(printh_t *help_s va_list args);
char *perform_flag_funcs(int *flags, char *str, char spec);
/**
  * _printf - Prints variatic arguments based on format string.
  * @format: String passed, may contain zero, or more directives.
  *
  * Return: Number of characters printed to stdout.
  */

int _printf(const char *format, ...)
{
	char *buff;
	/* ind == *f_ind of struct */
	unsigned int length;
	int E;
	va_list args;
	int flags[3] = {0};

	if (!format)
		return (-1);
	buff = create_buff(BUFF_SIZE);
	if (!buff)
		return (-1);
	va_start(args, format);
	printh_t help_s = { format, buff, 0, 0, 0, 0, 0, 0, 0, 0, &flags };
	length = 0, E = 0;

	while (format[help_s.f_i])
	{
		if (format[help_s.f_i] == '%' && !help_s.busy)
		{
			help_s.beg_i = help_s.f_i;
			help_s.busy = 1;
			if (format[help_s.f_i + 1] == '\0')
			{
				if (help_s.spec_c)
				{
					buff[help_s.buff_i++] = format[help_s.f_i];
					help_s.busy = 0;
				}
				else
				{
					free(buff);
					va_end(args);
					return (-1);
				}
			}
		}
		else if (help_s.busy)
		{
			E = print_helper(&help_s, args);
			if (!E)
			{
				free(buff);
				va_end(args);
				return (-1);
			}
		}
		else
			buff[help_s.buff_i++] = format[help_s.f_i];
		help_s.f_i++;
	}
	if (help_s.busy && format[help_s.f_i] == '\0')
	{
		print_buff(buff, help_s.beg_i - 1);
		return (-1);
	}
	if (help_s.buff_i > BUFF_SIZE)
		help_s.buff_i = BUFF_SIZE;
	length = print_buff(buff, help_s.buff_i);
	free(buff);
	va_end(args);
	return (length);
}
/**
 * print_helper - print helper function to split up logic of _printf
 * @help_s: pointer to our helper struct to contain variables for passing
 * @args: va_list of args to advance and use
 *
 * Return: 1 on success, 0 on failure
 */
int print_helper(printfh_t *help_s, va_list args)
{
	char *temp;
	int flag_index, i = 0;

	flag_index = is_flag(help_s->format[help_s->f_i]);
	if (flag_index > -1)
		help_s->flags[help_s->f_i] = 1;
	else
		(help_s->spec_c)++;
	if (_isalpha(help_s->format[help_s->f_i])
		|| help_s->format[help_s->f_i] == '%')
	{
		if (is_specifier(help_s->format[help_s->f_i]))
		{
			temp = get_string_func(help_s->format[help_s->f_i])(args);
			if (!temp)
				return (0);
			if (temp[0] == '\0' && help_s->format[help_s->f_i] == 'c')
			{
				for (i = 0; i < help_s->width - 1; i++)
					help_s->buff[(help_s->buff_i)++] = ' ';
				help_s->buff[(help_s->buff_i)++] = '\0';
				help_s->busy = 0;
				return (1);
			}
			else
			{
				temp = perform_flag_funcs(help_s->flags, temp,
						help_s->format[help_s->f_i]);
				temp = do_width(temp, help_s->width, 1);
			}
			if (!temp)
				return (0);
			copy_buff(temp, help_s->buff_i, help_s->buff, BUFF_SIZE);
			help_s->busy = 0;
		}
		else
		{
			help_s->f_i = help_s->beg_i;
			help_s->buff[(help_s->buff_i)++] = help_s->format[help_s->f_i];
			help_s->busy = 0;
		}
	}
	else if (_isdigit(help_s->format[help_s->f_i]) ||
		help_s->format[help_s->f_i] == '.' || help_s->format[help_s->f_i] == '*')
		get_width_precision(help_s, args);
	else if (help_s->format[(help_s->f_i) + 1] == '\0')
	{
		if (help_s->spec_c)
		{
			help_s->f_i = help_s->beg_i;
			help_s->buff[(help_s->buff_i)++] = help_s->format[help_s->f_i];
			help_s->busy = 0;
		}
		else
			return (0);
	}
	return (1);
}
/**
 * get_width_precision - gets the width and precision for a format string
 * @c: character currently present in loop over format string
 * @width: pointer to our width, default starts at 0
 * @precision: pointer to our precision, default starts at 0
 * @dot: pointer to a integer representing true/false if we found a dot
 * @args: pointer to our args to pull width from if * specified instead of num
 *
 * Return: always void
 */
void get_width_precision(printfh_t *help_s, va_list args)
{
	if (c == '.')
		*dot = 1;
	else if (_isdigit(c))
	{
		c -= '0';
		if (!dot)
			*width = (c + (*width * 10));
		else
			*precision = (c + (*precision * 10));
	}
	else if (c == '*')
	{
		if (!dot)
			*width = va_arg(args, int);
		else
			*precision = va_arg(args, int);
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
			if (!temp)
				return (NULL);
		}
	}
	return (temp);
}
