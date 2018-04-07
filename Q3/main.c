#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>

print(int **a, int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
int main()
{
    int n,i,j,k;
    char ch;
    scanf("%d", &n);
    int **a=(int **)malloc(n*sizeof(int *));
    int **d=(int **)malloc(n*sizeof(int *));

    for(i=0;i<n;i++)
        {
            a[i]=(int *)malloc(n*sizeof(int));
            d[i]=(int *)malloc(n*sizeof(int));
        }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        scanf("%d", &a[i][j]);
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(a[i][j]==-1)
            {
                a[i][j]=10000;
                d[i][j]=a[i][j];
            }
        else
            d[i][j]=-1*a[i][j];
    }
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(d[i][j]>d[i][k]+d[k][j])
            d[i][j]=d[i][k]+d[k][j];
    }
    //int min=
    for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            printf("%d ",d[i][j]);
            printf("\n");
        }


    print(a,n);
}
