/**
 * _strlen - gets length of string, not including null byte
 * @str: string to get length of
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int i;

	while (*(str + i))
		i++;
	return (i);
}
/**
 * _strcpy - copies a string
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
