#include <stdio.h>
#include <stdlib.h>

struct process {
    int pid; // process ID
    int arrival_time; // arrival time
    int burst_time; // burst time
    int remaining_time; // remaining time
};

int main() {
    int n = 0, i, j, time = 0, sum_bt = 0, largest;
    float average_wait_time = 0, average_turnaround_time = 0;

    struct process *p = NULL; // initialize the pointer to NULL

    while (1) {
        printf("Enter the arrival time and burst time for process %d (or enter -1 to exit): ", n+1);
        int at, bt;
        scanf("%d", &at);
        if (at == -1) {
            break; // exit loop if -1 is entered
        }
        scanf("%d", &bt);

        n++;
        p = (struct process *) realloc(p, n * sizeof(struct process)); // allocate memory for new process
        p[n-1].pid = n;
        p[n-1].arrival_time = at;
        p[n-1].burst_time = bt;
        p[n-1].remaining_time = bt;
        sum_bt += bt;
    }

    for(time = 0; time < sum_bt;) {
        largest = 0;
        for(i = 0; i < n; i++) {
            if(p[i].arrival_time <= time && p[i].remaining_time > p[largest].remaining_time) {
                largest = i;
            }
        }

        time += p[largest].remaining_time;
        p[largest].remaining_time = 0;

        printf("Process[%d]\t\tWaiting Time = %d\t\tTurnaround Time = %d\n", p[largest].pid, time - p[largest].arrival_time - p[largest].burst_time, time - p[largest].arrival_time);

        average_wait_time += time - p[largest].arrival_time - p[largest].burst_time;
        average_turnaround_time += time - p[largest].arrival_time;
    }

    printf("\nAverage waiting time = %f\n", average_wait_time / n);
    printf("Average turnaround time = %f\n", average_turnaround_time / n);

    free(p); // free allocated memory

    return 0;
}