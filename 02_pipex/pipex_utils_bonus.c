/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:48:46 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/11 13:02:08 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char	const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (0);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		tot_len;
	int		i;
	int		j;
	char	*join;

	if (!s1 || !s2)
		return (0);
	tot_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = (char *)malloc(sizeof(char) * tot_len);
	if (join == NULL)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	h;
	size_t	n;

	h = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (big[h] != '\0')
	{
		n = 0;
		while (big[h + n] == little[n] && (h + n) < len)
		{
			if (big[h + n] == '\0' && little[n] == '\0')
				return ((char *)&big[h]);
			n++;
		}
		if (little[n] == '\0')
			return ((char *)big + h);
		h++;
	}
	return (0);
}

char	*find_path(char **envp, char *cmd)
{
	char	*sub;
	char	**single_path;
	char	*cmd_path;

	cmd = *ft_split(cmd, ' ');
	while (*envp && !ft_strnstr(*envp, "PATH=", 5))
		envp++;
	sub = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
	single_path = ft_split(sub, ':');
	free(sub);
	sub = ft_strjoin("/", cmd);
	while (*single_path)
	{
		cmd_path = ft_strjoin(*single_path, sub);
		if (!cmd_path)
			return (NULL);
		if (!access(cmd_path, F_OK))
			break ;
		free(cmd_path);
		single_path++;
	}
	free(sub);
	free(cmd);
	return (cmd_path);
}
