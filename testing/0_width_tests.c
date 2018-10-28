#include <stdio.h>
#include "holberton.h"

int main()
{
	int len;
	int len2;

	len = _printf("%%0*d, 10, 100: [%0*d]\n", 10, 100);
	len2 = printf("%%0*d, 10, 100: [%0*d]\n", 10, 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 1: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%0*d, 10, -1100: [%0*d]\n", 10, -1100);
	len2 = printf("%%0*d, 10, -1100: [%0*d]\n", 10, -1100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test2: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%+06d, 10: [%+06d]\n", 10);
	len2 = printf("%%+06d, 10: [%+06d]\n", 10);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 3: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%0*d|%%i, 20, 15, 30: [%0*d|%i]\n", 20, 15, 30);
	len2 = printf("%%0*d|%%i, 20, 15, 30: [%0*d|%i]\n", 20, 15, 30);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 4: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%0*d %%0*i, 5, 20, 10, 30: [%0*d %0*i]\n", 5, 20, 10, 30);
	len2 = printf("%%0*d %%0*i, 5, 20, 10, 30: [%0*d %0*i]\n", 5, 20, 10, 30);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 5: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%010s: [%010s]\n", "hello");
	len2 = printf("%%010s: [%010s]\n", "hello");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 6: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%010c: [%010c]\n", 'c');
	len2 = printf("%%010c: [%010c]\n", 'c');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 7: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%0y: [%0y]\n", 'c');
	len2 = printf("%%0y: [%0y]\n", 'c');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 8: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%010u: [%010u]\n", 100);
	len2 = printf("%%010u: [%010u]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 9: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%010o: [%010o]\n", 100);
	len2 = printf("%%010o: [%010o]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 10: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%010x: [%010x]\n", 100);
	len2 = printf("%%010x: [%010x]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 11: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%020p: [%020p]\n", (void *)0x7ffe637541f0);
	len2 = printf("%%020p: [%020p]\n", (void *)0x7ffe637541f0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 12: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%02c: [%02c]\n", '\0');
	len2 = printf("%%02c: [%02c]\n", '\0');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 13: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
