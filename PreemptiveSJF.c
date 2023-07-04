/*#include <stdio.h>
#include <limits.h>

// Function to simulate SRTF scheduling algorithm
void srtf_scheduling(int processes[], int n, int burst_time[]) {
    int remaining_burst_time[n];
    int waiting_time[n];
    int turnaround_time[n];
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    int completed = 0;
    int current_time = 0;
    int shortest_job_index;

    // Copy burst time of all processes into remaining_burst_time array
    for (int i = 0; i < n; i++) {
        remaining_burst_time[i] = burst_time[i];
    }

    while (completed != n) {
        shortest_job_index = -1;
        int shortest_job_burst_time = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (remaining_burst_time[i] > 0 && remaining_burst_time[i] < shortest_job_burst_time) {
                shortest_job_index = i;
                shortest_job_burst_time = remaining_burst_time[i];
            }
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

    // Simulate SRTF scheduling algorithm
    srtf_scheduling(processes, n, burst_time);

    return 0;
}*/
#include<stdio.h>
 int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
  
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;         
    }
  
   //sorting of burst times
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
  
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
   
    wt[0]=0;            
  /*
  if (shortest_job_index == -1) {
            current_time++;
            continue;
        }

        remaining_burst_time[shortest_job_index]--;

        if (remaining_burst_time[shortest_job_index] == 0) {
            completed++;
            int current_process = processes[shortest_job_index];
            turnaround_time[shortest_job_index] = current_time + 1 - burst_time[shortest_job_index];
            waiting_time[shortest_job_index] = turnaround_time[shortest_job_index] - burst_time[shortest_job_index];
            total_waiting_time += waiting_time[shortest_job_index];
            total_turnaround_time += turnaround_time[shortest_job_index];
        }

        current_time++;
    }

    float average_waiting_time = (float) total_waiting_time / n;
    float average_turnaround_time = (float) total_turnaround_time / n;

    // Print results
    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    }
    printf("Average waiting time = %.2f\n", average_waiting_time);
    printf("Average turnaround time = %.2f\n", average_turnaround_time);
}*/
   
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
  
        total+=wt[i];
    }
  
    avg_wt=(float)total/n;      
    total=0;
  
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];   
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
  
    avg_tat=(float)total/n;    
    /*for (i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].priority, waiting_time[i], turnaround_time[i]);
    }
    
    avg_waiting_time /= num_processes;
    avg_turnaround_time /= num_processes*/
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
