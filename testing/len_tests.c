#include <stdio.h>
#include "holberton.h"
#include <limits.h>
int main(void)
{
	int len, len2;

	len = _printf("long digit:%ld\n", LONG_MAX);
	len2 = printf("long digit:%ld\n", LONG_MAX);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("long octal:%lo\n", LONG_MAX);
	len2 = printf("long octal:%lo\n", LONG_MAX);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("long digit: There is %ld bytes in %ld KB\n", 1024L, 1L);
	len2 = printf("long digit: There is %ld bytes in %ld KB\n", 1024L, 1L);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("long digit: %ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	len2 = printf("long digit: %ld + %ld = %ld\n", LONG_MIN, LONG_MAX, (LONG_MIN + LONG_MAX));
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("long octal: %lo - %lo = %lo\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	len2 = printf("long octal: %lo - %lo = %lo\n", ULONG_MAX, 2048UL, ULONG_MAX - 2048UL);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);


	len = _printf("long X with 0: %lX", 0UL);
	len2 = printf("long X with 0: %lX", 0UL);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	

	len = _printf("long X with MAX: %lX", ULONG_MAX);
	len2 = printf("long X with MAX: %lX", ULONG_MAX);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);



	return (0);
}
