#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head[10];
struct node* newnode(int data)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=data;
    temp->next=NULL;
    return temp;
};
int main()
{
   int i,n,data;
   for(i=0;i<10;i++)
    head[i]=NULL;

   while(1)
   {
       printf("1. For entering, 2. For Printing table, 3. Search for element, 4. Delete element, 5. Exit\n");
       scanf("%d", &n);
       if(n==1)
       {
          printf("Enter your value\n");
          scanf("%d", &data);
          if(head[data%10]==NULL)
                head[data%10]=newnode(data);
          else if(head[7-data%7]==NULL)
                head[7-data%7]=newnode(data);
          else
                {
                    struct node *temp=head[data%10];
                    while(temp->next!=NULL)
                        temp=temp->next;
                    temp->next=newnode(data);
                }
       }
       else if(n==2)
       {
            for(i=0;i<10;i++)
            {
                struct node* temp=head[i];
                while(temp!=NULL)
                {
                    printf("%d ",temp->data);
                    temp=temp->next;
                }
                printf("\n");
            }
       }
       else if(n==3)
       {
            printf("Enter data to be searched\n");
            scanf("%d", &data);
            if(head[data%10]->data==data)
                printf("Found\n");
            else if(head[7-data%7]->data==data)
                printf("Found\n");
            else
            {
                struct node *temp=head[data%10];
                while(temp!=NULL && temp->data!=data)
                    temp=temp->next;
                if(temp!=NULL)
                    printf("Found\n");
                else
                    printf("Not Found\n");
            }
       }
       else if(n==4)
       {
            printf("Enter element to be deleted\n");
            scanf("%d", &data);
            int found=0;
            if(head[data%10]->data==data)
                {
                    found=1;
                    head[data%10]=head[data%10]->next;
                }
            else if(head[7-data%7]->data==data)
                {
                    found=1;
                    head[7-data%7]=head[7-data%7]->next;
                }
            else
            {
                struct node *temp=head[data%10];
                while(temp!=NULL && temp->data!=data)
                    temp=temp->next;
                if(temp!=NULL)
                    {
                        found=1;
                        struct node* prev=head[data%10];
                        while(prev->next!=temp)
                            prev=prev->next;
                        prev->next=temp->next;
                    }
                else
                    found=0;
            }

            if(found==0)
                printf("Couldn't find element\n");
            else
                printf("Found and deleted\n");
       }
       else
       {
           break;
       }
   }
}
