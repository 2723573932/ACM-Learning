//状态压缩DP
#include <bits/stdc++.h>
using namespace std;
int dp[(1 << 16)][17];
string s[20];
void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        cin >> s[i], dp[(1 << (i - 1))][i] = s[i].size();
    for (int k = 0; k < (1 << n); k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i != j && s[i].back() == s[j][0] && (k & (1 << (j - 1))) == 0 && (k & (1 << (i - 1))))
                {
                    dp[k + (1 << (j - 1))][j] = max(dp[k + (1 << (j - 1))][j], dp[k][i] + (int)s[j].size());
                }
            }
        }
    }
    for(int i=0;i<(1<<n);i++)
        for(int j=1;j<=n;j++)
            ans=max(ans,dp[i][j]);
    cout<<ans<<'\n';
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
