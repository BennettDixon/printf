#include "holberton.h"
#include <stdlib.h>
unsigned int _abs(int);
/**
 * get_int - gets a character pointer to new string containing int
 * @args: va_list to get integer from and create str
 *
 * Return: character pointer to newly created string
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
	i = length;
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
 * _abs - gets absolute value of integer
 * @n: integer to get absolute value for
 *
 * Return: unsigned int containing abs
 */
unsigned int _abs(int n)
{
	return ((n < 0) ? -(unsigned int)n : (unsigned int)n);
}
