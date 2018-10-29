!#/bin/bash
wget -O test_x.c $1
gcc -Wall -Werror -Wextra -pedantic -Wno-format ../*.c test_x.c -o test_x
./test_x
