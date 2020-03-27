//Divide_and_conquer.cpp
//Author: Rahul Dev Kureel
//Roll number:181210039
//Branch: CSE 2nd year
//A program which when provided with an array outputs the sum of the maximum subarray
//Time complexity: O(nlogn)
//Though this problem can be solved in linear time using Kadane's algorithm, a Recursive approach has been used


#include<iostream>
#include<climits>
using namespace std;
int max_crossing_array(int a[], int low,int mid, int high)
{
    int i;
    int sum=0,leftsum=INT_MIN ,rightsum=INT_MIN,left_index,right_index;
    for(i=mid;i>=low;i--)
    {
        sum = sum + a[i];
        if(sum>leftsum)
        {
            leftsum = sum;
            left_index = i;
        }
    }
    sum = 0;
    for(i=mid+1;i<=high;i++)
    {
        sum = sum+a[i];
        if(sum>rightsum)
        {
            rightsum = sum;
            right_index = i;
        }
    }
    return leftsum+rightsum;   
}
int max_sub_array(int a[], int low, int high)
{
    if(high == low)
    return a[low];
    else
    {
        int mid = (low+high)/2;
        int leftsum = max_sub_array(a,low,mid);
        int rightsum = max_sub_array(a,mid+1,high);
        int crosssum = max_crossing_array(a,low,mid,high);
        if(leftsum>=rightsum&&leftsum>=crosssum)
        return leftsum;
        else if(rightsum>=leftsum&&rightsum>=crosssum)
        return rightsum;
        else
        {
            return crosssum;
        }
    }
}
int main()
{
    int n;
    cout<<"\nEnter the number of elements:";
    cin>>n;
    int i,*a = new int[n];
    cout<<"\nEnter the elements:";
    for(i=0;i<n;i++)
    cin>>a[i];
    cout<<"\nThe array is:\n";
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<"\nSum of elements of max sub array is:"<<max_sub_array(a,0,n-1)<<"\n";
    system("pause");
    return 0;
}