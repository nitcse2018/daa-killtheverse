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
    int graph[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            graph[i][j] = 0;
            else
            {
                graph[i][j] = INF;
            }
        }
    }
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
        graph[u][v] = w;
        graph[v][u] = w;
    }
    int V = n;
    int dist[V][V], k;  
    for (i = 0; i < V; i++)  
        for (j = 0; j < V; j++)  
            dist[i][j] = graph[i][j];  
    for (k = 0; k < V; k++)  
    {   
        for (i = 0; i < V; i++)  
        {  
            for (j = 0; j < V; j++)  
            {  
                if (dist[i][k] + dist[k][j] < dist[i][j])  
                    dist[i][j] = dist[i][k] + dist[k][j];  
            }  
        }  
    }  
    cout<<"The following matrix shows the shortest distances"
            " between every pair of vertices \n";  
    for (int i = 0; i < V; i++)  
    {  
        for (int j = 0; j < V; j++)  
        {  
            if (dist[i][j] == INF)  
                cout<<"INF"<<"     ";  
            else
                cout<<dist[i][j]<<"     ";  
        }  
        cout<<endl;  
    }  
}
