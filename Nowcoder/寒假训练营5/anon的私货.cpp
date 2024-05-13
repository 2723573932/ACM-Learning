#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin>>n;
    long long a[n+1];
    long long ans=0;
    a[0]=INT_MAX;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
        ans+=min(a[i]-1,a[i-1]-1);
        a[i]-=min(a[i]-1,a[i-1]-1);
    }
    ans+=a[n]-1;
    cout<<ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long tt=1;
    //cin>>tt;
    while(tt--)solve();
    return 0;
}
