#include<iostream>
#include<bits/stdc++.h>
using namespace std;
static int t[5][8];
int max(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
/*int knapsack(int wt[],int val[],int w,int n)
{
    if(n==0 || w==0)
        return 0;

    if(t[n][w]!=-1)
        return t[n][w];

    if(wt[n-1]<=w)
        return t[n][w] = max(val[n-1]+ knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));

    else
        return t[n][w] = knapsack(wt,val,w,n-1);
}*/

int main()
{
    int wt[]={1,3,4,5};
    int val[]={1,4,5,7};
    int w = 7;

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<8;j++)
            {
                if(i==0 || j==0)
                    t[i][j]=0;
            }
    }


    //filling matrix
    for(int i=1;i<5;i++)
    {
        for(int j=1;j<8;j++)
        {
            if(wt[i-1]<=j)
                t[i][j] = max( val[i-1] + t[i-1][j-wt[i-1],t[i-1][j]);

                t[i][j] = t[i-1][j];
        }
    }

    cout<<t[4][7];
    return 0;
}
