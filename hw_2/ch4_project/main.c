#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

const int MAX_DEPTH = 4;
const int MIN_PARTITION_SIZE = 128;

void* sort_thread(void* args);

struct SortParams 
{
    int* array;
    int len;
    int depth;
};

int* generate_array(int n) 
{
    srand(time(0));

    int* array = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        array[i] = rand() % 100000;
    }

    return array;
}

int cmp(const void* arg1, const void* arg2) {
    const int* lhs = (int*)arg1;
    const int* rhs = (int*)arg2;

    if (*lhs < *rhs) 
    {
        return -1;
    } 
    else if (*lhs == *rhs) 
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

void merge(int* start, int* mid, int* end) 
{
    int* result = (int*)malloc((end - start) * sizeof(int));
    int* lhs = start, *rhs = mid, *dst = result;

    while (lhs != mid && rhs != end) 
    {
        if (*lhs < *rhs) 
        {
            *dst++ = *lhs++;
        }
        else
        {
            *dst++ = *rhs++;
        }
    }

    while (lhs != mid)
    {
        *dst++ = *lhs++;
    }

    memcpy(start, result, (rhs - start) * sizeof(int));
    free(result);
}

void sort_multithread(int* array, int len, int depth)
{
    if (len < 2) return;

    if (depth == 0 || len < MIN_PARTITION_SIZE)
    {
        qsort(array, len, sizeof(int), cmp);
        return;
    }

    struct SortParams params = {array, len / 2, depth - 1};
    pthread_t t_id;

    pthread_create(&t_id, NULL, sort_thread, &params);

    sort_multithread(array + len / 2, len - len / 2, depth - 1);

    pthread_join(t_id, NULL);

    merge(array, array + len / 2, array + len);
}

void* sort_thread(void* args)
{
    struct SortParams* params = (struct SortParams*)args;
    sort_multithread(params->array, params->len, params->depth);
    return args;
}

void sort(int* array, int len)
{
    sort_multithread(array, len, MAX_DEPTH);
}

void print_sorted_array(int* array, int len)
{
    for (int i = 1; i < len; i++)
    {
        if (array[i] < array[i - 1])
        {
            printf("The array is not sorted!...:(\n");
            return;
        }
    }

    printf("The sorted array is:\n");
    for (int i = 0; i < len; i++)
    {
        printf("%5d ", array[i]);

        if (i % 10 == 9)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int main(int argc, char** argv) 
{
    const int n = atoi(argv[1]);
    int* array = generate_array(n);
    sort(array, n);
    print_sorted_array(array, n);
    free(array);
    return 0;
}
