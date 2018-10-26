/**
 * _isdigit - checks if a character is a digit or not
 * @c: character to check
 *
 * Return: 1 if isdigit, 0 if not digit
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * is_modifier - checks if a character is a length modifier
 * @c: character to check
 *
 * Return: 1 if modifier, otherwise 0.
 */
int is_modifier(char c)
{
	if (c == 'l' || c == 'h')
		return (1);
	return (0);
}
