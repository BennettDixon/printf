#include "holberton.h"
#include <unistd.h>
#include <stdlib.h>
/**
 * create_buff - creates a buffer in memory and sets to 0
 * @bytes: number of bytes to allocate for buffer
 *
 * Return: char pointer to beginning of buffer
 */
char *create_buff(unsigned int bytes)
{
	char *new_buff;
	unsigned int i;

	new_buff = malloc(bytes);
	if (!new_buff)
		return (NULL);
	for (i = 0; i < bytes; i++)
		new_buff[i] = 0;
	return (new_buff);
}
/**
 * copy_buff - copies a string into the buffer
 * @str: string to copy into buffer, null terminated
 * @index: pointer to current buffer index
 * @buff: pointer to buffer
 * @buff_size: size of buffer, needed for overflow
 *
 * Return: always void
 */
void copy_buff(char *str, unsigned int *index, char *buff,
		unsigned int buff_size)
{
	unsigned int i = 0;

	if (!str || !buff)
		return;
	while (str[i] && *index < buff_size)
	{
		buff[*index] = str[i];
		(*index)++, i++;
	}
	free(str);
}
/**
 * print_buff - prints the contents of the buffer
 * @buff: buffer to print
 * @buff_size: size of buffer in bytes
 *
 * Return: number of bytes written
 */
unsigned int print_buff(char *buff, unsigned int buff_size)
{
	unsigned int bytes_written;

	bytes_written = write(1, buff, buff_size);
	return (bytes_written);
}
