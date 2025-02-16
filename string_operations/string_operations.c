

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to concatenate two strings
char *concatenate_strings(const char *str1, const char *str2)
{
    // Allocate memory for the concatenated string
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char *result = malloc(len1 + len2 + 1); // +1 for null terminator

    if (!result)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    // Copy and concatenate the strings
    strcpy(result, str1);
    strcat(result, str2);

    return result;
}

/**
 * Implement a C function that takes two strings as input and
 * returns a new string that is the concatenation of the first string followed by the second.
 * Ensure proper memory management to avoid buffer overflows
 */
int main()
{
    // Data declaration
    char *str1 = NULL, *str2 = NULL;
    size_t len1 = 0, len2 = 0;

    // Read first string dynamically
    printf("Enter first string: ");
    if (getline(&str1, &len1, stdin) == -1)
    {
        printf("Error reading input!\n");
        return 1;
    }

    // Read second string dynamically
    printf("Enter second string: ");
    if (getline(&str2, &len2, stdin) == -1)
    {
        printf("Error reading input!\n");
        free(str1);
        return 1;
    }

    // Remove trailing newline characters
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    // Concatenate strings
    char *result = concatenate_strings(str1, str2);
    if (result)
    {
        printf("Concatenated string: %s\n", result);
        free(result);
    }

    // Free allocated memory
    free(str1);
    free(str2);

    return 0;
}
