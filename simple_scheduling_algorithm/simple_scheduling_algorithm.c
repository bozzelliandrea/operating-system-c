#include <stdio.h>
#include <stdlib.h>

// Function to compute waiting and turnaround times
void calculate_times(int burst[], int n, int waiting[], int turnaround[])
{
    // First process has zero waiting time
    waiting[0] = 0;
    // First turnaround time is its own burst time
    turnaround[0] = burst[0];

    for (int i = 1; i < n; i++)
    {
        // Previous WT + Previous Burst
        waiting[i] = waiting[i - 1] + burst[i - 1];
        // WT + Burst Time
        turnaround[i] = waiting[i] + burst[i];
    }
}

// Function to print results with tabs
void print_results(int burst[], int waiting[], int turnaround[], int n)
{
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, burst[i], waiting[i], turnaround[i]);
    }

    // Calculate and print average times
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++)
    {
        avg_wt += waiting[i];
        avg_tat += turnaround[i];
    }
    avg_wt /= n;
    avg_tat /= n;

    // Print average with 2 floating support
    printf("\nAverage Waiting Time: %.2f ms\n", avg_wt);
    printf("Average Turnaround Time: %.2f ms\n", avg_tat);
}

/**
 * Write a C program to implement a basic First-Come, First-Served (FCFS) scheduling algorithm.
 * The program should accept the burst times of a set of processes (from the command line)
 * and calculate their waiting times and turnaround times.
 */
int main(int argc, char *argv[])
{
    // Check if args are less than 2, means the CLI called the program only with the program name.
    if (argc < 2)
    {
        printf("Usage: %s <burst_times>...\n", argv[0]);
        return 1;
    }

    // Remove program name from args counter
    int n = argc - 1;
    // Array definition
    int burst[n], waiting[n], turnaround[n];

    // Read burst times from command-line arguments
    for (int i = 0; i < n; i++)
    {
        // Convert input to integer
        burst[i] = atoi(argv[i + 1]);
    }

    // Compute waiting and turnaround times
    calculate_times(burst, n, waiting, turnaround);

    print_results(burst, waiting, turnaround, n);

    return 0;
}
