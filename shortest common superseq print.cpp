/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <bits/stdc++.h>
static int t[6][7];
using namespace std;


string LCSu(string a,string b,int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 || j==0)
            t[i][j] = 0;
        }
    }
    
    for(int i = 1; i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(a[i-1] == b[j-1] )
            t[i][j] = t[i-1][j-1] + 1;
            
            else
            t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }
    
    string s = "";
    
    int i = m , j = n;
    
    while(i>0 && j>0)
    {
        if(a[i-1] == b[j-1])
        {
            s.push_back(a[i-1]);
            i--;j--;
        }
        
        else
        {
            if(t[i][j-1]>t[i-1][j])
            {
                s.push_back(b[j-1]);
                j--;
            }
            else
            {
                s.push_back(a[i-1]);
                i--;
            }
        }
    }
    
    while(i>0)
    {
        s.push_back(a[i-1]);
        i--;
    }
    
    while(j>0)
    {
        s.push_back(b[j-1]);
        j--;
    }
    
    reverse(s.begin(),s.end());
    return s;
}

int main()
{
    string a,b;
    
    cin>>a;
    cin>>b;
    
    int m = a.length();
    int n = b.length();
    
    cout<<LCSu(a,b,m,n);

    return 0;
}
