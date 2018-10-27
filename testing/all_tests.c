#include <stdio.h>
#include "holberton.h"

int main()
{
	int len;
	int len2;

	len = _printf("%%+10.7d: [%+10.7d]\n", 1024);
	len2 = printf("%%+10.7d: [%+10.7d]\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 1: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-+10.7d: [%-+10.7d]\n", 1024);
	len2 = printf("%%-+10.7d: [%-+10.7d]\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 2: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-#010.7x: [%-#010.7x]\n", 1024);
	len2 = printf("%%-#010.7x: [%-#010.7x]\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 3: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%#10.7X: [%#10.7X]\n", 1024);
	len2 = printf("%%#10.7X: [%#10.7X]\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 4: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%#010o: [%#010o]\n", 1024);
	len2 = printf("%%#010o: [%#010o]\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 5: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%+10u, 100: [%+10u]\n", 100);
	len2 = printf("%%+10u, 100: [%+10u]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 6: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-#10o, 100: [%-#10o]\n", 100);
	len2 = printf("%%-#10o, 100: [%-#10o]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 7: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%010x, 100: [%010x]\n", 100);
	len2 = printf("%%010x, 100: [%010x]\n", 100);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 8: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-20.*p: [%-20.*p]\n", 15, (void *)0x7ffe637541f0);
	len2 = printf("%%-20.*p: [%-20.*p]\n", 15, (void *)0x7ffe637541f0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 9: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%+10.5i: [%+*.5i]\n", 7, 0);
	len2 = printf("%%+10.5i: [%+*.5i]\n", 7, 0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 10: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%.5c: [%.5c]\n", '\0');
	len2 = printf("%%.5c: [%.5c]\n", '\0');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test X: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-5c: [%-5c]\n", '\0');
	len2 = printf("%%-5c: [%-5c]\n", '\0');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test X: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-6.5c: [%-6.5c]\n", 'H');
	len2 = printf("%%-6.5c: [%-6.5c]\n", 'H');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test X: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}


	len = _printf("%%-.c: [%-.c]\n", 'H');
	len2 = printf("%%-.c: [%-.c]\n", 'H');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test X: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%-05c: [%-05c]\n", 'H');
	len2 = printf("%%-05c: [%-05c]\n", 'H');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test X: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}


	len = _printf("%%-010.7c: [%-10.7c]\n", 'H');
	len2 = printf("%%-010.7c: [%-10.7c]\n", 'H');
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test X: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	return (0);
}
