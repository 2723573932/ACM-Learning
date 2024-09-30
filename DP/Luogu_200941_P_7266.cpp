#include <bits/stdc++.h>
using namespace std;
int mp[300][300];
int n;
int dp[300][300][2];
int ans = 0;
void dfs(int x, int y)
{
    if (x < n)
    {
        if (mp[x + 1][y] >= 0 && dp[x + 1][y][0] == -1)
        {
            dfs(x + 1, y);
        }
        if (mp[x + 1][y + 1] >= 0 && dp[x + 1][y + 1][0] == -1)
        {
            dfs(x + 1, y + 1);
        }

        dp[x + 1][y + 1][0] = max(0, dp[x + 1][y + 1][0]);
        dp[x + 1][y + 1][1] = max(0, dp[x + 1][y + 1][1]);
    }
    else
    {
        if (mp[x + 1][y] >= 0 && dp[x + 1][y][0] == -1)
        {
            dfs(x + 1, y);
        }
        if (mp[x + 1][y - 1] >= 0 && dp[x + 1][y - 1][0] == -1)
        {
            dfs(x + 1, y - 1);
        }
        dp[x + 1][y - 1][0] = max(0, dp[x + 1][y - 1][0]);
        dp[x + 1][y - 1][1] = max(0, dp[x + 1][y - 1][1]);
    }
    dp[x + 1][y][0] = max(0, dp[x + 1][y][0]);
    dp[x + 1][y][1] = max(0, dp[x + 1][y][1]);
    if (x < n)
    {
        dp[x][y][0] = max(dp[x + 1][y][0], dp[x + 1][y + 1][0]) + mp[x][y];
        dp[x][y][1] = max(max(dp[x + 1][y][1] + mp[x][y], dp[x + 1][y + 1][1] + mp[x][y]), max(dp[x + 1][y][0] + mp[x][299], dp[x + 1][y + 1][0] + mp[x][299]));
    }
    else
    {
        dp[x][y][0] = max(dp[x + 1][y][0], dp[x + 1][y - 1][0]) + mp[x][y];
        dp[x][y][1] = max(max(dp[x + 1][y][1] + mp[x][y], dp[x + 1][y - 1][1] + mp[x][y]), max(dp[x + 1][y][0] + mp[x][299], dp[x + 1][y - 1][0] + mp[x][299]));
    }
    ans = max(ans, dp[x][y][1]);
}
void solve()
{
    memset(dp, -1, sizeof(dp));
    memset(mp, -1, sizeof(mp));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int maxn = 0;
        for (int j = 1; j < n + i; j++)
        {
            cin >> mp[i][j];
            maxn = max(maxn, mp[i][j]);
        }
        mp[i][299] = maxn;
    }
    for (int i = n + 1; i < 2 * n; i++)
    {
        int maxn = 0;
        for (int j = 1; j < 3 * n - i; j++)
        {
            cin >> mp[i][j];
            maxn = max(maxn, mp[i][j]);
        }
        mp[i][299] = maxn;
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(1, i);
    }
    cout << ans;
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
