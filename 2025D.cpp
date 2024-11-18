#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> dp(m + 1), diff(m + 1);
    int sum = 0, ans = 0;
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            sum++;
            for (int i = 1; i <= m; i++)
                diff[i] += diff[i - 1];
            for (int i = 0; i <= m; i++)
                dp[i] += diff[i];
            for (int i = sum; i > 0; i--)
                dp[i] = max(dp[i], dp[i - 1]);
            diff.assign(m + 1, 0);
        }
        else if (sum >= abs(x))
        {
            if (x > 0)
            {
                diff[x]++;
            }
            else
            {
                diff[0]++;
                diff[sum + x + 1]--;
            }
        }
    }
    for (int i = 1; i <= m; i++)
        diff[i] += diff[i - 1];
    for (int i = 0; i <= m; i++)
        dp[i] += diff[i];
    for (int i = sum; i > 0; i--)
    {
        dp[i] = max(dp[i], dp[i - 1]);
        ans = max(ans, dp[i]);
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
