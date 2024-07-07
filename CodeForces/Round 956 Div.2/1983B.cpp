#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m;
    cin>>n>>m;
    int mp1[n][m],mp2[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            mp1[i][j]=c-'0';
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin>>c;
            mp2[i][j]=c-'0';
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            mp2[i][j]=(mp2[i][j]-mp1[i][j]+33)%3;
        }
    }
    int f=1;
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            if(mp2[i][j]==1)
            {
                mp2[i][j]=0;
                mp2[i][j+1]=(mp2[i][j+1]+1)%3;
                mp2[i+1][j]=(mp2[i+1][j]+1)%3;
                mp2[i+1][j+1]=(mp2[i+1][j+1]+2)%3;
            }
            else if(mp2[i][j]==2)
            {
                mp2[i][j]=0;
                mp2[i][j+1]=(mp2[i][j+1]+2)%3;
                mp2[i+1][j]=(mp2[i+1][j]+2)%3;
                mp2[i+1][j+1]=(mp2[i+1][j+1]+1)%3;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mp2[i][j]!=0)
            {
                f=0;
                break;
            }
        }
    }
    if(f)cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    cin>>tt;
    while(tt--)solve();
    return 0;
}
