#ifndef PIPEX_H
# define PIPEX_H

/*
** ------------------------------ LIBRARIES ------------------------------
*/

# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <time.h>
# include <fcntl.h>
# include "ft_printf/ft_printf.h"

/*
** ------------------------------ PROTOTYPES ------------------------------
*/

char	**ft_split(char const *s, char c);
char	*ft_substr(char	const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnstr(const char *big, const char *little, size_t len);

#endif