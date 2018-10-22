#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>

char *get_hex_n(unsigned int num);

/**
 * get_hex_n - gets a string that is the hex representation of an integer.
 * @num: The unsigned integer.
 *
 * Return: char pointer to the string representation. NULL if malloc fails.
 */
char *get_hex_n(unsigned int num)
{
	int length;
	char *ret;

	length = get_numbase_len(num, 16);
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(num, 16, ret, length);
	return (ret);
}
/**
 * get_hex - gets a string that is the hex representation of an integer
 * @args: va_list to get integer for conversion from
 *
 * Return: char pointer to new hex string
 */
char *get_hex(va_list args)
{
	unsigned int num;

	num = va_arg(args, unsigned int);

	return (get_hex_n(num));
}
/**
 * get_hex_upper - gets a string that is the upper case hex rep of an integer
 * @args: va_list to get integer for conversion from
 *
 * Return: char pointer to new hex string
 */
char *get_hex_upper(va_list args)
{
	char *ret;
	int i = 0;

	ret = get_hex(args);
	while (ret[i])
	{
		if (ret[i] >= 'a' && ret[i] <= 'z')
			ret[i] -= 32;
		i++;
	}
	return (ret);
}
/**
 * get_pointer - gets a string that contains an address in hexadecimals.
 * @args: va_list to get hexadecimal from.
 *
 * Return: char pointer to the string. NULL if malloc fails.
 */
char *get_pointer(va_list args)
{
	int length, i;
	unsigned long int addr, temp, rem;
	char *ret;

	addr = va_arg(args, unsigned long int);
	length = 1;
	temp = addr;
	while (temp > 15)
	{
		temp /= 16;
		length++;
	}

	ret = malloc(2 + length + 1);
	if (!ret)
		return (NULL);

	ret[0] = '0';
	ret[1] = 'x';
	ret[2 + length] = '\0';

	i = 2 + length - 1;

	while (i > 1)
	{
		rem = addr % 16;
		if (rem > 9)
			ret[i] = rem + 87;
		else
			ret[i] = rem + '0';
		addr /= 16;
		i--;
	}

	return (ret);
}
