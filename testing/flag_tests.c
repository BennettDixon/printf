#include <stdio.h>
#include "holberton.h"

int main()
{
	int len, len2;

	len = _printf("%%+d: [%+d]\n", 10);
	len2 = printf("%%+d: [%+d]\n", 10);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 1: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%% i: [% i]\n", 11);
	len2 = printf("%% i: [% i]\n", 11);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 2: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%#d: [%#d]\n", 12);
	len2 = printf("%%#d: [%#d]\n", 12);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 3: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%%#x: [%#x]\n", 13);
	len2 = printf("%%#x: [%#x]\n", 13);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 4: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%%#x: [%#x]\n", 0);
	len2 = printf("%%#x: [%#x]\n", 0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 5: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%#o: [%#o]\n", 14);
	len2 = printf("%%#o: [%#o]\n", 14);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 6: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%#o: [%#o]\n", 0);
	len2 = printf("%%#o: [%#o]\n", 0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 7: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%%+x: [%+x]\n", 15);
	len2 = printf("%%+x: [%+x]\n", 15);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 8: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	printf("----Test width with invalid and/or no specifiers----\n");


	len = _printf("%10 ");
	printf("\n");
	len2 = printf("%10 ");
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 9: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("% % % % ");
	printf("\n");
	len2 = printf("% % % % ");
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 10: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("% ");
	printf("\n");
	len2 = printf("% ");
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 11: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}

	len = _printf("%y %");
	printf("\n");
	len2 = printf("%y %");
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	if (len != len2)
	{
		printf("Test 12: Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	len = _printf("%y %+");
	printf("\n");
	len2 = printf("%y %+");
	printf("\n");
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
