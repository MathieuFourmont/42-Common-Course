/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:48:26 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/11 14:47:21 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(1);
}

void	last_process(char *outfile, char *cmd, char **envp)
{
	int		fd_out;
	char	*path;

	fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_out == -1)
		ft_perror("outfile error");
	dup2(fd_out, STDOUT_FILENO);
	path = find_path(envp, cmd);
	if (!path || execve(path, ft_split(cmd, ' '), envp) == -1)
		ft_perror("Command failed/does not exist");
}

static void	looping_pipes(char *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;
	char	*path;

	if (pipe(fd) == -1)
		ft_perror("Pipe error");
	pid = fork();
	if (pid == -1)
		ft_perror("Fork error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		path = find_path(envp, cmd);
		if (!path || execve(path, ft_split(cmd, ' '), envp) == -1)
			ft_perror("Command failed/does not exist");
	}
	else
	{
		close(fd[1]);
		wait(NULL);
		dup2(fd[0], STDIN_FILENO);
	}
}

static void	ft_infile(char *infile)
{
	int	fd_in;

	fd_in = open(infile, O_RDONLY);
	if (fd_in == -1)
		ft_perror("infile error");
	dup2(fd_in, STDIN_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;

	if (argc < 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 ... cmdn file2");
		return (1);
	}
	ft_infile(argv[1]);
	i = 2;
	while (i < argc - 2)
	{
		looping_pipes(argv[i], envp);
		i++;
	}
	last_process(argv[argc - 1], argv[argc - 2], envp);
	return (0);
}
