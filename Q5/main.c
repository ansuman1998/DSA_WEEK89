#include <stdio.h>
#include <stdlib.h>
/*
struct point
{
 int i;
 int j;
 int parenti;
 int parentj;
};
struct point queue[1000];
int front=-1,rear=-1;
void push(int i,int j, int parenti, int parentj)
{
    rear++;
    queue[rear].i=i;
    queue[rear].j=j;
    queue[rear].parenti=parenti;
    queue[rear].parentj=parentj;
    printf("(%d,%d) being pushed to queue\n",i,j);
    if(front==-1)
        front++;
}
void pop(int *i, int *j)
{
    *i=queue[front].i;
    *j=queue[front].j;
    printf("(%d,%d) being popped from queue\n",*i,*j);
    front++;
    if(front>rear)
    {
        front=-1;
        rear=-1;
    }
}
int m,n;
int isvalid(int i, int j)
{
    return (i>=0)&&(i<m)&&(j>=0)&&(j<m);
}
int main()
{
    m=5,n=8;
    //scanf("%d %d", &m, &n);
    char grid[][8]={{'W','W','W','W','W','W','W','E'},
                {'W','H','M','A','E','E','E','M'},
                {'W','E','W','W','E','W','A','W'},
                {'W','E','D','W','E','E','D','W'},
                {'E','W','W','W','W','W','W','W'}};

   int src_i=1, src_j=1,i,j, dest_i, dest_j;

   push(src_i, src_j, -1, -1);

   int **visited=(int **)malloc(m*sizeof(int *));
   for(i=0;i<m;i++)
        visited[i]=(int *)malloc(n*sizeof(int));
    /////////////////////////////////////////////////
    int **parenti=(int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++)
        parenti[i]=(int *)malloc(n*sizeof(int));
    int **parentj=(int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++)
        parentj[i]=(int *)malloc(n*sizeof(int));
    int **closed=(int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++)
        closed[i]=(int *)malloc(n*sizeof(int));
    int **opened=(int **)malloc(m*sizeof(int *));
    for(i=0;i<m;i++)
        opened[i]=(int *)malloc(n*sizeof(int));
    /////////////////////////////////////////////////
   for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    {
        visited[i][j]=0;
        closed[i][j]=0;
        opened[i][j]=0;
    }

   int success=0;
   while(!(front==-1 && rear==-1))
   {
       int a,b;
       pop(&a,&b);
       printf("%d %d\n", m,n);
       opened[a][b]=0;
       closed[a][b]=1;
       visited[a][b]=1;
       if(grid[a][b]=='E' &&((a==0)||(a==m-1)||(b==0)||(b==n-1)))
        {
            printf("FOund path\n");
            success=1;
            dest_i=a;
            dest_j=b;
            printf("%d %d %d %d\n",m,n,dest_i,dest_j);
            break;
        }
       if(grid[a][b]=='A')
       {
           for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            if(grid[i][j]=='N')
            grid[i][j]='M';
       }
       else if(grid[a][b]=='D')
       {
           for(i=0;i<m;i++)
            for(j=0;j<n;j++)
            if(grid[i][j]=='M')
            grid[i][j]='N';
       }
       //Here a is supposed to be the row value so, its y axis and b is supposed to be column value, so x axis

       if(isvalid(a,b-1)&&opened[a][b-1]==0&&(grid[a][b-1]=='E'||grid[a][b-1]=='H'||grid[a][b-1]=='N'||grid[a][b-1]=='A'||grid[a][b-1]=='D'))
        {
            //printf("%c\n",grid[a][b]);
            push(a,b-1,a,b);
            parenti[a][b-1]=a;
            parentj[a][b-1]=b;
            opened[a][b-1]=1;
        }
       if(isvalid(a+1,b)&&opened[a+1][b]==0&&(grid[a+1][b]=='E'||grid[a+1][b]=='H'||grid[a+1][b]=='N'||grid[a+1][b]=='A'||grid[a+1][b]=='D'))
           {
            push(a+1,b,a,b);
            parenti[a+1][b]=a;
            parentj[a+1][b]=b;
            opened[a+1][b]=1;
        }
       if(isvalid(a,b+1)&&opened[a][b+1]==0&&(grid[a][b+1]=='E'||grid[a][b+1]=='H'||grid[a][b+1]=='N'||grid[a][b+1]=='A'||grid[a][b+1]=='D'))
        {
            push(a,b+1,a,b);
            parenti[a][b+1]=a;
            parentj[a][b+1]=b;
            opened[a][b+1]=1;
        }
       if(isvalid(a-1,b)&&opened[a-1][b]==0&&(grid[a-1][b]=='E'||grid[a-1][b]=='H'||grid[a-1][b]=='N'||grid[a-1][b]=='A'||grid[a-1][b]=='D'))
        {
            push(a-1,b,a,b);
            parenti[a-1][b]=a;
            parentj[a-1][b]=b;
            opened[a-1][b]=1;
        }
   }

   if(success==0)
   {
       printf("Couldn't find path\n");
       return 0;
   }

   int pathlength=0;
   i=src_i;
   j=src_j;
   while(!(i==dest_i&&j==dest_j))
   {
       int a,b;
       a=parenti[i][j];
       b=parentj[i][j];
       i=a;
       j=b;
       pathlength++;
   }

   printf("%d\n", pathlength);

}
*/
 char grid[][8]={{'W','W','W','W','W','W','W','E'},
                {'W','H','M','A','E','E','E','M'},
                {'W','E','W','W','E','W','A','W'},
                {'W','E','D','W','E','E','D','W'},
                {'E','W','W','W','W','W','W','W'}};
