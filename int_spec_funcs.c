#include "holberton.h"
#include <stdlib.h>
unsigned int _abs(int);
/**
 * get_int - gets a character pointer to new string containing int
 * @args: va_list to get integer from and create str
 * @mods: array containing length modifier bytes, representing t/f for l & h
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_int(va_list args, char *mods)
{
	int num, length;
	unsigned int temp;
	char *ret;

	if (mods[0] > 0 && mods[1] == 0) /* l byte is lit, h is not */
		num = va_arg(args, long int);
	else if (mods[1] > 0 && mods[0] == 0) /* h byte lit, l is not */
		num = va_arg(args, int);
	else /* both are lit (cancels out), or no length mods are lit */
		num = va_arg(args, int);
	temp = _abs(num);
	length = get_numbase_len(temp, 10);
	if (num < 0)
		length++; /* negative sign */

	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	temp = _abs(num);
	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * get_binary - convert unsigned integer to binary representation.
 * @args: va_list containing the unsigned integer.
 * @mods: length modifiers, voided, not used with this specifier
 *
 * Return: char pointer to the binary string. NULL if malloc fails.
 */

char *get_binary(va_list args, char *mods)
{
	unsigned int num;
	int length;
	char *ret;

	(void)mods;
	num = va_arg(args, unsigned int);
	length = get_numbase_len(num, 2);

	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(num, 2, ret, length);

	return (ret);
}
/**
 * get_unsigned - gets a string representing an unsigned integer
 * @args: va_list to get unsigned integer from
 * @mods: array containing length modifier bytes, representing t/f for l & h
 *
 * Return: char pointer to new memory location of string
 */
char *get_unsigned(va_list args, char *mods)
{
	unsigned int num;
	int length;
	char *ret;

	if (mods[0] > 0 && mods[1] == 0) /* l byte is lit, h is not */
		num = va_arg(args, unsigned long int);
	else if (mods[1] > 0 && mods[0] == 0) /* h byte lit, l is not */
		num = va_arg(args, int);
	else /* both are lit (cancels out), or no length mods are lit */
		num = va_arg(args, unsigned int);
	length = get_numbase_len(num, 10);

	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(num, 10, ret, length);

	return (ret);
}

/**
 * get_octal - gets a string representing an unsigned octal.
 * @args: va_list to get unsigned octal from.
 * @mods: array containing length modifier bytes, representing t/f for l & h
 *
 * Return: char pointer to new memory location of string. NULL if malloc fails.
 */

char *get_octal(va_list args, char *mods)
{
	unsigned int num;
	int length;
	char *ret;

	if (mods[0] > 0 && mods[1] == 0) /* l byte is lit, h is not */
		num = va_arg(args, unsigned long int);
	else if (mods[1] > 0 && mods[0] == 0) /* h byte lit, l is not */
		num = va_arg(args, int);
	else /* both are lit (cancels out), or no length mods are lit */
		num = va_arg(args, unsigned int);
	length = get_numbase_len(num, 8);
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(num, 8, ret, length);

	return (ret);
}

/**
 * _abs - gets absolute value of integer
 * @n: integer to get absolute value for
 *
 * Return: unsigned int containing abs
 */
unsigned int _abs(int n)
{
	return ((n < 0) ? -(unsigned int)n : (unsigned int)n);
}
