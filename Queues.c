#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int front;
    int rear;
    int size;
    int *q;
}Que;

void enter(Que *q,int x)
{   
    if((q->rear+1)%q->size==q->front)
    {
        printf("THE QUE IS FULL\n");
    }
    else
    {
        q->rear=(q->rear+1)%(q->size);
        q->q[q->rear]=x;
    }
}
void delete(Que *q)
{   
    if(q->rear==q->front)
    {
        printf("THE QUE IS EMPTY ");
    }
    else 
    {
       q->front=(q->front+1)%q->size;
    }
}

void display(Que q)
{
    int i=q.front+1;
do
{
    printf("%d\t",q.q[i]);
    i=(i+1)%q.size;
}while(i!=(q.rear+1)%q.size);
printf("\n");
}
int main()
{
    Que Q;
    Q.size=4;
    Q.front=0;
    Q.rear=0;
    Q.q=(int *)calloc(Q.size,sizeof(int));
    enter(&Q,5);
    enter(&Q,7);
    enter(&Q,9);
    delete(&Q);
    enter(&Q,10);
    display(Q);
   
}