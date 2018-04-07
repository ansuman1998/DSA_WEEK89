#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct edges
{
    int src;
    int dest;
    int weight;
};
int main()
{
    int n;
    scanf("%d", &n);
    int i,j;
    int **a=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
        a[i]=(int *)malloc(n*sizeof(int));
    int e=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
            if(a[i][j]==0)
                a[i][j]=10000;
            else
                e++;
        }
    struct edges edge[e];
    int k=0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        if(a[i][j]!=10000)
        {
            edge[k].src=i;
            edge[k].dest=j;
            edge[k].weight=a[i][j];
            k++;
        }
    }
    int *dist=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        dist[i]=INT_MAX;
    dist[0]=0;
    for(i=1;i<=n-1;i++)
    {
        for(j=0;j<k;j++)
        {
            if(dist[edge[j].dest]>dist[edge[j].src]+edge[j].weight)
                dist[edge[j].dest]=dist[edge[j].src]+edge[j].weight;
        }
    }

    for(j=0;j<k;j++)
        {
            if(dist[edge[j].dest]>dist[edge[j].src]+edge[j].weight)
               break;
        }
    if(j<k)
        printf("INFINITE LOOP OCCURS\n");
    else
        printf("DOESN'T OCCUR\n");



}
