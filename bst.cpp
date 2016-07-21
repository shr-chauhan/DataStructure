#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<limits.h>
using namespace std;

struct node
{
 int data;
 struct node *left;
 struct node *right;
};

struct node* newNode(int x)
{
struct node* newnode= new node;
newnode->data = x;
newnode->left = NULL;
newnode->right = NULL;

return (newnode);
}


struct node* insert(struct node*r, int x)
{

if(r==NULL)
return newNode(x);
else{
if(x<r->data)
r->left=insert(r->left,x);
else
r->right=insert(r->right,x);


return r;
}

}

void inorder(struct node* n)
{
    if(n==NULL)
    return ;

    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
}
int search(struct node *r, int key)
{
    if(r==NULL)
    return 0;
    if(r->data==key)
    return 1;
    else
    {
        if(key<r->data)
        return search(r->left,key);
        else
        return search(r->right,key);
    }

}

void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

/*
struct node* minValue(struct node* r)
{
    struct node* result=r;

    while(result->left!=NULL)
    result=result->left;


    return (result);
}

struct node* deleteNode(struct node* root, int key)
{
    if(root==NULL)
    return root;

    if(key>root->data)
    root->right=deleteNode(root->right,key);

    else if(key<root->data)
    root->left=deleteNode(root->left,key);

    else
    {
        if(root->left==NULL)
        {
            struct node* temp=root->right;
            free(root);
            return temp;
        }

        else if(root->right==NULL)
        {
            struct node* temp=root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValue(root->right);
        root->data = temp->data;
        root->right=deleteNode(root->right,temp->data);
    }

    return root;
}
*/
int isBSTUtil(node* r, int min, int max)
{
    if(r==NULL)
    return 1;

    if(r->data < min || r->data > max)
    return 0;
    else
    {
        return(isBSTUtil(r->left,min,r->data-1) && isBSTUtil(r->right,r->data+1,max));
    }

}

int isBST(struct node* r)
{
    return isBSTUtil(r, 0,100);
}

void findPreSuc(node* r, node*& pre, node*& suc, int key)
{
    if(r==NULL)
    return ;

    if(r->data == key)
    {
        if(r->left!=NULL)
        {
            struct node* temp =r->left;
            while(temp->right!=NULL)
            temp=temp->right;

            pre = temp;
        }
        if(r->right!=NULL)
        {
            struct node* temp = r->right;
            while(temp->left!=NULL)
            temp=temp->left;

            suc=temp;
        }
        return;
    }
    if(key > r->data)
    {
        pre=r;
        findPreSuc(r->right,pre,suc,key);
    }
    else
    {
        suc=r;
        findPreSuc(r->left,pre,suc,key);
    }

}


struct node* LCA(struct node* r, int n1, int n2)
{
    if(r==NULL)
    return NULL;

    if(r->data > n1 && r->data > n2)
    return LCA(r->left,n1,n2);

    if(r->data < n1 && r->data < n2)
    return LCA(r->right,n1,n2);

    return r;
}


struct node* ksmall(struct node* r, int n)
{
    stack<node*> s;
    s.push(r);
    struct node* temp=NULL;

    while(r->left!=NULL)
    {
        r=r->left;
        s.push(r);
    }

    while(!s.empty())
    {
        temp=s.top();
        s.pop();
        if(!--n)
        break;
        else
        {
            if(temp->right!=NULL)
            {
                temp=temp->right;
                s.push(temp);
                while(temp->left!=NULL)
                {
                    temp=temp->left;
                    s.push(temp);
                }
            }
        }
    }
return temp;
}

int ciel(struct node* r, int input)
{
if(r==NULL)
return -1;

if(input>r->data)
return ciel(r->right,input);

int Ciel=ciel(r->left,input);
if(Ciel>=input)
{
    return Ciel;
}

else
return r->data;

}

int floor(struct node *r, int input)
{
    if(r==NULL)
    return 100000;
    if(r->data==input)
    return r->data;

    if(r->data > input)
    return floor(r->left,input);

    int Floor=floor(r->right,input);

    if(Floor<=input)
    return Floor;
    else
    return r->data;


}

struct node* minValue(node* A)
{
    if(A->left==NULL)
    return A;
    else
    return minValue(A->left);
}

struct node* getSuccessor(node* A, int B, node* C) {
  node* temp=NULL;
  if(A==NULL)
  return A;
  if(A->data < B)
  return getSuccessor(A->right,B,C);
  else if(A->data > B)
  return getSuccessor(A->left,B,C);
  else
  {
      if(A->right)
      return minValue(A->right);
      else
      {

          while(C!=NULL)
          {
              if(C->data > B)
              {
                  temp=C;
                  C=C->left;
              }
              else if(C->data < B)
              C=C->right;
              else
              break;

          }
          return temp;
      }
  }

}

struct node* getVal(struct node* A, int B)
{
    struct node *C=A;
    return getSuccessor(A,B,C);
}


int main()
{

    struct node* root= NULL;
    struct node* min=NULL;
    root=insert(root,100);
    insert(root,98);
    insert(root,102);
    insert(root,96);
    insert(root,99);
    insert(root,97);
    insert(root,105);
    min=getVal(root,102);
    cout<<min->data;
  /*  insert(root,8);
    insert(root,22);
    insert(root,4);
    insert(root,12);
    insert(root,10);
    insert(root,14);
    inorder(root);

    int n=search(root,50);
    cout<<endl<<n<<endl;

    min=minValue(root);
    cout<<min->data<<endl;

    //root=deleteNode(root,30);
   // inorder(root);
    //node *pre=NULL;
    //node *suc=NULL;
   // findPreSuc(root,pre,suc,49);
    //if(pre!=NULL)
    //cout<<endl<<pre->data;
    //if(suc!=NULL)
    //cout<<endl<<suc->data<<endl;
    if(isBST(root)==1)
    cout<<"YES its a BST";
    else
    cout<<"NOT a BST";
    struct node* lca = LCA(root,10,14);
    cout<<endl<<"this is the LCA "<<lca->data;


struct node* small=ksmall(root,6);
cout<<endl<<small->data;

int c=ciel(root,16);
cout<<endl<<"ciel value : "<<c;


int f=floor(root,16);
cout<<endl<<"floor value : "<<f;

*/



}
