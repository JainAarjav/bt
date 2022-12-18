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

struct node* create()
{
    struct node* root=malloc(sizeof(struct node));
    int x;
    printf("ENTER THE DATA\n");
    scanf("%d",&x);
    root->data=x;
    if(x==-1)
    return NULL;
    printf("ENTER THE DATA OF THE LCHILD OF %d\n",root->data);
    root->lchild=create();
    printf("ENTER THE DATA OF THE RCHILD OF %d\n",root->data);
    root->rchild=create();
    return root;
}

void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d",p->data);
        inorder(p->rchild);
    }
    else
    {
        return;
    }
}
void itpre(struct node *p)
{
    struct stack st;
    innit(&st,100);
    while(p || !isempty(st))
    {
        if(p)
        {
            printf("%d",p->data);
            push(&st,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&st);
            p=p->rchild;
        }

    }
}
void itpost(struct node *p)
{
    struct stack st;
    long int temp;
    innit(&st,100);
    while(p || !isempty(st))
    {
        if(p)
        {
            push(&st,p);
            p=p->lchild;
        }
        else
        {
            temp=(long)pop(&st);
            if(temp>0)
            {
                push(&st,-temp);
                p=((struct node *)temp)->rchild;
            }
            else
            {
                printf("%d",((struct node *)-temp)->data);
                p=NULL;

            }
        }

    }
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
struct node* BST(struct node* p ,int key)
{
    if (p==NULL)
    {
        p=malloc(sizeof(struct node));
        p->data=key;
        p->rchild=NULL;
        p->lchild=NULL;
        return p;
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
struct node * inpre(struct node * p)
{
    while(p&&p->rchild)
    {
        p=p->rchild;
    }
    return p;
}

struct node * insucc(struct node * p)
{
    while(p&&p->lchild)
    {
        p=p->lchild;
    }
    return p;
}
struct node* DELETE(struct node *p,int key)
{
    struct node *q;
    if(p==NULL)
    return NULL;
    if(p->rchild==NULL && p->lchild==NULL)
    {
        if(p==root)
        root=NULL;
        free(p);
        return NULL;
    }
    if(key<p->data)
    {
        p=Delete(p->lchild,key);
    }
    else if(key>p->rchild)
    {
        p=Delete(p->rchild,key);
    }
    else
    {
        if(Height(p->lchild)>Height(p->rchild))
        {
            q=inpre(p->lchild);
            p->data=q->data;
            p->lchild=Delete(p->lchild,q->data);
        }
         else
        {
            q=insucc(p->rchild);
            p->data=q->data;
            p->lchild=Delete(p->rchild,q->data);
        }
    }
    return p;
}
int main()
{
    struct node *root=create();
    // inorder(root);
    itpre(root);
    itpost(root);
    printf("%d",Height(root));
    
}
/*
                3
             /    \
            1       4  
             \        \ 
                2       5

inorder: 1 2 3 4 5
preorder: 3 1 2 4 5
postorder: 2 1 5 4 3

*/
