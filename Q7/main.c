#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    int **a=(int **)malloc((n+1)*sizeof(int *));
    int i,j,k;
    for(i=0;i<=n;i++)
        a[i]=(int *)malloc((n+1)*sizeof(int));
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        a[i][j]=10000;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    for(i=1;i<=n;i++)
    {
        int x;
        char ch[10];
        printf("Iteration number %d\n", i);
        scanf(" %[^\n]s", ch);
        if(ch[2]=='t')
            a[i][ch[0]-48]=2;
        else
            a[i][ch[0]-48]=1;
    }
     for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(a[i][j]>a[i][k]+a[k][j])
        a[i][j]=a[i][k]+a[k][j];
    int temp=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    for(i=1;i<=n;i++)
    if(a[i][i]<100 && a[i][i]%2!=0)
    {
        temp=1;
        break;
    }
    if(temp==1)
        printf("PARA\n");
    else
        printf("NOT PARA\n");

}
