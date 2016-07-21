#include<iostream>
#include<stdlib.h>
using namespace std;

struct list{
int data;
struct list *next;
};

class Graph{
int v;
list* *adj;
public:

Graph(int v)
{
this->v=v;
adj=new list*[v];
for(int i=0;i<v;i++)
{
    struct list* temp=NULL;
    adj[i]=temp;
}
}

void push_back(struct list **r,int i)
{
    struct list* temp=(*r);
    struct list* s=new list;

    s->data=i;
    s->next=NULL;
    if(*r==NULL)
    *r=s;
    else{
    while(temp->next!=NULL)
    temp=temp->next;
    temp->next=s;
    }

}

int pop(struct list **r)
{
    int x;
    struct list* temp=*r;
    if(temp->next==NULL)
    {
    x=temp->data;
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
    x=temp->data;
    free(temp);
    return x;
    }
}

void addEdge(int u, int v)
{
    //struct list* add=adj[u];
    push_back(&adj[u],v);
    //adj[u]=add;
}

int popTest(int s)
{
    int i=pop(&adj[s]);
    return i;
}

void show(int i)
{
    struct list* t=adj[i];
    while(t!=NULL)
    {
        cout<<t->data<<" ";
        t=t->next;
    }
}

void DFS(int s)
{
bool *visited=new bool[v];
for(int i=0;i<v;i++)
visited[i]=false;
struct list* dfs=NULL;
push_back(&dfs,s);
visited[s]=true;
struct list *temp=NULL;
while(dfs!=NULL)
{

    s=pop(&dfs);
    cout<<s<<" ";
    temp=adj[s];
    while(temp!=NULL)
    {
        if(visited[temp->data]==false)
        {
            //cout<<":"<<temp->data<<" ";
            push_back(&dfs,temp->data);
            visited[temp->data]=true;
        }
        temp=temp->next;
    }

}
}
};


int main() {
	// your code goes
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
	g.DFS(2);
    //g.funct(0);
    //g.show(0);
    //int i=g.popTest(0);
    //g.show(0);
	return 0;
}
