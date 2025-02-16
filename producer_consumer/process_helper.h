#include <stdio.h>
#include <time.h>

// Log colors
#define RESET "\033[0m"
#define RED "\033[31m"
#define CYAN "\033[36m"

// Shared memory config
#define SHM_SIZE 1024
#define SHM_KEY 1111
#define SEM_NAME "/opit_os_sem"

// Process type
#define CONSUMER "Consumer"
#define PRODUCER "Producer"

// Helper to print Date now with timestamp 
void print_time_now(void)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("%d-%02d-%02d %02d:%02d:%02d ", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void log_info(char *process, char *msg)
{
    print_time_now();
    printf(CYAN "INFO " RESET "%s => %s\n", process, msg);
}

void log_err(char *process, char *msg)
{
    print_time_now();
    printf(RED "ERROR " RESET "%s => %s\n", process, msg);
}
