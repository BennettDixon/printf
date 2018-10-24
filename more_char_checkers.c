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
