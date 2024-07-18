#include<bits/stdc++.h>
using namespace std;

const string s="dfs~",S="DFS~";
void solve()
{
    string x;
    cin>>x>>x;
    int f1=0,f2=0;
    for(auto i:x)
    {
        if(s[f1]==i)
        f1++;
        if(S[f2]==i)
        f2++;
    }
    if(f2>=3)
    cout<<"1"<<' ';
    else
    cout<<"0"<<' ';
    if(f1>=3)
    cout<<"1"<<'\n';
    else
    cout<<"0"<<'\n';
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
