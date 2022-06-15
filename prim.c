#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void prims(int** arr,int src,int n);
int mincost(int* cost,bool* setMST,int n);
int main()
{
    printf("Enter no of nodes\n");
    int n,i,j;
    scanf("%d",&n);

    int** arr=(int**)malloc(n*sizeof(int*));

    printf("Enter the adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        arr[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    prims(arr,0,n);
}

void prims(int** arr,int src,int n)
{
    int i,j;
    int* cost=(int*)malloc(n*sizeof(int));
    int* parent=(int*)malloc(n*sizeof(int));
    bool* setMST=(bool*)malloc(n*sizeof(bool));

    for(i=0;i<n;i++)
    {
        cost[i]=INT_MAX;
        setMST[i]=false;
    }
    parent[src]=-1;
    cost[src]=0;

    for(i=0;i<n-1;i++)
    {
        int u=mincost(cost,setMST,n);
        setMST[u]=true;
        for(j=0;j<n;j++)
        {
            if(arr[u][j]!=0 && setMST[j]==false && arr[u][j]<cost[j])
            {
                cost[j]=arr[u][j];
                parent[j]=u;
            }

        }
    }
    for(i=1;i<n;i++)
    {
        printf("%d to %d = %d\n",parent[i],i,cost[i]);
    }
    int sum=0;

    for(i=0;i<n;i++)
    {
        sum+=cost[i];
    }

    printf("Total cost of MST=%d",sum);
}

int mincost(int* cost,bool* setMST,int n)
{
    int min=INT_MAX;
    int min_index,i;

    for(i=0;i<n;i++)
    {
        if(cost[i]<min && setMST[i]==false)
        {
            min=cost[i];
            min_index=i;
        }
    }
    return min_index;
}
