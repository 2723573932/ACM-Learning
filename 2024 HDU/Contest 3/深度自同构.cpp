#include <bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long f[(int)1e6+7],ans[(int)1e6+7];
void solve()
{
    int n;
    cin>>n;    
    f[1]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;i*j<=n;j++)
        {
            f[i*j+1]=(f[i*j+1]+f[i])%mod;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;i*j<=n;j++)
        {
            ans[i*j]=(ans[i*j]+f[i])%mod;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
    return 0;
}
