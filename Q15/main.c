#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
/*
int isprime(long long int n )
{
    long long int i;
    if(n==1)
        return 0;

    for(i=2;i<n;i++)
        if(n%i==0)
        return 0;
    return 1;
}
long long int *recur;
long long int recurse(long long int n)
{

    long long int sum=0,i;
    for(i=1;i<n;i++)
        if(n%i==0)
        sum++;
    //printf("Proper factors of %lld are %lld\n",n,sum);
    long long int max=INT_MIN;
    for(i=1;i<n;i++)
        if(n%i==0 && recur[i]>max)
        max=recur[i];
    sum+=(max+1);
    //printf("Value needed for %lld is %lld\n",n,sum);
    return sum;

}
int main()
{
    printf("Hello world!\n");
    long long int sum=0,i,j;
    recur=(long long int *)malloc(1000001*sizeof(long long int));
    for(i=1;i<=1000000;i++)
        recur[i]=1;
    recur[1]=0;
    i=2;
    while(i<=1000000)
    {
        if(recur[i]==1)
            for(j=2;i*j<=1000000;j++)
                recur[i*j]=0;
        i++;
    }
    for(i=1;i<=1000000;i++)
    if(recur[i]==1)
        recur[i]=2;
     for(i=2;i<=1000000;i++)
        if(recur[i]==0)
        {

            recur[i]=recurse(i);
            //printf("%lld %lld\n",i, recur[i]);
        }

    for(i=932451;i<=935212;i++)
        printf("%lld\n", recurse(i));
    printf("%lld\n", sum);
    return 0;
}*/
long long int factors(long long int n, long long int *maxi)
{
    long long int count=1,c,i,target;
    long long int N=n;
    long long int maxexp=INT_MIN;
    for(i=2;i<=n;i++)
    {
        c=0;
        while(n%i==0)
        {
            n/=i;
            c++;
            if(c>maxexp)
            {
                maxexp=c;
                target=i;
            }
        }
        count*=(c+1);
    }
    *maxi=N/target;
    //printf("Next greedy node is %lld, target is %lld and number of factors is %lld\n", *maxi, target, count);
    return count;
}
long long int litelevel(long long int n)
{
    long long int i,max,maxi;
    long long int sum=0;
    //sum+=factors(n);

    while(n!=1)
    {
        sum+=factors(n,&maxi);
        n=maxi;
        //printf("Factor with max degree is %lld with degrees %lld\n", maxi, max);
    }
    //printf("Lite level for %lld is %lld\n",n, sum);
    return sum;
}
int main()
{
    long long int a, b,i,n,sum=0;
    scanf("%lld %lld", &a, &b);
    for(i=a;i<=b;i++)
        sum+=litelevel(i);
    printf("Answer is %lld\n", sum);
    /*
    scanf("%lld %lld", &a, &b);
    for(i=a;i<=b;i++)
    {
        sum+=litelevel(i);
    }
    printf("%lld\n", sum);*/
}
