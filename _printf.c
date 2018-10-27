#include "holberton.h"
#include <stdlib.h>
int print_helper(printh_t *help_s, va_list args);
char *perform_sub_specs(char *temp, printh_t *help_s);
printh_t *init_help_s(const char *, va_list args);
void exit_busy_reset(printh_t *help_s);
/**
  * _printf - Prints variatic arguments based on format string.
  * @format: String passed, may contain zero, or more directives.
  *
  * Return: Number of characters printed to stdout.
  */

int _printf(const char *format, ...)
{
	int E;
	unsigned int t_bytes;
	va_list args;
	printh_t *help_s;

	if (!format)
		return (-1);
	va_start(args, format);
	help_s = init_help_s(format, args);
	if (!help_s)
		return (-1);
	E = 0;

	while (format[help_s->f_i])
	{
		if (format[help_s->f_i] == '%' && !help_s->busy)
		{
			help_s->beg_i = help_s->f_i;
			help_s->busy = 1;
			if (format[help_s->f_i + 1] == '\0')
			{
				if (help_s->spec_c)
				{
					help_s->buff[help_s->buff_i++] = format[help_s->f_i];
					help_s->buff_len++;
					exit_busy_reset(help_s);
				}
				else
				{
					free_all(help_s, args);
					return (-1);
				}
			}
		}
		else if (help_s->busy)
		{
			E = print_helper(help_s, args);
			if (!E)
			{
				free_all(help_s, args);
				return (-1);
			}
		}
		else
		{
			help_s->c[0] = format[help_s->f_i];
			help_s->c[1] = '\0';
			help_s->buff_len += copy_buff(help_s->c, help_s);
		}
		help_s->f_i++;
	}
	if (help_s->busy && format[help_s->f_i] == '\0')
	{
		print_buff(help_s->buff, help_s->beg_i - 1);
		free_all(help_s, args);
		return (-1);
	}
	print_buff(help_s->buff, help_s->buff_i);
	t_bytes = help_s->buff_len;
	free_all(help_s, args);
	return (t_bytes);
}
/**
 * print_helper - print helper function to split up logic of _printf
 * @help_s: pointer to our helper struct to contain variables for passing
 * @args: va_list of args to advance and use
 *
 * Return: 1 on success, 0 on failure
 */
int print_helper(printh_t *help_s, va_list args)
{
	char *temp;
	int flag_index, i = 0;

	flag_index = is_flag(help_s->format[help_s->f_i],
			help_s->format[help_s->f_i - 1]);
	if (flag_index > -1)
		help_s->flags[flag_index] = 1;
	else if (!is_modifier(help_s->format[help_s->f_i]))
		(help_s->spec_c)++;
	if (_isalpha(help_s->format[help_s->f_i])
		|| help_s->format[help_s->f_i] == '%')
	{
		if (is_specifier(help_s->format[help_s->f_i]))
		{
			temp = get_string_func(help_s->format[help_s->f_i])(args, help_s->mods);
			if (!temp)
				return (0);
			if (temp[0] == '\0' && help_s->format[help_s->f_i] == 'c')
			{
				for (i = 0; i < help_s->width - 1; i++)
					help_s->buff[help_s->buff_i++] = ' ';
				help_s->buff[help_s->buff_i++] = '\0';
				if (help_s->width)
					help_s->buff_len += help_s->width - 1;
				help_s->buff_len++;
				exit_busy_reset(help_s);
				free(temp);
				return (1);
			}
			else
				temp = perform_sub_specs(temp, help_s);
			if (!temp)
				return (0);
			help_s->buff_len += copy_buff(temp, help_s);

			exit_busy_reset(help_s);
		}
		else if (is_modifier(help_s->format[help_s->f_i]))
		{
			switch (help_s->format[help_s->f_i])
			{
				case ('l'):
					help_s->mods[0] = 1;
					break;
				case ('h'):
					help_s->mods[1] = 1;
					break;
				default:
					break;
			}
		}
		else
		{
			help_s->f_i = help_s->beg_i;
			help_s->buff[(help_s->buff_i)++] = help_s->format[help_s->f_i];
			help_s->buff_len++;
			exit_busy_reset(help_s);
		}
	}
	else if (_isdigit(help_s->format[help_s->f_i]) ||
			help_s->format[help_s->f_i] == '.' ||
			help_s->format[help_s->f_i] == '*')
		get_width_precision(help_s, args);
	else if (help_s->format[(help_s->f_i) + 1] == '\0')
	{
		if (help_s->spec_c)
		{
			help_s->f_i = help_s->beg_i;
			help_s->buff[(help_s->buff_i)++] = help_s->format[help_s->f_i];
			help_s->buff_len++;
			exit_busy_reset(help_s);
		}
		else
			return (0);
	}
	return (1);
}
/**
 * perform_sub_specs - Performs sub specifier formats on the specifier string.
 * @temp: Pointer to string of the specifier.
 * @help_s: Pointer to structure containing information on all the flags seen
 * between the % and the specifier.
 *
 * Longer description: Performs precision on the string if precision was seen.
 * Next if the specifier is a pointer and the string does not contain '(' from
 * (nil) (for null pointers) append 0x to the string. Afterwards, ' ', '+', '0'
 * , '0x', '0X' is appended for applicable integer values if the flags ' ', '+'
 * ,'#' was set. Left justified is performed on the string next if '-' flag was
 * specified with a value. If left justified is performd, width that is
 * performed next will not occur.Lastly width, padding with either zeroes or
 * spaces is applied if the flags was set. Width with padding for zeroes will
 * not occur is precision was performed; if a width was specified with
 * precision, the string will be padded with spaces.
 *
 * Returns: A formatted specifier string.
 */
