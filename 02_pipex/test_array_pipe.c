#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

// 2 processes
// 1) Child should generate random nb and send them to the parent
// 2) Parent is going to sum all the nb and print the result

int main(int argc, char **argv)
{
    int fd[2];
    int pid;
    if (pipe(fd) == -1)
        return 2;
    pid = fork();
    if (pid == -1)
        return (1);
    if (pid == 0)
    {
        close(fd[0]);
        int n;
        int i;
        int arr[10];
        srand(time(NULL));
        n = rand() % 10 + 1;
        i = 0;
        printf("Generated: ");
        while (i < n)
        {
            arr[i] = rand() % 11;
            printf("%d ", arr[i]);
            i++;
        }
        printf("\n");
        if (write(fd[1], &n, sizeof(int)) < 0)
            return (4);
        printf("Sent n = %d\n", n);
        if (write(fd[1], arr, sizeof(int) * n) < 0)
            return (3);
        printf("Sent array\n");
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        int arr[10];
        int i;
        int n;
        int sum = 0;
        if (read(fd[0], &n, sizeof(int)) < 0)
            return (5);
        printf("Received n = %d\n", n);
        if (read(fd[0], arr, sizeof(int) * n) < 0)
            return (6);
        printf("Received array\n");
        i = 0;
        while (i < n)
        {
            sum += arr[i];
            i++;
        }
        printf("Result is: %d\n", sum);
        wait(NULL);
    }
    return (0);
}