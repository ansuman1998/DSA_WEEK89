#include <stdio.h>
#include <stdlib.h>
void multiply(int **a, int **b, int n)
{
    int **c=(int **)malloc(n*sizeof(int *));
    int i,j,k;
    for(i=0;i<n;i++)
            c[i]=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
    {
        int sum=0;
        for(k=0;k<n;k++)
            sum+=(a[i][k]*a[k][j]);
        c[i][j]=sum;
    }

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        a[i][j]=c[i][j];
}
int main()
{
    int n,z,i,j;
    scanf("%d %d", &n, &z);
    int **a=(int **)malloc(n*sizeof(int *));
    int **c=(int **)malloc(n*sizeof(int *));

    for(i=0;i<n;i++)
        {
            a[i]=(int *)malloc(n*sizeof(int));
            c[i]=(int *)malloc(n*sizeof(int));
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d", &a[i][j]);
            c[i][j]=a[i][j];
        }
    int src, dest;
    scanf("%d %d", &src, &dest);
    int count=c[src][dest];
    printf("count %d\n",count);
    while(z!=1)
    {
        multiply(c,a,n);
        count+=c[src][dest];
        printf("count %d\n",count);
        z--;
    }
    printf("%d\n", count);


}
