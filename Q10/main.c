#include <stdio.h>
#include <stdlib.h>
int checkprime(int n)
{
    int i;
    if(n==1)
        return 0;
    for(i=2;i*i<=n;i++)
        if(n%i==0)
        return 0;
    return 1;
}
int onediffer(int a, int b)
{
    int count=0;
    while(a!=0)
    {
        if(a%10!=b%10)
            count++;
        a/=10;
        b/=10;
    }
    if(count==1)
        return 1;
    else
        return 0;
}
int *queue;
int front=-1,rear=-1;
void push(int n)
{
    if(front==-1 && rear==-1)
    {
        front++;
        rear++;
        queue[rear]=n;
    }
    else
        queue[++rear]=n;
    printf("%d is pushed onto queue\n", queue[rear]);
}
int pop()
{
    int ret= queue[front++];
    if(front>rear)
    {
        front=-1;
        rear=-1;
    }
    printf("%d being popped from queue\n", ret);
    return ret;
}
int main()
{
    int n=1000;
    int count=0;
    int **a=(int **)malloc(1061*sizeof(int *));
    int i,j;
    for(i=0;i<1061;i++)
        a[i]=(int *)malloc(1061*sizeof(int *));
    int *index=(int *)malloc(1061*sizeof(int));
    int *map=(int *)malloc(10000*sizeof(int));
    while(n<=9999)
    {
        if(checkprime(n))
            {
                index[count++]=n;
                map[n]=count-1;
            }
        n++;
    }
    for(i=0;i<1061;i++)
        for(j=0;j<1061;j++)
            {
                if(i==j)
                    a[i][j]=0;
                else
                    a[i][j]=10000;
            }

    for(i=0;i<1061;i++)
        for(j=i+1;j<1061;j++)
    {
        if(onediffer(index[i],index[j]))
            {
                a[i][j]=1;
                a[j][i]=1;
            }
    }

    int k;
    for(k=0;k<1061;k++)
        for(i=0;i<1061;i++)
        for(j=0;j<1061;j++)
            if(a[i][j]>a[i][k]+a[k][j])
            a[i][j]=a[i][k]+a[k][j];


    printf("%d\n",count);
    int t;
    scanf("%d", &t);
    while(t!=0)
    {

        int src, dest;
        scanf("%d %d", &src, &dest);
        printf("%d\n",a[map[src]][map[dest]]);
    }


    //Inserting source into queue/////

}
