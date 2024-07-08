#include <bits/stdc++.h>
using namespace std;

long long a[57];
int n, m1, m2;
long long ans = 0x3f3f3f3f3f;
vector<long long> lst(57);
void check(int pos, int maxn, int t)
{
    // 动态规划计算当前状态下的最优解
    if (pos == n||t==0)
    {
        long long dp[57];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
            for (int j = m1; j >= lst[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - lst[i]] + a[i]);
                // 剪枝：如果当前解已经大于等于ans，没有继续计算的必要
                if (dp[m1] >= ans)
                    break;
            }
        ans = min(ans, dp[m1]);
    }
    // 剪枝：如果当前已找到的最优解很小，或者没有更多的拆分方式，停止递归
    if (pos > n || t == 0 || ans == 0)
        return;
    for (int i = 1; i <= maxn && i <= t; i++)
    {
        lst[pos] = i;
        check(pos + 1, i, t - i);
        lst[pos] = 0;
    }
}
void solve()
{
    cin >> n >> m1 >> m2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<long long>());
    check(1, m2, m2);
    if (m1 == 0)
    {
        ans = 0;
        for (int i = 1; i <= n - m2; i++)
            ans += a[i];
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
