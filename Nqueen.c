#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool nQueen(int **arr,int x,int n);
bool isSafe(int **arr,int x,int y,int n);
int main()
{
    int n,i,j;
    printf("Enter no. of queens");
    scanf("%d",&n);

    int** board= (int **)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        board[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
            board[i][j]=0;
    }

    if(nQueen(board,0,n))
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%d\t",board[i][j]);

            printf("\n");
        }
    }
    return 0;
}

bool nQueen(int **arr,int x,int n)
{
    int col;
    if(x>=n)
        return true;

    for(col=0;col<n;col++)
    {
        if(isSafe(arr,x,col,n))
        {
            arr[x][col]=1;

            if(nQueen(arr,x+1,n))
                return true;

            arr[x][col]=0;
        }
    }
    return false;
}

bool isSafe(int **arr,int x,int y,int n)
{
    int i;
    for(i=0;i<x;i++)
    {
        if(arr[i][y]==1)
            return false;
    }

    int row=x;
    int col=y;
    while(row>=0 && col>=0)
    {
        if(arr[row][col]==1)
            return false;

        row--;
        col--;
    }

    row=x;
    col=y;
    while(row>=0 && col>=0)
    {
        if(arr[row][col]==1)
            return false;

        row--;
        col++;
    }

    return true;
}
