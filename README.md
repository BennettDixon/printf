# printf() - Custom Implementation
In this project we will implement a printf() function of the following prototype: `int _printf(const char *format, ...);`

The function is variadic and thus takes any amount of arguments following the format pointer.


## Goals

- Implement custom printf() function similar to that of the standard library
- Use variadic functions to allow a custom number of arguments
- Parse a format string to identify custom print options


## Files / Directories
|Name                |Information                        |Relevant Files                         |
|----------------|-------------------------------|-----------------------------|
|`testing`|Directory containing files relevant to testing, such as main files.|`main.c`|
|`holberton.h`	| Header file containing struct and public function definitions| `*.c`
|`_printf.c`|Main printf function file. Calls other functions and holds buffer|`char_checkers.c`, `get_string_funcs.c`, `buffer_functions.c`|
`_bases.c` | Contains generic base calculation functions. Gets size of buffer needed to hold conversion from int[base]->string, and fills the buffer with the proper conversion (seperate functions).| `int_spec_funcs.c`, `hex_spec_funcs.c` |
`_strings.c` | Custom functions for string operations, such as strlen and strcpy | `char_spec_funcs.c` |
`buffer_functions.c` | Functions used by `_printf.c` to create, copy, and print the buffer so only one write call is needed | `_printf.c` |
`get_string_funcs.c` | Function that gets the proper string function for a given type specifier | `_printf.c` |
`char_checkers.c` | Functions that check characters, such as if it is a flag or specifier | `print_f.c` |
`char_spec_funcs.c` | Character specific functions returned by `get_string_func()`. Creates memory and copies variable type into a string usable by buffer. | `get_string_funcs.c` |
`int_spec_funcs.c` | Integer specific functions returned by `get_string_func()`. Creates memory and copies variable type into a string, doing proper base conversion. | `_bases.c`, `get_string_funcs.c` |
`hex_spec_funcs.c` | Hexadecimal specific functions returned by `get_string_funcs.c`. Creates memory and copies variable type into string, doing proper base conversion for hex (16). | `_bases.c`, `get_string_funcs.c` |
