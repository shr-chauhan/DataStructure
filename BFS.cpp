#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph{
	int V;
	list<int> *adj;
public:
Graph(int V)
{
	this->V=V;
	adj = new list<int>[V];
}


void addEdge(int u,int v)
{
	adj[u].push_back(v);
}


void BFS(int s)
{
	vector<bool> visited(V);
	for(int i=0;i<V;i++)
	visited[i]=false;

	queue<int> q;
	q.push(s);
	visited[s]=true;
	list<int>::iterator i;
	int temp;
	while(!q.empty())
	{
		temp=q.front();
		cout<<temp<<" ";
		q.pop();
	  for(i = adj[temp].begin(); i != adj[temp].end(); ++i)
        {
            if(visited[*i]==false)
            {
                visited[*i] = true;
                q.push(*i);
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
	g.BFS(2);

	return 0;
}
