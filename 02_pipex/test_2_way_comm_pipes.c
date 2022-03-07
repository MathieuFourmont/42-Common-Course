/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_2_way_comm_pipes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:56:44 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/07 11:57:07 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This program is to implement a two way communication between processes using pipes

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int	main()
{
	int	p1[2]; // Child -> Parent
	int	p2[2]; // Parent -> Child
	int	pid;

	if (pipe(p1) == -1)
		return (1);
	if (pipe(p2) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0)
	{
		// Child process
		close(p1[0]);
		close(p2[1]);
		int	x;
		if (read(p2[0], &x, sizeof(x)) == -1)
			return (3);
		printf("Received x = %d\n", x);
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1)
			return (4);
		printf("Wrote x = %d\n", x);
		close(p1[1]);
		close(p2[0]);
	}
	else
	{
		// Parent process
		close(p1[1]);
		close(p2[0]);
		srand(time(NULL));
		int	y;
		y = rand() % 10;
		if (write(p2[1], &y, sizeof(y)) == -1)
			return (5);
		printf("Wrote y = %d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1)
			return (6);
		printf("Result = %d\n", y);
		close(p1[0]);
		close(p2[1]);
		wait(NULL);
	}
	return (0);
}
