/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Hendrik <Hendrik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:51:15 by Hendrik           #+#    #+#             */
/*   Updated: 2022/05/04 11:18:39 by Hendrik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	print_tokens(char **tokens)
{
	int	i;

	i = 0;
	if (!tokens)
		exit(1);
	printf("#----#\n");
	while (tokens[i])
	{
		printf("tokens[%d] is: %s\n", i, tokens[i]);
		i++;
	}
	printf("#----#\n");
	return ;
}

int	check_token_type(int token)
{
	if (token == CHAR_PIPE
		|| token == CHAR_AMPERSAND
		|| token == CHAR_GREATER
		|| token == CHAR_LESSER)
		return (1);
	else if (token == CHAR_SQUOTE
		|| token == CHAR_DQUOTE)
		return (2);
	return (0);
}

int	check_quotes(const char *s)
{
	int	i;

	i = 0;
	if (s[i] == CHAR_DQUOTE)
	{
		i++;
		while (s[i] != CHAR_DQUOTE && s[i])
			i++;
	}
	if (s[i] == CHAR_SQUOTE)
	{
		i++;
		while (s[i] != CHAR_SQUOTE && s[i])
			i++;
	}
	return (i);
}

int	metachar_wordlen(const char *s, int offset)
{
	if (*(s + offset) == CHAR_PIPE || *(s + offset) == CHAR_AMPERSAND)
		return (1);
	if (offset < (int)ft_strlen(s))
	{
		if (*(s + offset) == CHAR_GREATER && *(s + offset + 1) == CHAR_GREATER)
			return (2);
		else if (*(s + offset) == CHAR_LESSER
			&& *(s + offset + 1) == CHAR_LESSER)
			return (2);
		else if (*(s + offset) == CHAR_GREATER || *(s + offset) == CHAR_LESSER)
			return (1);
	}
	return (0);
}
