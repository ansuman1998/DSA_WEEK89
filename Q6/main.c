#include <stdio.h>
#include <stdlib.h>

/*void recruse(int **a, int index, int n)
{
    int i=0,c=0;
    for(i=0;i<n;i++)
        if(a[index][i]==1)
        c++;
    if(c==0)
    {
        printf("%d",index);
        return;
    }

    c=0;
    for(i=0;i<n;i++)
        if(in)
}*/
int main()
{
  int n;
  scanf("%d", &n);
  int **a=(int **)malloc(n*sizeof(int *));
  int **b=(int **)malloc(n*sizeof(int *));
  int i;
  for(i=0;i<n;i++)
    {
        a[i]=(int *)malloc(n*sizeof(int));
        b[i]=(int *)malloc(n*sizeof(int));
    }
  int j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    {
        a[i][j]=10000;
        b[i][j]=10000;
    }

  printf("Enter the number of edges\n");
  int e;
  scanf("%d", &e);
  while(e!=0)
  {
      int c,d;
      scanf("%d %d", &c, &d);
      a[c][d]=1;
      b[c][d]=1;
      b[d][c]=1;
      e--;
  }
     for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
  int k;
  for(k=0;k<n;k++)
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    if(b[i][j]>b[i][k]+b[k][j])
        b[i][j]=b[i][k]+b[k][j];

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        if(b[i][j]==10000)
    {
        printf("Graph not connected\n");
        return 0;
    }

    /////DFS///////
    //Reclaim the undirected graph/////
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(a[i][j]==1)
    {
        b[i][j]=1;
        b[j][i]=1;
    }
    int *stack=(int *)malloc(n*sizeof(int));
    int *visited=(int *)malloc(n*sizeof(int));
    int *parent=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        {
            visited[i]=0;
            parent[i]=-1;
        }

    int top=-1;
    stack[++top]=0;
    int curr;
    while(top!=-1)
    {

        curr=stack[top--];
        printf("Current item just popped from stack is %d and top is %d\n", curr, top);
        visited[curr]=1;
        for(i=0;i<n;i++)
        {
            if(i!=curr && visited[i]==0&&b[curr][i]==1)
            {
                parent[i]=curr;
                stack[++top]=i;
                printf("%d pushed onto stack\n", i);
            }
            else if(i!=curr && b[curr][i]==1 && visited[i]==1&&parent[curr]!=i)
            {
                printf("Graph has cycles and i value is %d\n",i);
                return 0;
            }
        }
    }

    printf("Graph is a tree\n");

    for(i=0;i<n;i++)
    {
        int c=0;
        for(j=0;j<n;j++)
            if(a[i][j]==1)
            c++;
        if(c>2)
        {
            printf("Not a binary tree\n");
            return 0;
        }

    }

    int roots=0, rootindex=-1;
    for(j=0;j<n;j++)
    {
        int c=0;
        for(i=0;i<n;i++)
            if(a[i][j]==1)
            c++;
        if(c==0)
        {
            roots++;
            rootindex=j;
        }
    }
    if(roots==0 || roots>=2)
       {
            printf("Not a binary tree\n");
            return 0;
       }


    printf("Binary tree rooted at %d\n", rootindex);



}
