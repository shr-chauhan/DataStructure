#include<iostream>
#include<list>
#include<stack>
using namespace std;

class Graph{

int V;
list<int> *adj;
public:
Graph(int V)
{
    this->V=V;
    adj=new list<int>[V];
}

void addEdge(int u, int v)
{
    adj[u].push_back(v);
}
void DFS(int s)
{
    bool *visited = new bool[V];
    for(int i=0;i<V;i++)
	visited[i]=false;
    stack<int> a;
    a.push(s);
    visited[s]=true;
    list<int>::iterator i;
    while(!a.empty())
    {
        s=a.top();
        a.pop();
        cout<<s<<" ";
        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(visited[*i]==false)
            {
                visited[*i]=true;
                a.push(*i);
            }
        }

    }
}
};


int main() {
	// your code goes here
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
	g.DFS(2);

	return 0;
}
