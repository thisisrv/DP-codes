#include<iostream>
#include<bits/stdc++.h>
static int t[6][7];
using namespace std;

void LCS(string x,string y, int m, int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i == 0 || j == 0)
            t[i][j] = 0;
        }
    }

    for(int i=1;i<m+1;i++)
    {
        for(int j=1;j<n+1;j++)
        {
            if(x[i-1] == y[j-1])
            t[i][j] = 1 + t[i-1][j-1];

            else
            t[i][j] = max(t[i-1][j],t[i][j-1]);
        }
    }

    int i = m, j = n;
    string s = "";
    while(i >0 && j>0)
    {
        if(x[i-1] == y[j-1])
        {
            s.push_back(x[i-1]);
            i--;j--;
        }
        else
        {
            if(t[i][j-1] > t[i-1][j])
                j--;
            else
                i--;
        }
    }

    reverse(s.begin(),s.end());

    cout<<s;
}
int main()
{
    string a,b;
    cin>>a;
    cin>>b;

    int m = a.length();
    int n = b.length();

    memset(t,-1,sizeof(t));

    LCS(a,b,m,n);

    return 0;
}
