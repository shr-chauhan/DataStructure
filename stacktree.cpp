#include<iostream>
using namespace std;

struct tree{
int data;
struct tree *left;
struct tree *right;
};

struct stack{
tree *t;
stack *next;
};



struct tree* newNode(int x)
{
struct tree* newnode= new tree;
newnode->data = x;
newnode->left = NULL;
newnode->right = NULL;

return (newnode);
}

void push(struct stack** top, struct tree* t)
{
    struct stack* s=new stack;
    if(s==NULL)
    {
        cout<<"stack is full";
        return;
    }
    s->t=t;
    s->next=(*top);
    *top=s;
}

void enqueue(struct stack** r,struct tree* t)
{
    struct stack* s=new stack;
    struct stack* temp=*r;
    s->t=t;
    s->next=NULL;
    if((*r)==NULL)
    {
        (*r)=s;
    }
    else{
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=s;

    }
}


struct tree* pop(struct stack** s)
{

    struct stack* temp=*s;
    struct tree* t= temp->t;
    temp=temp->next;
    *s=temp;

    return t;
}

void display(struct stack* s)
{
    while(s!=NULL)
    {
        cout<<s->t->data;
        s=s->next;
    }
}

int main()
{
    struct tree* t=newNode(2);
    t->left=newNode(4);
    struct tree *p=NULL;
    struct stack* s=NULL;
    enqueue(&s,t);
    enqueue(&s,t->left);
    //push(&s,t);
    //push(&s,t->left);

    p=pop(&s);
    cout<<p->data;
    //display(s);
    //cout<<s->t->data;
}
