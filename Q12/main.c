#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int shouldswap(char *ch, int index, int curr, int n)
{
    int i;
    for (i = index; i < curr; i++)
        if (ch[i] == ch[curr])
            return 0;
    return 1;

}
void swap(char *a, char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
void permute(char *ch, int index, int n)
{
    if(index>=n)
        {
            printf("%s\n", ch);
            return;
        }
    int i;
    for(i=index;i<n;i++)
    {
        int check=shouldswap(ch,index,i,n);
        if(check)
        {
            swap(&ch[index],&ch[i]);
            permute(ch,index+1,n);
            swap(&ch[index],&ch[i]);
        }
    }

}

int main()
{
    char ch[100];
    scanf("%s", ch);
    permute(ch,0,strlen(ch));
}
