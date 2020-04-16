//greedy.cpp
//Author: Rahul Dev Kureel
//Roll number:181210039
//Branch: CSE 2nd year
//A program which solves the fractional knapsack problem through Greedy Programming approach
//Time complexity: O(nlogn) where n is the number of items

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item 
{ 
    int value, weight; 
}; 
  
bool cmp(struct Item a, struct Item b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 

double fractionalKnapsack(int W, vector<Item> arr, int n) 
{ 
    sort(arr.begin(), arr.end(), cmp); 
  
    int curWeight = 0;  
    double finalvalue = 0.0; 
  
    for (int i = 0; i < n; i++) 
    { 
       
        if (curWeight + arr[i].weight <= W) 
        { 
            curWeight += arr[i].weight; 
            finalvalue += arr[i].value; 
        } 
  
        else
        { 
            int remain = W - curWeight; 
            finalvalue += arr[i].value * ((double) remain / arr[i].weight); 
            break; 
        } 
    } 
  
    return finalvalue; 
}

int main()
{
    int n, W;
    
    cout<<"\nEnter the number of items:";
    cin>>n;
    vector <Item> a;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter value and weight for item "<<i+1<<":";
        int temp1, temp2;
        cin>>temp1>>temp2;
        Item temp3;
        temp3.value = temp1;
        temp3.weight = temp2;
        a.push_back(temp3);
    }
    cout<<"\nEnter the knapsack capacity:";
    cin>>W;
    int answer =fractionalKnapsack(W, a, n);
    cout<<"\nMaximum total value is:"<<answer<<"\n";
    return 0;
}
