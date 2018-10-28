#include <stdio.h>
#include "holberton.h"

int main()
{
	int len;
	int len2;

	len = _printf("%%*d, 10, 100: [%*d]\n", 10, 100);
	len2 = printf("%%*d, 10, 100: [%*d]\n", 10, 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 1: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%*d|%%i, 20, 15, 30: [%*d|%i]\n", 20, 15, 30);
	len2 = printf("%%*d|%%i: 20, 15, 30: [%*d|%i]\n", 20, 15, 30);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 2: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%*d %%*i, 5, 20, 10, 30: [%*d %*i]\n", 5, 20, 10, 30);
	len2 = printf("%%*d %%*i, 5, 20, 10, 30: [%*d %*i]\n", 5, 20, 10, 30);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 3: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%10s: [%10s]\n", "hello");
	len2 = printf("%%10s: [%10s]\n", "hello");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 4: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%10c: [%10c]\n", 'c');
	len2 = printf("%%10c: [%10c]\n", 'c');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 5: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%10d, 100: [%10d]\n", 100);
	len2 = printf("%%10d, 100: [%10d]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 6: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%10o, 100: [%10o]\n", 100);
	len2 = printf("%%10o, 100: [%10o]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 7: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%10x, 100: [%10x]\n", 100);
	len2 = printf("%%10x, 100: [%10x]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 8: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%20p: [%20p]\n", (void *)0x7ffe637541f0);
	len2 = printf("%%20p: [%20p]\n", (void *)0x7ffe637541f0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 9: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%2c: [%2c]\n", '\0');
	len2 = printf("%%2c: [%2c]\n", '\0');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 10: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	return (0);
}
