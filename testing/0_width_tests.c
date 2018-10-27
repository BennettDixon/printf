#include <stdio.h>
#include "holberton.h"

int main()
{
	int len;
	int len2;

	len = _printf("10 width on integer: [%0*d]\n", 10, 100);
	len2 = printf("10 width on integer: [%0*d]\n", 10, 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("10 width on negative integer: [%0*d]\n", 10, -1100);
	len2 = printf("10 width on negative integer: [%0*d]\n", 10, -1100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("6 width with sign: [%+06d]\n", 10);
	len2 = printf("6 width with sign: [%+06d]\n", 10);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("20 width and no width on integers: [%0*d|%i]\n", 20, 15, 30);
	len2 = printf("20 width and no width on integers: [%0*d|%i]\n", 20, 15, 30);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("5 width then 10 width on integers: [%0*d %0*i]\n", 5, 20, 10, 30);
	len2 = printf("5 width then 10 width on integers: [%0*d %0*i]\n", 5, 20, 10, 30);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("10 width on string: [%010s]\n", "hello");
	len2 = printf("10 width on string: [%010s]\n", "hello");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("10 width on character: [%010c]\n", 'c');
	len2 = printf("10 width on character: [%010c]\n", 'c');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%0y: [%0y]\n", 'c');
	len2 = printf("%%0y: [%0y]\n", 'c');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("10 width on unsigned: [%010d]\n", 100);
	len2 = printf("10 width on unsigned: [%010d]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("10 width on octal: [%010o]\n", 100);
	len2 = printf("10 width on octal: [%010o]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("10 width on hex: [%010x]\n", 100);
	len2 = printf("10 width on hex: [%010x]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("20 width on pointer: [%020p]\n", (void *)0x7ffe637541f0);
	len2 = printf("20 width on pointer: [%020p]\n", (void *)0x7ffe637541f0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("2 width on nullbyte character: [%02c]\n", '\0');
	len2 = printf("2 width on nullbyte character: [%02c]\n", '\0');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	return (0);
}



