#include <stdio.h>
#include "holberton.h"

int main()
{
	int len, len2;

	len = _printf("Int: [%+d]", 10);
	printf("\n");
	len2 = printf("Int: [%+d]", 10);
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("Inti: [% i]", 11);
	printf("\n");
	len2 = printf("Inti: [% i]", 11);
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("Hash int: [%#d]", 12);
	printf("\n");
	len2 = printf("Hash int: [%#d]", 12);
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("Hash hex: [%#x]", 13);
	printf("\n");
	len2 = printf("Hash hex: [%#x]", 13);
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("Hash hex 0: [%#x]", 0);
	printf("\n");
	len2 = printf("Hash hex 0: [%#x]", 0);
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("Hash oct: [%#o]", 14);
	printf("\n");
	len2 = printf("Hash oct: [%#o]", 14);
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("Hash oct 0: [%#o]", 0);
	printf("\n");
	len2 = printf("Hash oct 0: [%#o]", 0);
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("+ hex: [%+x]", 15);
	printf("\n");
	len2 = printf("+ hex: [%+x]", 15);
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	printf("----Test width with invalid and/or no specifiers----\n");


	len = _printf("%10 ");
	printf("\n");
	len2 = printf("%10 ");
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("% % % % ");
	printf("\n");
	len2 = printf("% % % % ");
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("% ");
	printf("\n");
	len2 = printf("% ");
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("% ");
	printf("\n");
	len2 = printf("% ");
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%y %");
	printf("\n");
	len2 = printf("%y %");
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);

	len = _printf("%y %+");
	printf("\n");
	len2 = printf("%y %+");
	printf("\n");
	printf("len: %d\n", len);
	printf("len2: %d\n", len2);
	
	
	
	
	
	return (0);
}
