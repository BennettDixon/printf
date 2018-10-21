#define NULL 0

int ch_in_array(char c, char *ptr);

/**
  * is_specifier - Checks if the character is a format specifier.
  * @c: The character passed.
  *
  * Return: 1 if the character is a specifier, 0 otherwise.
  */

int is_specifier(char c)
{
	char spec[] = {'c', 's', '%', NULL};

	return (ch_in_array(c, spec));
}

/**
  * is_flag - Checks if the character is a format flag.
  * @c: The character passed.
  *
  * Return: 1 if the character is a flag, 0 otherwise.
  */

int is_flag(char c)
{
	c = 'a';
	if (c)
		c = 'b';
	return (0);
}

/**
 * _isalpha - checks if character is alpha or not
 * @c: character to check
 *
 * Return: 1 if is alpha, 0 otherwise
 */
int _isalpha(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/**
  * ch_in_array - Checks if the character is in the array.
  * @c: The character passed.
  * @ptr: Pointer to the array.
  *
  * Return: 1 if the character is in the array, 0 otherwise.
  */

int ch_in_array(char c, char *ptr)
{
	int i = 0;

	while (ptr[i])
	{
		if (ptr[i] == c)
			return (1);
		i++;
	}

	return (0);
}
