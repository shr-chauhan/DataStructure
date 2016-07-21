#include<iostream>
#include<stdlib.h>
using namespace std;


struct tree
{
int data;
struct tree* left;
struct tree* right;
};

struct list{
struct tree* t;
struct list* next;
};



struct tree* newNode(int x)
{
struct tree* newnode= new tree;
newnode->data = x;
newnode->left = NULL;
newnode->right = NULL;

return (newnode);
}



void push_back(struct list **r,struct tree* t)
{
    struct list* temp=(*r);
    struct list* s=new list;

    s->t=t;
    s->next=NULL;
    if(*r==NULL)
    *r=s;
    else{
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=s;
    }

}


struct tree* pop(struct list **r)
{
    struct tree* x=NULL;
    struct list* temp=*r;
    if(temp->next==NULL)
    {
    x=temp->t;
    (*r)=NULL;
    return x;
    }
    else{

    struct list* s=NULL;
    while(temp->next!=NULL)
    {
        s=temp;
        temp=temp->next;
    }
    s->next=NULL;
    x=temp->t;
    free(temp);
    return x;
    }
}


void smallest(struct tree* r, int k)
{
    struct list* s=NULL;
    struct tree* temp=NULL;
    if(r!=NULL)
    {
        push_back(&s,r);
        while(r->left!=NULL)
        {
            r=r->left;
            push_back(&s,r);

        }
        //temp=pop(&s);
        while(s!=NULL)
        {

            temp=pop(&s);
            if(!--k)
            break;
            if(temp->right!=NULL){
            temp=temp->right;
            push_back(&s,temp);

            while(temp->left!=NULL)
        {
            push_back(&s,r->left);
            r=r->left;
        }
            }
        }
        cout<<temp->data;
    }
}


int main()
{
    struct tree* root = newNode(15);
    root->left=newNode(10);
    root->left->left=newNode(7);
    root->left->left->left=newNode(4);
    root->left->right=newNode(12);
    root->left->left->right=newNode(8);
    root->right=newNode(19);
    root->right->left=newNode(17);
   root->right->right=newNode(21);
   // temp=pop(&l);
    //cout<<root->left->data;
   // cout<<l->t->data;
   // cout<<l->next->t->data;
/*
  cout<<temp->data;
    while(l!=NULL)
    {
        cout<<l->t->data;
        l=l->next;
    }
    */


    smallest(root,6);

}
