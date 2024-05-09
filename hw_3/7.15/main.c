#include <stdio.h>
#include <pthread.h>

#define MAX_SEQUENCE 10

int fibonacci_sequence[MAX_SEQUENCE];
int sequence_length = 2; // Initial sequence length is 2 (0 and 1)
pthread_mutex_t mutex;

void *fibonacci(void *param) {
    int i;
    int n = *((int *)param);

    fibonacci_sequence[0] = 0;
    fibonacci_sequence[1] = 1;

    for (i = 2; i < n; i++) {
        int new_fibonacci = fibonacci_sequence[i-1] + fibonacci_sequence[i-2];
        pthread_mutex_lock(&mutex);
        fibonacci_sequence[i] = new_fibonacci;
        sequence_length++; // Increment the sequence length
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

int main()
{
    pthread_t tid;
    int n = MAX_SEQUENCE;
    int i;

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&tid, NULL, fibonacci, &n);

    // Output the Fibonacci sequence as soon as it's calculated
    while (sequence_length < n) {
        pthread_mutex_lock(&mutex);
        for (i = 0; i < sequence_length; i++) {
            printf("%d ", fibonacci_sequence[i]);
        }
        printf("\n");
        pthread_mutex_unlock(&mutex);
    }

    pthread_join(tid, NULL);
    pthread_mutex_destroy(&mutex);

    return 0;
}