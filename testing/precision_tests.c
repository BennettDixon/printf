#include <stdio.h>
#include "holberton.h"
int main()
{
	int len, len2;

	len = _printf("%%.*s: [%.*s]", 30, "Hi!\n");
	len2 = printf("%%.*s: [%.*s]", 30, "Hi!\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 1: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%.*s: [%.*s]\n", 0, "Hi!\n");
	len2 = printf("%%.*s: [%.*s]\n", 0, "Hi!\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 2: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%.*d, 1, 2: [%.*d]\n", 1, 2);
	len2 = printf("%%.*d, 1, 2: [%.*d]\n", 1, 2);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 3: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%.*d, 0, 0: [%.*d]\n", 0, 0);
	len2 = printf("%%.*d, 0, 0: [%.*d]\n", 0, 0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 4: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%.6i, 0: [%.6i]\n", 0);
	len2 = printf("%%.6i, 0: [%.6i]\n", 0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 5: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%.6d, -1024: [%.6d]\n", -1024);
	len2 = printf("%%.6d, -1024: [%.6d]\n", -1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 6: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-+010d, 1024: [%-+010d]\n", 1024);
	len2 = printf("%%-+010d, 1024: [%-+010d]\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 7: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("In the middle [%.6i] of a sentence\n", 1024);
	len2 = printf("In the middle [%.6i] of a sentence\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 8: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%.6o, 102498402: [%.6o]\n", 102498402);
	len2 = printf("%%.6o, 102498402: [%.6o]\n", 102498402);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 9: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%.6o, 1024: [%.6o]\n", 1024);
	len2 = printf("%%.6o, 1024: [%.6o]\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 10: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%.6x, 102498402: [%.6x]\n", 102498402);
	len2 = printf("%%.6x, 102498402: [%.6x]\n", 102498402);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 1: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%.6x, 0: [%.6x]\n", 0);
	len2 = printf("%%.6x, 0: [%.6x]\n", 0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 1: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%.20p: [%.20p]\n", (void *)0x7ffe637541f0);
	len2 = printf("%%.20p: [%.20p]\n", (void *)0x7ffe637541f0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	return (0);
}
