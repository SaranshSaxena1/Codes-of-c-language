#include <stdio.h>
#include <stdlib.h>

// Defining struct
typedef struct process {
    int pid;
    int burst_time;
    int arrival_time;
} process;

// FCFS scheduling algorithm
void fcfs_scheduling(process processes[], int n) {
    int total_time = 0;
    float average_waiting_time = 0;
    float average_turnaround_time = 0;
    int burst_time[n], waiting_time[n], turnaround_time[n];

    // Sorting on the processes based on their arrival times
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (processes[j].arrival_time > processes[j+1].arrival_time) {
                process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    // Copy burst time of all processes into this array
    for (int i = 0; i < n; i++) {
        burst_time[i] = processes[i].burst_time;
    }

    // Calculate waiting time and turnaround time for each process
    waiting_time[0] = 0;
    for (int i = 1; i < n; i++) {
        waiting_time[i] = burst_time[i-1] + waiting_time[i-1];
    }
    for (int i = 0; i < n; i++) {
        turnaround_time[i] = burst_time[i] + waiting_time[i];
    }

    // Calculate total waiting time and turnaround time for all processes
    for (int i = 0; i < n; i++) {
        total_time += turnaround_time[i];
        average_waiting_time += waiting_time[i];
        average_turnaround_time += turnaround_time[i];
    }

    // Calculate average waiting time and average turnaround time for all processes
    average_waiting_time /= n;
    average_turnaround_time /= n;

    // Print results
    printf("Process ID\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n"); 
    //printing the table
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, burst_time[i], processes[i].arrival_time, waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time = %.2f\n", average_waiting_time);
    printf("Average turnaround time = %.2f\n", average_turnaround_time);
}

int main() {
    // Get number of processes from user
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Get burst time and arrival time for each process from user
    process processes[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &processes[i].burst_time);
        printf("Enter arrival time for process %d: ", i+1);
        scanf("%d", &processes[i].arrival_time);
        processes[i].pid = i+1;
    }

    // Simulate FCFS scheduling algorithm
    fcfs_scheduling(processes, n);

    return 0;
}//end