char *perform_sub_specs(char *temp, printh_t *help_s)
{
	char current_spec;
	int precision, width, dot_flag, shift_flag, zero_flag;

	current_spec = help_s->format[help_s->f_i];
	precision = help_s->precision;
	width = help_s->width;
	dot_flag = help_s->dot;
	shift_flag = help_s->flags[3];
	zero_flag = help_s->flags[4];

	if (dot_flag)
	{
		temp = do_precision(temp, precision, current_spec);
		zero_flag = 0;
	}
	if (current_spec == 'p' && temp[0] != '(')
		/* append 0x to pointer if it is not (nil) */
		temp = do_hex_flag(temp);
	temp = perform_flag_funcs(help_s->flags, temp, current_spec);
	if (shift_flag)
	{
		temp = do_shift(temp, width);
		zero_flag = 0;
		width = 0;
	}
	if (zero_flag && current_spec != 's' && current_spec != 'c')
		temp = do_width(temp, width, 1);
	else
		temp = do_width(temp, width, 0);

	return (temp);
}
/**
 * init_help_s - initializes print helper structure, creating space for it
 * @format: pointer to format specifier string to set as pointer
 * @args: va_list pointer, will be sent to free_all to have memory freed if a
 * malloc fails.
 *
 * Return: pointer to structure created in memory
 */
printh_t *init_help_s(const char *format, va_list args)
{
	printh_t *help_s;

	help_s = malloc(sizeof(*help_s));
	if (!help_s)
	{
		va_end(args);
		return (NULL);
	}
	help_s->flags = calloc(5, sizeof(int));
	if (!help_s->flags)
	{
		free_all(help_s, args);
		return (NULL);
	}
	help_s->mods = calloc(2, sizeof(char));
	if (!help_s->mods)
	{
		free_all(help_s, args);
		return (NULL);
	}
	help_s->buff = create_buff(BUFF_SIZE);
	if (!help_s->buff)
	{
		free_all(help_s, args);
		return (NULL);
	}
	help_s->c = create_buff(2);
	if (!help_s->c)
	{
		free_all(help_s, args);
		return (NULL);
	}
	help_s->format = format;
	help_s->dot = 0;
	help_s->busy = 0;
	help_s->f_i = 0;
	help_s->buff_i = 0;
	help_s->beg_i = 0;
	help_s->buff_len = 0;
	help_s->width = 0;
	help_s->precision = 0;
	help_s->spec_c = 0;
	return (help_s);
}


/**
 * exit_busy_reset - Reset values of busy, width, precision, and dot to zero
 * upon exit of busy.
 * @help_s: Pointer to structure.
 *
 * Return: Void.
 */

void exit_busy_reset(printh_t *help_s)
{
	int i;

	help_s->busy = 0;
	help_s->width = 0;
	help_s->precision = 0;
	help_s->dot = 0;

	for (i = 0; i < 5; i++)
		help_s->flags[i] = 0;
}
