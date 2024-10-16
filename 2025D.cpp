#include <bits/stdc++.h>
using namespace std;
int dp[2][5003];
int cnt[5003];
void solve()
{
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        cnt[i] = cnt[i - 1];
        if (x == 0)
        {
            cnt[i]++;
            dp[1][0] = dp[0][0];
            for (int j = 1; j <= cnt[i]; j++)
            {
                dp[1][j] = max(dp[0][j], dp[0][j - 1]);
            }
        }
        else if (x > 0)
        {
            for (int j = 0; j < x; j++)
            {
                dp[1][j] = dp[0][j];
            }
            for (int j = x; j <= cnt[i]; j++)
            {
                dp[1][j] = dp[0][j] + 1;
            }
        }
        else
        {
            for (int j = 0; j <= cnt[i] + x; j++)
            {
                dp[1][j] = dp[0][j] + 1;
            }
            for (int j = cnt[i] + x + 1; j <= cnt[i]; j++)
            {
                dp[1][j] = dp[0][j];
            }
        }
        swap(dp[0], dp[1]);
    }
    for (int i = 0; i <= 5000; i++)
        ans = max(ans, dp[0][i]);
    cout << ans << '\n';
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
