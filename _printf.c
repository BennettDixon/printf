#include "holberton.h"
#include <stdlib.h>
int print_helper(printh_t *help_s, va_list args);
char *perform_flag_funcs(int *flags, char *str, char spec);
printh_t *init_help_s(const char *);
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
	help_s = init_help_s(format);
	if (!help_s)
	{
		va_end(args);
		return (-1);
	}
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
		else if (!(format[help_s->f_i] == 'l' && help_s->mods[0])
			&& !(format[help_s->f_i] == 'h' && help_s->mods[1]))
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
	int flag_index, mod_index, i = 0;

	flag_index = is_flag(help_s->format[help_s->f_i],
			help_s->format[help_s->f_i - 1]);
	mod_index = is_modifier(help_s->format[help_s->f_i]);
	if (flag_index > -1)
		help_s->flags[flag_index] = 1;
	else if (!mod_index)
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
			{
				if (help_s->dot)
					temp = do_precision(temp,
							help_s->precision,
						help_s->format[help_s->f_i]);
				if (help_s->format[help_s->f_i] == 'p' && temp[0] != '(')
					temp = do_hex_flag(temp);
				temp = perform_flag_funcs(help_s->flags, temp,
						help_s->format[help_s->f_i]);
				if (help_s->flags[3])
					temp = do_shift(temp, help_s->width);
				if (help_s->flags[4] && help_s->format[help_s->f_i] != 's'
						&& help_s->format[help_s->f_i] != 'c')
					temp = do_width(temp, help_s->width, 1);
				else
					temp = do_width(temp, help_s->width, 0);
			}
			if (!temp)
				return (0);
			help_s->buff_len += copy_buff(temp, help_s);

			exit_busy_reset(help_s);
		}
		else if (mod_index)
		{
			switch (help_s->format[help_s->f_i])
			{
				case ('l'):
					help_s->mods[0] = mod_index;
					break;
				case ('h'):
					help_s->mods[1] = mod_index;
					break;
				default:
					break;
			}
		}
		else
		{
			if (help_s->mods[0] || help_s->mods[1])
				(help_s->spec_c)++;
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
 * init_help_s - initializes print helper structure, creating space for it
 * @format: pointer to format specifier string to set as pointer
 *
 * Return: pointer to structure created in memory
 */
printh_t *init_help_s(const char *format)
{
	printh_t *help_s;

	help_s = malloc(sizeof(*help_s));
	if (!help_s)
		return (NULL);
	help_s->flags = calloc(5, sizeof(int));
	if (!help_s->flags)
	{
		free(help_s);
		return (NULL);
	}
	help_s->mods = calloc(2, sizeof(char));
	if (!help_s->mods)
	{
		free(help_s->flags);
		free(help_s);
		return (NULL);
	}
	help_s->buff = create_buff(BUFF_SIZE);
	if (!help_s->buff)
	{
		free(help_s->mods);
		free(help_s->flags);
		free(help_s);
		return (NULL);
	}
	help_s->c = create_buff(2);
	if (!help_s->c)
	{
		free(help_s->buff);
		free(help_s->mods);
		free(help_s->flags);
		free(help_s);
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
 * perform_flag_funcs - Perform flag functions that were encountered on the
 * string.
 * @flags: An array int to keep track of which flags were encountered. 1 if
 * encountered, otherwise 0.
 * @temp: The string to perform functions on.
 * @spec: The specifier.
 *
 * Return: char pointer to the formatted string.
 */

char *perform_flag_funcs(int *flags, char *temp, char spec)
{
	int i;
	char *(*f)(char *);

	for (i = 0; i < 5; i++)
	{
		if (flags[i])
		{
			f = get_flag_func(i, spec);
			if (f)
				temp = f(temp);
			if (!temp)
				return (NULL);
		}
	}
	return (temp);
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
