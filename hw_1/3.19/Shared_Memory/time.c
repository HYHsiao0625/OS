#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <sys/shm.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./time <command>\n");
        return 1;
    }

    struct timeval *start_time;

    int shmid = shmget(IPC_PRIVATE, sizeof(struct timeval), IPC_CREAT | 0666);
    start_time = (struct timeval *)shmat(shmid, NULL, 0);

    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0)
    {
        gettimeofday(start_time, NULL);
        
        execvp(argv[1], &argv[1]);

        perror("Exec failed");
        return 1;
    }
    else
    {
        wait(NULL);

        struct timeval end_time;
        gettimeofday(&end_time, NULL);

        float elapsed = (end_time.tv_sec - start_time->tv_sec) +
                        (end_time.tv_usec - start_time->tv_usec) / 1e6;

        printf("Elapsed time: %.5f\n", elapsed);
    }

    shmdt(start_time);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}