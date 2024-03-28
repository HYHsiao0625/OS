#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./time <command>\n");
        return 1;
    }

    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("Pipe failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0)
    {
        close(fd[0]);

        struct timeval start_time;
        gettimeofday(&start_time, NULL);

        write(fd[1], &start_time, sizeof(struct timeval));

        close(fd[1]);

        execvp(argv[1], &argv[1]);

        perror("Exec failed");
        return 1;
    }
    else
    {
        close(fd[1]);

        wait(NULL);

        struct timeval start_time, end_time;
        read(fd[0], &start_time, sizeof(struct timeval));

        gettimeofday(&end_time, NULL);

        float elapsed = (end_time.tv_sec - start_time.tv_sec) +
                        (end_time.tv_usec - start_time.tv_usec) / 1e6;

        printf("Elapsed time: %.5f seconds\n", elapsed);
    }

    close(fd[0]);

    return 0;
}