#include<iostream>
#include<limits.h>
using namespace std;

int solve (int arr[],int i,int j)
{
    if(i>=j)
    return 0;
    
    int min = INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int tempans = solve(arr,i,k) + solve(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        if(tempans<min)
        min=tempans;
    }

    return min;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    
    for(int i=0;i<n;i++)
    cin>>arr[i];
    
    cout<< solve(arr,1,n-1); 
    return 0;
}
