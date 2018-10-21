#ifndef _PRINTF_H_
#define _PRINTF_H_
#include <stdarg.h>

#define BUFF_SIZE 1024;
/**
 * struct type_specifier - contains a type represented as char
 * @f: print_fucntion for specific type
 * @t: character representing type
 */
typedef struct type_specifier
{
	char *(*f)(va_list);
	char t;
} spec_t;
int _printf(const char *format, ...);
char *create_buff(unsigned int bytes);
void copy_buff(char *str, int *index, char *buff, unsigned int buff_size);
void print_buff(char *buff, unsigned int buff_size);
char *(*get_string_func(char ch))(va_list);
int is_specifier(char c);
int is_flag(char c);
#endif /* _PRINTF_H_ */
