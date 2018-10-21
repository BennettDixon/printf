#include "holberton.h"
#include <stdlib.h>
unsigned int _abs(int);
/**
 * get_int - gets a character pointer to new string containing int
 * @args: va_list to get integer from and create str
 *
 * Return: character pointer to newly created string. NULL if malloc fails.
 */
char *get_int(va_list args)
{
	int num, i, length;
	unsigned int temp;
	char *ret;

	length = 1; /* numbers always contain 1 digit */
	num = va_arg(args, int);
	if (num < 0)
		length++; /* negative sign */
	temp = _abs(num);
	while (temp > 9) /* get length of integer */
	{
		length++;
		temp /= 10;
	}

	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	ret[length] = '\0';
	i = length - 1;
	temp = _abs(num);
	while (i >= 0) /* put integer in new string */
	{
		if (num < 0 && i == 0)
		{
			ret[i] = '-';
			break;
		}
		ret[i] = temp % 10 + '0';
		temp /= 10;
		i--;
	}
	return (ret);
}

/**
 * get_binary - convert unsigned integer to binary representation.
 * @args: va_list containing the unsigned integer.
 *
 * Return: char pointer to the binary string. NULL if malloc fails.
 */

char *get_binary(va_list args)
{
	unsigned int num, bit;
	int length, i;
	char *ret;

	bit = 1;
	length = 1;
	num = va_arg(args, unsigned int);

	while (num > bit * 2)
	{
		bit *= 2;
		length++;
	}

	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	for (i = 0; i < length; i++)
	{
		if (bit <= num)
		{
			ret[i] = '1';
			num -= bit;
		}
		else
		{
			ret[i] = '0';
		}
		bit /= 2;
	}
	ret[length] = '\0';

	return (ret);
}
/**
 * get_unsigned - gets a string representing an unsigned integer
 * @args: va_list to get unsigned integer from
 *
 * Return: char pointer to new memory location of string
 */
char *get_unsigned(va_list args)
{
	unsigned int num, temp;
	int i, length;
	char *ret;

	length = 1; /* numbers always contain 1 digit */
	num = va_arg(args, unsigned int);
	temp = num;

	while (temp > 9) /* get length of integer */
	{
		length++;
		temp /= 10;
	}

	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	ret[length] = '\0';
	i = length - 1;
	temp = num;
	while (i >= 0) /* put integer in new string */
	{
		ret[i] = temp % 10 + '0';
		temp /= 10;
		i--;
	}
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
