#include <bits/stdc++.h>
using namespace std;
constexpr int N = 13, M = (int)1e5 + 3;
int mp[N][M];
int dp1[M], dp2[M], dp3[M];
int s[M], t[M];
void solve()
{
    int n, m;
    cin >> n >> m;
    if (n <= 2 || m <= 2)
    {
        cout << "-1";
        return;
    }
    dp1[0] = dp2[0] = dp3[0] = -1e9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> mp[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        t[i] = mp[1][i] + mp[n][i];
        for (int j = 1; j <= n; j++)
        {
            s[i] += mp[j][i];
        }
    }
    int ans=0;
    for (int i = 1; i <= m; i++)
    {
        dp1[i] = max(dp1[i - 1], 0) + s[i];
    }
    for (int i = 1; i <= m; i++)
    {
        dp2[i] = max(dp1[i - 1], dp2[i - 1]) + t[i];
    }
    for (int i = 1; i <= m; i++)
    {
        dp3[i] = max(dp2[i - 1], dp3[i - 1]) + s[i];
        ans=max(ans,dp3[i]);
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
