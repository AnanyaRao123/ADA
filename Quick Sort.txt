#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[],int low,int high)
{
	int pivot = arr[low];
	int i = low+1;
	int j = high;
	while(i<=j)
	{
		while(i<=high&&arr[i]<=pivot)
			i++;
		while(arr[j]>pivot)
			j--;
		if(i<j)
			swap(&arr[i],&arr[j]);
	}
	swap(&arr[low],&arr[j]);
	return j;
}
void quickSort(int arr[],int low,int high)
{
	if(low<high)	
	{
		int pivotIndex = partition(arr,low,high);
		quickSort(arr,low,pivotIndex-1);
		quickSort(arr,pivotIndex+1,high);
	}
}
int main()
{
	int n,i;
	printf("Enter the array size: ");
	scanf("%d",&n);
	int arr[n];
	srand(time(NULL));
	for(i=0;i<n;i++){
		arr[i]=rand()%1000000;
	}
	clock_t start=clock();
	quickSort(arr,0,n-1);
	clock_t end=clock();
	double time_taken=(double)(end-start)/CLOCKS_PER_SEC;
	printf("Time taken to sort %d elements %lf seconds\n",n,time_taken);
	/*printf("The sorted array is\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}*/
	return 0;
}