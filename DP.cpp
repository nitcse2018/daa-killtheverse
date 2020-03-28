//DP.cpp
//Author: Rahul Dev Kureel
//Roll number:181210039
//Branch: CSE 2nd year
//A program which solves the 0-1 knapsack problem through Dynamic Programming approach
//Time complexity: O(nW) where n is the number of items and W is knapsack capacity

#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b)
{
    return (a>=b)?a:b;
}

int knapsack(int W, vector<int> wt, vector<int> v, int n) 
{ 
    int i, w; 
    int K[n+1][W+1]; 
  
    for (i = 0; i <= n; i++) 
    { 
        for (w = 0; w <= W; w++) 
        { 
            if (i==0 || w==0) 
            K[i][w] = 0; 
            else if (wt[i-1] <= w) 
                K[i][w] = max(v[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
            else
                K[i][w] = K[i-1][w]; 
        } 
    } 
  
    return K[n][W]; 
}

int main()
{
    int n, W;
    vector<int> v, wt;
    cout<<"\nEnter the number of items:";
    cin>>n;
    cout<<"\nEnter the values of items:";
    for(int i=0;i<n;i++)
    {
        int j;
        cin>>j;
        v.push_back(j);
    }
    cout<<"\nEnter the weights of items:";
    for(int i=0;i<n;i++)
    {
        int j;
        cin>>j;
        wt.push_back(j);
    }
    cout<<"\nEnter the knapsack capacity:";
    cin>>W;
    cout<<"\nMaximum total value is:"<<knapsack(W, wt, v, n)<<"\n";
    return 0;
}
