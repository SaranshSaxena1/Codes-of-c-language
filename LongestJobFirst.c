#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int arrival_time;
};

int main() {
    int num_processes, i, j;
    float avg_waiting_time = 0, avg_turnaround_time = 0;
    
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    
    struct Process processes[num_processes], temp;
    
    for (i = 0; i < num_processes; i++) {
        processes[i].pid = i + 1;
        
        printf("Enter the arrival time and burst time for process %d: ", processes[i].pid);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
    }
    
    // Sort processes by burst time in descending order
    for (i = 0; i < num_processes - 1; i++) {
        for (j = i + 1; j < num_processes; j++) {
            if (processes[i].burst_time < processes[j].burst_time) {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    
    int waiting_time[num_processes], turnaround_time[num_processes], completion_time[num_processes];
    
    waiting_time[0] = 0;
    completion_time[0] = processes[0].burst_time;
    
    for (i = 1; i < num_processes; i++) {
        completion_time[i] = completion_time[i-1] + processes[i].burst_time;
        waiting_time[i] = completion_time[i-1] - processes[i].arrival_time;
        if (waiting_time[i] < 0) {
            waiting_time[i] = 0;
        }
    }
    
    for (i = 0; i < num_processes; i++) {
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
    }
    
    printf("\nProcess\tArrival time\tBurst time\tWaiting time\tTurnaround time\n");
    
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, waiting_time[i], turnaround_time[i]);
        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }
    
    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;
    
    printf("\nAverage waiting time: %.2f", avg_waiting_time);
    printf("\nAverage turnaround time: %.2f", avg_turnaround_time);
    
    return 0;
}
