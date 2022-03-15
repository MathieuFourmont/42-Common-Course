/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:14:18 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/11 13:02:59 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/*
** ------------------------------ LIBRARIES ------------------------------
*/

# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <unistd.h>
# include <time.h>
# include <string.h>
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
char	*find_path(char **envp, char *cmd);

#endif
