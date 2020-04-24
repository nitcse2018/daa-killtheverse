#include<iostream>
#include<vector>
#include<list>
#include<iterator>
using namespace std;


int main()
{
    cout<<"\nEnter the number of nodes in the graph:";
    int n,i,j;
    cin>>n;
    vector<int> adj[n];
    cout<<"\nEnter the number of edges:";
    int m;
    cin>>m;
    cout<<"\nFor next "<<m<<" lines enter integers u v such that node u and v are connected by an edge:";
    for(i=0;i<m;i++)
    {
        int u, v;
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"\nEnter the starting node for BFS:";
    int s;
    cin>>s;
    s--;
    list<int> q;
    q.push_back(s);
    vector<bool> visited(n, false);
    visited[s] = true;
    cout<<"\nThe nodes are visited in the following order:\n";
    while(!q.empty())
    {
        s = q.front();
        cout<<s+1<<" ";
        q.pop_front();
        
        for(int it=0;it<adj[s].size();it++)
        {
            if(!visited[adj[s][it]])
            {
                visited[adj[s][it]] = true;
                q.push_back(adj[s][it]);
                //cout<<"\npushing adj[s][it]:"<<adj[s][it];
            }
        }
    }
    return 0;
}