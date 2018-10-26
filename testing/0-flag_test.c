#include <stdio.h>
#include "holberton.h"
int main(void)
{
	int len, len2;

	len = _printf("In the middle %06X of a sentence.\n", 1024);
	len2 = printf("In the middle %06X of a sentence.\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("06u w/ 0:%06u\n", 0);
	len2 = printf("06u w/ 0:%06u\n", 0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("06i w/ negative:%06i\n", -102498402);
	len2 = printf("06i w/ negative:%06i\n", -102498402);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("06X w/ 1024:%06X\n", 1024);
	len2 = printf("06X w/ 1024:%06X\n", 1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);


	len = _printf("octal w/ 0:%06o\n", 0);
	len2 = printf("octal w/ 0:%06o\n", 0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	
	len = _printf("06o w/ big int:%06o\n", 102498502);
	len2 = printf("06o w/ big int:%06o\n", 102498502);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("06X w/ 0:%06X\n", 0);
	len2 = printf("06X w/ 0:%06X\n", 0);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	
	len = _printf("06d w/ neg:%06d\n", -1024);
	len2 = printf("06d w/ neg:%06d\n", -1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("06i w/ neg:%06i\n", -1024);
	len2 = printf("06i w/ neg:%06i\n", -1024);
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	return (0);






	
}
