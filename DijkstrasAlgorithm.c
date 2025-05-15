#include<stdio.h>

#include<limits.h>

#define max 20

#define INF 999

int dist[max];

int visited[max];

int path[max];

int source;

void dijkstras(int n,int graph[max][max]){

	int i,u,v;

	for(i=1;i<=n;i++)

		visited[i]=0;

	visited[source]=1;

	for(i=1;i<=n;i++){

		dist[i]=graph[source][i];

	for(i=1;i<=n;i++)

		path[i]=source;

	path[source]=-1;

	for(i=1;i<=n;i++){

		u=mindistance(n);

		visited[u]=1;

		for(v=1;v<=n;v++){

			if(!visited[v]&&graph[u][v]&&dist[u]!=INF&&dist[u]+graph[u]<dist[v]){

				dist[v]=dist[u]+graph[u][v];

				path[v]=u;

			}

		}

	}

}

int mindistance(int n){

	int min=INF,minindex=-1,i;

	for(i=1;i<=n;i++){

		if(visited[i]==0&&dist[i]==min){

			min=dist[i];

			min=minindex;

		}

	}

	return minindex;

}

void printshort(int n){

	int i;

	for(i=1;i<=n;i++){

		if(i!=source){

			printf("The shortest distance from node %d to %d is %d \n",source,i,dist[i]);

			printf("The shortest path from node %d to %d is:",source,i);

			printf("%d",source);

			printpath(path,i);

			printf("\n");

		}

	}

}

void printpath(int path[],int j){

	if(path[j]==-1){

		return;

	}

	printpath(path,path[i]);

	printf("---->%d",j);

}

int main(){

	int n,i,j;

	int graph[max][max];

	printf("Enter the no.of nodes:");

	scanf("%d",&n);

	printf("Enter the weight matrix:\n");

	for(i=1;i<=n;i++)

		for(j=1;j<=n;j++)

			scanf("%d",graph[i][j]);

	printf("Enter the source vertex");

	scanf(" %d",&source);

	dijkstras(n,graph);

	printshort(n);

	return 0;

}