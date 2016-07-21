#include<iostream>
using namespace std;

#define V 9

int minDistance(bool *a, int *d)
{
    int min=9999;
    int min_index;

    for(int i=0;i<V;i++)
    {
        if(a[i]==false && a[i]<min )
        {
            min=a[i];
            min_index=i;
        }
    }
    return min_index;
}


void printSolution(int *d)
{
    cout<<"this is the solution"<<endl;
    for(int i=0;i<V;i++)
    {
        cout<<i<<"--->"<<d[i]<<endl;
    }
}


void dijkstras(int g[V][V],int src)
{
    int d[V];
    bool s[V];
    for(int i=0;i<V;i++)
    {
      d[i]=9999;
      s[i]=false;
    }
    d[src]=0;
    //s[src]=true;
    for(int j=0;j<V;j++)
    {
        int u=minDistance(s,d);
        s[u]=true;

        for(int n=0;n<V;n++)
        {
            if(g[u][n] && !s[n] && d[u]!=9999 && d[u]+g[u][n]<d[n])
            d[n]=d[u]+g[u][n];
        }
    }

    printSolution(d);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstras(graph, 0);
}
