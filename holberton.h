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
	char *(*f)(char*);
} flag_t;

int _printf(const char *format, ...);
char *create_buff(unsigned int bytes);
void copy_buff(char *str, unsigned int *index, char *buff, unsigned int b_s);
unsigned int print_buff(char *buff, unsigned int buff_size);
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
int ch_in_array(char c, char *ptr);
int is_specifier(char c);
int is_flag(char c);
int _isalpha(char c);
int is_printable(char c);
int _strlen(char *s);
void _string_upper(char *str);
char *_strcpy(char *dest, char *src);
int fill_nonprint_buffer(int length, char *buff, char *str);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int, unsigned int, char *b, int size);
#endif /* _PRINTF_H_ */
