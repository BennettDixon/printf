#ifndef _PRINTF_H_
#define _PRINTF_H_
#include <stdarg.h>

#define BUFF_SIZE 1024
/**
 * struct type_specifier - contains a type represented as char
 * @f: print_fucntion for specific type
 * @t: character representing type
 */
typedef struct type_specifier
{
	char t;
	char *(*f)(va_list);
} spec_t;
/**
 * struct flag_specifier - contains a flag and it's valid specifiers and func
 * @flag: flag represented as character
 * @specs: char pointer to array of valid specifiers for flag
 * @f: get_flag function that returns a char pointer and modifies a char *
 */
typedef struct flag_specifier
{
	char flag;
	char *specs;
	char *(*f)(char *);
} flag_t;
/**
 * struct print_helper_s - contains values needed in print helper
 * @format: pointer to format string
 * @f_i: pointer to index of format string
 * @buff: pointer to buffer
 * @c: pointer to character string, used by copy buffer
 * @buff_i: pointer to index of buffer
 * @busy: pointer to printf isbusy
 * @beg_i: pointer to beginning index (where % was found)
 * @buff_len: Counter for the total amount of characters so far.
 * @flags: pointer to int array pertaining to flag's being used
 * @width: width pulled from format string
 * @precision: precision pulled from format string
 * @dot: boolean value 0 or 1 representing precision dot found or not
 * @spec_c: Counter for number of non flag characters encountered during busy
 */
typedef struct print_helper_s
{
	/* string  values */
	const char *format;
	char *buff;
	char *c;
	/* boolean values */
	char dot;
	char busy;
	/* integer values */
	unsigned int f_i;
	unsigned int buff_i;
	unsigned int beg_i;
	unsigned int buff_len;
	int width;
	int precision;
	int spec_c;
	/* flags is a pointer to an array of booleans */
	int *flags;
} printh_t;

int _printf(const char *format, ...);
char *create_buff(unsigned int bytes);
unsigned int copy_buff(char *str, printh_t *help_s);
unsigned int print_buff(char *buff, unsigned int buff_size);
void free_all(printh_t *help_s, va_list args);
void get_width_precision(printh_t *help_s, va_list args);
char *(*get_string_func(char ch))(va_list);
char *(*get_flag_func(int flag_index, char spec))(char *);
char *get_char(va_list);
char *get_string(va_list);
char *get_nonprint_string(va_list);
char *get_percent(va_list);
char *get_int(va_list);
char *get_binary(va_list);
char *get_unsigned(va_list);
char *get_octal(va_list);
char *get_hex_n(unsigned int);
char *get_hex(va_list);
char *get_hex_upper(va_list);
char *get_pointer(va_list);
char *get_reverse(va_list);
char *get_rot(va_list);
char *do_plus_flag(char *str);
char *do_spc_flag(char *str);
char *do_octal_flag(char *str);
char *do_hex_flag(char *str);
char *do_hex_upper_flag(char *str);
char *do_width(char *str, int width, int space);
int ch_in_array(char c, char *ptr);
int is_specifier(char c);
int is_flag(char c);
int _isalpha(char c);
int _isdigit(char c);
int is_printable(char c);
int _strlen(char *s);
void _string_upper(char *str);
char *_strcpy(char *dest, char *src);
int fill_nonprint_buffer(int length, char *buff, char *str);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int, unsigned int, char *b, int size);
#endif /* _PRINTF_H_ */
