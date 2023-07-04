#include <stdio.h>

struct Process {
    int pid;
    int burst_time;
    int priority;
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
        
        printf("Enter the arrival time, burst time, and priority for process %d: ", processes[i].pid);
        scanf("%d %d %d", &processes[i].arrival_time, &processes[i].burst_time, &processes[i].priority);
    /*int current_time = 0, count = 0;
    while(count < num_processes) {
        for(int i=0; i<num_processes; i++) {
            if(processes[i].arrival_time <= current_time && processes[i].remaining_time > 0) {
                if(processes[i].remaining_time > quantum) {
                    current_time += quantum;
                    processes[i].remaining_time -= quantum;
                }
                else {
                    current_time += processes[i].remaining_time;
                    completion_time[i] = current_time;
                    processes[i].remaining_time = 0;
                    executed[i] = 1;
                    count++;
                }
            }
        }
        current_time++;
    }*/
    
    for (i = 0; i < num_processes - 1; i++) {
        for (j = i + 1; j < num_processes; j++) {
            if (processes[i].priority > processes[j].priority) {
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
        int min_priority_process = i;
        for (j = i; j < num_processes; j++) {
            if (processes[j].arrival_time <= completion_time[i - 1] && processes[j].priority < processes[min_priority_process].priority) {
                min_priority_process = j;
            }
        }/*
        if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }*/
        temp = processes[i];
        processes[i] = processes[min_priority_process];
        processes[min_priority_process] = temp;
        
        completion_time[i] = completion_time[i - 1] + processes[i].burst_time;
        waiting_time[i] = completion_time[i - 1] - processes[i].arrival_time;
        if (waiting_time[i] < 0) {
            waiting_time[i] = 0;
        }
        avg_waiting_time += waiting_time[i];
    }
    
    for (i = 0; i < num_processes; i++) {
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
        avg_turnaround_time += turnaround_time[i];
    }
    
    printf("\nProcess\tArrival time\tBurst time\tPriority\tWaiting time\tTurnaround time\n");
    
    for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, waiting_time[i], turnaround_time[i]);
    }
    
    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes;
    
    printf("\nAverage waiting time: %.2f", avg_waiting_time);
    printf("\nAverage turnaround time: %.2f", avg_turnaround_time);
    
    return 0;
}
