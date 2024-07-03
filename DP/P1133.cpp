#include <bits/stdc++.h>
using namespace std;

int dp[(int)1e5 + 3][3][2];
int lst[(int)1e5 + 3][3];
void solve()
{
    int n;
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> lst[i][0] >> lst[i][1] >> lst[i][2];
    }
    for (int j = 0; j < 3; j++)
    {
        memset(dp[1], 0, sizeof(dp[1]));
        dp[1][j][0] = dp[1][j][1] = lst[1][j];
        for (int i = 2; i <= n; i++)
        {
            dp[i][0][0] = max(dp[i - 1][2][1], dp[i - 1][1][1]) + lst[i][0];
            dp[i][1][0] = dp[i - 1][2][1] + lst[i][1];
            dp[i][1][1] = dp[i - 1][0][0] + lst[i][1];
            dp[i][2][1] = max(dp[i - 1][0][0], dp[i - 1][1][0]) + lst[i][2];
        }
        for (int i = 0; i < j; i++)
        {
            ans = max(ans, dp[n][i][0]);
        }
        for (int i = 2; i > j; i--)
        {
            ans = max(ans, dp[n][i][1]);
        }
    }
    cout << ans << '\n';
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
