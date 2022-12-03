#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
};
struct node* front=NULL;
struct node* rear=NULL;

void enter(int x)
{
    struct node *t= malloc(sizeof(struct node));
    t->data=x;
    t->next=NULL;
    if(front==NULL)
    {
        front=rear=t;
    }
    else
    {
        rear->next=t;
        rear=t;
    }
}
void display()
{
    struct node *p;
    p=front;
    while(p)
    {
        printf("%d\t",p->data);
        p=p->next;
    }
}

void delete()
{
    if(front==NULL)
    {
        printf("QUEUE IS EMPTY");
    }
    else
    {
        struct node* t;
        t=front;
        front=front->next;
        free(t);
    }
}
int main()
{
    enter(5);
    enter(8);
    enter(10);
    enter(12);
    delete();
        delete();

    display();

}