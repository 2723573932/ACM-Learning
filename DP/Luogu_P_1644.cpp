#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp(50, vector<int>(50));
void solve()
{
    int n, m;
    cin >> m >> n;
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {

            if (i > 1)
            {
                if (j > 0)
                    dp[i][j] += dp[i - 2][j - 1];
                if (j != m)
                    dp[i][j] += dp[i - 2][j + 1];
            }
            if (i > 0)
            {
                if (j > 1)
                    dp[i][j] += dp[i - 1][j - 2];
                if (j < m - 1)
                    dp[i][j] += dp[i - 1][j + 2];
            }
        }
    }
    cout << dp[n][m];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    // cin>>tt;
    while (tt--)
        solve();
    return 0;
}
