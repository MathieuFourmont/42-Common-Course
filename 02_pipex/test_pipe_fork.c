#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int	fd[2];
	// fd[0] -> read
	// fd[1] -> write
	if (pipe(fd) == -1)
	{
		printf("An error ocurred when opening the pipe\n");
		return (1);
	}
	int	id = fork();
	if (id == -1)
	{
		printf("An error ocurred with the fork\n");
		return (2);
	}
	if (id == 0)
	{
		close(fd[0]); // we don't read anything in the child process, just writing
		int	x;
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("An error ocurred when writing to the pipe\n");
			return (3);
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]); // we don't write anything in the main process, just reading
		int	y;
		if (read(fd[0], &y, sizeof(int)) == -1)
		{
			printf("An error ocurred when reading from the pipe\n");
			return (4);
		}
		close(fd[0]);
		y = 3 * y;
		printf("Got from child process %d\n", y);
		wait(NULL);
	}
	return (0);
}
