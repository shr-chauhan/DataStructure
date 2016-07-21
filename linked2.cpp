#include<iostream>
using namespace std;
struct node
{
  int data;
  struct node *next;
};

void append(struct node** n, int x)
{
    struct node* first = new node;
    struct node* temp=NULL;
    temp=*n;
    first->data =x;
    first->next=NULL;
    if(*n==NULL)
    {
    (*n)=first;
    }
    else
    {
        while(temp->next!=NULL)
        temp=temp->next;

        temp->next = first;

    }


}

void splitlist(struct node *n, struct node** rear, struct node** front)
{
    struct node* temp = n;
    struct node* slow = n;
    struct node* fast = n;
    while(fast->next!=NULL)
    {
        fast=fast->next;
        if(fast->next!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }
    *rear=temp;
    *front = slow->next;
    slow->next=NULL;

}



struct node* mergelist(struct node* x, struct node* y)
{
    struct node *result = new node;
    if(x==NULL)
    return y;
    if(y==NULL)
    return x;
    if(x->data >= y->data)
    {
        result=y;
        result->next=mergelist(x,y->next);
    }
    if(x->data < y->data)
    {
        result=x;
        result->next=mergelist(x->next,y);
    }
    return result;

}

void reverselist(struct node** n)
{
    struct node* prev=NULL;
    struct node* cur=*n;
    struct node* temp=NULL;
    while(cur!=NULL)
    {
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;

    }
    *n = prev;
}

void mergesort(struct node** wat)
{
    struct node *head = *wat;
    struct node *a = NULL;
    struct node *b = NULL;
    if(head ==NULL || head->next ==NULL)
    return;
    splitlist(head,&a,&b);
    mergesort(&a);
    mergesort(&b);

    *wat = mergelist(a,b);
}
void printlist(struct node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}

struct node* addlist(struct node* x, struct node* y, int i)
{
    int a=0;
    struct node* result = new node;
    if(x==NULL && y!=NULL)
    {

        if(i==0)
        return y;
        else
        {
            a = (y->data + i);
            i=a/10;
            a=a%10;
            y->data++;
            return y;

        }
    }

    if(y==NULL && x!=NULL)
    {
         if(i==0)
        return x;
        else
        {
            a = (x->data + i);
            i=a/10;
            a=a%10;
            x->data++;
            return x;


        }
    }





   if(x==NULL && y==NULL)
    {
        struct node* temp1 = new node;
        if(i>0){

        temp1->data=i;
        temp1->next=NULL;
        return(temp1);

        }
        else{
        return NULL;
        }
    }
else{
      a=x->data + y->data + i;
    i=a/10;
    a=a%10;

    result->data = a;

    result->next = addlist(x->next,y->next,i);
}
return(result);

}
/*
void reverseAdd(struct node *temp, struct node* x, struct node* y)
{
 temp = addlist(x,y,0);
 reverselist(&temp);
}
*/
int main()
{
    struct node* root=NULL;
    struct node* root2=NULL;
    struct node* n=NULL;
    struct node* m=NULL;


append(&root,3);
append(&root,2);
append(&root,1);

append(&root2,1);
append(&root2,8);
append(&root2,8);
append(&root2,8);
append(&root2,8);
//append(&root2,9);
 /*   append(&root,10);
    append(&root,30);
    append(&root,20);
    append(&root,70);
    append(&root,50);*/
  //  splitlist(root,&n,&m);
n=addlist(root,root2,0);
reverselist(&n);
printlist(n);
/*
printlist(root);
reverselist(&root);
cout<<endl;
printlist(root);

cout<<endl;
mergesort(&root);
printlist(root);
    append(&root2,5);
    append(&root2,15);
    append(&root2,35);
*/
//printlist(root);
//cout<<endl;
//printlist(n);
//cout<<endl;
//printlist(m);
cout<<endl;
//printlist(mergelist(root,root2));
}
