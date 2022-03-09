#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include "pipex.h"


int main(int argc, char **argv)
{
    int     fd[2];
    pid_t   pid1;
    pid_t   pid2;

    if (argc != 5)
        printf("Correct input: ./pipex file1 cmd1 cmd2 file2");
        return (0);
    if (pipe(fd) == -1)
        return (1);
    pid1 = fork();
    if (pid1 == -1)
        perror("Fork error");
    if (pid1 == 0)
    {
        // Child process 1 (1st command)
        int infile;
        infile = open(argv[1], O_RDONLY);
        dup2(fd[1], STDOUT_FILENO);
        dup2(infile, STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        /*ft_split(argv[2], ' ');*/
        if (execlp(argv[2], argv[2], NULL) == -1) // 1st process is replaced by the ping program
            perror("First command failed/does not exist");
    }
    pid2 = fork();
    if (pid2 == -1)
        return (3);
    if (pid2 == 0)
    {
        // Child process 2 (2nd command)
        int outfile;
        outfile = open(argv[4], O_WRONLY | O_CREAT, 0777);
        dup2(fd[0], STDIN_FILENO);
        dup2(outfile, STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        /*ft_split(argv[3], ' ');*/
        if (execlp(argv[3], argv[3], argv[3], NULL) == -1)
            perror("Second command failed/does exist");
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return (0);
}