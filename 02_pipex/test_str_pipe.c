#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv)
{
    int fd[2];
    int pid;
    if (pipe(fd) == -1)
        return (1);
    pid = fork();
    if (pid == -1)
        return (2);
    if (pid == 0)
    {
        close(fd[0]);
        char    str[200];
        int n;
        printf("Input string: ");
        fgets(str, 200, stdin);
        str[strlen(str) - 1] = '\0'; // to not have the \n at the end of the string
        n = strlen(str) + 1;
        if (write(fd[1], &n, sizeof(int)) < 0)
            return (4);
        if (write(fd[1], str, sizeof(char) * n) < 0)
            return (3);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        char str[200];
        int n;
        if (read(fd[0], &n, sizeof(int)) < 0)
            return (5);
        if (read(fd[0], str, sizeof(char) * n) < 0)
            return (6);
        printf("Received: %s\n", str);
        close(fd[0]);
        wait(NULL);
    }
    return (0);
}