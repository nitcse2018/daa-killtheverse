#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<queue>
#define INF 9999999
using namespace std;


int main()
{
    cout<<"\nEnter the number of nodes in the graph:";
    int n,i,j;
    cin>>n;
    vector<pair<int, int> > adj[n];
    cout<<"\nEnter the number of edges:";
    int m;
    cin>>m;
    cout<<"\nFor next "<<m<<" lines enter integers u v w, such that node u and v are connected by an edge with weight w:\n";
    for(i=0;i<m;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        u--;
        v--;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    int src = 0;
    priority_queue< pair<int, int>, vector <pair<int, int> > , greater<pair<int, int> > > pq; 
    vector<int> dist(n, INF); 
    pq.push(make_pair(0, src)); 
    dist[src] = 0; 
    while (!pq.empty()) 
    { 
        int u = pq.top().second; 
        pq.pop();  
         
        for (i = 0; i < adj[u].size(); ++i) 
        {  
            int v = adj[u][i].first; 
            int weight = adj[u][i].second; 
            if (dist[v] > dist[u] + weight) 
            {
                dist[v] = dist[u] + weight; 
                pq.push(make_pair(dist[v], v)); 
            } 
        } 
    } 
  
    printf("Vertex   Distance from Source\n"); 
    for (int i = 0; i < n; ++i) 
        printf("%d \t\t %d\n", i+1, dist[i]); 
    return 0;
}
