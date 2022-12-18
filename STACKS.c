#include <stdio.h>
#include <stdlib.h>
#include<string.h>
typedef struct stack
{
    int top;
    int size;
    char *Q;
}stack;

void innit(int size,stack *s)
{
    s->top=-1;
    s->size=size;
    s->Q=malloc(s->size*sizeof(char));
}

int isempty(stack* s)
{   
    if(s->top==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isfull(stack* s)
{
    if(s->top==s->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(char x,stack* s)
{
    if(isfull(s))
    {
        return ;
    }
    else
    {
        s->top++;
        s->Q[s->top]=x;
    }
}
char pop(stack*s)
{
    if(isempty(s))
    {
        return '\0';
    }
    else
    {
        return s->Q[(s->top)--];
    }
}

void display(stack *s)
{
    for(int i=0;i<s->top;i++)
    {
        printf("%c",s->Q[i]);
    }
}
int isoperand(char x)
{
    if(x=='+'||x=='-'||x=='/'||x=='*'||x==')'||x=='(')
    return 0;
    return 1;
}
int precedence(char x)
{
    if(x=='+'||x=='-')
    return 1;
    if(x=='/'|| x=='*')
    return 2;
    if(x=='(')
    return -69;
    return 0;
}
char* convert(char *infix)
{
    stack st;
    innit(strlen(infix),&st);
    // push('#',&st);
    char *postfix=malloc((strlen(infix)+1)*sizeof(char));
    int i=0;
    int j=0;
    while(infix[i]!='\0')
    {
        if(infix[i]=='('){
            push('(',&st);
            i++;
        }
        else if(isoperand(infix[i]))
        {
            postfix[j++]=infix[i++];
        }
        else
        {
             if(infix[i]==')')
            {
                while(st.Q[st.top]!='('&&!isempty(&st))
                {
                    postfix[j++]=pop(&st);
                }
                pop(&st);
                i++;
            }
            else if(precedence(infix[i])>=precedence(st.Q[st.top]))
            {
                push(infix[i++],&st);
            }
            else
            {
                postfix[j++]=pop(&st);
            }
           

        }
    }
    while(!isempty(&st))
    {
        postfix[j++]=pop(&st);
    }
    postfix[j]='\0';
    return postfix;
}
int main(int argc, char const *argv[])
{
    char *infix="(c+b)*a";
    char* postfix=convert(infix);
    printf("%s",postfix);
}

