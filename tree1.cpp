#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<map>
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



void inorder(struct node* n)
{
    if(n==NULL)
    return ;

    inorder(n->left);
    cout<<n->data;
    inorder(n->right);
}

void preorder(struct node* n)
{
    if(n==NULL)
    return ;

    cout<<n->data;
    preorder(n->left);
    preorder(n->right);
}

void postorder(struct node* n)
{
    if(n==NULL)
    return ;

    postorder(n->left);
    postorder(n->right);
    cout<<n->data;
}

void printLeaves(struct node* n)
{
    if(n==NULL)
    return;

    else{
        printLeaves(n->left);
    if(n->right==NULL && n->left==NULL)
    {
        cout<<n->data;
    }
    printLeaves(n->right);
    }

}

void printLeft(struct node* n)
{
  if(n)
  {
      if(n->left)
      {
          cout<<n->data;
          printLeft(n->left);
      }
      else if(n->right)
      {
          cout<<n->data;
          printLeft(n->right);
      }
  }
}




void printRight(struct node* n)
{
  if(n)
  {
      if(n->right)
      {
          cout<<n->data;
          printRight(n->right);
      }
      else if(n->left)
      {
          cout<<n->data;
          printRight(n->left);
      }
  }
}
void printBoundary(struct node* root)
{
    if(root)
    cout<<root->data;

    printLeft(root->left);
    printLeaves(root);
    printRight(root->right);


}

int height(struct node* r)
{
    if(r==NULL)
    return 0;
    else{
    return 1+max(height(r->left),height(r->right));

    }
}


int diameter(struct node * n)
{
    if(n==NULL)
    return 0;

int l=height(n->left);
int r=height(n->right);

int ld=diameter(n->left);
int rd=diameter(n->right);

return max((1+l+r),max(ld,rd));
}

//void printgiven(struct node *, int);
/*
void printlevel(struct node* r)
{
    int h=height(r);
    int i =0;
    for(i=1;i<=h;i++)
    printgiven(r,i);


}
*/
int getWidth(struct node*, int);

int printwidth(struct node* r)
{
    int max=0;
    int num;
    int h=height(r);
    int i =0;
    for(i=1;i<=h;i++)
    {
        num=getWidth(r,i);
        cout<<endl<<num;
        if(num>max)
        max=num;
    }
    return max;


}

int getWidth(struct node *r, int i)
{
    if(r==NULL)
    return NULL;

    if(i==1)
    return 1;
    else
    return (getWidth(r->left,i-1)+getWidth(r->right,i-1));

}

void levelOrder(struct node* r)
{
    struct node * temp=NULL;
    queue<node*> q;
    q.push(r);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data;
        if(temp->left!=NULL)
        q.push(temp->left);
        if(temp->right!=NULL)
        q.push(temp->right);


    }
}
/*
void printgiven(struct node* r, int i)
{
    if(r==NULL)
    return;
    if(i==1)
    cout<<r->data;
    else
    {
        printgiven(r->left,i-1);
        printgiven(r->right,i-1);
    }

}*/

bool printAcestors(struct node* r, int num)
{
    if(r==NULL)
    return false;

    if(r->data == num)
    return true;

    if(printAcestors(r->left,num)||printAcestors(r->right,num))
    {
      cout<<r->data<<" ";
      return true;
    }


    return false;
}

void inorderIterative(struct node* n)
{
    stack<node*> q;
    struct node* temp = n;
    int i=1;
    while(i)
    {
        if(temp!=NULL)
        {
        q.push(temp);
        temp=temp->left;
        }


        else{
        if(!q.empty())
        {
            temp=q.top();
            cout<<temp->data;
            q.pop();

            temp=temp->right;
        }
        else
        break;


        }
    }
}

void preorderIterative(struct node *r)
{
    stack<node*> s;
    struct node* temp = r;
    s.push(r);

    while(!s.empty())
    {
        temp=s.top();
        cout<<temp->data;
        s.pop();

        if(temp->right!=NULL)
        s.push(temp->right);
        if(temp->left!=NULL)
        s.push(temp->left);

    }
}

void postorderIterative(struct node *r)
{
    stack<node*> s1;
    stack<node*> s2;
    struct node* temp=NULL;
    s1.push(r);
    int i=1;
    while(!s1.empty())
    {
        temp=s1.top();
        s2.push(temp);
        s1.pop();

        if(temp->left!=NULL)
        s1.push(temp->left);

        if(temp->right!=NULL)
        s1.push(temp->right);
    }
    while(!s2.empty())
    {
        temp=s2.top();
        cout<<temp->data;
        s2.pop();
    }
}

