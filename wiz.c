#include<stdio.h>
#include<omp.h>
#define INFINITY 9999
#define MAX 10
 
void dijkstra(int G[MAX][MAX],int n,int startnode);
 
int main()
{
	int G[MAX][MAX],i,j,n,u;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	/*printf("\nEnter the adjacency matrix:\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&G[i][j]);*/
	if(n==6){
	G[0][1] = G[1][0] = 40;
   	G[0][2] = G[2][0] = 15;
   	G[1][2] = G[2][1] = 20;
   	G[1][3] = G[3][1] = 10;
   	G[1][4] = G[4][1] = 25;
   	G[2][3] = G[3][2] = 100;
   	G[1][5] = G[5][1] = 6;
   	G[4][5] = G[5][4] = 8;
	}
	else if (n==4){
	G[0][1] = G[1][0] = 40;
   	G[0][2] = G[2][0] = 15;
   	G[1][2] = G[2][1] = 20;
   	G[1][3] = G[3][1] = 10;
	}
	else
		printf("Choose 6 or 4");
		
	/*for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d  ",G[i][j]);
		}
		printf("\n");
	}*/	
	printf("\nEnter the starting node:");
	scanf("%d",&u);
	dijkstra(G,n,u);
	
	return 0;
}



void dijkstra(int G[MAX][MAX],int n,int startnode)
{
 
	int cost[MAX][MAX],distance[MAX],pred[MAX];
	int visited[MAX],count,mindistance,nextnode,i,j,id;
	
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

//initialize pred[],distance[] and visited[]
#pragma omp parallel private(id) num_threads (4)
	#pragma omp for
	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	#pragma omp single
	    distance[startnode]=0;
		visited[startnode]=1;
		count=1;

	while(count<n-1)
	{
	#pragma omp parallel private(id) num_threads (4)
		{
		mindistance=INFINITY;
		
		#pragma omp for
		//nextnode gives the node at minimum distance
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
			
//check if a better path exists through nextnode
		#pragma omp single		
	visited[nextnode]=1;
		for(i=0;i<n;i++)
			if(!visited[i])
				if(mindistance+cost[nextnode][i]<distance[i])
				 {
					distance[i]=mindistance+cost[nextnode][i];
					 pred[i]=nextnode;
				 }
			count++; 	
	 	}
	 }
//print the path and distance of each node

	for(i=0;i<n;i++)
		if(i!=startnode)
		{
			printf("\nDistance of node %d = %d",i,distance[i]);
			printf("\nPath = %d",i);
			
			j=i;
			do
			{
				j=pred[j];
				printf(" <- %d \n",j);
			}while(j!=startnode);
	}
}



//	The "critical" clause sets up a critical section, with invisible
//      lock/unlock operations.  Note carefully that the clause may be
//      followed by an optional name, which is crucial in some
//      applications.  All critical sections with the same name 
//      are guarded by the same (invisible) locks.  Those with 
//      no name are also guarded by the same locks, so the programmer
//      could really lose parallelism if he/she were not aware of this.

//      Certain very specialized one-statement critical sections can be
//      handled more simply and efficiently using the "atomic"
//      directive, e.g.

//         #pragma omp atomic
//         y += x;

//      Note that that statment can NOT be a block.
