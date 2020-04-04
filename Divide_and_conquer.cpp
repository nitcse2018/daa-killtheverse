//Divide_and_conquer.cpp
//Author: Rahul Dev Kureel
//Roll number:181210039
//Branch: CSE 2nd year
//A program which which solves the 0-1 knapsack problem using divide and conquer approach
//Time complexity: O(2^n)

#include<iostream>
#include<vector>
using namespace std;

int max(int a, int b)
{
    return (a>=b)?a:b;
}

int knapSack(int W, vector<int> wt, vector<int> val, int n)  
{  
      
if (n == 0 || W == 0)  
    return 0;  

if (wt[n-1] > W)  
    return knapSack(W, wt, val, n-1);  

else return max( val[n-1] + knapSack(W-wt[n-1], wt, val, n-1),  
                    knapSack(W, wt, val, n-1) );  
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
    cout<<"\nMaximum total value is:"<<knapSack(W, wt, v, n)<<"\n";
    return 0;
}
