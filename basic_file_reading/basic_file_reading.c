#include <stdio.h>
#include <stdlib.h>

/**
 * Create a C program that reads a text file containing a list of numbers, one per line, and calculates their sum.
 * The file name should be passed as a command-line argument.
 */
int main(int argc, char *argv[])
{
    // Check if args length is different that 2, if yes, log error and quit
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Open file and check if file reference exists
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    int num, sum = 0;

    char *line;
    // Read every line by line from the file stream until the end of file 
    while (fscanf(file, "%s", line) != EOF)
    {
        char *end_ptr;
        // Convert value which is a char pointer to number, use end pointer strategy to intercept invalid chars
        int num = strtol(line, &end_ptr, 10);

        // If arg_ptr after conversion is > 0, means we find chars that are not number, skip and continue iteration
        if (*end_ptr != '\0')
        {
            printf("WARN: Invalid number found: %s skipped..\n", line);
            continue;
        }

        sum += num;
    }

    // Close file stream
    fclose(file);
    printf("Sum of numbers: %d\n", sum);
    return 0;
}
