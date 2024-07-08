#include<iostream>
using namespace std;
int At[20],Bt[20],Tat[20],Wt[20],order[20],P[20],id,Ct[20];
int main(){
	int i,n,j;
	float avg_wt=0,avg_tat=0;
	cout<<"enter the number of process"<<endl;
	cin>>n;
	for(i=1;i<=n;i++){
		printf("Enter p%d burst time and priority\n",i);
		cin>>Bt[i]>>P[i];
		order[i]=i;
	}
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){  
			if(P[order[i]]>P[order[j]]){
				swap(order[i],order[j]);
			}
		}
	}
	for(i=1;i<=n;i++){
	Ct[order[i]]=Ct[order[i-1]]+Bt[order[i]];
	}
	for(i=1;i<=n;i++){
		 id=order[i];
		Tat[id]=Ct[id];
		Wt[id]=Tat[id]-Bt[id];
		avg_wt=avg_wt+Wt[id];
		avg_tat=avg_tat+Tat[id];
	}
	printf("\n P_id...Burst...TAT...Wt\n");
	for(i=1;i<=n;i++){
		id=order[i];
		printf("P%d\t%d\t%d\t%d\t\n",id,Bt[id],Tat[id],Wt[id]);
	}
	cout<<"average waiting time:  "<<avg_wt/n<<endl;
	cout<<"Average Turnaround time: "<<avg_tat/n;
}