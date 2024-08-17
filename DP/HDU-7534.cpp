#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long v[11];
    for(long long i = 0; i < 10; i++)
        cin >> v[i];
    long long n,m;
    cin >> n >> m;
    vector<long long> dp(m+1),f(m+1);
    while(n--)
    {
        long long a,b;
        cin>>a>>b;
        for(long long i=a;i<=m;i++)
        {
            dp[i]=max(dp[i],dp[i-a]+b);
        }
    }
    for(long long i=1;i<=m;i++)
    {
        if(dp[i])
        for(long long j=i;j<=m;j++)
        {
            f[j]=max(f[j],f[j-i]+i*v[(dp[i]*10+i-1)/i-1]);
        }
    }
    cout<<f[m]<<'\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    long long tt = 1;
    cin >> tt;
    while (tt--)
        solve();
#if LOCAL
system("pause");
#endif
    return 0;
}
