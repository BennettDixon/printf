#include <stdio.h>
#include "holberton.h"

int main()
{
	int len;
	int len2;

	len = _printf("%%-d: [%-d]\n", 10);
	len2 = printf("%%-d: [%-d]\n", 10);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%-10d: [%-10d]\n", 10);
	len2 = printf("%%-10d: [%-10d]\n", 10);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%-*d: [%-*d]\n", 10, 20);
	len2 = printf("%%-*d: [%-*d]\n", 10, 20);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%-10y: [%-10y]\n",30);
	len2 = printf("%%-10y: [%-10y]\n", 30);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%-*y: [%-*y]\n", 5, 30);
	len2 = printf("%%-*y: [%-*y]\n", 5, 30);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%-10c: [%-10c]\n", 'H');
	len2 = printf("%%-10c: [%-10c]\n", 'H');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%-*c: [%-*c]\n", 10, 'c');
	len2 = printf("%%-*c: [%-*c]\n", 10, 'c');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%-10s: [%-10s]\n", "Hello");
	len2 = printf("%%-10s: [%-10s]\n", "Hello");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%-10o: [%-10o]\n", 100);
	len2 = printf("%%-10o: [%-10o]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%-10x: [%-10x]\n", 100);
	len2 = printf("%%-10x: [%-10x]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%-20p: [%-20p]\n", (void *)0x7ffe637541f0);
	len2 = printf("%%-20p: [%-20p]\n", (void *)0x7ffe637541f0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%-2c: [%-2c]\n", '\0');
	len2 = printf("%%-2c: [%-2c]\n", '\0');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	return (0);
}



