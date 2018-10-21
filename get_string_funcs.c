#include "holberton.h"
#define NULL 0
/**
 * get_string_func - gets a pointer to a function
 * @ch: char to match with specifier function
 *
 * Return: pointer to a function that takes va_list and returns char *
 */
char *(*get_string_func(char ch))(va_list)
{
	spec_t specs[] = {
		{ 'c', get_char },
		{ 's', get_string },
		{ '%', get_percent },
		{ NULL, NULL }
	};
	int i = 0;

	while(specs[i].t != ch)
		i++;
	return (specs[i].f)
}
