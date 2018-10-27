#include <stdio.h>
#include "holberton.h"
int main()
{
	int len, len2;

	len = _printf("big *: %.*s", 30, "Hi!\n");
	len2 = printf("big *: %.*s", 30, "Hi!\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("prec < len: %.*s\n", 0, "Hi!\n");
	len2 = printf("prec < len: %.*s\n", 0, "Hi!\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("prec == len: %.*d\n", 1, 2);
	len2 = printf("prec == len: %.*d\n", 1, 2);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("prec 0 val 1: %.*d\n", 0, 0);
	len2 = printf("prec 0 val 1: %.*d\n", 0, 0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);





	len = _printf("zero integer: %.6i\n", 0);
	len2 = printf("zero integer: %.6i\n", 0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);


	len = _printf("negative: %.6d\n", -1024);
	len2 = printf("negative: %.6d\n", -1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%-+010d on 1024: [%-+010d]\n", 1024);
	len2 = printf("%%-+010d on 1024: [%-+010d]\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("In the middle %.6i of a sentence\n", 1024);
	len2 = printf("In the middle %.6i of a sentence\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("octal > prec: %.6o\n", 102498402);
	len2 = printf("octal > prec: %.6o\n", 102498402);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("octal < prec: %.6o\n", 1024);
	len2 = printf("octal < prec: %.6o\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("hex > prec: %.6x\n", 102498402);
	len2 = printf("hex > prec: %.6x\n", 102498402);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("hex < prec: %.6x\n", 0);
	len2 = printf("hex < prec: %.6x\n", 0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%%.20p: [%.20p]\n", (void *)0x7ffe637541f0);
	len2 = printf("%%.20p: [%.20p]\n", (void *)0x7ffe637541f0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	return (0);
}


