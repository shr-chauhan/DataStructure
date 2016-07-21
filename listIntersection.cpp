#include<iostream>
using namespace std;

struct ListNode{
int val;
ListNode* next;
};
int getCount(ListNode* a)
{
    int count=1;
while(a->next!=NULL)
{
    a=a->next;
    count++;
}
return count;
}

ListNode* getIntersection(int d,ListNode* A, ListNode* B)
{
    ListNode* current1=A;
    ListNode* current2=B;
    //current1=A;
    //current2=B;
    while(d>0)
    {
        d--;
        current1=current1->next;
    }
    while(current1!=NULL && current2!=NULL)
    {
        if(current1==current2)
        {
            //cout<<current1->val;

        return current1;
        }
        current1=current1->next;
        current2=current2->next;
    }



}

ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
int d=0;
    int c1=getCount(A);
    int c2=getCount(B);
    if(c1>c2)
    {
        d=c1-c2;
        return getIntersection(d,A,B);
    }
     if(c2>c1)
    {
        d=c2-c1;
        return getIntersection(d,B,A);
    }

}


int main()
{
struct ListNode* newNode;
  struct ListNode* head1 =
            new ListNode;
  head1->val  = 10;

  struct ListNode* head2 =
            new ListNode;
  head2->val  = 3;

  newNode = new ListNode;
  newNode->val = 6;
  head2->next = newNode;

  newNode = new ListNode;
  newNode->val = 9;
  head2->next->next = newNode;

  newNode = new ListNode;
  newNode->val = 15;
  head1->next = newNode;
  head2->next->next->next  = newNode;

  newNode = new ListNode;
  newNode->val = 30;
  head1->next->next= newNode;
  head2->next->next->next->next=newNode;

  head2->next->next->next->next->next=NULL;
  head1->next->next->next = NULL;
struct ListNode* ans=NULL;
ans=getIntersectionNode(head1,head2);
while(ans!=0)
{
cout<<ans->val;
ans=ans->next;
}
}
