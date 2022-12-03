#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node* next; 
};
struct node* first=NULL;

void enter(struct node *p,int x)
{
    struct node* t=malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(p==NULL)
    {
        first=t;
    }
    else
    {
        while(p->next)
        {
            p=p->next;
        }
        p->next=t;
    }
}
void count(struct node* p)
{
    int count=0;
    while(p)
    {
        count++;
        p=p->next;
    }
    printf("\n%d",count);
}
void delete(struct node *p,int index)
{
    struct node *q=NULL;
    if(index==1)
    {
        q=first;
        first=first->next;
        free(q);
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        
    }
    q->next=p->next;
    q=p;
    p=p->next;
    free(q);
}
void reverse(struct node*p)
{
    struct node *r,*q;
    r=NULL;q=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}
void display(struct node* p)
{
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}

int main()
{
    enter(first,2);
    enter(first,6);
    enter(first,5);
    reverse(first);
    display(first);   
    count(first);
    delete(first,2);
    display(first);
}