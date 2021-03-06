//BranhandBound.cpp
//Author: Rahul Dev Kureel
//Roll number:181210039
//Branch: CSE 2nd year
//A program which solves the fractional knapsack problem through Branch and bound approach

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

struct Item 
{ 
    float weight; 
    int value; 
}; 
  
struct Node 
{ 
    int level, profit, bound; 
    float weight; 
}; 

bool cmp(Item a, Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 

int bound(Node u, int n, int W, Item arr[]) 
{ 
    if (u.weight >= W) 
        return 0; 
  
    int profit_bound = u.profit; 
  
    int j = u.level + 1; 
    int totweight = u.weight; 
  
    while ((j < n) && (totweight + arr[j].weight <= W)) 
    { 
        totweight    += arr[j].weight; 
        profit_bound += arr[j].value; 
        j++; 
    } 
  
    if (j < n) 
        profit_bound += (W - totweight) * arr[j].value / 
                                         arr[j].weight; 
  
    return profit_bound; 
} 
  

int knapsack(int W, Item arr[], int n) 
{ 
    sort(arr, arr + n, cmp); 
  
    queue<Node> Q; 
    Node u, v; 
  
    u.level = -1; 
    u.profit = u.weight = 0; 
    Q.push(u); 
  
    int maxProfit = 0; 
    while (!Q.empty()) 
    { 
        u = Q.front(); 
        Q.pop(); 
  
        if (u.level == -1) 
            v.level = 0; 
  
        
        if (u.level == n-1) 
            continue; 
  
        v.level = u.level + 1; 
  
        v.weight = u.weight + arr[v.level].weight; 
        v.profit = u.profit + arr[v.level].value; 
  
        if (v.weight <= W && v.profit > maxProfit) 
            maxProfit = v.profit; 
  
        v.bound = bound(v, n, W, arr); 
  
        if (v.bound > maxProfit) 
            Q.push(v); 
  
        v.weight = u.weight; 
        v.profit = u.profit; 
        v.bound = bound(v, n, W, arr); 
        if (v.bound > maxProfit) 
            Q.push(v); 
    } 
  
    return maxProfit; 
} 

int main()
{
    int n, W;
    
    cout<<"\nEnter the number of items:";
    cin>>n;
    Item a[n];
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter value and weight for item "<<i+1<<":";
        int temp1;
        float temp2;
        cin>>temp1>>temp2;
        Item temp3;
        temp3.value = temp1;
        temp3.weight = temp2;
        a[i] = temp3;
    }
    cout<<"\nEnter the knapsack capacity:";
    cin>>W;
    int answer = knapsack(W, a, n);
    cout<<"\nMaximum total value is:"<<answer<<"\n";
    return 0;
}
