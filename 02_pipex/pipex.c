/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:13:59 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/11 10:33:12 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(1);
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

void	right_side_pipe(int fd[2], char *outfile, char *cmd2, char **envp)
{
	int		fd_out;
	pid_t	pid2;
	char	*path;

	pid2 = fork();
	if (pid2 == -1)
		ft_perror("2nd fork error");
	if (pid2 == 0)
	{
		close(fd[1]);
		fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd_out == -1)
			ft_perror("outfile error");
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_out, STDOUT_FILENO);
		path = find_path(envp, cmd2);
		if (!path || execve(path, ft_split(cmd2, ' '), envp) == -1)
			ft_perror("Second command failed/does not exist");
	}
}

void	left_side_pipe(int fd[2], char *infile, char *cmd1, char **envp)
{
	int		fd_in;
	pid_t	pid1;
	char	*path;

	pid1 = fork();
	if (pid1 == -1)
		ft_perror("1st fork error");
	if (pid1 == 0)
	{
		close(fd[0]);
		fd_in = open(infile, O_RDONLY);
		if (fd_in == -1)
			ft_perror("infile error");
		dup2(fd[1], STDOUT_FILENO);
		dup2(fd_in, STDIN_FILENO);
		path = find_path(envp, cmd1);
		if (!path || execve(path, ft_split(cmd1, ' '), envp) == -1)
			ft_perror("First command failed/does not exist");
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc != 5)
	{
		ft_printf("Usage: ./pipex file1 cmd1 cmd2 file2");
		return (1);
	}
	if (pipe(fd) == -1)
		ft_perror("Pipe error");
	left_side_pipe(fd, argv[1], argv[2], envp);
	wait(NULL);
	right_side_pipe(fd, argv[4], argv[3], envp);
	close(fd[0]);
	close(fd[1]);
	return (0);
}
