#include<stdio.h>
#include <stdlib.h>
int graph[10][10];
int visited[10];
int total;
int arr[30];
static int k=0;
int count=0;
void DFS(int);
int main(){

	int i,j;
	printf("\n enter the total number of vertices in a graph");
	scanf("%d",&total);
	printf("Enter the adjancency matrix\n");
	for(i=0;i<total;i++)
	for(j=0;j<total;j++)
	{
		scanf("%d",&graph[i][j]);
	}
	for(i=0;i<total;i++)
	{
		visited[i]=0;
	}
	DFS(0);
}
void DFS(int vertex)
{
	int j,c=0;
	count++;
	printf("%d",vertex);
	visited[vertex]=1;
	for(j=0;j<=total;j++)
	{
		if(!visited[j]&&graph[vertex][j]==1)
		{
			arr[++k]=j;
			c=1;
		}
		if(count==total)
		{
			exit(0);
		}
	}

if(c==1)
{
	DFS(arr[k]);
}
else
{
	k--;
	DFS(arr[k]);
}
}
