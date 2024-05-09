#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define MAX_THREADS 10  // Define a maximum number of threads

typedef struct Point {
  double x;
  double y;
} Point;

int points_in_circle = 0;
pthread_mutex_t mtx; // Declare a mutex for thread synchronization

void generate_points(int num_points) {
  srand(time(NULL)); // Seed the random number generator (once per thread)

  for (int i = 0; i < num_points; i++) {
    double x = (double)rand() / (double)RAND_MAX * 2.0 - 1.0; // Generate random x in [-1, 1]
    double y = (double)rand() / (double)RAND_MAX * 2.0 - 1.0; // Generate random y in [-1, 1]

    pthread_mutex_lock(&mtx); // Lock before accessing shared data
    if (sqrt(x * x + y * y) <= 1.0) {
      points_in_circle++;
    }
    pthread_mutex_unlock(&mtx); // Unlock after accessing shared data
  }
}

void* thread_function(void* arg) {
  int num_points = *(int*)arg;
  generate_points(num_points);
  return NULL;
}

int main() {
  int total_points, num_threads;

  printf("How many points would you like to generate?\n");
  scanf("%d", &total_points);

  printf("How many threads should create points (max %d)?\n", MAX_THREADS);
  scanf("%d", &num_threads);

  if (num_threads > MAX_THREADS) {
    printf("Limiting threads to %d (max allowed).\n", MAX_THREADS);
    num_threads = MAX_THREADS;
  }

  pthread_t threads[num_threads];
  int points_per_thread = total_points / num_threads;
  int remaining_points = total_points % num_threads;

  pthread_mutex_init(&mtx, NULL); // Initialize the mutex

  for (int i = 0; i < num_threads; i++) {
    int points_to_generate = points_per_thread;
    if (remaining_points > 0) {
      points_to_generate++;
      remaining_points--;
    }

    int ret = pthread_create(&threads[i], NULL, thread_function, (void*)&points_to_generate);
    if (ret) {
      printf("Error creating thread: %d\n", ret);
      return 1;
    }
  }

  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  pthread_mutex_destroy(&mtx); // Destroy the mutex

  double pi_estimation = 4.0 * (double)points_in_circle / (double)total_points;
  printf("Estimated pi value: %f\n", pi_estimation);

  return 0;
}