int search(int a[], int start, int end, int value)
{
    for(int i=start;i<=end;i++)
    {
        if(value==a[i])
        return i;
    }
}


struct node* buildTree(int a[], int pre[],int start, int end)
{
   static int num=0;
if(start>end)
return NULL;

    struct node* root=newNode(pre[num++]);

    if(start==end)
    return root;

    int index = search(a,start,end,root->data);

    root->left=buildTree(a,pre,start,index-1);
    root->right=buildTree(a,pre,index+1,end);

    return root;

}

/*
void vertical(struct node* n, int hd, map<int, vector<int> > &m)
{
    if(n==NULL)
    return;

    m[hd].push_back(n->data);
    vertical(n->left,hd-1,m);
    vertical(n->right,hd+1,m);
}
*/

void printgiventop(struct node* r, int i,int hd,map<int, int > &m);

void printleveltop(struct node* r,map<int,int> &m)
{
    int h=height(r);
    int i =0;
    int hd=0;
    for(i=1;i<=h;i++)
    printgiventop(r,i,hd,m);


}

void printgiventop(struct node* r, int i,int hd,map<int, int > &m)
{
    if(r==NULL)
    return;
    if(i==1)
    {
        cout<<"r->data: "<<r->data<<endl;
    m.insert(pair<int,int>(hd,r->data));
    }
    else
    {
        printgiventop(r->left,i-1,hd-1,m);
        printgiventop(r->right,i-1,hd+1,m);
    }

}
/*
void vertical(struct node* n, int hd, map<int, int> &m)
{

if(n==NULL)
    return;
 m.insert(pair<int,int>(hd,n->data));
  //  m[hd].push_back(n->data);
    vertical(n->left,hd-1,m);
    vertical(n->right,hd+1,m);


     struct node * temp=NULL;
    queue<node*> q;
    q.push(n);
    int l=hd;
    int r=hd;
    m.insert(pair<int,int>(hd,n->data));
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data;
        if(temp->left!=NULL)
        {l=l-1;
        q.push(temp->left);
        m.insert(pair<int,int>(l,n->data));
        }
        if(temp->right!=NULL)
        {
            r=r+1;
        q.push(temp->right);
        }

    }
}*/
void printVertical(struct node* n)
{
    if(n==NULL)
    return;
    map<int,int>m;
    printleveltop(n,m);

    map<int, int> :: iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        cout<<it->second<<" ";

    }
}

int main()
{

 /*   struct node* root = newNode(1);
    root->left=newNode(2);
    root->left->right=newNode(5);
    root->left->left=newNode(4);
    root->right=newNode(3);
    root->right->left=newNode(6);
    root->right->right=newNode(7);

    cout<<"inorder recursive : ";
    inorder(root);
    cout<<endl;
    cout<<"inorder iterative : ";
    inorderIterative(root);
    cout<<endl;
    cout<<"preorder recursive : ";
    preorder(root);
    cout<<endl;
    cout<<"preorder iterative : ";
    preorderIterative(root);
    cout<<endl;

    cout<<"postorder recursive : ";
    postorder(root);
    cout<<endl;
    cout<<"postorder iterative : ";
    postorderIterative(root);
    cout<<endl;
    cout<<"height is : "<<height(root)<<endl;
    cout<<"diameter is : "<<diameter(root)<<endl;
    cout<<"levelorder recursive : ";
    printlevel(root);
    cout<<endl;
    cout<<"levelorder iterative : ";
    levelOrder(root);
    cout<<endl;
    int a[]={4,2,5,1,6,3,7};
    int b[]={1,2,4,5,3,6,7};
    struct node* root3=buildTree(a,b,0,6);
    postorder(root3);


    int num=printwidth(root);

    cout<<endl<<"this is d max width : "<<num;
    cout<<endl;
    printAcestors(root,6);
    cout<<endl;
    printBoundary(root);
*/

struct node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
   // root->left->left->left = newNode(15);
    root->left->left->right = newNode(52);
    root->left->left->right->left = newNode(53);
    root->left->left->right->left->left = newNode(55);
    root->left->right = newNode(3);
    //root->left->right->right = newNode(5);
    //root->left->right->right->right = newNode(6);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    cout << "Vertical order traversal is \n";
   // printVertical(root);

   // printBoundary(root);
    //printAcestors(root,14);
	printVertical(root);
	return 0;
}
