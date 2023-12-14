/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:39:40 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/06/07 20:58:01 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/*
| Removed comment by hendirk in below function: //free(to_set->content);
*/

void	set_pwd_vars_env(char *name, char *value, t_list **env)
{
	t_list	*to_set;
	char	*var_to_search;
	size_t	name_len;
	void	*tmp;

	if (!value)
		return ;
	to_set = *env;
	name_len = ft_strlen(name);
	var_to_search = ft_strjoin(name, "=");
	while (to_set)
	{
		if (!ft_strncmp(var_to_search, (to_set)->content, name_len))
		{
			tmp = to_set->content;
			to_set->content = NULL;
			to_set->content = ft_strjoin(var_to_search, value);
			free(tmp);
			ft_free(&var_to_search);
			return ;
		}
		to_set = to_set->next;
	}
	return ;
}

static char	*update_cwd(char *cwd)
{
	if (cwd)
		free(cwd);
	cwd = NULL;
	cwd = getcwd(cwd, 0);
	return (cwd);
}

static char	*get_new_cwd(char **tokens, t_list **env)
{
	char	*new_cwd;

	if (!tokens[1] || (!ft_strcmp(tokens[1], "~")))
	{
		new_cwd = get_env_value("HOME", env);
		if (!new_cwd)
		{
			ft_printf("HOME not set.\n");
			return (NULL);
		}
	}
	else if (!ft_strcmp(tokens[1], "-"))
	{
		new_cwd = get_env_value("OLDPWD", env);
		if (!new_cwd)
		{
			ft_printf("OLDPWD not set.\n");
			return (NULL);
		}
	}
	else
		new_cwd = tokens[1];
	return (new_cwd);
}

int	exec_cd(char **tokens, t_list **env)
{
	char	*cwd;
	char	*new_cwd;

	cwd = NULL;
	cwd = getcwd(cwd, 0);
	new_cwd = get_new_cwd(tokens, env);
	if (new_cwd == NULL)
		return (-1);
	if (chdir(new_cwd) != 0)
	{
		if (access(tokens[1], F_OK) != 0)
			ft_printf("cd: %s: No such file or directory\n", tokens[1]);
		else if (access(tokens[1], X_OK) != 0)
			ft_printf("cd: %s: Permission denied\n", tokens[1]);
		return (-1);
	}
	set_pwd_vars_env("OLDPWD", cwd, env);
	free(cwd);
	cwd = NULL;
	cwd = update_cwd(cwd);
	set_pwd_vars_env("PWD", cwd, env);
	free(cwd);
	return (0);
}