int d[100][100][3];
int dr[]={0,0,-1,1};
int dc[]={-1,1,0,0};
int m=5,n=8;
void findstart(int *r, int *c)
{
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        if(grid[i][j]=='H')
    {
        *r=i;
        *c=j;
    }
}
int *queue;
int front=-1, rear=-1;
void push(int n)
{
    queue[++rear]=n;
    if(front==-1)
        front++;
}
int pop()
{
    int ret=queue[front++];
    if(front>rear)
    {
        front=-1;
        rear=-1;
    }
    return ret;
}
int bfs(int r, int c)
{
    if(r==m-1||r==0||c==n-1||c==0)
        return 0;
    int i,rr,cc,fl,now;
    queue=(int *)malloc(10000*sizeof(int));
    push(r);
    push(c);
    push(0);
    printf("%d %d %d pushed onto stack\n",r,c,0);
    d[r][c][0]=0;
    printf("Going to enter while loop when front is %d and rear is %d\n", front, rear);
    while(!(front==-1 && rear==-1))
    {
        r=pop();
        c=pop();
        fl=pop();
        printf("%d %d %d popped from queue\n",r,c,fl);
        int i;
        for(i=0;i<4;i++)
        {
            rr=r+dr[i];
            cc=c+dc[i];
            if(rr>=0 && rr<m && cc>=0 && cc<n && grid[rr][cc]!='W')
            {
                if(fl!=1 && grid[rr][cc]=='M')
                    continue;
                if(rr==0||rr==m-1||cc==0||cc==n-1)
                    return d[r][c][fl]+1;
                if(grid[rr][cc]=='D')
                    {
                        now=1;
                        printf("Disappear switch\n");
                    }
                else if(grid[rr][cc]=='A')
                    {
                        now=2;
                        printf("Appear switch\n");
                    }
                else
                    now=fl;
                if(d[rr][cc][now]>d[r][c][fl]+1)
                {
                    push(rr);
                    push(cc);
                    push(now);
                    printf("%d %d %d pushed onto stack\n",rr,cc,now);
                    d[rr][cc][now]=d[r][c][fl]+1;
                }

            }
        }
    }
   return -2;
}
int main()
{
    int r,c;
    findstart(&r, &c);
    int i,j,k;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
        for(k=0;k<3;k++)
        d[i][j][k]=10000;
    printf("%d %d\n", r,c);
    printf("%d\n", bfs(r,c)+1);
}
