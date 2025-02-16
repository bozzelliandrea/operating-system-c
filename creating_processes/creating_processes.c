#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * In a UNIX/Linux environment, write a C program to simulate a simple process scheduler using the First-Come, First-Served (FCFS) approach. Your program
 *  should create a separate child process for each given burst time in an array, then wait for all child processes to complete execution before the parent process exits.
 *  Requirements:
 *  • Use the fork() system call to create new child processes. Each child process should
 *  print its Process ID (PID) and its assigned burst time from the array, e.g.,
 *  burstTimes[] = {10, 15, 20}.
 *  • Ensure that your program can handle an arbitrary number of burst times provided in the burstTimes array.
 *  • In the child process, after printing its PID and burst time, exit successfully using exit(EXIT_SUCCESS).
 *  • In the parent process, wait for each child process to complete. Use the wait() system call to ensure that the parent process waits until all child processes have finished executing. For each terminated child, print a message indicating that the child process with a specific PID has finished.
 *  • Ensure proper error handling for the fork() system call. If fork() fails, print an appropriate error message and exit the program with exit(EXIT_FAILURE).
 *  • The program should not cause any zombie processes.
 *  Write the complete C program to implement the above specifications.
 */
int main()
{
    // Array of burst times
    int burst_times[] = {10, 15, 20, 3, 4, 2, 1, 5};
    // Lenght of the array
    int num_processes = sizeof(burst_times) / sizeof(int);

    for (int i = 0; i < num_processes; i++)
    {
        // Create new child process
        pid_t pid = fork();

        // Check if process was created successfully
        if (pid < 0)
        {
            // Fork failed
            perror("fork failed");
            exit(EXIT_FAILURE);
        }
        // Ensure is a child process
        else if (pid == 0)
        {
            printf("Child Process PID: %d - Burst Time: %d seconds\n", getpid(), burst_times[i]);
            // Simulate CPU execution time using burst_time unit as seconds
            sleep(burst_times[i]);
            exit(EXIT_SUCCESS);
        }
    }

    // Parent process waits for all child processes
    for (int i = 0; i < num_processes; i++)
    {
        // Wait child process completed
        pid_t completed_pid = wait(NULL);
        printf("Child Process PID: %d has finished execution.\n", completed_pid);
    }

    return 0;
}
