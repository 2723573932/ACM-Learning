#include <bits/stdc++.h>
using namespace std;

vector<long long> dp[(int)1e7 + 7];
long long f[(int)1e7 + 7];
void solve()
{
    long long n, m;
    cin >> n >> m;
    dp[0].push_back(1);
    long long sum = 1;
    for (long long i = 1; i <= n; i++)
    {
        dp[i].push_back(sum);
        sum *= 2;
        dp[i].insert(dp[i].end(), dp[i - 1].begin(), dp[i - 1].end());
        for (long long j = 0; j <= min(i, m); j++)
        {
            f[i] += dp[i][j] * (j + 1);
            if(i/)
        }
    }
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
