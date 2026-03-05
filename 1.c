#include<stdio.h>

#define m 10
struct process{
    int at;
    int bt;
    int tat;
    int ct;
    int wt;
};

void sort(struct process f[],int n){
    for(int i=0;i<n-1;i++){

        for(int j=0;j<n-1-i;j++){
            if(f[j].at>f[j+1].at){
                struct process temp=f[j];
                f[j]=f[j+1];
                f[j+1]=temp;
            }
        }
    }
}

void fcfs(struct process f[],int n){
    int t=0;
    for(int i=0;i<n;i++){
        if(t<f[i].at){
            t=f[i].at;
        }
        f[i].wt=t-f[i].at;
        f[i].tat=f[i].wt+f[i].bt;
        f[i].ct=t+f[i].bt;
        t=t+f[i].bt;
    }

printf("%-5s%-5s%-5s%-5s%-5s%-5s\n","Process id","Burst time","Arrival time","Completion time","Waiting time","Turn around time");
for(int i=0;i<n;i++){
    printf("%-5d%-5d%-5d%-5d%-5d%-5d\n",i,f[i].bt,f[i].at,f[i].ct,f[i].wt,f[i].tat);
}
float awt=0;
float atat=0;
for(int i=0;i>n;i++){
    awt+=f[i].wt;
    atat+=f[i].tat;
}
awt=awt/n;
atat=atat/n;
printf("awt is %-5f atat is %-5f\n",awt,atat);
}

int main(){
    int n;
    struct process f[m];
    printf("enter number of process\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the burst time\n");
        scanf("%d",&f[i].bt);
        printf("enter the arrival time\n");
        scanf("%d",&f[i].at);
    }
    sort(f,n);
    fcfs(f,n);
}