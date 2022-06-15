#include <stdio.h>
#include <stdlib.h>


void printparen(int** s,int i,int j);
void print(int** m,int** s,int n);
int main()
{
    int n;
    scanf("%d",&n);

    int* D=(int*)malloc((n+1)*sizeof(int));

    for(int i=0;i<=n;i++)
    {
        scanf("%d",&D[i]);
    }

    int** m=(int**)malloc((n+1)*sizeof(int*));
    int** s=(int**)malloc((n+1)*sizeof(int*));

    for(int i=0;i<=n;i++)
    {
        m[i]=(int*)malloc((n+1)*sizeof(int));
        s[i]=(int*)malloc((n+1)*sizeof(int));
        for(int j=0;j<=n;j++)
        {
            m[i][j]=0;
            s[i][j]=0;
        }
    }


    int min,d,j,k,i;
    n=n+1;

    for(d=1;d<n-1;d++)
    {
        for(i=1;i<n-d;i++)
        {
            j=i+d;
            min=INT_MAX;
            for(k=i;k<j;k++)
            {
                int q=m[i][k]+m[k+1][j]+(D[i-1]*D[k]*D[j]);
                if(q<min)
                {
                    min=q;
                    s[i][j]=k;
                }
            }
            m[i][j]=min;
        }
    }

    print(m,s,n);
    printparen(s,1,n-1);
    return 0;
}

void print(int** m,int** s,int n)
{
    for(int i=1;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for(int i=1;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            printf("%d\t",s[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

void printparen(int** s,int i,int j)
{
    if(i==j)
        printf("A%d",i);
    else
    {
        printf("(");
        printparen(s,i,s[i][j]);
        printparen(s,s[i][j]+1,j);
        printf(")");
    }
}
