#include<iostream>
using namespace std;

struct Stack
{
int top;
int capacity;
int *a;
};

int isEmpty(struct stack*);
struct Stack* createStack(int cap)
{
    struct Stack* s=new Stack;
    s->top=-1;
    s->capacity=cap;
    s->a=new int[s->capacity];
    return s;
}


int isFull(struct Stack* s)
{
   /* if((s->top) == (s->capacity-1))
    return 1;
    else
    return 0;
    */
    return s->top == s->capacity-1;
}

int isEmpty(struct Stack* s)
{
    return s->top==-1;
}

void push(struct Stack* s, int item)
{
    if(isFull(s))
    {
        cout<<"stack is full";
        return ;
    }
    else
    {
        s->a[++s->top]=item;
    }
}


int pop(struct Stack* s)
{
    if(isEmpty(s))
    {
        cout<<"stack is empty";
        return -999;
    }
    else
    {
        int temp=s->a[s->top--];
        return temp;
    }
}


void insertAtBottom(struct Stack* s, int item)
{
    if(isEmpty(s))
    push(s,item);
    else{
    int temp = pop(s);
    insertAtBottom(s,item);
    push(s,temp);

    }
}
void reverseStack(struct Stack* s)
{
    if(!isEmpty(s))
    {
        int temp=pop(s);
        reverseStack(s);
        insertAtBottom(s,temp);
    }
}
int peak(struct Stack* s)
{
      if(isEmpty(s))
    {
        cout<<"stack is empty";
        return -999;
    }
    else
    return s->a[s->top];
}

void printNGE(int a[], int n)
{
    struct Stack* s= createStack(n);
    push(s,a[0]);
    int element;
    int next;
    for(int i=1;i<n;i++)
    {
        next = a[i];
        if(!isEmpty(s))
        {
            element=pop(s);
            while(element<next)
            {
                cout<<element<<"--->"<<next<<endl;
                if(isEmpty(s))
                break;
                element=pop(s);
            }

            if(element>next)
            {
            push(s,element);
            }
        }

        push(s,next);
    }
    while(!isEmpty(s))
    {
        element=pop(s);
        cout<<element<<"---->"<<"-1"<<endl;
    }

}


int main()
{
    struct Stack* s= NULL;
    s=createStack(100);
    push(s,100);
    push(s,200);
    push(s,300);
    push(s,400);
    push(s,500);

    cout<<"this is the peak : "<<peak(s);
    reverseStack(s);
    cout<<"this is the peak : "<<peak(s);
int arr[]= {11, 13, 21, 3};
cout<<endl<<endl;
printNGE(arr,4);
}
