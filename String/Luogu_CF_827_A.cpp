#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    string s((int)1e6,'a');
    int mx=0;
    while(n--)
    {
        string tmp;
        cin>>tmp;
        int k;
        cin>>k;
        while(k--)
        {
            int x;
            cin>>x;
            mx=max(x+(int)tmp.size()-1,mx);
            s.replace(x-1,tmp.size(),tmp);
        }
    }
    s.resize(mx);
    cout<<s;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt=1;
    // cin>>tt;
    while(tt--)solve();
    return 0;
}
