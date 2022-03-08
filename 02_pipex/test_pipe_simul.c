#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv)
{
    int fd[2];
    int pid1;
    int pid2;
    if (pipe(fd) == -1)
        return (1);
    pid1 = fork();
    if (pid1 == -1)
        return (2);
    if (pid1 == 0)
    {
        // Child process 1 (1st command)
        dup2(fd[1], STDOUT_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("ping", "ping", "-c", "5", "google.com", NULL); // 1st process is replaced by the ping program
    }
    pid2 = fork();
    if (pid2 == -1)
        return (3);
    if (pid2 == 0)
    {
        // Child process 2 (2nd command)
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        close(fd[1]);
        execlp("grep", "grep", "round-trip", NULL);
    }
    close(fd[0]);
    close(fd[1]);
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    return (0);
}