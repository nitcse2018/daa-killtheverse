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
    vector<bool> visited(n, false);
    visited[0] = true;
    for(i=0;i<n-1;i++)
    {
    	//cout<<"\ni:"<<i;
        int x,y,weight = 9999999;
        for(j=0;j<n;j++)
        {
            if(visited[j])
            {
                for(int k=0;k<n;k++)
                {
                    if(k==j)
                    continue;
                    if(visited[k])
                    continue;
                    //cout<<"\nchecking for k:"<<k<<" j:"<<j;
                    for(int l=0;l<m;l++)
                    {
                        if((u[l]==k&&v[l]==j)||(u[l]==j&&v[l]==k))
                        {
                        	//cout<<"\nchecking edge l:"<<l<<" u:"<<u[l]<<" v:"<<v[l];
                            if(a[l].first<weight)
                            {
                                x = k;
                                y = j;
                                weight = a[l].first;
                                //cout<<"\nx:"<<x<<" y:"<<y<<" weight:"<<weight;
                            }
                        }
                    }
                }
            }
        }
        visited[x] = true;
        visited[y] = true;
        cout<<x+1<<"-----"<<y+1<<" with weight:"<<weight<<"\n";
    }
    return 0;
}
