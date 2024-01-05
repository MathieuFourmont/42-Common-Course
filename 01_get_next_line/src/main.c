/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <mmaxime-@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 10:26:16 by mmaxime-          #+#    #+#             */
/*   Updated: 2024/01/05 11:06:04 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	// ft_putchars('\n');
}

int	main (int argc, char **argv)
{
	int		fd;
	char	*line;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("Couldn't read file: ");
			ft_putstr(argv[1]);
			ft_putstr("\n");
			return (-1);
		}
		line = get_next_line(fd);
		while (line != NULL)
		{
			ft_putstr(">>>>>");
			ft_putstr(line);
			ft_putstr("<<<<<\n");
			line = get_next_line (fd);
		}
	}
	else
	{
		ft_putstr("Usage: ./gnl <filename> OR ./gnl_bonus <filename> \n");
	}
	return (0);
}

/*int	main(void)
{
	char *buffer;
	int fd;
	int n;

	// fd = open("files/bin", O_RDONLY);
	// fd = -2147483647;
	// fd = open("files/41_no_nl", O_RDONLY);
	// fd = open("files/41_with_nl", O_RDONLY);
	// fd = open("files/42_no_nl", O_RDONLY);
	// fd = open("files/42_with_nl", O_RDONLY);
	// fd = open("files/43_no_nl", O_RDONLY);
	// fd = open("files/43_with_nl", O_RDONLY);
	// fd = open("files/alternate_line_nl_no_nl", O_RDONLY);
	// fd = open("files/alternate_line_nl_with_nl", O_RDONLY);
	// fd = open("files/big_line_no_nl", O_RDONLY);
	// fd = open("files/big_line_with_nl", O_RDONLY);
	// fd = open("files/multiple_nlx5", O_RDONLY);
	// fd = open("files/nl", O_RDONLY);
	fd = open("test", O_RDONLY);
	n = 1;
	while (n)
	{
		buffer = get_next_line(fd);
		if (buffer)
		{
			ft_putstr(buffer);
			free (buffer);
		}
		else
			n = 0;
		// n--;
	}
	// ft_putchar('\n');
	printf("\n&%s| \n",buffer);
	close(fd);


	return (0);
}*/
