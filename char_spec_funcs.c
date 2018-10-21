#include "holberton.h"
char *get_char(va_list args)
{
	char str[] = { 't', '\0' };

	str[0] = va_arg(args, char);
	return (str);
}
char *get_string(va_list args)
{
	return (va_arg(args, char *));
}
char *get_percent(va_list args)
{
	return ("%");
}
