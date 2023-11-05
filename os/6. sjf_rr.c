#include <stdio.h>

// Function to implement Shortest Job First (Preemptive) Scheduling
void shortestJobFirst(int n, int bt[], int at[]) {

// time = current time smallest = index of process shortest remaining burst time 
    int time = 0, i, smallest, count = 0; //count = number of process that have finished executing
    double avgWT = 0, avgTAT = 0;

 // ct = complition time  wt = waiting time  tat = turn around time  
    int ct[n], wt[n], tat[n], rt[n]; //rt = remaining time  bt = burst time  at = arrival time 

    for (i = 0; i < n; i++) {
        rt[i] = bt[i];
    }

    while (count != n) {
        smallest = -1;
        for (i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (smallest == -1 || rt[i] < rt[smallest]) {
                    smallest = i;
                }
            }
        }

        if (smallest == -1) {
            time++;
        } else {
            rt[smallest]--;
            if (rt[smallest] == 0) {
                count++;
                ct[smallest] = time + 1;
                wt[smallest] = ct[smallest] - bt[smallest] - at[smallest];
                tat[smallest] = ct[smallest] - at[smallest];
                avgWT += wt[smallest];
                avgTAT += tat[smallest];
            }
            time++;
        }
    }

    printf("Shortest Job First (Preemptive) Scheduling:\n");
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %f\n", avgWT / n);
    printf("Average Turnaround Time: %f\n\n", avgTAT / n);
}

// Function to implement Round Robin Scheduling
void roundRobin(int n, int bt[], int at[], int quantum) {
    int i, time = 0, wt[n], tat[n], rt[n], remain = n;
    double total_wt = 0, total_tat = 0;

    for (i = 0; i < n; i++) {
        rt[i] = bt[i];
    }

    while (1) {
        int done = 1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;
                if (rt[i] > quantum) {
                    time += quantum;
                    rt[i] -= quantum;
                } else {
                    time += rt[i];
                    wt[i] = time - at[i] - bt[i];
                    rt[i] = 0;
                    tat[i] = bt[i] + wt[i];
                    total_wt += wt[i];
                    total_tat += tat[i];
                    remain--;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }

    printf("Round Robin Scheduling:\n");
    printf("Process\tBurst Time\tArrival Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], at[i], wt[i], tat[i]);
    }
    printf("Average Waiting Time: %f\n", total_wt / n);
    printf("Average Turnaround Time: %f\n\n", total_tat / n);
}

int main() {
    int n, i, quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n], arrivalTime[n];

    printf("Enter the burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Burst time of process %d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    printf("Enter the arrival time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("Arrival time of process %d: ", i + 1);
        scanf("%d", &arrivalTime[i]);
    }

    printf("Enter time quantum for Round Robin Scheduling: ");
    scanf("%d", &quantum);

    shortestJobFirst(n, bt, arrivalTime);
    roundRobin(n, bt, arrivalTime, quantum);

    return 0;
}