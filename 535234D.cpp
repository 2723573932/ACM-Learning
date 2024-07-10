#include <bits/stdc++.h>
using namespace std;
int dp[1007];
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += 100;
    }
    long long ans=0;
    for (int i = 1;i<=n;i++)
    {
        
    }
    cout<<ans;
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
