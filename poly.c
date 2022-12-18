#include<stdio.h>
#include<stdlib.h>

struct node
{
    int coeff;
    int pow;
    struct node* next;
};

void create(struct node **p)
{
    struct node* t, *last=NULL;
    int n,sum;
    printf("ENTER THE NUMBER OF TERMS\n");
    scanf("%d",&sum);
    printf("ENTER THE COEFF AND POWER\n");
    for(n=0;n<sum;n++)
    {
        struct node *t=malloc(sizeof(struct node ));
        scanf("%d %d",&t->coeff,&t->pow);
        t->next=NULL;
        if(*p==NULL)
        {
       
            *p=t;
            last=t;
        }
        else
        {
            last->next=t;
            last=t;
        }
    }
}
void display(struct node* p)
{
    while(p->next)
    {
        printf("%dx^%d +",p->coeff,p->pow);
        p=p->next;
    }
    printf("%dx^%d",p->coeff,p->pow);

}
void enter(struct node **s,int data,int col)
{
    struct node *p;
    p=*s;
  if(*s==NULL)
  {
    p=malloc(sizeof(struct node ));
    p->coeff=data;
    p->next=NULL;
    p->pow=col;
    *s=p;
  }
  else
  {
    while(p->next)
    {
        p=p->next;
    }
    p->next=malloc(sizeof(struct node ));
    p->next->coeff=data;
    p->next->next=NULL;
    p->next->pow=col;
  }
}
struct node* polyadd(struct node *p,struct node *s)
{
    struct node *t=NULL;
    while(p&&s)
    {
        if(p->coeff==s->coeff)
        {
            enter(&t,p->coeff+s->coeff,p->pow);
            p=p->next;
            s=s->next;
        }
        else if(p->coeff>s->coeff)
        {
            enter(&t,p->coeff,p->pow);
            p=p->next;
        }
        else
        {
            enter(&t,s->coeff,s->pow);
            s=s->next;
        }
    }
    while(p)
    {
        enter(&t,p->coeff,p->pow);
        p=p->next;
    }
    while(s)
    {
         enter(&t,s->coeff,s->pow);
        s=s->next;
    }
    return t;
}
int main()
{
    struct node*first=NULL;
    struct node*second=NULL;
    
    create(&first);
    display(first);
    create(&second);
    struct node *add=polyadd(first,second);
    display(add);
    
}