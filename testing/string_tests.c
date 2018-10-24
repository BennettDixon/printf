#include<stdio.h>
#include "holberton.h"

int main()
{
	int i, j;
	char c = 'H';
	char *str = "Hello";
	/*
	i = _printf("Empty arg for string: %s\n");
	j = printf("Empty arg for string: %s\n");
	printf("len: %d\n", i);
	printf("len2: %d\n", j);
	*/
	i = _printf("Unknown: %y\n");
	j = printf("Unknown: %y\n");
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("Unknown newline: %\n");
	j = printf("Unknown newline: %\n");
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("Unknown nullbyte: %");
	printf("\n");
	j = printf("Unknown nullbyte: %");
	printf("\n");
	printf("len: %d\n", i);
	printf("len2: %d\n", j);


	i = _printf("NULL arg for string: %s\n", NULL);
	j = printf("NULL arg for string: %s\n", NULL);
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("NULL arg for char: %c\n", NULL);
	j = printf("NULL arg for char: %c\n", NULL);
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("String: %s\n", str);
	j = printf("String: %s\n", str);
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("Character: %c\n", c);
	j = printf("Character: %c\n", c);
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("Percent: %%\n");
	j = printf("Percent: %%\n");
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("String, character, percent: %s %c %%\n", str, c);
	j = printf("String, character, percent: %s %c %%\n", str, c);
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("Character, string: %c %s\n", c, str);
	j = printf("Character, string: %c %s\n", c, str);
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("Character, percent: %c %%\n", c);
	j = printf("Character, percent: %c %%\n", c);
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("Percent, string: %% %s\n", str);
	j = printf("Percent, string: %% %s\n", str);
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("Unknown, string: %y %s\n", str);
	j = printf("Unknown, string: %y %s\n", str);
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("Unknown, char: %y %c\n", c);
	j = printf("Unknown, char: %y %c\n", c);
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	i = _printf("Unknown percent: %y %%\n");
	j = printf("Unknown percent: %y %%\n");
	printf("len: %d\n", i);
	printf("len2: %d\n", j);

	return (0);
}
