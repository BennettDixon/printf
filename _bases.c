/**
 * get_numbase_len - gets length of buffer needed for an unsigned int
 * @num: number to get length needed for
 * @base: base of number representation used by buffer
 *
 * Return: integer containing length of buffer needed
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}
/**
 * fill_numbase_buff - fills buffer with correct numbers up to base 10
 * @num: number to convert to string given base
 * @base: base of number used in conversion, only works up to base 10
 * @buff: buffer to fill with result of conversion
 * @buff_size: size of buffer in bytes
 *
 * Return: always void
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, unsigned int buff_size)
{
	unsigned int i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		buff[i] = num % base + '0';
		num /= base;
		i--;
	}
}
