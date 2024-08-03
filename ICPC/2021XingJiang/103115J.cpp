#include <bits/stdc++.h>
using namespace std;
int dp[(int)1e6 + 7][2];
int f[(int)1e6 + 7];
void solve()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        f[x]++;
    }
    for (int i = 1; i <= 1e6; i++)
    {
        if (i & 1)
        {
            dp[i][1] = f[i];
            dp[i][0] = 0;
        }
        else
        {
            dp[i][1] = min(dp[i / 2][1], dp[i / 2][0]) + f[i];
            dp[i][0] = dp[i /2][1];
        }
    }
    int ans = 0;
    for (int i = 5e5 + 1; i <= 1e6; i++)
        ans += min(dp[i][0], dp[i][1]);
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
