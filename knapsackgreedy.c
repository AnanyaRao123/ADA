#include<stdio.h>

#define MAX_ITEMS 100

double ComputeMaxValue(double w,double weight[],double value[],double ratio[],int nitems){

	double cw=0;

	double cv=0;

	printf("\nItems considered are:");

	while(cw<w){

		int item=getNextItem(weight,value,ratio,nitems);

		if(item==-1){

			break;

		}

		printf("%d",item+1);

		if(cw+weight[item]<=w){

			cw+=weight[item];

			cv+=value[item];

			ratio[item]=0;

		}

		else{

			cv+=(ratio[item]*(w-cw));

			cw+=(w-cw);

			break;

		}

	}

	return cv;

}

int getNextItem(double weight[],double value[],double ratio[],int nItems){

	double highest=0;

	int index=-1,i;

	for(i=0;i<nItems;i++){

		if(ratio[i]>highest){

			highest=ratio[i];

			index=i;

		}

	}

	return index;

}

int main(){

	int nItems,i;

	double w,weight[MAX_ITEMS],value[MAX_ITEMS],ratio[MAX_ITEMS];

	printf("Enter the no.of items:\n");

	scanf("%d",&nItems);

	printf("Enter the weight of items:");

	for(i=0;i<nItems;i++)

		scanf("%lf",&weight[i]);

	printf("Enter the values/profit of items:");

	for(i=0;i<nItems;i++)

		scanf("%lf",&value[i]);

	for(i=0;i<nItems;i++)

		ratio[i]=value[i]/weight[i];

	printf("Enter the capacity if the knapsack:");

	scanf("%lf",&w);

	printf("\nThe max value in a knapsack of capacity %2f is %2f\n",w,ComputeMaxValue(w,weight,value,ratio,nItems));

	return 0;

}