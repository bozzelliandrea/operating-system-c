#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (used for quick sorting)
int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

// Function to find the median of an array
double find_median(int arr[], int size)
{

    // If size is odd, return middle element
    if (size % 2 != 0)
    {
        return arr[size / 2];
    }
    // If size is even, return average of middle two elements
    return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
}

/**
 * Write a C program that implements a function to find the median of an array of integers.
 * The program should take an array and its size as input, and return the median value of the integers.
 */
int main()
{
    int size;

    // Input array size
    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1 || size < 0)
    {
        printf("Invalid array size!\n");
        return 1;
    }

    // If input size is 0, means empty array, so return and quit
    if (size == 0)
    {
        printf("Empty array size, exting...\n");
        return 0;
    }

    int arr[size];

    // Input numbers
    printf("Enter %d integers separated by whitespace: ", size);

    int element_counter = 0;
    // Loop until we scan input numbers, if user add more numbers than size, extra will be ignored
    while (element_counter < size)
    {
        int entry;
        if (scanf("%u", &entry) != 1)
        { // Invalid input (not an integer)
            printf("Invalid input! Please enter only integers.\n");
            return 1;
        }

        arr[element_counter] = entry;
        element_counter++;
    }

    // Sort the array
    qsort(arr, size, sizeof(int), compare);

    // Print the valid numbers
    printf("Sorted numbers for input array of size %d (numbers beyond the input size will be excluded):\n", size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double median = find_median(arr, size);
    // Print float value with 1 decimal
    printf("Median: %.1f\n", median);

    return 0;
}
