#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    struct node* lchild;
    int data;
    struct node* rchild;
};

struct stack
{
    int size;
    int top;
    struct node **S;
};

void init(struct stack *s,int size)
{
    s->size=size;
    s->top=-1;
    s->S=malloc(s->size*sizeof(struct node *));
}

int isempty(struct stack *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    else
    return 0;
}

void push(struct stack *st,struct node *s)
{
    if(st->top==st->size-1)
    {
        printf("STACK OVERFLOW");
    }
    else
    {
        st->S[++(st->top)]=s;
    }
}
struct node * pop(struct stack *st)
{
    if(isempty(st))
    {
        return NULL;
    }
    else
    return st->S[(st->top)--];
}

struct node* Create()
{
    struct node* root= malloc(sizeof(struct node));
    printf("ENTER THE DATA ");
    scanf("%d",&root->data);
    if(root->data == -1)
    {
        return NULL;
    }
    
    printf("ENTER THE DATA OF LEFT CHILD OF  %d\n",root->data);
    root->lchild=Create();
    printf("ENTER THE DATA OF RIGHT CHILD OF %d \n",root->data);
    root->rchild=Create();
    return root;
}
void inorder(struct node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d \t",p->data);
        inorder(p->rchild);
    }
}
void iterativepre(struct node *t)
{
    struct stack s;
    init(&s,100);
    while(t || !isempty(&s))
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

void iterativepost(struct node *t)
{
    struct stack s;
    init(&s,100);
    long int temp;
    while(t || !isempty(&s))
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

void createBT(struct node **root)
{
    struct node *temp,*prev=NULL,*curr;
    if(*root==NULL)
    {
        temp=malloc(sizeof(struct node));
        temp->rchild=temp->lchild=NULL;
        printf("ENTER ROOT NODE DATA\n");
        int x;
        scanf("%d",&x);
        temp->data=x;
        *root=temp;
        prev=*root;
    }
    curr=*root;
    temp=malloc(sizeof(struct node));
    printf("ENTER THE OPTION \n 1.LEFT CHILD \n 2.RIGHT CHILD \n3.PREV \n4.ROOT\n 5.EXIT\n");
    int x;
    scanf("%d",&x);

    while(x!=5)
    {
        if(x==1)
        {
            prev=curr;
            temp=malloc(sizeof(struct node));
            temp->rchild=temp->lchild=NULL;
            printf("ENTER DATA OF LEFT CHILD\n");
            scanf("%d",&temp->data);
            curr->lchild=temp;
            curr=temp;
        
        }else if(x==2)
        {
            prev=curr;
            temp=malloc(sizeof(struct node));
            temp->rchild=temp->lchild=NULL;
            printf("ENTER DATA OF RIGHT CHILD\n");
            scanf("%d",&temp->data);
            curr->rchild=temp;
            curr=temp;
        }else if(x==3)
        {
            curr=prev;
        }else if(x==4)
        {
            curr=*root;
        }
        else
        return;
        printf("ENTER THE OPTION\n");
        scanf("%d",&x);
    }
}

int depth(struct node* root, int depthSoFar)
{
    if(root== NULL) return depthSoFar;
    //cout<<root->dat<<" "<<depthSoFar<<endl;
    int max = depth(root->lchild, depthSoFar+1), temp;
    if((temp=depth(root->rchild, depthSoFar+1))>max) 
    max=temp;
    return max;
}
int nLeafs(struct node *root){
    if(root==NULL) return 0;
    if(root->lchild==NULL&&root->rchild==NULL) return 1;
    return nLeafs(root->lchild)+nLeafs(root->rchild);
}

struct node* BST(struct node *p,int key)
{
    struct node* temp;
    if(p==NULL)
    {
        temp=malloc(sizeof(struct node ));
        temp->rchild=temp->lchild=NULL;
        temp->data=key;
        return temp;
    }
    else if(key<p->data)
    {
        p->lchild=BST(p->lchild,key);        
    }
    else
    {
          p->rchild=BST(p->rchild,key);  
    }
}

int main(int argc, char const *argv[])
{
    struct node *root=NULL;
    // struct node* root=NULL;
    // createBT(&root);
      BST(root,5);
    BST(root,6);
    BST(root,4);
    BST(root,3);
    BST(root,7);
    BST(root,2);
    BST(root,8);
    BST(root,1);
    inorder(root);
    printf("\n");
    iterativepre(root);
        printf("\n");
    iterativepost(root);
    printf("\nTHE DEPTH IS %d",depth(root,0));
    return 0;
}
