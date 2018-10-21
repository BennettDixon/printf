#include "holberton.h"
/**
 * get_char - gets a pointer to an array containing char and null byte
 * @args: va_list to get argument from of type char
 *
 * Return: pointer to array containing char and null byte
 */
char *get_char(va_list args)
{
	char str[] = { 't', '\0' };

	str[0] = va_arg(args, char);
	return (str);
}
/**
 * get_string - gets a pointer to a string, null terminated
 * @args: va_list to get argument of type char *
 *
 * Return: pointer to beginning of string
 */
char *get_string(va_list args)
{
	return (va_arg(args, char *));
}
/**
 * get_percent - gets a pointer to a string literal containing "%\0"
 * @args: va_list required for function pointer, voided, not used
 *
 * Return: pointer to string literal containing %
 */
char *get_percent(va_list args)
{
	void(args);
	return ("%");
}
