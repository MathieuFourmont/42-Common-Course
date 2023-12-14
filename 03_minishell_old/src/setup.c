/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvan-hov <hvan-hov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:49:01 by hvan-hov          #+#    #+#             */
/*   Updated: 2022/06/07 20:01:20 by hvan-hov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_setup(t_cmd *cmd, char **envp)
{
	if (init_term() < 0)
	{
		ft_putstr_fd("Termcaps have failed.\n", STDERR_FILENO);
		exit (1);
	}
	cmd->env = (t_list **)malloc(sizeof(t_list));
	if (!cmd->env)
	{
		ft_printf("error: unable to initialize the shell\n");
		exit(1);
	}
	*(cmd->env) = NULL;
	cmd->tokens = NULL;
	env_init(cmd, envp);
	cmd->exit_status = 0;
	exec_signals(INIT);
}
