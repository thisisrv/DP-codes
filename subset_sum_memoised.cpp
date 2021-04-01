#include<iostream>
using namespace std;
int t[4][8]={-1};

bool subset(int arr[],int sum,int n)
{
    if(n==0)
        return false;
    else if(sum == 0)
        return true;

    if(t[n][sum] != -1)
        return t[n][sum];

    if(arr[n-1]<=sum)
        return t[n][sum] = (subset(arr,sum-arr[n-1],n-1) || subset(arr,sum,n-1));
    else
        return t[n][sum] = subset(arr,sum,n-1);
}

int main()
{
    int arr[]={4,5,6};
    int sum= 14;

    cout<<subset(arr,sum,3);

}
