#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 998244353;
ll dp[107][107][107];
void solve()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    t = " " + t;
    s = " " + s;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m+1; j++)
            for (int k = 0; k < j; k++)
                dp[i][j][k] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int l = 1; l <= m; l++)
        {
            for (int r = l; r <= m; r++)
            {
                for (int k = l-1; k <= r; k++)
                {
                    (dp[i][l][r] += dp[i - 1][l][k] * dp[i - 1][k+1][r]) %= mod;
                }
                for (int k = l-1; k < r; k++)
                {
                    if (s[i] == t[k + 1])
                    {
                        (dp[i][l][r] += dp[i - 1][l][k] * dp[i - 1][k + 2][r]) %= mod;
                    }
                }
            }
        }
    }
    cout << dp[n][1][m] << '\n';
}
int main()
{
#if !LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tt = 1;
    // cin >> tt;
    while (tt--)
        solve();
#if LOCAL
    system("pause");
#endif
    return 0;
}
