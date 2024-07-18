#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long ans=0,t,a,k;
    cin>>t>>a>>k;
    if(t>=a&&a>=-k||k>=a&&t<=a)
    ans=abs(a)+abs(a-t);
    else ans=abs(t)+abs(a-t)*2;
    cout<<ans;
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
