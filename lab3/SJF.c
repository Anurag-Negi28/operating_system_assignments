#include <stdio.h>

void sortProcesses(int num_processes, int burst_time[]) {
    // Implement a simple sorting algorithm (e.g., Bubble Sort)
    for (int i = 0; i < num_processes - 1; i++) {
        for (int j = 0; j < num_processes - i - 1; j++) {
            if (burst_time[j] > burst_time[j + 1]) {
                // Swap burst time
                int temp_burst = burst_time[j];
                burst_time[j] = burst_time[j + 1];
                burst_time[j + 1] = temp_burst;
            }
        }
    }
}

int main() {
    int num_processes;
    
    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);  // Read the number of processes from the user
    
    int burst_time[num_processes];
    int waiting_time[num_processes];
    
    printf("Enter burst time for each process:\n");
    
    // Input burst time for each process
    for (int i = 0; i < num_processes; i++) {
        printf("Burst time for Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }
    
    // Sort processes based on burst time
    sortProcesses(num_processes, burst_time);
    
    // Calculate waiting time for each process
    waiting_time[0] = 0;  // The first process starts with 0 waiting time
    
    for (int i = 1; i < num_processes; i++) {
        waiting_time[i] = waiting_time[i - 1] + burst_time[i - 1];
    }
    
    // Display the process details and waiting time
    printf("\nProcess\tBurst Time\tWaiting Time\n");
    
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i]);
    }

    // Display Gantt chart
    printf("\nGantt Chart:\n");
    printf("|");
    
    for (int i = 0; i < num_processes; i++) {
        for (int j = 0; j < burst_time[i]; j++) {
            printf("-");
        }
        printf("|P%d", i + 1);
    }
    
    printf("|");
    
    // Display waiting time below each process
    printf("\n ");
    
    for (int i = 0; i < num_processes; i++) {
        printf(" ");
        for (int j = 0; j < burst_time[i] - 1; j++) {
            printf(" ");
        }
        printf(" %d ", waiting_time[i]);
    }

    return 0;
}
