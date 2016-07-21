#include<iostream>
#include<stdlib.h>
using namespace std;


struct node {
int data;
node *next;
};

void printlist(struct node* n)
{
 while(n->next!=NULL)
 {
 cout<<(n->data)<<" ";
 n=n->next;
 }


 cout<<(n->data);
}

void addFirst(struct node** n, int x)
{
  struct node* newNode = new node;
  newNode->data = x;
  newNode->next= *n;
  *n = newNode;

}

void deletenode(struct node** n, int x)
{
    struct node* temp=*n;
    struct node* prev;

    if(temp!=NULL && temp->data==x)
    {
        if(temp->next != NULL)
        {
      (*n) = temp->next;
      free(temp);}
      else
      free(temp);

      return;
    }

    while(temp!=NULL && temp->data != x)
    {
        prev=temp;
        temp=temp->next;
    }

    prev->next = temp->next;
    free(temp);
}

void insert(struct node* n, int x, int num)
{
    struct node* newNode = new node;
  newNode->data = num;

  int s=0;
  while(s<x)
  {
  s++;
  n=n->next;
  }
  newNode->next = n->next;
  n->next = newNode;
}

void swaplist(struct node* n, int x, int y)
{
    struct node* temp = n;
    struct node* prev1=NULL;
    struct node* num=NULL;
    struct node* prev2=NULL;
    struct node* num2=NULL;
    while(temp->data != x && temp->data !=y)
    {
        prev1=temp;
        prev2=prev1;
        temp=temp->next;
    }



    if(temp->data == x)
       {
           num=temp;
           while(temp->data !=y)
           {
               prev2=temp;
               temp=temp->next;
           }

           if(num->next->data ==temp->data)
           {
               num2= temp->next;
               prev1->next=temp;
               temp->next=num;
               num->next=num2;
           }

       else{
           num2 = num->next;



           prev1->next = temp;
         //  temp->next = num ->next;

           prev2->next = num;

           num->next = temp ->next;
           temp -> next=num2;
       }
       }


}

struct node* invertlist(struct node** n)
{
    struct node* prev = NULL;
    struct node* current = *n;
    struct node* temp=NULL;

    while(current != NULL)
    {
        temp = current->next;
        current->next =prev;
        prev = current;
        current = temp;
    }
    return prev;
}

struct node* SortedMerge(struct node *a, struct node *b)
{
    struct node* result = NULL;
    if(a==NULL)
    return (b);
    if(b==NULL)
    return (a);

    if(a->data >= b->data)
    {
        result = b;
        result->next=SortedMerge(a,b->next);
    }
    else
    {
        result = a;
        result->next=SortedMerge(a->next,b);
    }

    return(result);
}

void append(struct node **n, int x)
{
    struct node* newNode = new node;;
    struct node* last = *n;
    newNode->data= x;
    newNode->next=NULL;
    if(*n == NULL)
    {
    *n = newNode;
    return;
    }
while(last->next!=NULL)
{
last=last->next;
}
last->next=newNode;

}

int lPalin(node* A) {

   struct node* prev=new node;
   prev=invertlist(&A);


    /*current=A;
    node* prev=NULL;
    node* temp=NULL;

    while(current!=NULL)
    {
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;

    }*/
while(prev!=NULL)
{
    cout<<prev->data;
    prev=prev->next;
}
    while(A!=NULL && prev!=NULL)
    {
        if(prev->data!=A->data)
        return 0;
        cout<<A->data<<" "<<prev->data<<endl;
        prev=prev->next;
        A=A->next;
    }
    return 1;
}

struct node* deleteDuplicates(node* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    node* current=A;
    node* temp=A;
    node* ans=new node;
    ans=temp;

   // temp=current;
    int x;
    int count=0;
    while(current!=NULL)
    {
        x=current->data;
       // cout<<x;

        while(current->data==x )
        {

            //cout<<current->data;
        current=current->next;
        if(current==NULL)
        break;
        }

        temp->next=current;

        if(temp->next!=NULL)
        temp=temp->next;

    }
    return ans;
}

struct node* omit(node* a)
{
    if(a==NULL)
    return NULL;
    node* cur=a;
    node* prev=new node;
    append(&prev,0);
    prev->next=a;
    node* temp=prev;

    while(cur!=NULL)
    {
    while(cur->next!=NULL && cur->data==cur->next->data)
    cur=cur->next;

    if(temp->next==cur)
    temp=temp->next;

    else
    temp->next=cur->next;

    cur=cur->next;
}
return prev->next;
}


struct node* removeNthFromEnd(node* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int count=0;
    int num;
    int i=0;
    node* s=A;
    node* cur=A;
   // ListNode* prev=NULL;
    node* ans=A;
    node* temp=NULL;
    temp=ans;

 if(A==NULL)
 return NULL;
    while(A!=NULL)
    {
        count++;
        A=A->next;
    }
   // cout<<count;
    if(B>count)
    return s;
    num=count-B+1;
    //scout<<num;
    if(num==1)
       return cur->next;

    else
    {
        while(ans->next!=NULL)
        {
        i++;
        if(i==num-1)
        {
            ans->next=ans->next->next;
        }
       // cout<<ans->data;
        ans=ans->next;
        }
        return temp;
    }
}


int main()
{

struct node* root = NULL;
struct node* root2 = NULL;
/*
struct node* second = NULL;
struct node* third = NULL;

root = new node;
second = new node;
third = new node;

root->data = 5;
root->next = second;

second->data= 10;
second->next = third;


third -> data = 20;
third->next = NULL;
*/

append(&root,20);
//addFirst(&root,10);
append(&root,30);
append(&root,40);
append(&root,50);
append(&root,60);
append(&root,70);
//printlist(root);

append(&root2,15);
append(&root2,19);
append(&root2,25);
append(&root2,39);

//cout<<endl;
//invertlist(&root);
//swaplist(root,30,40);

//deletenode(&root,20);
//insert(root,1,30);
//printlist(root2);
//cout<<endl;


struct node* root3 = NULL;
append(&root3,1);
//append(&root3,1);
append(&root3,4);
//append(&root3,4);
//append(&root3,4);
append(&root3,5);
//append(&root3,6);
append(&root3,6);
//append(&root3,1);
struct node* ans=removeNthFromEnd(root3,2);
//cout<<ans->data;
printlist(ans);
//deleteDuplicates(root3);
//int x= lPalin(root3);
//cout<<endl<<x;
//printlist(SortedMerge(root,root2));

}
