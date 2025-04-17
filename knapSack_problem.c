#include<stdio.h>
#define MAX_ITEMS 10
int knapSack(int W,int wt[],int val[],int n){
	int i,j;
	int v[MAX_ITEMS+1][W+1];
	for(i=0;i<=n;i++){
		for(j=0;i<=W;j++){
			if(i==0||j==0){
				v[i][j]=0;
			}
			else if(j-wt[i]<0){
				v[i][j]=v[i-1][j];
			}else{
				v[i][j]=max(v[i-1][j],val[i]+v[i-1][j-wt[i]]);
			}
		}
	}
	return v[n][W];
}
int max(int a,int b){
	return (a>b)?a:b;
}
int main(){
	int i,n,w,wt[MAX_ITEMS],val[MAX_ITEMS],maxcap;
	printf("Enter the number of items:");
	scanf("%d",&n);
	printf("Enter the maximum capacity:");
	scanf("%d",&maxcap);
	printf("Enter the weights:");
	for(i=1;i<=n;i++){
		scanf("%d",&wt[i]);
	}
	printf("Enter the values:");
	for(i=1;i<=n;i++){
		scanf("%d",&val[i]);
	}
	printf("The maximum value is %d\n",knapSack(maxcap,wt,val,n));
	return 0;
}