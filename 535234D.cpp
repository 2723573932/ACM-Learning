#include <bits/stdc++.h>
using namespace std;
int dp[1007][2 * (int)1e4+ 13];
constexpr long long mod = 998244353;
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
    long long ans = 0;
    dp[0][100] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j >=0; j--)
        {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i] >= 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - a[i]]) % mod;
        }
        dp[i][a[i]]++;
        ans = (ans + dp[i][100]) % mod;
    }
    cout << ans;
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
