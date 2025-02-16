#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (used for quick sorting)
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/**
 * Write a program in C that takes command-line arguments representing integer values and sorts them in ascending order.
 * The sorted numbers should be printed to the console.
 *
 * @param argc number of cli arguments, containing also program name, so argc >= 1
 * @param argv char pointers array, every element inside the array reference a single cli param, containing also program name
 */
int main(int argc, char *argv[])
{
    // check if no cli args passed, if only 1, means inside the cli context was enter only execution file name
    if (argc <= 1)
    {
        printf("Usage example: %s 1 2 3 -4 -5 -6...\n", argv[0]);
        return 1;
    }

    // initilize total params, we decrement argc by 1 because it include also the program name
    int total_params = argc - 1;
    int total_valid_params = 0;
    // numbers array declaration
    int numbers[total_params];

    // Convert arguments to integers
    for (int i = 0; i < total_params; i++)
    {
        char *agr_ptr;
        long int num;
        // Convert value which is a char pointer to number, use end pointer strategy to intercept invalid chars
        num = strtol(argv[i + 1], &agr_ptr, 10);

        // If arg_ptr after conversion is > 0, means we find chars that are not number, skip and continue iteration
        if (*agr_ptr != '\0')
        {
            printf("WARN: Invalid number at position: %d skipped..\n", i + 1);
            continue;
        }

        numbers[total_valid_params] = num;
        total_valid_params++;
    }

    // If all args are invalid, quit program.
    if (total_valid_params == 0)
    {
        printf("No valid arguments was passed, exiting...\n");
        return 0;
    }

    // Sort numbers
    qsort(numbers, total_valid_params, sizeof(int), compare);

    // Print sorted numbers
    printf("Sorted numbers: ");
    for (int i = 0; i < total_valid_params; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
