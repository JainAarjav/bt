#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node* rchild;
    int data;
    struct node* lchild;
}*root=NULL;

struct stack
{
    int top;
    int size;
    struct node **S;
};

int isempty(struct stack s)
{
    if(s.top==-1)
    return 1;
    else
    return 0;
}
int isfull(struct stack s)
{
    if(s.top==s.size-1)
    return 1;
    else
    return 0;
}
void innit(struct stack *st,int size)
{
    st->top=-1;
    st->size=size;
    st->S=malloc(sizeof(struct node*));
}
void push(struct stack *st,struct node *s)
{
    if(isfull(*st))
    {
        printf("STACK IS FULL");
    }
    else
    st->S[++(st->top)]=s;
}

struct node* pop(struct stack *st)
{
    if(isempty(*st))
    {
        return NULL;
    }
    else
    return st->S[(st->top)--];
}

struct node* Create()
{
    struct node *root=malloc(sizeof(struct node));
    printf("ENTER THE DATA\n");
    scanf("%d",&root->data);
    if(root->data==-1)
    return NULL;
    printf("ENTER THE DATA OF LCHILD OF %d\n",root->data);
    root->lchild=Create();
    printf("ENTER THE DATA OF RCHILD OF %d\n",root->data);
    root->rchild=Create();
    return root;
}
void IteCreate(struct node **root)
{
    struct node *temp,*curr,*prev=NULL;
    if( (*root)==NULL)
    {
        temp=malloc(sizeof(struct node));
        temp->rchild=temp->lchild=NULL;
        printf("ENTER THE DATA OF ROOT ");
        scanf("%d",&temp->data);
        *root=temp;
        curr=*root;
        prev=*root;
    }
    printf("ENTER THE OPTION \n 1.LEFT CHILD \n 2.RIGHT CHILD \n3.PREV \n4.ROOT\n 5.EXIT\n");
    int option;
    scanf("%d",&option);
    while(option!=5)
    {
        if(option==1)
        {
            prev=curr;
            temp=malloc(sizeof(struct node));
            temp->rchild=temp->lchild=NULL;
            printf("ENTER THE DATA");
            scanf("%d",&temp->data);
            curr->lchild=temp;
            curr=temp;
        }
        else if (option==2)
        {
            prev=curr;
            temp=malloc(sizeof(struct node));
            temp->rchild=temp->lchild=NULL;
            printf("ENTER THE DATA");
            scanf("%d",&temp->data);
            curr->rchild=temp;
            curr=temp;
        }
        else if(option ==3)
        {
            curr=prev;
        }
        else if(option ==4)
        {
            curr=*root;
        }
        else 
        {
            return;
        }
        printf("ENTER THE OPTION");
        scanf("%d",&option);
        
    }
}
void DisInorder(struct node *p)
{
    if(p)
    {
        DisInorder(p->lchild);
        printf("%d \t",p->data);
        DisInorder(p->rchild);
    }
}
void ItePre(struct node *t)
{
    struct stack s;
    innit(&s,100);
    while(t||!isempty(s))
    {
        if(t)
        {
            printf("%d",t->data);
            push(&s,t);
            t=t->lchild;
        }
        else
        {
        t=pop(&s);
        t=t->rchild; 
        }
    }
}
void ItePost(struct node *t)
{
    struct stack s;
    long int temp;
    innit(&s,100);
    while(t||!isempty(s))
    {
        if(t)
        {
            push(&s,t);
            t=t->lchild;
        }
        else
        {
            temp=(long int)pop(&s);
            if(temp>0)
            {
                push(&s,-temp);
                t=((struct node*)temp)->rchild;
            }
            else
            {
                printf("%d",((struct node*)-temp)->data);
                t=NULL;
            }
        }
    }
}

struct node* BST(struct node *p,int key)
{
    struct node *temp;
    if(p==NULL)
    {
        temp=malloc(sizeof(struct node));
        temp->rchild=temp->lchild=NULL;
        temp->data=key;
        return temp;
    }
    else if(key<p->data)
    {
        p->lchild=BST(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=BST(p->rchild,key);
    }
    return p;
}

int Height(struct node *p)
{
    int x,y;
    if (p==NULL)
    return 0;
    x=Height(p->lchild);
    y=Height(p->rchild);
    return x>y?x+1:y+1;
}
struct node *InPre(struct node *p)
{
    while(p && p->rchild!=NULL)
    {
        p=p->rchild;
    }
    return p;
}
struct node *Insucc(struct node *p)
{
    while(p && p->lchild!=NULL)
    {
        p=p->lchild;
    }
    return p;
}

struct node* Delete(struct node *p,int key)
{
    struct node *q;
    if(p==NULL)
    return NULL;
    if(p->lchild ==NULL && p->rchild == NULL)
    {
        if (p==root)
        root=NULL;
        free(p);
        return NULL;
    }
    
    if(key<p->data )
    {
        p->lchild=Delete(p->lchild,key);
    }
    else if(key>p->data)
    {
        p->rchild=Delete(p->rchild,key);
    }
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=InPre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
        else
        {
            q=Insucc(p->rchild);
            p->data=q->data;
            p->rchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}
int main(int argc, char const *argv[])
{
    // struct node *root=Create();
    
   root=BST(root,30);
   BST(root,20);
   BST(root,4);
    BST(root,3);
    BST(root,7);
    BST(root,2);
    BST(root,8);
    BST(root,1);

    root=Delete(root,20);
    // IteCreate(&root);

    DisInorder(root);
    printf("\n");
    ItePre(root);
    printf("\n");
    ItePost(root);
    return 0;
}
