#include <stdio.h>
#include <stdlib.h>

struct node
{
    int col;
    int data;
    struct node* next;
};

void enter(struct node **s,int data,int col)
{
    struct node *p;
    p=*s;
  if(*s==NULL)
  {
    p=malloc(sizeof(struct node ));
    p->data=data;
    p->next=NULL;
    p->col=col;
    *s=p;
  }
  else
  {
    while(p->next)
    {
        p=p->next;
    }
    p->next=malloc(sizeof(struct node ));
    p->next->data=data;
    p->next->next=NULL;
    p->next->col=col;
  }
}
void reverse(struct node **s)
{
    struct node *p,*q,*r;
    p=*s;
    q=NULL;
    r=NULL;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    *s=q;
}
void display(struct node *p)
{
    struct node *t=p;
    while(t)
    {
        printf("%d",t->data);
        t=t->next;
    }
}
int main()
{

    struct node *head=NULL;
    enter(&head,4,3);
    enter(&head,2,3);
    enter(&head,1,3);
    enter(&head,3,3);
    enter(&head,9,3);
    reverse(&head);
    display(head);
    struct node *head2=NULL;
        enter(&head,4,3);
    enter(&head2,2,3);
    enter(&head2,1,3);
    enter(&head2,3,3);
    enter(&head2,9,3);
    display(head2);

}