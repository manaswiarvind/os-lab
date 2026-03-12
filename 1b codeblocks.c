#include<stdio.h>
#define max 10
struct process{
    int at;
    int bt;
    int tat;
    int wt;
    int ct;
    int done;
};

void sjf(struct process p[],int n){
    int completed=0;
    int t=0;
    float atat=0;
    float awt=0;
    while(completed<n){
        int idx=-1;
        int min_bt=9999;
        for(int i=0;i<n;i++){
            if(p[i].at<=t && p[i].done==0){
                if(p[i].bt<min_bt){
                    min_bt=p[i].bt;
                    idx=i;
                }
                else if(p[i].bt==min_bt){
                    if(p[i].at<p[idx].at){
                        idx=i;
                    }
                }
            }
        }
        if(idx!=-1){
            p[idx].wt=t-p[idx].at;
            p[idx].ct=t+p[idx].bt;
            p[idx].tat=p[idx].ct-p[idx].at;

            awt+=p[idx].wt;
            atat+=p[idx].tat;
            p[idx].done=1;
            completed++;
            t=p[idx].ct;
        }
        else{
            t++;
        }
    }
    printf("\nID\tAT\tBT\tct\twt\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",i,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tat);
    }
    printf("\nAverage waiting time:%.2f\n",awt/n);
    printf("Average turnaround time:%.2f\n",atat/n);
}

int main(){
    int n;
    struct process p[max];
    printf("enter number of processes:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter arrival time for process %d:",i);
        scanf("%d",&p[i].at);
        printf("enter burst time for process %d:",i);
        scanf("%d",&p[i].bt);
        p[i].done=0;
    }
    sjf(p,n);
    return 0;
}
