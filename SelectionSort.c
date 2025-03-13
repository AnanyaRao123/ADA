
#include<stdio.h>
#include<time.h>
void main()
{
	int i,n,j,k,t;
	printf("Enter the array size: ");
	scanf("%d",&n);
	int a[n];
	srand(time(NULL));
	for(i=1;i<=n;i++){
		a[i]=rand()%1000;
	}
	clock_t start=clock();
	for(i=1;i<=n;i++){
		j=i;
		for(k=i+1;k<=n;k++){
			if(a[k]<a[j]){
				j=k;
			}
		}
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	}
	clock_t end=clock();
	double time_taken=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time taken to sort %d elements %lf seconds\n",n,time_taken);
	//printf("The sorted array is\n");
	//for(i=1;i<=n;i++){
	//	printf("%d ",a[i]);
	//}
	//printf("\n");
}
