#include <stdio.h>
#include "holberton.h"

int main()
{
	int len;
	int len2;

	len = _printf("10 width on integer: [%*d]\n", 10, 100);
	len2 = printf("10 width on integer: [%*d]\n", 10, 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("20 width and no width on integers: [%*d|%i]\n", 20, 15, 30);
	len2 = printf("20 width and no width on integers: [%*d|%i]\n", 20, 15, 30);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("5 width then 10 width on integers: [%*d %*i]\n", 5, 20, 10, 30);
	len2 = printf("5 width then 10 width on integers: [%*d %*i]\n", 5, 20, 10, 30);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("10 width on string: [%10s]\n", "hello");
	len2 = printf("10 width on string: [%10s]\n", "hello");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("10 width on character: [%10c]\n", 'c');
	len2 = printf("10 width on character: [%10c]\n", 'c');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("10 width on unsigned: [%10d]\n", 100);
	len2 = printf("10 width on unsigned: [%10d]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("10 width on octal: [%10o]\n", 100);
	len2 = printf("10 width on octal: [%10o]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("10 width on hex: [%10x]\n", 100);
	len2 = printf("10 width on hex: [%10x]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("20 width on pointer: [%20p]\n", (void *)0x7ffe637541f0);
	len2 = printf("20 width on pointer: [%20p]\n", (void *)0x7ffe637541f0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("2 width on nullbyte character: [%2c]\n", '\0');
	len2 = printf("2 width on nullbyte character: [%2c]\n", '\0');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	return (0);
}



