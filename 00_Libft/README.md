# LIBFT: Your very own first library

<img width="101" alt="Capture d'écran 2024-01-04 175726" src="https://github.com/MathieuFourmont/42-Common-Course/assets/91331763/9f83aa36-b819-4ae8-8392-54c2a2113fc4">

<img width="394" alt="image" src="https://github.com/MathieuFourmont/42-Common-Course/assets/91331763/e57a6c8a-8ccd-40e8-b1dd-d11a52ec2252">

## Project Goal

The goal of the first 42 project is to gain a deeper understanding in the functions we take for granted every day and are quick to use in other higher level languages. We'll write a bunch of string and memory manipulation functions for the mandatory part as well as linked-list manipulation functions for the bonus part.

## How to install and run

Create the library (.a format) by running the `make` or `make bonus` command after cloning the repository. Functions within the library can be used with other programs by compiling together with gcc.

## Key Learnings

### C libraries:

The functions in our libft are an odd match of functions from stdio.h, string.h, stdlib.h and others.

### Library compilation and reusability:

- We can compile libraries using Makefiles, in which we define how a program must be defined. Makefiles have very specific formatting rules
- There are 4 steps in compilation in c: preprocessing, compiling, assembling and linking.
- In our makefile, we describe how the compiler should turn our code into object code during the assembly phase. At the last phase, linking, we can link in additional libraries which were already pre-compiled.

### Linked Lists:

- Benefits
	- Insertion and deletion are easier for memory than working with arrays, because no continuous space must be reserved in memory for the linked list.
	- With large records, moving pointers is faster than moving the data themselves.
	- Overflow of memory can not occur unless the memory is actually full.
	- Can grow and shrink at runtime without the need to define list length upfront.

- Drawbacks
	- Memory usage is higher than arrays, because a pointer (of 8 bytes) is also required.
	- Traversal is more time consuming
	- Reverse traversal of a singly-linked list is not possible.
	- Random access of the list is not possible due to its dynamic memory allocation. To find an item, we must start from the beginning of the list.

### Stack and Heap:

- Stack:  
When writing C programs, we generally start at the main. This function is allocated some memory on the stack portion of memory and every function call thereafter within this main is allocated some memory on the top of the stack of memory. When a function completes its task, memory that was allocated on the stack is deallocated. If too many functions are called (such as in a recursive function), the stack can overflow.

- Heap:  
The stack does have some limitations. Let's say we want to define an array in a function which is not the main and return a pointer to that array. If defined in a function on the stack and then returned, the memory is deallocated. For this problem, we can make use of the heap, which is a part of memory that is available for the programmer to store data, at the risk of it being the programmer's own responsibility to free this memory after usage. We can use the functions malloc and free for this.

## Libft Functions

### Functions from `<ctype.h>`

- [`ft_isalpha`](src/ft_isalpha.c)	- checks  for  an  alphabetic  character.
- [`ft_isdigit`](src/ft_isdigit.c)	- checks for a digit (0 through 9).
- [`ft_isalnum`](src/ft_isalnum.c)	- checks for an alphanumeric character.
- [`ft_isascii`](src/ft_isascii.c)	- checks whether c fits into the ASCII character set.
- [`ft_isprint`](src/ft_isprint.c)	- checks for any printable character.
- [`ft_toupper`](src/ft_toupper.c)	- convert char to uppercase.
- [`ft_tolower`](src/ft_tolower.c)	- convert char to lowercase.

### Functions from `<string.h>`

- [`ft_memset`](src/ft_memset.c)	- fill memory with a constant byte.
- [`ft_strlen`](src/ft_strlen.c)	- calculate the length of a string.
- [`ft_bzero`](src/ft_bzero.c)	- zero a byte string.
- [`ft_memcpy`](src/ft_memcpy.c)	- copy memory area.
- [`ft_memmove`](src/ft_memmove.c)	- copy memory area.
- [`ft_strlcpy`](src/ft_strlcpy.c)	- copy string to an specific size.
- [`ft_strlcat`](src/ft_strlcat.c)	- concatenate string to an specific size.
- [`ft_strchr`](src/ft_strchr.c)	- locate character in string.
- [`ft_strrchr`](src/ft_strrchr.c)	- locate character in string.
- [`ft_strncmp`](src/ft_strncmp.c)	- compare two strings.
- [`ft_memchr`](src/ft_memchr.c)	- scan memory for a character.
- [`ft_memcmp`](src/ft_memcmp.c)	- compare memory areas.
- [`ft_strnstr`](src/ft_strnstr.c)	- locate a substring in a string.
- [`ft_strdup`](src/ft_strdup.c)	- creates a dupplicate for the string passed as parameter.

### Functions from `<stdlib.h>`
- [`ft_atoi`](src/ft_atoi.c)	- convert a string to an integer.
- [`ft_calloc`](src/ft_calloc.c)	- allocates memory and sets its bytes' values to 0.

### Non-standard functions
- [`ft_substr`](src/ft_substr.c)	- returns a substring from a string.
- [`ft_strjoin`](src/ft_strjoin.c)	- concatenates two strings.
- [`ft_strtrim`](src/ft_strtrim.c)	- trims the beginning and end of string with specific set of chars.
- [`ft_split`](src/ft_split.c)	- splits a string using a char as parameter.
- [`ft_itoa`](src/ft_itoa.c)	- converts a number into a string.
- [`ft_strmapi`](src/ft_strmapi.c)	- applies a function to each character of a string.
- [`ft_striteri`](src/ft_striteri.c)	- applies a function to each character of a string.
- [`ft_putchar_fd`](src/ft_putchar_fd.c)	- output a char to a file descriptor.
- [`ft_putstr_fd`](src/ft_putstr_fd.c)	- output a string to a file descriptor.
- [`ft_putendl_fd`](src/ft_putendl_fd.c)	- output a string to a file descriptor, followed by a new line.
- [`ft_putnbr_fd`](src/ft_putnbr_fd.c)	- output a number to a file descriptor.

### Linked list functions

- [`ft_lstnew`](src/ft_lstnew.c)	- creates a new list element.
- [`ft_lstadd_front`](src/ft_lstadd_front.c)	- adds an element at the beginning of a list.
- [`ft_lstsize`](src/ft_lstsize.c)	- counts the number of elements in a list.
- [`ft_lstlast`](src/ft_lstlast.c)	- returns the last element of the list.
- [`ft_lstadd_back`](src/ft_lstadd_back.c)	- adds an element at the end of a list.
- [`ft_lstdelone`](src/ft_lstdelone.c)	- deletes and free an element  of the list.
- [`ft_lstclear`](src/ft_lstclear.c)	- deletes and free list.
- [`ft_lstiter`](src/ft_lstiter.c)	- applies a function to each element of a list.
- [`ft_lstmap`](src/ft_lstmap.c)	- applies a function to each element of a list.
