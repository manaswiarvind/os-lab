#include <stdio.h>
#define max 10
struct process
{
    int at;   
    int bt;  
    int pr;   
    int rt;  
    int wt;   
    int tat;  
    int ct;   
};
void priorityScheduling(struct process p[], int n)
{
    int completed = 0, t = 0;
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++)
        p[i].rt = p[i].bt;
    while (completed < n)
    {
        int idx = -1;
        int highest_priority = 9999;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= t && p[i].rt > 0)
            {
                if (p[i].pr < highest_priority)
                {
                    highest_priority = p[i].pr;
                    idx = i;
                }
                else if (p[i].pr == highest_priority)
                {
                    if (p[i].at < p[idx].at)
                        idx = i;
                }
            }
        }

        if (idx != -1)
        {
            p[idx].rt--;
            t++;
            if (p[idx].rt == 0)
            {
                completed++;
                p[idx].ct = t;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;
                if (p[idx].wt < 0)
                    p[idx].wt = 0;
                total_wt += p[idx].wt;
                total_tat += p[idx].tat;
            }
        }
        else
        {
            t++;
        }
    }
    printf("\nID\tAT\tBT\tPR\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i, p[i].at, p[i].bt, p[i].pr,
               p[i].ct, p[i].wt, p[i].tat);
    }
    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}
int main()
{
    int n;
    struct process p[max];
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d: ", i);
        scanf("%d", &p[i].at);
        printf("Enter burst time for process %d: ", i);
        scanf("%d", &p[i].bt);
        printf("Enter priority for process %d (lower number = higher priority): ", i);
        scanf("%d", &p[i].pr);
    }
    priorityScheduling(p, n);
    return 0;
}