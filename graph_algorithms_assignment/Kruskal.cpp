#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<algorithm>
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
    vector<pair<int, int> > a;
    vector<int> u, v;
    cout<<"\nFor next "<<m<<" lines enter integers u v w such that node u and v are connected by an edge with weight w:\n";
    for(i=0;i<m;i++)
    {
        int x, y, w;
        cin>>x>>y>>w;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
        u.push_back(x);
        v.push_back(y);
        a.push_back(make_pair(w, i));
    }
    cout<<"\nFollowing are the edges for the minimum spanning tree:\n";
    sort(a.begin(), a.end());
    i=0;
    vector<bool> visited(n, false);
    while(true)
    {
        if(i==n-1)
        break;
        int x,y;
        x = u[a[i].second];
        y = v[a[i].second];
        while(visited[x]&&visited[y])
        {
            i++;
            x = u[a[i].second];
            y = v[a[i].second];
        }
        visited[x] = true;
        visited[y] = true;
        cout<<x+1<<"-----"<<y+1<<" with weight:"<<a[i].first<<"\n";
    }
    return 0;
}
