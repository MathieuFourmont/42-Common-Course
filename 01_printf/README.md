# FT_PRINTF: A partial reimplementation of the printf() in C

## Project Goal

In this, the goal is pretty straightforward. We had to recode printf().
Aims mainly to learn about using a variable number of arguments.

| Conversion | Short Description                                                                             |
|------------|-----------------------------------------------------------------------------------------------|
| %c         | Print a single character.                                                                     |
| %s         | Print a string of characters.                                                                 |
| %p         | The void * pointer argument is printed in hexadecimal.                                        |
| %d         | Print a decimal (base 10) number.                                                             |
| %i         | Print an integer in base 10.                                                                  |
| %u         | Print an unsigned decimal (base 10) number.                                                   |
| %x         | Print a number in hexadecimal (base 16), with lowercase.                                      |
| %X         | Print a number in hexadecimal (base 16), with uppercase.                                      |
| %%         | Print a percent sign.                                                                         |

## How to install and run

Create the library (.a format) by running the `make` or `make bonus` command after cloning the repository.  
Then there is a main.c  file to test it, you can compile using `gcc -Wall -Wextra -Wall main.c libftprintf.a` and execute the ./a.out created.

