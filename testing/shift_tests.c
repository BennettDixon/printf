#include <stdio.h>
#include "holberton.h"

int main()
{
	int len;
	int len2;

	len = _printf("%%-d, 10: [%-d]\n", 10);
	len2 = printf("%%-d, 10: [%-d]\n", 10);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 1: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-10d, 10: [%-10d]\n", 10);
	len2 = printf("%%-10d, 10: [%-10d]\n", 10);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 2: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-*d, 10, 20: [%-*d]\n", 10, 20);
	len2 = printf("%%-*d, 10, 20: [%-*d]\n", 10, 20);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 3: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-10y, 30: [%-10y]\n", 30);
	len2 = printf("%%-10y, 30: [%-10y]\n", 30);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 4: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-*y, 5, 30: [%-*y]\n", 5, 30);
	len2 = printf("%%-*y, 5, 30: [%-*y]\n", 5, 30);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 5: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-10c: [%-10c]\n", 'H');
	len2 = printf("%%-10c: [%-10c]\n", 'H');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 6: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-*c: [%-*c]\n", 10, 'c');
	len2 = printf("%%-*c: [%-*c]\n", 10, 'c');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 7: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-10s: [%-10s]\n", "Hello");
	len2 = printf("%%-10s: [%-10s]\n", "Hello");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 8: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-10o, 100: [%-10o]\n", 100);
	len2 = printf("%%-10o, 100: [%-10o]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 9: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-10x, 100: [%-10x]\n", 100);
	len2 = printf("%%-10x, 100: [%-10x]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 10: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-20p: [%-20p]\n", (void *)0x7ffe637541f0);
	len2 = printf("%%-20p: [%-20p]\n", (void *)0x7ffe637541f0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 11: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-2c: [%-2c]\n", '\0');
	len2 = printf("%%-2c: [%-2c]\n", '\0');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 12: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
