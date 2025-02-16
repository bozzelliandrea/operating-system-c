#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

struct thread_range
{
    int *data;
    int start_index;
    int end_index;
};

// Function to calculate sum of a given half
void *calculate_sum(void *arg)
{
    // Get the input context passed from the main process when thread initialized
    struct thread_range *context = (struct thread_range *)arg;
    int partial_sum = 0;

    // Sum the selected array window
    for (int i = context->start_index; i < context->end_index; i++)
    {
        partial_sum += context->data[i];
    }

    printf("Thread ID %lu is processing\n", (unsigned long)pthread_self());
    printf("Subtotal: %d\n", partial_sum);

    // Return sum using dynamically allocated memory
    int *result = malloc(sizeof(int));
    *result = partial_sum;
    pthread_exit(result);
}

/**
 *  Write a C program for Linux OS that uses two threads to calculate the sum of two halves of an integer array.
 *  Your program should divide an array of integers into two halves.
 *  Then, create two threads: one to calculate the sum of the first half, and the other to calculate the sum of the second half.
 * Finally, the main thread should wait for these two threads to complete their execution and then calculate and display the total sum of the array.
 *  Use the POSIX thread library (pthread) for creating and managing threads. (NOTE: when compiling, do not forget to use the -lpthread switch)
 */
int main()
{
    // Data declaration
    const int ARRAY_SIZE = 10;
    int arr[ARRAY_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Threads declaration
    pthread_t thread1, thread2;
    int *sum_first_half, *sum_second_half;
    int start_index = 0, half_index = ARRAY_SIZE / 2;

    struct thread_range *first_half_thread_range = malloc(sizeof(struct thread_range) * 1);

    first_half_thread_range->start_index = start_index;
    first_half_thread_range->end_index = half_index;
    first_half_thread_range->data = arr;

    struct thread_range *second_half_thread_range = malloc(sizeof(struct thread_range) * 1);

    second_half_thread_range->start_index = half_index;
    second_half_thread_range->end_index = ARRAY_SIZE;
    second_half_thread_range->data = arr;

    // Creating two threads
    pthread_create(&thread1, NULL, calculate_sum, first_half_thread_range);
    pthread_create(&thread2, NULL, calculate_sum, second_half_thread_range);

    // Waiting for threads to finish
    pthread_join(thread1, (void **)&sum_first_half);
    pthread_join(thread2, (void **)&sum_second_half);

    // Clean memory threads context config
    free(first_half_thread_range);
    free(second_half_thread_range);

    // Calculating total sum
    int total_sum = *sum_first_half + *sum_second_half;

    // Clean thread subtotal results
    free(sum_first_half);
    free(sum_second_half);

    // Display results
    printf("Total Sum = %d\n", total_sum);

    return 0;
}
