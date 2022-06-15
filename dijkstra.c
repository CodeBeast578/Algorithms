#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int n;

int dijkstra(int** g,int src);
int minvertex(bool p[n],int d[n]);
int main()
{
    int i,j;
    printf("Enter the no of nodes\n");
    scanf("%d",&n);
    int** graph=(int **)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
        graph[i]=(int*)malloc(n*sizeof(int));

    printf("Enter the cost matrix\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
	dijkstra(graph,0);
    return 0;
}

int dijkstra(int** g,int src)
{
    bool processed[n];
    int dist[n],i,v,u;

    for(i=0;i<n;i++)
    {
        processed[i]=false;
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    for(i=0;i<n-1;i++)
    {
        u=minvertex(processed,dist);
        processed[u]=true;

        for(v=0;v<n;v++)
        {
            if(g[u][v]!=0 && processed[v]==false && dist[src]!=INT_MAX && dist[u]+ g[u][v]<dist[v])
                dist[v]=dist[u]+ g[u][v];
        }
    }

    for(i=0;i<n;i++)
    {
        printf("Min Cost From vertex %d --> %d = %d\n",src,i,dist[i]);
    }
    return 0;
}

int minvertex(bool p[n],int d[n])
{
    int min=INT_MAX,index,i;
    for(i=0;i<n;i++)
    {
        if(p[i]==false && d[i]<min)
        {
            min=d[i];
            index=i;
        }
    }
    return index;
}
