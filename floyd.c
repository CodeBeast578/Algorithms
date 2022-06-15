#include <stdio.h>
#include <stdlib.h>
#define INF 99999


void floydWarshall(int** arr,int n);
int min(int a,int b);
int main()
{
    int n;
    scanf("%d",&n);

    int** arr=(int **)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
    {
        arr[i]=(int*)malloc(n*sizeof(int));

        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==-1)
                arr[i][j]=INF;
        }
    }
    floydWarshall(arr,n);


}

void floydWarshall(int** arr,int n)
{

    int** dist=arr;

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dist[i][j]==INF)
                printf("INF\t");
            else
                printf("%d \t",dist[i][j]);
        }
        printf("\n");
    }
}

int min(int a,int b)
{
    if(a>b)
        return b;
    else
        return a;
}
