/*#include <stdio.h>

// Function to simulate Round Robin scheduling algorithm
void round_robin_scheduling(int processes[], int n, int burst_time[], int quantum) {
    int remaining_burst_time[n];
    int waiting_time = 0;
    int turnaround_time = 0;
    int waitingTime[n] ;
    int TurnAroundTime[n] ;
    // Copy burst time of all processes into remaining_burst_time array
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = burst_time[i];
    }

    
*/
#include<stdio.h>
 
int main()
{
      int i, limit, total = 0, x, counter = 0, time_quantum;
      int wait_time = 0, turnaround_time = 0, arrival_time[10], burst_time[10], temp[10];
      float average_wait_time, average_turnaround_time;
      printf("\nEnter Total Number of Processes:");
      scanf("%d", &limit);
      x = limit;
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);

            //taking value
 
            printf("Arrival Time:");
 
            scanf("%d", &arrival_time[i]);
 
            printf("Burst Time:");
 
            scanf("%d", &burst_time[i]);
 
            temp[i] = burst_time[i];
      }
 /*int current_time = 0;
    while (1) {
        int all_processes_completed = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0) {
                all_processes_completed = 0;

                if (remaining_burst_time[i] > quantum) {
                    current_time += quantum;
                    remaining_burst_time[i] -= quantum;
                } else {
                    current_time += remaining_burst_time[i];
                    waitingTime[i] += current_time - burst_time[i] - quantum;
                    remaining_burst_time[i] = 0;
                    TurnAroundTime[i] += current_time - burst_time[i];
                }
            }
        }

        if (all_processes_completed == 1) {
            break;
        }
    }

    float average_waiting_time = (float) waiting_time / n;
    float average_turnaround_time = (float) turnaround_time / n;

    // Print results
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waitingTime[i], TurnAroundTime[i]);
    }
    printf("Average waiting time = %.2f\n", average_waiting_time);
    printf("Average turnaround time = %.2f\n", average_turnaround_time);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processes[n], burst_time[n];
    for (int i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i+1);
        scanf("%d", &burst_time[i]);
        processes[i] = i+1;
    }

    int quantum;
    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    // Simulate Round Robin scheduling algorithm
    round_robin_scheduling(processes, n, burst_time, quantum);

    return 0;
}*/

 
      printf("\nEnter Time Quantum:");
      scanf("%d", &time_quantum);
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= time_quantum && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - time_quantum;
                  total = total + time_quantum;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, burst_time[i], total - arrival_time[i], total - arrival_time[i] - burst_time[i]);
                  wait_time = wait_time + total - arrival_time[i] - burst_time[i];
                  turnaround_time = turnaround_time + total - arrival_time[i];
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(arrival_time[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
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
 
      average_wait_time = wait_time * 1.0 / limit;
      average_turnaround_time = turnaround_time * 1.0 / limit;
      printf("\n\nAverage Waiting Time:%f", average_wait_time);
      printf("\nAvg Turnaround Time:%f\n", average_turnaround_time);
      return 0;
}
/*#include <stdio.h>
#include <stdlib.h>

struct process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
};

int main() {
    int num_processes, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    struct process *processes = (struct process *) malloc(num_processes * sizeof(struct process));
    int *completion_time = (int *) malloc(num_processes * sizeof(int));
    int *turnaround_time = (int *) malloc(num_processes * sizeof(int));
    int *waiting_time = (int *) malloc(num_processes * sizeof(int));
    int *executed = (int *) malloc(num_processes * sizeof(int));

    for(int i=0; i<num_processes; i++) {
        printf("Enter arrival time and burst time for process %d: ", i+1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].process_id = i+1;
        processes[i].remaining_time = processes[i].burst_time;
        executed[i] = 0;
    }

    

    for(int i=0; i<num_processes; i++) {
        turnaround_time[i] = completion_time[i] - processes[i].arrival_time;
        waiting_time[i] = turnaround_time[i] - processes[i].burst_time;
    }

    printf("\nProcess ID\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for(int i=0; i<num_processes; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t\t%d\n", processes[i].process_id, processes[i].arrival_time, processes[i].burst_time, completion_time[i], turnaround_time[i], waiting_time[i]);
    }

    float average_turnaround_time = 0, average_waiting_time = 0;
    for(int i=0; i<num_processes; i++) {
        average_turnaround_time += turnaround_time[i];
        average_waiting_time += waiting_time[i];
    }
    average_turnaround_time /= num_processes;
    average_waiting_time /= num_processes;

    printf("\nAverage Turnaround Time = %0.2f", average_turnaround_time);
    printf("\nAverage Waiting Time = %0.2f", average_waiting_time);

    free(processes);
    free(completion_time);
    free(turnaround_time);
    free(waiting_time);
    free(executed);

    return 0;
}*/

